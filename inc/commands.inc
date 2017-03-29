////////////////~~~~~Class Variables~~~~~//////////////////////
new SCMstring[128];
new GodMode[MAX_PLAYERS];
////////////////////////~~~~~Defines~~~~~/////////////////////
#define TELEPORT_DIALOG 1
/////////////////////////~~~~~Commands~~~~~///////////////////
CMD:gotocoords( playerid, params[] )
{
	new Float:x,
		Float:y,
		Float:z;
	
	//Detects if player use /gotocoords x y z or else.
	if(sscanf(params, "ddd", x, y, z)) return SendClientMessage(playerid, -1, "/gotocoords [X] [Y] [Z]");
	//This command is only able for RCON admin.
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] You are not authorized to use this command");
	//Sets player's position to the given coords.
	SetPlayerPos(playerid, x, y, z);
	//Formate for SendClientMessage.
	format(SCMstring, sizeof(SCMstring), "You have teleported to X = %d  Y= %d  Z= %d  ", x, y, z);
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
			"(1) [LS] Grove Street\n\
			 (2) [LS] Ganton Gym\n\
			 (3) [LS] Idlewood Stacks\n\
			 (4) [LS] Alhambra\n\
			 (5) [LS] SAPD HQ\n\
			 (6) [LS] Bank\n\
			 (7) [LS] ASGH\n\
			 (8) [LS] Santa Marina PnS\n\
			 (9) [LS] LS. International Airport\n\
			 (10) [LS] Mt. Chilliad\n\
			 (11) [SF] Gas Station\n\
			 (12) [SF] SAPD HQ\n\
			 (13) [SF] Bank\n\
			 (14) [SF] Square\n\
			 (15) [SF] Transfender\n\
			 (16) [SF] Brothel\n\
			 (17) [LV] Airport\n\
			 (18) [LV] The Four Dragons\n\
			 (19) [LV] Pay and Spray\n\
			 (20) [LV] Sub-urbs\n\
			 ", "Ok", "");
	TP_Player(playerid, destination);
	return 1;	
}
CMD:godmode(playerid, params[])
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
	SCM(playerid, -1, SCMstring);
	return 1;
}
