
#if defined _fmt_included
	#endinput
#endif
#define _fmt_included

native SendClientMessagef(playerid, color, const message[], {Float,_}:...);
native SendClientMessageToAllf(color, const message[], {Float,_}:...);
native GameTextForAllf(time, style, const string[], {Float,_}:...);
native GameTextForPlayerf(playerid, time, style, const string[], {Float,_}:...);
native SendRconCommandf(const command[], {Float,_}:...);
native TextDrawSetStringf(Text:text, const string[], {Float,_}:...);
native PlayerTextDrawSetStringf(playerid, PlayerText:text, const string[], {Float,_}:...);
native ShowPlayerDialogf(playerid, dialogid, style, const caption[], const button1[], const button2[], const info[], {Float,_}:...);
