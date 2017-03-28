new SCMstring[128];

CMD:gotocoords( playerid, params[] )
{
	new Float:x,
		Float:y,
		Float:z;
	
	//Detects if player use /gotocoords x y z or else.
	if(sscanf(params, "ddd", x, y, z)) return SendClientMessage(playerid, -1, "/gotocoords [X] [Y] [Z]");
	//This command is only able for RCON admin.
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "You aren't an admin.");
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
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "You aren't an admin.");
	//It sets your player's virtual world.
	SetPlayerVirtualWorld(trgID, vwID);
	//Formats and others
	format(SCMstring, sizeof(SCMstring), "%s sets %s's virtual worlds to %d", GetPName(playerid), GetPName(trgID), vwID);
	return 1;
}