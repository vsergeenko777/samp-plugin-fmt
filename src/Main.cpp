
#include "Main.h"

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return sampgdk::Supports() | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
	bool load = sampgdk::Load(ppData);

	if (load) {
		Plugin::Load();
	}

	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	return load;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	Plugin::Unload();
	sampgdk::Unload();
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
	return Plugin::AmxLoad(amx);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx)
{
	return Plugin::AmxUnload(amx);
}
