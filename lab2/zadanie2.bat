md d:\temp\batfile\
rem echo введите текст >> G:\ос\моя работа\lab2\zadanie2.bat
@Echo off
Echo Введите текст. Завершение ввода - комбинация Ctrl+Z {ENTER}
copy con D:\temp\batfile\zadanie2.TXT
type D:\temp\batfile\zadanie2.TXT
@PAUSE