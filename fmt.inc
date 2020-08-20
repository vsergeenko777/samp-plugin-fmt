
#if defined _fmt_included
	#endinput
#endif
#define _fmt_included

native fmt_toggle_crp_mode(bool: toggle);
native fmt_toggle_dialog_callback(bool: toggle);

native SendClientMessagef(playerid, color, const message[], {Float,_}:...);
native SendClientMessageToAllf(color, const message[], {Float,_}:...);
native GameTextForAllf(time, style, const string[], {Float,_}:...);
native GameTextForPlayerf(playerid, time, style, const string[], {Float,_}:...);
native SendRconCommandf(const command[], {Float,_}:...);
native TextDrawSetStringf(Text:text, const string[], {Float,_}:...);
native PlayerTextDrawSetStringf(playerid, PlayerText:text, const string[], {Float,_}:...);
native ShowPlayerDialogf(playerid, dialogid, style, const caption[], const button1[], const button2[], const info[], {Float,_}:...);
native SendPlayerMessageToPlayerf(playerid, senderid, const message[], {Float,_}:...);
native SendPlayerMessageToAllf(senderid, const message[], {Float,_}:...);
native SetPlayerChatBubblef(playerid, color, Float:drawdistance, expiretime, const text[], {Float,_}:...);
native Text:TextDrawCreatef(Float:x, Float:y, const text[], {Float,_}:...);
native PlayerText:CreatePlayerTextDrawf(playerid, Float:x, Float:y, const text[], {Float,_}:...);

forward OnPlayerDialogShow(playerid, dialogid, style, caption[], info[], button1[], button2[]);
