
#include "Main.h"

std::map<AMX*, Plugin::AmxData> Plugin::amxMap;

void Plugin::Load()
{
	sampgdk::logprintf(" * fmt plugin loaded");
	sampgdk::logprintf(" * v2.3 (c) vsergeenko");
}

void Plugin::Unload()
{
	sampgdk::logprintf(" * fmt plugin unloaded");
}

const AMX_NATIVE_INFO nativeList[] =
{
	{ "fmt_toggle_crp_mode", Natives::fmt_toggle_crp_mode },
	{ "fmt_toggle_dialog_callback", Natives::fmt_toggle_dialog_callback },
	// ======================
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
	{ "TextDrawCreatef", Natives::TextDrawCreatef },
	{ "CreatePlayerTextDrawf", Natives::CreatePlayerTextDrawf },
	// ======================
	{ NULL, NULL }
};

int32_t Plugin::AmxLoad(AMX* amx)
{
	if (amxMap.find(amx) == amxMap.end()) {
		amxMap.insert(std::make_pair(amx, AmxData()));
	}

	return amx_Register(amx, nativeList, -1);
}

int32_t Plugin::AmxUnload(AMX* amx)
{
	if (amxMap.find(amx) != amxMap.end()) {
		amxMap.erase(amx);
	}

	return AMX_ERR_NONE;
}

void Plugin::ToggleCrpMode(AMX* amx, bool toggle)
{
	auto amxData = amxMap.find(amx);

	if (amxData == amxMap.end()) {
		return;
	}

	amxData->second.useCrpMode = toggle;
}

void Plugin::ToggleDialogCallback(AMX* amx, bool toggle)
{
	auto amxData = amxMap.find(amx);

	if (amxData == amxMap.end()) {
		return;
	}

	amxData->second.useDialogCallback = toggle;
}

cell* get_amxaddr(AMX* amx, cell amx_addr)
{
	return (cell*)(amx->base + (int)(((AMX_HEADER*)amx->base)->dat + amx_addr));
}

char* Plugin::FormatString(AMX* amx, cell* params, int32_t parm, bool gxt)
{
	static char outbuf[4096];
	cell* addr = get_amxaddr(amx, params[parm++]);
	int32_t len = atcprintf(outbuf, sizeof(outbuf) - 1, addr, amx, params, &parm);
	outbuf[len] = 0;

	if (gxt)
	{
		auto amxData = amxMap.find(amx);

		if (amxData != amxMap.end() && amxData->second.useCrpMode) {
			TranslateString(outbuf, len);
		}
	}

	return outbuf;
}

void Plugin::TranslateString(char* buf, int32_t len)
{
	for (int32_t i = 0; i < len; i++)
	{
		switch (buf[i])
		{
			case '�': { buf[i] = 'a'; break; }
			case '�': { buf[i] = 'A'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = 'e'; break; }
			case '�': { buf[i] = 'E'; break; }
			case '�': { buf[i] = 'e'; break; }
			case '�': { buf[i] = 'E'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = 'k'; break; }
			case '�': { buf[i] = 'K'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = 'M'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = 'H'; break; }
			case '�': { buf[i] = 'o'; break; }
			case '�': { buf[i] = 'O'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = 'p'; break; }
			case '�': { buf[i] = 'P'; break; }
			case '�': { buf[i] = 'c'; break; }
			case '�': { buf[i] = 'C'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = 'y'; break; }
			case '�': { buf[i] = 'Y'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = 'x'; break; }
			case '�': { buf[i] = 'X'; break; }
			case '�': { buf[i] = '�'; break; } // 160
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '�': { buf[i] = '�'; break; }
			case '*': { buf[i] = ']'; break; }
		}
	}
}

void Plugin::CallDialogCallback(AMX* amx, int32_t playerId, int32_t dialogId, int32_t style, const char* caption, const char* info, const char* button1, const char* button2)
{
	auto amxData = amxMap.find(amx);

	if (amxData == amxMap.end() || !amxData->second.useDialogCallback) {
		return;
	}

	int32_t index = -1;

	if (amx_FindPublic(amx, "OnPlayerDialogShow", &index) != AMX_ERR_NONE) {
		return;
	}

	cell captionAddr;
	cell infoAddr;
	cell button1Addr;
	cell button2Addr;

	amx_PushString(amx, &button2Addr, nullptr, button2, 0, 0);
	amx_PushString(amx, &button1Addr, nullptr, button1, 0, 0);
	amx_PushString(amx, &infoAddr, nullptr, info, 0, 0);
	amx_PushString(amx, &captionAddr, nullptr, caption, 0, 0);
	amx_Push(amx, static_cast<cell>(style));
	amx_Push(amx, static_cast<cell>(dialogId));
	amx_Push(amx, static_cast<cell>(playerId));
	amx_Exec(amx, nullptr, index);
	amx_Release(amx, captionAddr);
	amx_Release(amx, infoAddr);
	amx_Release(amx, button1Addr);
	amx_Release(amx, button2Addr);
}
