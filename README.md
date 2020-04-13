# SA-MP fmt plugin
San Andreas Multiplayer plugin that adds natives with formatting support:
```pawn
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
```

## Build
* Clone repository:
```
git clone --recursive https://github.com/vsergeenko777/samp-plugin-fmt.git
cd samp-plugin-fmt
```
* Generate the files needed for compilation:
```
mkdir build
cd build
cmake ..
```
* Build a plugin:
  * On Windows, open Visual Studio and compile the project
  * On Linux, use make:
    > make
* The compiled plugin should appear in the **bin** folder

## Русская локализация для SanLtd
Если вы используете плагин CRP, вы также можете включить подобный режим в плагине fmt:
```pawn
native fmt_toggle_crp_mode(bool: toggle);
```

При включенном режиме CRP, плагин будет автоматически конвентировать символы, чтобы они нормально отображались у игроков с локализацией от SanLtd.
