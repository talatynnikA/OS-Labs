Const OverwriteExisting = True
Set fso=WScript.CreateObject("Scripting.FileSystemObject")
Set file=fso.CreateTextFile("c:\Work\Scripts\newfile.bat")
file.WriteLine("start Excel.exe")

Set fso1=WScript.CreateObject("Scripting.FileSystemObject")
Set file1=fso.CreateTextFile("c:\Work\Scripts\newfile2.bat")
fso.CopyFile "c:\Work\Scripts\newfile.bat","c:\Work\Scripts\newfilecopy.txt", OverwriteExisting
file.Close
file1.Close