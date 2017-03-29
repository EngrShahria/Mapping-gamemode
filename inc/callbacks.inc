public OnPlayerUpdate(playerid)
{
	if(GodMode[playerid]==1&&GetPHealth(playerid)!=100)
	    SetPlayerHealth(playerid, 100.0);
	return 1;
}
