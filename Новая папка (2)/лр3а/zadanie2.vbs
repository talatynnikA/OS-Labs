Option Explicit

Dim WshShell, objEnv

Set WshShell = CreateObject ("WScript.Shell")

Set objEnv = WshShell.Environment("Process")

objEnv("C:\Windows\notepad.exe") = InputBox("¬ведите путь к файлу")

WshShell.Run objEnv("C:\Windows\notepad.exe"),1