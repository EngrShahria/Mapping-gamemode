/*
   _____                       .__                
  /     \ _____  ______ ______ |__| ____    ____  
 /  \ /  \\__  \ \____ \\____ \|  |/    \  / ___\ 
/    Y    \/ __ \|  |_> >  |_> >  |   |  \/ /_/  >
\____|__  (____  /   __/|   __/|__|___|  /\___  / 
        \/     \/|__|   |__|           \//_____/  
___________              __                           
\__    ___/___   _______/  |_    _________  _________ 
  |    |_/ __ \ /  ___/\   __\  /  ___/\  \/ /\_  __ \
  |    |\  ___/ \___ \  |  |    \___ \  \   /  |  | \/
  |____| \___  >____  > |__|   /____  >  \_/   |__|   
             \/     \/              \/
WHAT IT DOES? : You can test any mapping code by yourself, anytime without GMX the server or load manytimes.
 */

/*
	SERVER CORE INCLUDS 
*/
#include <a_samp>
#include <streamer>
#include <sscanf2>
#include <ZCMD>


/*

	SCRIPT'S CORE INCLUDS
*/
#include "./inc/core.pwn"
#include "./inc/commands.inc"
#include "./inc/callbacks.inc"
#include "./inc/stocks.inc"



main( ) { }

public OnPlayerConnect(playerid){ return 1; }
public OnPlayerDisconnect(playerid, reason){ return 1; }

public OnGameModeInit()
{

  AddPlayerClass(0, -2299.2156, -1644.6145, 483.6988, 269.1425, 0, 0, 0, 0, 0, 0);
  return 1;
}

public OnGameModeExit()
{
  return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
  SetPlayerPos(playerid, -2299.2156, -1644.6145, 483.6988);
  SetPlayerCameraPos(playerid, -2299.2156, -1644.6145, 483.6988);
  SetPlayerCameraLookAt(playerid, -2299.2156, -1644.6145, 483.6988);
  return 1;
}

