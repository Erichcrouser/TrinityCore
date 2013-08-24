#include "ScriptPCH.h"
#include "Config.h"

#define CUSTOM_BLUE          "|cff00479E"
#define CUSTOM_RED            "|cffFF0000"
#define CUSTOM_WHITE        "|cffffffff"
#define CUSTOM_LIGHTRED    "|cffD63931"

class announce_login : public PlayerScript
{
    public:
                announce_login() : PlayerScript("announce_login") { }
        
                void OnLogin(Player * player)
				{
					if (sWorld->getBoolConfig(CONFIG_ANNOUNCE_LOGIN_PLAYER))
					{
						char msg[500];
						if(player->GetTeam() == ALLIANCE)
						{
							sprintf(msg, "%s|r Игрок %s%s|r подключился к серверу. [%sАльянс|r]", CUSTOM_LIGHTRED, CUSTOM_WHITE, player->GetName(), CUSTOM_BLUE);
							sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
						}else{
							sprintf(msg, "%s|r Игрок %s%s|r подключился к серверу. [%sОрда|r]", CUSTOM_LIGHTRED, CUSTOM_WHITE, player->GetName(), CUSTOM_RED);
							sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
						}
					}
				}
				
				void OnLogout(Player* player)
				{
					if (sWorld->getBoolConfig(CONFIG_ANNOUNCE_LOGOUT_PLAYER))
					{
						char msg[500];
						if(player->GetTeam() == ALLIANCE)
						{
						sprintf(msg, "%s|r Игрок %s%s|r отключился от сервера. [%sАльянс|r]", CUSTOM_LIGHTRED, CUSTOM_WHITE, player->GetName(), CUSTOM_BLUE);
						sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
						}else{
						sprintf(msg, "%s|r Игрок %s%s|r отключился от сервера. [%sОрда|r]", CUSTOM_LIGHTRED, CUSTOM_WHITE, player->GetName(), CUSTOM_RED);
						sWorld->SendWorldText(LANG_SYSTEMMESSAGE, msg);
						}	
					}
				}
};
 
void AddSC_announce_login()
{
        new announce_login;
}