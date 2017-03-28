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