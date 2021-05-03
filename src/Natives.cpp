
#include "Main.h"

cell AMX_NATIVE_CALL Natives::fmt_toggle_crp_mode(AMX* amx, cell* params)
{
	Plugin::ToggleCrpMode(amx, params[1] ? true : false);
	return 1;
}

cell AMX_NATIVE_CALL Natives::fmt_toggle_dialog_callback(AMX* amx, cell* params)
{
	Plugin::ToggleDialogCallback(amx, params[1] ? true : false);
	return 1;
}

cell AMX_NATIVE_CALL Natives::SendClientMessagef(AMX* amx, cell* params)
{
	return static_cast<cell>(SendClientMessage(
		static_cast<int>(params[1]),
		static_cast<int>(params[2]),
		Plugin::FormatString(amx, params, 3)
	));
}

cell AMX_NATIVE_CALL Natives::SendClientMessageToAllf(AMX* amx, cell* params)
{
	return static_cast<cell>(SendClientMessageToAll(
		static_cast<int>(params[1]),
		Plugin::FormatString(amx, params, 2)
	));
}

cell AMX_NATIVE_CALL Natives::GameTextForAllf(AMX* amx, cell* params)
{
	return static_cast<cell>(GameTextForAll(
		Plugin::FormatString(amx, params, 3, true),
		static_cast<int>(params[1]),
		static_cast<int>(params[2])
	));
}

cell AMX_NATIVE_CALL Natives::GameTextForPlayerf(AMX* amx, cell* params)
{
	return static_cast<cell>(GameTextForPlayer(
		static_cast<int>(params[1]),
		Plugin::FormatString(amx, params, 4, true),
		static_cast<int>(params[2]),
		static_cast<int>(params[3])
	));
}

cell AMX_NATIVE_CALL Natives::SendRconCommandf(AMX* amx, cell* params)
{
	return static_cast<cell>(SendRconCommand(
		Plugin::FormatString(amx, params, 1)
	));
}

cell AMX_NATIVE_CALL Natives::TextDrawSetStringf(AMX* amx, cell* params)
{
	return static_cast<cell>(TextDrawSetString(
		static_cast<int>(params[1]),
		Plugin::FormatString(amx, params, 2, true)
	));
}

cell AMX_NATIVE_CALL Natives::PlayerTextDrawSetStringf(AMX* amx, cell* params)
{
	return static_cast<cell>(PlayerTextDrawSetString(
		static_cast<int>(params[1]),
		static_cast<int>(params[2]),
		Plugin::FormatString(amx, params, 3, true)
	));
}

cell AMX_NATIVE_CALL Natives::ShowPlayerDialogf(AMX* amx, cell* params)
{
	char* caption = nullptr;
	amx_StrParam(amx, params[4], caption);

	char* button1 = nullptr;
	amx_StrParam(amx, params[5], button1);

	char* button2 = nullptr;
	amx_StrParam(amx, params[6], button2);

	char* info = Plugin::FormatString(amx, params, 7);

	bool result = ShowPlayerDialog(
		static_cast<int>(params[1]),
		static_cast<int>(params[2]),
		static_cast<int>(params[3]),
		caption ? caption : "",
		info ? info : "",
		button1 ? button1 : "",
		button2 ? button2 : ""
	);

	Plugin::CallDialogCallback(
		amx,
		static_cast<int>(params[1]),
		static_cast<int>(params[2]),
		static_cast<int>(params[3]),
		caption ? caption : "",
		info ? info : "",
		button1 ? button1 : "",
		button2 ? button2 : ""
	);

	return static_cast<cell>(result);
}

cell AMX_NATIVE_CALL Natives::SendPlayerMessageToPlayerf(AMX* amx, cell* params)
{
	return static_cast<cell>(SendPlayerMessageToPlayer(
		static_cast<int>(params[1]),
		static_cast<int>(params[2]),
		Plugin::FormatString(amx, params, 3)
	));
}

cell AMX_NATIVE_CALL Natives::SendPlayerMessageToAllf(AMX* amx, cell* params)
{
	return static_cast<cell>(SendPlayerMessageToAll(
		static_cast<int>(params[1]),
		Plugin::FormatString(amx, params, 2)
	));
}

cell AMX_NATIVE_CALL Natives::SetPlayerChatBubblef(AMX* amx, cell* params)
{
	return static_cast<cell>(SetPlayerChatBubble(
		static_cast<int>(params[1]),
		Plugin::FormatString(amx, params, 5),
		static_cast<int>(params[2]),
		static_cast<float>(amx_ctof(params[3])),
		static_cast<int>(params[4])
	));
}

cell AMX_NATIVE_CALL Natives::TextDrawCreatef(AMX* amx, cell* params)
{
	return static_cast<cell>(TextDrawCreate(
		static_cast<float>(amx_ctof(params[1])),
		static_cast<float>(amx_ctof(params[2])),
		Plugin::FormatString(amx, params, 3, true)
	));
}

cell AMX_NATIVE_CALL Natives::CreatePlayerTextDrawf(AMX* amx, cell* params)
{
	return static_cast<cell>(CreatePlayerTextDraw(
		static_cast<int>(params[1]),
		static_cast<float>(amx_ctof(params[2])),
		static_cast<float>(amx_ctof(params[3])),
		Plugin::FormatString(amx, params, 4, true)
	));
}
