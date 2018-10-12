
#pragma once

class Natives
{
public:
	static cell AMX_NATIVE_CALL SendClientMessagef(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL SendClientMessageToAllf(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL GameTextForAllf(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL GameTextForPlayerf(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL SendRconCommandf(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL TextDrawSetStringf(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL PlayerTextDrawSetStringf(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL ShowPlayerDialogf(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL SendPlayerMessageToPlayerf(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL SendPlayerMessageToAllf(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL SetPlayerChatBubblef(AMX* amx, cell* params);
};
