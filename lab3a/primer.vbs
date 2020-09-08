WshShell.Run objEnv("C:\Windows\notepad.exe"),1

Set WshShell = WScript.CreateObject("WScript.Shell")

Dim exeName 
Dim statusCode

exeName = "%windir%\notepad"

statusCode = WshShell.Run (exeName, 1, true)
