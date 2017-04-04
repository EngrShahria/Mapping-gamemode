////////////////~~~~~Class Variables~~~~~//////////////////////
new SCMstring[128];
new GodMode[MAX_PLAYERS];
////////////////////////~~~~~Defines~~~~~/////////////////////
#define TELEPORT_DIALOG 1
#define WEAPON_DIALOG 2
#if !defined isnull
    #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif
/////////////////////////~~~~~Commands~~~~~///////////////////
CMD:gotocoords( playerid, params[] )
{
	new Float:x,
		Float:y,
		Float:z;
	
	//Detects if player use /gotocoords x y z or else.
	if(sscanf(params, "fff", x, y, z)) return SendClientMessage(playerid, -1, "/gotocoords [X] [Y] [Z]");
	//This command is only able for RCON admin.
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] You are not authorized to use this command");
	//Sets player's position to the given coords.
	SetPlayerPos(playerid, x, y, z);
	//Formate for SendClientMessage.
	format(SCMstring, sizeof(SCMstring), "You have teleported to X = %f Y= %f  Z= %f  ", x, y, z);
	SendClientMessage(playerid, -1, SCMstring);
	return 1;
}

CMD:setvw( playerid, params[] )
{
	new vwID,
	    trgID;

	//Detects if player use /setvw id vw
	if(sscanf(params, "id", trgID, vwID)) return SendClientMessage(playerid, -1, "/setvw [playerid] [VW]");
	//This command also for RCON.
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] You are not authorized to use this command");
	//It sets your player's virtual world.
	SetPlayerVirtualWorld(trgID, vwID);
	//Formats and others
	format(SCMstring, sizeof(SCMstring), "%s sets %s's virtual worlds to %d", GetPName(playerid), GetPName(trgID), vwID);
	return 1;
}

CMD:setmyvw( playerid, params[] )
{
	new vwID;
	if(sscanf(params, "d", vwID)) return SendClientMessage(playerid, -1, "/setmyvw [VW]");
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] You are not authorized to use this command");
	SetPlayerVirtualWorld(playerid, vwID);
	SendClientMessage(playerid, -1, "Your virtual World has been changed.");
	return 1;
}
CMD:teleport( playerid, params[] )
{

	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] You are not authorized to use this command");	//Checking if the player is a RCON admin or not//
	new destination;	//variable to store the destination ID//
	if(sscanf(params, "d", destination))	//if the player doesn't put a destination token then it'll show a dialog which states all the IDs along with their destination name//
		return ShowPlayerDialog(playerid, TELEPORT_DIALOG, DIALOG_STYLE_MSGBOX, "/teleport <location ID>", 
			"(1) [LS] Grove Street\
			 (2) [LS] Ganton Gym\
			 (3) [LS] Idlewood Stacks\
			 (4) [LS] Alhambra\
			 (5) [LS] SAPD HQ\
			 (6) [LS] Bank\
			 (7) [LS] ASGH\
			 (8) [LS] Santa Marina PnS\
			 (9) [LS] LS. International Airport\
			 (10) [LS] Mt. Chilliad\
			 (11) [SF] Gas Station\
			 (12) [SF] SAPD HQ\
			 (13) [SF] Bank\
			 (14) [SF] Square\
			 (15) [SF] Transfender\
			 (16) [SF] Brothel\
			 (17) [LV] Airport\
			 (18) [LV] The Four Dragons\
			 (19) [LV] Pay and Spray\
			 (20) [LV] Sub-urbs\
			 ", "Ok", "");
	TP_Player(playerid, destination);
	return 1;	
}
CMD:godmode( playerid, params[] )
{
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] You are not authorized to use this command");	//Checking if the player is a RCON admin or not//
	switch(GodMode[playerid])
	{
	    case 1:
	        {
	            GodMode[playerid]=0;
	            format(SCMstring, sizeof(SCMstring), "[{fa1107}AdmCmd{ffffff}] You have disabled your GodMode");
	        }
		case 0:
		    {
		        SetPlayerHealth(playerid, 100.00);
		        GodMode[playerid]=1;
		        format(SCMstring, sizeof(SCMstring), "[{fa1107}AdmCmd{ffffff}] You have enabled your GodMode");
		    }
	}
	SendClientMessage(playerid, -1, SCMstring);
	return 1;
}


CMD:god(playerid, params[])
{
    if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] You are not authorized to use this command");	//Checking if the player is a RCON admin or not//
	switch(GodMode[playerid])
	{
	    case 1:
	        {
	           
	           	GodMode[playerid] = 0;
	            format(SCMstring, sizeof(SCMstring), "[{fa1107}AdmCmd{ffffff}] You have disabled your GodMode");
	            SendClientMessage(playerid, -1, SCMstring);
	            SetPlayerHealth(playerid, 100);	           
	            return 1;
        	}
		case 0:
		    {
	           	GodMode[playerid] = 1;
	            format(SCMstring, sizeof(SCMstring), "[{fa1107}AdmCmd{ffffff}] You have enabled your GodMode");
	            SendClientMessage(playerid, -1, SCMstring);
	            SetPlayerHealth(playerid, 1000);
	            return 1;
        	}
    }
    return 1;
}

CMD:mypos( playerid, params[] )
{
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	format(SCMstring, sizeof(SCMstring), "X: %f | Y: %f | Z: %f ", pos[0], pos[1], pos[2]);
	SendClientMessage(playerid, -1, SCMstring);
	return 1;

}


CMD:giveweapon( playerid, params[] )
{
    if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] You are not authorized to use this command");	//Checking if the player is a RCON admin or not//
    new targetID;
    if(sscanf(params, "u", targetID)) return SendClientMessage(playerid, -1, "[{fa1107}USAGE{ffffff}] /giveweapon <targetID>");
    if(!IsPlayerConnected(targetID)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] Could not find player.");
    SetPVarInt(playerid, "targetid", targetID);
    SendClientMessage(playerid, COLOR_GREEN, "====================================================================================================================");
	SendClientMessage(playerid, COLOR_GRAD1, "1: Brass Knuckles 2: Golf Club 3: Nite Stick 4: Knife 5: Baseball Bat 6: Shovel 7: Pool Cue 8: Katana 9: Chainsaw");
	SendClientMessage(playerid, COLOR_GRAD1, "10: Purple Dildo 11: Small White Vibrator 12: Large White Vibrator 13: Silver Vibrator 14: Flowers 15: Cane 16: Frag Grenade");
	SendClientMessage(playerid, COLOR_GRAD1, "17: Tear Gas 18: Molotov Cocktail 19: Vehicle Missile 20: Hydra Flare 21: Jetpack 22: 9mm 23: Silenced 9mm 24: Desert Eagle 25: Shotgun");
	SendClientMessage(playerid, COLOR_GRAD1, "26: Sawnoff Shotgun 27: SPAS-12 28: Micro SMG (Mac 10) 29: SMG (MP5) 30: AK-47 31: M4 32: Tec9 33: Rifle");
	SendClientMessage(playerid, COLOR_GRAD1, "25: Shotgun 34: Sniper Rifle 35: Rocket Launcher 36: HS Rocket Launcher 37: Flamethrower 38: Minigun 39: Satchel Charge");
	SendClientMessage(playerid, COLOR_GRAD1, "40: Detonator 41: Spraycan 42: Fire Extinguisher 43: Camera 44: Nightvision Goggles 45: Infared Goggles 46: Parachute");
	SendClientMessage(playerid, COLOR_GREEN, "====================================================================================================================");
    format(SCMstring, sizeof(SCMstring), "Giving weapon to %s", GetPName(targetID));
    ShowPlayerDialog(playerid, WEAPON_DIALOG, DIALOG_STYLE_INPUT, SCMstring, "Put weapon ID", "Ok", "Cancel");

	return 1;
}


CMD:loadmap( playerid, params[] )
{
	//new mapstrg[124];
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] You are not authorized to use this command");	//Checking if the player is a RCON admin or not//

	//SendRconCommand()
	return 1;
} 

//FLYMODE
CMD:flymode( playerid, params[] )
{
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] You are not authorized to use this command");	//Checking if the player is a RCON admin or not//
	// Place the player in and out of edit mode
	if(GetPVarType(playerid, "FlyMode")) CancelFlyMode(playerid);
	else FlyMode(playerid);
	return 1;
}

CMD:go( playerid, params[] )
{
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] You are not authorized to use this command");

	if(isnull(params))
	{

		SendClientMessage(playerid, -1, "USAGE: /up [ direction ]");
		SendClientMessage(playerid, -1, "General locations: up, dw , fd ( Forward )");
		SendClientMessage(playerid, COLOR_GRAD1, "fd ( forward) = Just point your camera toward anywhere and do /go fd for move");
	}

	if(strcmp(params, "up", true) == 0)
	{
		up(playerid);
	}
	if(strcmp(params, "dn", true) == 0)
	{
		dn(playerid);
	}
	if(strcmp(params, "fd", true) == 0)
	{
		goforward(playerid);
	}
	return 1;
}

