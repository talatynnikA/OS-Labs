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
    Message=Message & "�������: " & objItem.CurrentClockSpeed & vbCrLf 
file.WriteLine("�������: " & objItem.CurrentClockSpeed & vbCrLf)	
    Message=Message & "�����������: " & objItem.DataWidth& vbCrLf
file.WriteLine("�����������: " & objItem.DataWidth& vbCrLf)
    Message=Message & "��������: " & objItem.Description& vbCrLf
file.WriteLine("��������: " & objItem.Description& vbCrLf)
    Message=Message & "���������: " & objItem.Family& vbCrLf
file.WriteLine("���������: " & objItem.Family& vbCrLf)
    Message=Message & "������ ���: " & objItem.L2CacheSize& vbCrLf
file.WriteLine("������ ���: " & objItem.L2CacheSize& vbCrLf)
    Message=Message & "������� ��������: " & objItem.LoadPercentage& vbCrLf
file.WriteLine("������� ��������: " & objItem.LoadPercentage& vbCrLf)
    Message=Message & "�������������: " & objItem.Manufacturer& vbCrLf
file.WriteLine("�������������: " & objItem.Manufacturer& vbCrLf)
    Message=Message & "����� ����������: " & objItem.ProcessorId& vbCrLf
file.WriteLine("����� ����������: " & objItem.ProcessorId& vbCrLf)
    Message=Message &"������: " & objItem.Version & vbCrLf
file.WriteLine("������: " & objItem.Version & vbCrLf)
   
Next
   MsgBox Message
