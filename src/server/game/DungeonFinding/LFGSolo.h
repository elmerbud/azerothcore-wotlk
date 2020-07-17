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

namespace lfg
{
    class LFGSoloAnnounce : public PlayerScript
    {

        public:
            LFGSoloAnnounce() : PlayerScript("LFGSoloAnnounce") {}

            void OnLogin(Player* player);

    };

    class LFGSolo : public PlayerScript
    {

        public:
            LFGSolo() : PlayerScript("LFGSolo") {}

            void OnLogin(Player* player);

    };

    class LFGSoloConfig : public WorldScript
    {

        public:
            LFGSoloConfig() : WorldScript("LFGSoloConfig") { }

            void OnBeforeConfigLoad(bool reload) override;

    };

} // namespace lfg