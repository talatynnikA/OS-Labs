Set fso=WScript.CreateObject("Scripting.FileSystemObject")
Set file=fso.CreateTextFile("c:\Work\Scripts\newfile.bat")
file.WriteLine("start Excel.exe")
file.Close
Set WshShell = CreateObject("WScript.Shell")
WshShell.Run "c:\Work\Scripts\newfile.bat", 1
