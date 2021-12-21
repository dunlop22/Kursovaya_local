#define _CRT_SECURE_NO_WARNINGS
#include "File_O.h";
#include <conio.h>;
#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <cstring>
#include <cstdio>
#include "Menu.h"


void File_O::File_input()
{
    do
    {
        do
        {
            cout << "0 - возврат в меню\n\nВведите путь к файлу с информацией о кинотеатре: ";
            cin >> path;
        } while (path == "");
        if (path == "0\0")
        {
            return;
        }
    } while (File_check() != 1);
}

int File_O::File_new()
{
    //проверка на существование такого файла
    //если имеется файл с таким названием, то спросить пользователя что делать с существующим

    //создание файла с таким названием


    cout << "Введите название нового файла (без расширения): ";
    string path;
    cin >> path;
    Menu Menu_t;
    //проверка введеного имени файла на наличие "txt"
    if (File_check() == 1)   //проверка на существование такого файла в памяти
    {
        //файл с таким названием существует, создать копию и создать чистый файл или затереть текущий
        cout << "Файл с таким названием уже существует\n1) Создать копию файла и переименовать (" << path + "_1.txt)" << "\n2) Удалить текущую версию файла " << path;
        Menu_t.item_num = 2;
        Menu_t.Input_number();
        if (Menu_t.menu_number == 1)
        {
            ifstream    inFile(path + ".txt");
            ofstream    outFile(path + "_1.txt");

            outFile << inFile.rdbuf();
            ofstream fout(path);
            fout.close();
        }
        else if (Menu_t.menu_number == 2)
        {
            ofstream fout(path); //создание объекта класса ofstream для записи
            fout.close();   //закрытие фалйа
        }

    }

    if (File_check() == 1)
    {
        
        return 4;//файл успешно создан, заполнение информации о кинотеатре  
    }
    else
    {
        cout << "При создании файла произошла ошибка\n\nНажмите любую клавишу для возврата в меню";
        _getch();
        //файл не создан, изменение файла
    }


}

/*
void File_O::file_new()
{
    cout << "Введите название нового файла (без расширения): ";
    string path;


    //проверка введеного имени файла на наличие "txt"

    if (file_check(path) == 1)   //проверка на существование такого файла в памяти
    {
        //файл с таким названием существует, создать копию и создать чистый файл или затереть текущий
        cout << "Файл с таким названием уже существует\n1) Создать копию файла и переименовать (" << path + "_1.txt)" << "\n2) Удалить текущую версию файла " << path;
        item_num = 2;
        input_number();
        if (menu_number == 1)
        {
            ifstream    inFile(path + ".txt");
            ofstream    outFile(path + "_1.txt");

            outFile << inFile.rdbuf();
            ofstream fout(path);
            fout.close();
        }
        else if (menu_number == 2)
        {
            ofstream fout(path); //создание объекта класса ofstream для записи
            fout.close();   //закрытие фалйа
        }

    }

    if (file_check(path) == 1)
    {
        //файл успешно создан, заполнение информации о кинотеатре
    }
    else
    {
        //файл не создан, изменение файла
    }
}
*/

int File_O::File_check()
{
    ifstream f1;
    if (path != "0\0")
    {
        f1.open(path);
        if (!(f1.is_open()))
        {
            //cout << "Файл не найден"; //тест
            return 2;
            //создание файла, заполнение всех данных

        }
        else {
            //cout << "Файл найден!"; //тест
            return 1;
        }
    }
    else
    {
        return 3;
    }

    /*ofstream fout(path); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
    fout << "Работа с файлами в С++"; // запись строки в файл
    fout.close(); // закрываем файл
    */
}



void File_O::File_read(Kinoteatr *kinoteatr)
{
    ifstream file(path);

    int numb = 0;
    int i = 0;
    int j = 0;
    string temp;

    //заполнение информации о кинотеатре
    getline(file, (*kinoteatr).name);    //чтение названия кинотеатра
    getline(file, (*kinoteatr).adress);    //чтение адреса кинотеатра
    getline(file, (*kinoteatr).kassirs[0]);     //чтения ФИО кассиров


    //разложение количества кассиров на массив ???


    //заполнение информации о фильмах
    do
    {
        getline(file, temp);
        getline(file, (*kinoteatr).filmi[i].name);
        getline(file, (*kinoteatr).filmi[i].duration);
        getline(file, (*kinoteatr).filmi[i].age);
        getline(file, (*kinoteatr).filmi[i].short_description);
        getline(file, (*kinoteatr).filmi[i].main_role);
        getline(file, (*kinoteatr).filmi[i].rejisser);
        
        

        for (j = 0; j < 9; j++)
        {
            getline(file, temp);
            getline(file, ((*kinoteatr).filmi[i].price[j]));
            getline(file, ((*kinoteatr).filmi[i].time[j]));
            getline(file, (*kinoteatr).filmi[i].rand[j]);
            //(*kinoteatr).filmi[i].rand[j] = (*kinoteatr).filmi[i].rand[j][0] + "\0";
            
            for (int k = 0; k < 10; k++)
            {
                getline(file, temp);
                (*kinoteatr).filmi[i].mesta[j] = (*kinoteatr).filmi[i].mesta[j] + temp;
            }
            if (kinoteatr->filmi[i].rand[j][0] == '0')
            {
                (*kinoteatr).filmi[i].mesta[j] = kinoteatr->New_zal(i, j);
            }
            //_getch();   //тест
        }
        //getline(file, temp);
        i++;
    } while (i < (*kinoteatr).kol_vo_filmov);

    //cout << filmi[0].duration;        //тест

}

int File_O::File_check_compound(int* kol_vo)        //проверка форматирования текстового файла
{
    char* str = new char[1024];
    int i = 0;
    ifstream base(path);
    while (!base.eof())
    {
        base.getline(str, 1024, '\n');
        i++;
    }
    base.close();
    delete str;
    if ((i - 3) % 133 == 0)            //форматирование верно
    {
        *kol_vo = (i - 3) / 133;
        return 1;

    }
    else               //форматирование неверно, в файле имеются ошибки
    {
        //cout << "В файле имеются ошибки";
        return 2;
    }
}

void File_O::File_write(Kinoteatr kinoteatr)
{
    /*
    string path_cop = path;
    path_cop.resize(path_cop.size() - 4);
    path_cop = path_cop + "_copy.txt\0";

    //создание копии текущего файла
    ifstream    inFile(path);
    ofstream    outFile(path_cop);
    outFile << inFile.rdbuf();

    this->File_clean();   //удаление всех данных из файла

    //запись в файл
    ofstream  f;
    f.open(path);
    if (f)
    {
        f << kinoteatr.name << endl;    //запись названия кинотеатра в файл
        f << kinoteatr.adress << endl;  //запись адреса кинотеатра в файл
        f << kinoteatr.inn << endl;     //запись ИНН кинотеатра в файл
        for (int i = 0; i < kinoteatr.kol_vo_filmov; i++)
        {
            f << endl;  //пустая строка
            f << kinoteatr.filmi[i].name << endl;   //запись названия фильма
            f << kinoteatr.filmi[i].duration << endl;   //запись длительность фильма
            f << kinoteatr.filmi[i].age << endl;    //запись возрастного ограничения
            f << kinoteatr.filmi[i].short_description << endl;  //запись короткого описания
            f << kinoteatr.filmi[i].main_role << endl;  //запись главных актеров фильма
            f << kinoteatr.filmi[i].rejisser << endl;   //запись режиссеров фильма
            f << endl;  //пустая строка
            for (int j = 0; j < 9; j++)
            {
                f << kinoteatr.filmi[i].price[j] << endl;   //запись стоиомсти билета
                f << kinoteatr.filmi[i].time[j] << endl;   //запись времени сеанса
                f << "0" << endl;   //запись точки (флажка) генерации
                for (int o = 0; o < 10; o++)
                {
                    for (int y = 0; y < 10; y++)
                    {
                        f << kinoteatr.filmi[i].mesta[j][y + o * 10];
                    }
                    f << endl;
                }
                f << endl;
            }
        }
        f.close();
    }
    */
}

void File_O::File_clean()
{
    fstream ofs;
    ofs.open(path, ios::out | ios::trunc);
    ofs.close();
}

