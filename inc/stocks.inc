stock GetPName(playerid)
{
    new pname[24];
    GetPlayerName(playerid, pname, 24);
    return pname;
}