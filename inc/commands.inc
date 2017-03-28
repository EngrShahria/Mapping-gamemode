CMD:gotocoords( playerid, params[] )
{
	new Float:x,
		Float:y,
		Float:z,
		string[128];
	//Detects if player did /gotocoords x y z or else.
	if(sscanf(params, "ddd", x, y, z)) return SendClientMessage(playerid, -1, "/gotocoords [X] [Y] [Z]");
	//This command is only able for RCON admin.
	if(!IsPlayerAdmin(playerid)) return SendClientMessage(playerid, -1, "You aren't an admin.");
	//Sets player's position to the given coords.
	SetPlayerPos(playerid, x, y, z);
	//Formate for SendClientMessage.
	format(string, sizeof(string), "You have teleported to X = %d  Y= %d  Z= %d  ", x, y, z);
	SendClientMessage(playerid, -1, string);
	return 1;
}

CMD:setvw( playerid, params[] )
{
	
}