'Processor Information

On Error Resume Next
Message =""
strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
    & "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")

Set colItems = objWMIService.ExecQuery("Select * from Win32_Processor")
Set fso=WScript.CreateObject("Scripting.FileSystemObject")
Set file=fso.CreateTextFile("c:\Work\Scripts\newfile1.bat")
For Each objItem in colItems
    Message=Message & "Частота: " & objItem.CurrentClockSpeed & vbCrLf 
file.WriteLine("Частота: " & objItem.CurrentClockSpeed & vbCrLf)	
    Message=Message & "Разрядность: " & objItem.DataWidth& vbCrLf
file.WriteLine("Разрядность: " & objItem.DataWidth& vbCrLf)
    Message=Message & "Описание: " & objItem.Description& vbCrLf
file.WriteLine("Описание: " & objItem.Description& vbCrLf)
    Message=Message & "Семейство: " & objItem.Family& vbCrLf
file.WriteLine("Семейство: " & objItem.Family& vbCrLf)
    Message=Message & "Размер кэш: " & objItem.L2CacheSize& vbCrLf
file.WriteLine("Размер кэш: " & objItem.L2CacheSize& vbCrLf)
    Message=Message & "Текущая загрузка: " & objItem.LoadPercentage& vbCrLf
file.WriteLine("Текущая загрузка: " & objItem.LoadPercentage& vbCrLf)
    Message=Message & "Производитель: " & objItem.Manufacturer& vbCrLf
file.WriteLine("Производитель: " & objItem.Manufacturer& vbCrLf)
    Message=Message & "Номер процессора: " & objItem.ProcessorId& vbCrLf
file.WriteLine("Номер процессора: " & objItem.ProcessorId& vbCrLf)
    Message=Message &"Версия: " & objItem.Version & vbCrLf
file.WriteLine("Версия: " & objItem.Version & vbCrLf)
   
Next
   MsgBox Message
