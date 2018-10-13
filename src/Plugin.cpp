
#include "Main.h"

void Plugin::Load()
{
	sampgdk::logprintf(" * fmt plugin loaded");
	sampgdk::logprintf(" * v1.0 (c) vsergeenko");
}

void Plugin::Unload()
{
	sampgdk::logprintf(" * fmt plugin unloaded");
}

const AMX_NATIVE_INFO nativeList[] =
{
	{ "SendClientMessagef", Natives::SendClientMessagef },
	{ "SendClientMessageToAllf", Natives::SendClientMessageToAllf },
	{ "GameTextForAllf", Natives::GameTextForAllf },
	{ "GameTextForPlayerf", Natives::GameTextForPlayerf },
	{ "SendRconCommandf", Natives::SendRconCommandf },
	{ "TextDrawSetStringf", Natives::TextDrawSetStringf },
	{ "PlayerTextDrawSetStringf", Natives::PlayerTextDrawSetStringf },
	{ "ShowPlayerDialogf", Natives::ShowPlayerDialogf },
	{ "SendPlayerMessageToPlayerf", Natives::SendPlayerMessageToPlayerf },
	{ "SendPlayerMessageToAllf", Natives::SendPlayerMessageToAllf },
	{ "SetPlayerChatBubblef", Natives::SetPlayerChatBubblef },
	// ======================
	{ NULL, NULL }
};

int Plugin::AmxLoad(AMX* amx)
{
	return amx_Register(amx, nativeList, -1);
}

cell* get_amxaddr(AMX* amx, cell amx_addr)
{
	return (cell*)(amx->base + (int)(((AMX_HEADER*)amx->base)->dat + amx_addr));
}

char* Plugin::FormatString(AMX* amx, cell* params, int parm)
{
	static char outbuf[4096];
	cell* addr = get_amxaddr(amx, params[parm++]);
	int len = atcprintf(outbuf, sizeof(outbuf) - 1, addr, amx, params, &parm);
	outbuf[len] = 0;
	return outbuf;
}
