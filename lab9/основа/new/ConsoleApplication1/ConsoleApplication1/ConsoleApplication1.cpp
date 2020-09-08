//основное задание: НАПИСАТЬ ПРОГРАММУ С ДВУМЯ ПОТОКАМИ.ОДИН ПИШЕТ В ФАЙЛ, ДРУГОЙ ЧИТАЕТ ИЗ ТОГО ЖЕ ФАЙЛА.ПРОДУМАТЬ СИНХРОНИЗАЦИЮ ДОСТУПА ЧЕРЕ МЕХАНИЗМ КРИТИЧЕСКИХ ЗОН
#include <windows.h>
#include <iostream>
#include <string>

CRITICAL_SECTION cs = { 0 };

int size = 0;

DWORD WINAPI Write(void* lpPar) {// 1 поток который записывает в файл числа
    for (int i = 1; i <= 10; i++) {
        EnterCriticalSection(&cs);//вход в критическую секцию
        DWORD nLenCurDir;
        HANDLE hOut;
        DWORD dwNumberOfBytes;

        TCHAR stdPath[] = TEXT("C:\\Users\\Admin\\Documents\\учебные штуки\\ос\\моя работа\\lab9\\основа\\new\\ConsoleApplication1\\new.txt");// файл в еоторый мы записываем числа

        hOut = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,//создаем этот файл
            CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

        if (hOut == INVALID_HANDLE_VALUE) { // если ошибка
            printf("ERROR %x \n", GetLastError());
            return 2;
        }

        else
        {//генерация случайных чисел для записи в файл
            std::wstring buf = std::to_wstring((int)(rand() % 1000));//

            size = sizeof(buf.c_str());

            WriteFile(hOut, buf.c_str(), size, NULL, NULL);//запись в файл
            CloseHandle(hOut);
        }
        //std::cout << "write " << i << std::endl;
        LeaveCriticalSection(&cs);//выход из критической секции
        Sleep(5);
    }
    return 0;
}

DWORD WINAPI Read(void* lpPar) {// 2 поток который считывает данные из файла и выводит на экран
    for (int i = 0; i < 10; i++) {
        EnterCriticalSection(&cs);//вход в критическую секцию
        TCHAR stdPath[] = TEXT("C:\\Users\\Admin\\Documents\\учебные штуки\\ос\\моя работа\\lab9\\основа\\new\\ConsoleApplication1\\new.txt");// файл в который мы записывали числа для считывания


        TCHAR BufferToRead[256];
        DWORD dwNumberOfBytes;

        HANDLE hIn = CreateFile(stdPath, GENERIC_READ, 0, NULL,
            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        if (hIn == INVALID_HANDLE_VALUE) {
            printf("ERROR %x \n", GetLastError());
            return 0;
        }

        else
        {
            ReadFile(hIn, BufferToRead, sizeof(BufferToRead), &dwNumberOfBytes, NULL);// считывание информации из файла
            CloseHandle(hIn);
            WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), BufferToRead, size, NULL, NULL);
            printf("\n");
        }

        //std::cout << "read " << i << std::endl;
        LeaveCriticalSection(&cs);//выход из критической секции
        Sleep(5);
    }
    return 0;
}


int main(int argc, TCHAR* argv[])
{
    HANDLE threads[2];

    InitializeCriticalSection(&cs);

    threads[0] = CreateThread(NULL, 0, Write, NULL, 0, 0);
    threads[1] = CreateThread(NULL, 0, Read, NULL, 0, 0);

    WaitForMultipleObjects(2, threads, TRUE, INFINITE);//Ожидание до тех пор, пока один или все указанные объекты не окажутся в сигнальном состоянии или пока не истечет интервал времени ожидания.

    DeleteCriticalSection(&cs);

    return 0;
}
//основные определения по теории:
//что такое синхронизация- механизм который обеспечивает целостность какого-то ресурса когда он используется несколькими процессами или потоками в рандомном порядке
//в рандомном порядке
//
//Как она работает - 
//Для нее используются критические секции

//Критическая секция как она работает:
//Выбираем учсток программы и в начале ставим вход а потом выход
//С помощю нее производится общий доступ к ресурсу и он не должен быть использован более чем 1 - м потоком.
//Она задает ограничение в 1 поток и в это время другие потоки не используются