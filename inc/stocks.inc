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
		default: SendClientMessage(playerid, -1, "Wrong destination ID");
	}
	return 1;
}

stock GetWepName(weaponid)
{
	new Wep_NAme[MAX_PLAYER_NAME];
	switch(weaponid)
	{
		case 0: Wep_NAme="None";
		case 1: Wep_NAme="Brass knuckles";
		case 2: Wep_NAme="Golf club";
		case 3: Wep_NAme="Night stick";
		case 4: Wep_NAme="Knife";
		case 5: Wep_NAme="Baseball bat";
		case 6: Wep_NAme="Shovel";
		case 7: Wep_NAme="Pool cue";
		case 8: Wep_NAme="Katana";
		case 9: Wep_NAme="Chainsaw";
		case 10, 11: Wep_NAme="Dildo";
		case 12, 13: Wep_NAme="Vibrator";
		case 14: Wep_NAme="Flowers";
		case 15: Wep_NAme="Cane";
		case 16: Wep_NAme="Grenade";
		case 17: Wep_NAme="Molotov";
		case 18: Wep_NAme="Tear gas";
		case 19,20,21: Wep_NAme="None";
		case 22: Wep_NAme="Pistol";
		case 23: Wep_NAme="Silenced Pistol";
		case 24: Wep_NAme="Desert Eagle";
		case 25: Wep_NAme="Shotgun";
		case 26: Wep_NAme="Sawn-off shotgun";
		case 27: Wep_NAme="Combat shotgun";
		case 28: Wep_NAme="Micro UZI";
		case 29: Wep_NAme="MP5";
		case 30: Wep_NAme="AK-47";
		case 31: Wep_NAme="M4A1";
		case 32: Wep_NAme="Tec-9";
		case 33: Wep_NAme="Country rifle";
		case 34: Wep_NAme="Sniper rifle";
		case 35: Wep_NAme="RPG";
		case 36: Wep_NAme="Missle launcher";
		case 37: Wep_NAme="Flame thrower";
		case 38: Wep_NAme="Minigun";
		case 39: Wep_NAme="Satchel charge";
		case 40: Wep_NAme="Detonator";
		case 41: Wep_NAme="Spray paint";
		case 42: Wep_NAme="Fire extinguisher";
		case 43: Wep_NAme="Camera";
		case 44: Wep_NAme="Night vision goggles";
		case 45: Wep_NAme="Thermal goggles";
		case 46: Wep_NAme="Parachute";
	}
	return Wep_NAme;
}



new Float:slX, Float:slY, Float:slZ;
new Float:pcX, Float:pcY, Float:pcZ;
new Float:mX, Float: mY;

dn(playerid) //Go down
{
    GetPlayerPos(playerid, slX, slY, slZ);
    SetPlayerPos(playerid, slX, slY, slZ-2);
    return 1;
}

up(playerid) // Go up
{
    GetPlayerPos(playerid, slX, slY, slZ);
    SetPlayerPos(playerid, slX, slY, slZ+5);
    return 1;
}


goforward(playerid) // Go Left [ Left Turn]
{
    GetPlayerCameraPos(playerid, slX, slY, slZ);
    GetPlayerCameraFrontVector(playerid, pcX, pcY, pcZ);
    mX = slX + (pcX*10);
    mY = slY + (pcY*10);
    SetPlayerPos(playerid, mX, mY, slZ);
    return 1;
}
