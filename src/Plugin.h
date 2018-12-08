
#pragma once

class Plugin
{
public:
	static void Load();
	static void Unload();
	static int32_t AmxLoad(AMX* amx);
	static int32_t AmxUnload(AMX* amx);
	static void ToggleCrpMode(AMX* amx, bool toggle);
	static char* FormatString(AMX* amx, cell* params, int32_t parm, bool gxt = false);

private:
	struct AmxData
	{
		bool useCrpMode;

		AmxData() :
			useCrpMode(false)
		{

		}
	};

	static std::map<AMX*, AmxData> amxMap;
	static void TranslateString(char* buf, int32_t len);
};
