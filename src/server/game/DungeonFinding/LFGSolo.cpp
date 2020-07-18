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

        if (sConfigMgr->GetIntDefault("LFG.SOLO.Announce", true))
        {
            ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Solo Dungeon Finder |rCORE-update.");
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage("|cff4CFF00Solo Dungeon Finder |rCORE-update announcer is disabled.");
        }
    }

    void LFGSolo::OnLogin(Player* __attribute__ ((unused))player)
    {
        if (sConfigMgr->GetIntDefault("LFG.SOLO.Enable", true))
        {   
            ChatHandler(player->GetSession()).SendSysMessage("|cff4CFF00Solo Dungeon Finder |gEnabled.");
            if (!sLFGMgr->IsSoloLFG())
            {
                sLFGMgr->ToggleSoloLFG();
            }
        }
        else 
        {
            ChatHandler(player->GetSession()).SendSysMessage("|cff4CFF00Solo Dungeon Finder |rDisabled.");
        }
    }

    void LFGSoloConfig::OnBeforeConfigLoad(bool reload) 
    {
        if (!reload) {
            // TBD - advanced configurations
        }
    }

} // namespace lfg