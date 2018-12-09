
#pragma once

class Plugin
{
public:
	static void Load();
	static void Unload();
	static int32_t AmxLoad(AMX* amx);
	static int32_t AmxUnload(AMX* amx);
	static void ToggleCrpMode(AMX* amx, bool toggle);
	static void ToggleDialogCallback(AMX* amx, bool toggle);
	static char* FormatString(AMX* amx, cell* params, int32_t parm, bool gxt = false);
	static void CallDialogCallback(AMX* amx, int32_t playerId, int32_t dialogId, int32_t style, const char* caption, const char* info, const char* button1, const char* button2);

private:
	struct AmxData
	{
		bool useCrpMode;
		bool useDialogCallback;

		AmxData() :
			useCrpMode(false),
			useDialogCallback(false)
		{

		}
	};

	static std::map<AMX*, AmxData> amxMap;
	static void TranslateString(char* buf, int32_t len);
};
