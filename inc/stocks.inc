stock GetPName(playerid)
{
    new pname[24];
    GetPlayerName(playerid, pname, 24);
    return pname;
}
stock TP_Player(playerid, destination)
{
	switch(destination)
	{
		case 0: SendClientMessage(playerid, -1, "Destination should be more than 1");
		case 1: SetPlayerPos(playerid, 2468.8638, -1661.7458, 13.3261);
		case 2: SetPlayerPos(playerid, 2225.0276, -1717.3409, 13.5068);
		case 3: SetPlayerPos(playerid, 2089.5481, -1807.4532, 13.5469);
		case 4: SetPlayerPos(playerid, 1814.2579, -1682.4962, 13.5469);
		case 5: SetPlayerPos(playerid, 1522.1483, -1675.1681, 13.5469);
		case 6: SetPlayerPos(playerid, 1461.5372, -1040.9363, 23.8281);
		case 7: SetPlayerPos(playerid, 1211.9059, -1324.9248, 13.5593);
		case 8: SetPlayerPos(playerid, 493.2221, -1703.8882, 12.0211);
		case 9: SetPlayerPos(playerid, 1657.8394, -2287.1001, -1.2126);
		case 10: SetPlayerPos(playerid, -2299.2156, -1644.6145, 483.6988);
		case 11: SetPlayerPos(playerid, -2014.5182, 156.7760, 27.6875);
		case 12: SetPlayerPos(playerid, -1610.2262, 740.9380, 12.8124);
		case 13: SetPlayerPos(playerid, -1724.6692, 785.7502, 24.8906);
		case 14: SetPlayerPos(playerid, -2721.5261, 381.7838, 4.3672);
		case 15: SetPlayerPos(playerid, -2711.4729, 214.1168, 4.2032);
		case 16: SetPlayerPos(playerid, -2612.0398, 1389.6061, 7.1382);
		case 17: SetPlayerPos(playerid, 1703.5859, 1444.2036, 16.1336);
		case 18: SetPlayerPos(playerid, 2035.0367, 1007.3993, 10.8203);
		case 19: SetPlayerPos(playerid, 1934.3407, 2146.7466, 10.8203);
		case 20: SetPlayerPos(playerid, 978.6031, 2299.8274, 10.8281);
	}
	return 1;
}
