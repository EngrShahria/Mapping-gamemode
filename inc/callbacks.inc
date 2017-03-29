public OnPlayerUpdate(playerid)
{
	if(GodMode[playerid]==1&&GetPHealth(playerid)!=100)
	    SetPlayerHealth(playerid, 100.0);
	return 1;
}
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
	    case WEAPON_DIALOG:
	        {
	            if(response==1)
	            {
		            new weaponID;
		            new targetID;
					targetID=GetPVarInt(playerid, "targetid");
		            switch(listitem)
		            {
		                case 0 .. 9: weaponID=listitem+1;
		                case 10: weaponID=listitem+2;
		                case 11 .. 15: weaponID=listitem+3;
		                case 16 .. 40: weaponID=listitem+6;
		            }
		            GivePlayerWeapon(targetID, weaponID, 100);
		            format(SCMstring, sizeof(SCMstring), "[{f24faa}SERVER{ffffff}] You have given %s a %s", GetPName(targetID), GetWepName(weaponID));
		            SendClientMessage(playerid, -1, SCMstring);
		            format(SCMstring, sizeof(SCMstring), "[{f24faa}SERVER{ffffff}] You were given a %s by %s", GetWepName(weaponID), GetPName(playerid));
		            SendClientMessage(targetID, -1, SCMstring);
				}
				DeletePVar(playerid, "targetid");
	        }
	        // space for more dialog cases...
	}
	return 1;
}
