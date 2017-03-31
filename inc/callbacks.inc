
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch(dialogid)
	{
		case WEAPON_DIALOG:
		{
			if(response==1)
			{
				new targetID;
				targetID=GetPVarInt(playerid, "targetid");
				if(strval(inputtext)<1||strval(inputtext)>46) SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] Invalid Input");
				switch(strval(inputtext)){
					case 11,13,19,20,21: SendClientMessage(playerid, -1, "[{fa1107}WARNING{ffffff}] Invalid Input"); }
				if(IsPlayerConnected(targetID)){
					GivePlayerWeapon(targetID, strval(inputtext), 100);}
				new temp[5];
				valstr(temp, targetID);
				
			}
			DeletePVar(playerid, "targetid");
		}
		//space for more dialogID cases//
	}
	return 1;
}


public OnPlayerUpdate(playerid)
{

	if(GodMode[playerid] == 1){
		new Float: iHP;
		GetPlayerHealth(playerid, iHP);	
		if(iHP < 100)
		{
			SetPlayerHealth(playerid, iHP+1000);
		}
	}
	return 1;
}
