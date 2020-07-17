/*
** Made by Traesh https://github.com/Traesh
** AzerothCore 2019 http://www.azerothcore.org/
** Conan513 https://github.com/conan513
** Made into a module by Micrah https://github.com/milestorme/
** Integrated to core by elmerbud https://github.com/elmerbud/
*/

#include "ScriptMgr.h"
#include "Player.h"
#include "Configuration/Config.h"
#include "World.h"
#include "LFGMgr.h"
#include "Chat.h"
#include "Opcodes.h"
#include "LFGSolo.h"

namespace lfg
{
    void LFGSoloAnnounce::OnLogin(Player* player)
    {

        if (sConfigMgr->GetBoolDefault("SoloLFG.Announce", true))
        {
            ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Solo Dungeon Finder |rCORE-update.");
        }
    }

    void LFGSolo::OnLogin(Player* __attribute__ ((unused))player)
    {
        if (sConfigMgr->GetIntDefault("SoloLFG.Enable", true))
        {
            if (!sLFGMgr->IsSoloLFG())
            {
                sLFGMgr->ToggleSoloLFG();
            }
        }
    }

    void LFGSoloConfig::OnBeforeConfigLoad(bool reload) 
    {
        if (!reload) {
            std::string conf_path = _CONF_DIR;
            std::string cfg_file = conf_path + "/SoloLfg.conf";

            std::string cfg_def_file = cfg_file + ".dist";
            sConfigMgr->LoadMore(cfg_def_file.c_str());
            sConfigMgr->LoadMore(cfg_file.c_str());
        }
    }

} // namespace lfg