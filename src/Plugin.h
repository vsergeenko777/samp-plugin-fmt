
#pragma once

class Plugin
{
public:
	static void Load();
	static void Unload();
	static int AmxLoad(AMX* amx);
	static char* FormatString(AMX* amx, cell* params, int parm);
};
