//
//  main.cpp
//  String Tester.cpp
//
//  Created by Kirill Kuvychkin on 12.02.2022.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    cout <<"\nВведите Слово1: ";
    cin >> a;
    string word1 = a;
    string b;
    cout << "\nВведите Слово 2: ";
    cin >> b;
    string word2 = b;
    string word3(1, '!');
    string phrase = word1 + " " + word2 + word3;
    cout <<"\nВаша фраза: " << phrase << "\n";
    cout <<"\nФраза содержит " << phrase.size() <<" символов\n";
    //cout <<"\nФраза содержит " << phrase.length() <<" символов\n";
    //принципиальной функционально разницы между size и length нет
    //char again;
    int number;
    for (unsigned int i = 0; i < phrase.size(); ++i)
    {
        cout <<"\nЗначения позиции симовола № " << i << " следующие: " << phrase[i] << endl;
    }
    char choise;
    do
    {
    cout << "\nЕсть ошибка? (y/n)";
    cin >> choise;
    if (choise == 'y')
    {
    cout <<"\nУкажите номер символа от 0 до " << phrase.size() << ":";
               cin >> number;
               cout << "\nУказанный символ: " << phrase[number] << "\n";
    cout << "\nВведите новый символ: ";
        //тип переменной задан по причине того, что тут нужен один символ, а не слово
    char newSign;
    cin >> newSign;
    phrase[number] = newSign;
    cout << "\nОбновленная фраза: " << phrase << "\n";
    }
    else if (choise != 'y' && choise != 'n')
    {
        cout << "\nВведено неверное значение!";
        choise = 'y';
    }
    else if (choise == 'n')
    {
        cout <<"\nИдём дальше!";
    }
    }
    while (choise == 'y');
    //добавим поиск слова
    cout << "\nВведите искомое слово: ";
    string search;
    cin >> search;
    //что если искомое отсутствует
    if (phrase.find(search) == string::npos)
    {
        cout <<"\nИскомое в текущей фразе не найдено!" << endl;
    }
    else
    {
        cout <<"\nИскомое " << search <<" в Вашей фразе начинается с символа №: ";
        cout << phrase.find(search) << endl;
    }
    
    //удалим лишние символы
    unsigned int deleting;
    char choise2;
    do
    {
        cout << "\nХотите удалить символ? (y/n)";
        cin >> choise2;
        if (choise2 != 'y' && choise2 != 'n')
        {
            cout << "\nВведено неверное значение!";
            choise2 = 'y';
        }
        else if (choise2 == 'n')
        {
            cout << "\nBye-bye!" << endl;
        }
        else
        {
            cout <<"\nВведите номер удаляемого символа: ";
            cin >> deleting;
            phrase.erase(deleting);
            cout <<"\nВаша фраза: " << phrase << endl;
        }
    }
        while (choise2 == 'y' && phrase.size() > 0);
    if (phrase.empty())
    {
        cout <<"\nВашей фразы больше нет" << endl;
    }
    return 0;
}
