SET NOT_DONE=true 
  LOOP:
   CALL C:\batch\dirab.bat
   cls
Copy CON C:\batch\%1.bat
newbatch
  IF %NOT_DONE%==true GOTO loop
 pause