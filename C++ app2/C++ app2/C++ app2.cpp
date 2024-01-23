// C++ app2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using  namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    while (true)
    {
        int a, b, c;

        cout << "1) Сложение\n2) Вычетание\n3) Частное\n4) Производное\n5) Возведение в степень\n6) кв. корень\n7) 1% от числа\n8) Факториал чила\n9) Выйти\n";

        cout << "\nВведите Действие: ", cin >> c, cout << "\n";

        if (c >= 1 && c <= 8)
        {
            cout << "Введите первое число: ", cin >> a, cout << "\n";

            cout << "Введите второе число: ", cin >> b, cout << "\n";

            switch (c)
            {
            case 1:
                cout << "Вывод: " << a + b << "\n\n";
                break;
            case 2:
                cout << "Вывод: " << a - b << "\n\n";
                break;
            case 3:
                cout << "Вывод: " << a * b << "\n\n";
                break;
            case 4:
                cout << "Вывод: " << a / b << "\n\n";
                break;
            case 5:
                cout << "Вывод: " << pow(a, b) << endl << "\n\n";
                break;
            case 6:
                cout << "Вывод: " << sqrt(a) << endl << "\n\n";
                break;
            case 7:
                cout << "Вывод: " << a / 100 << "\n\n";
                break;
            case 8:
                int b;
                b = 1;
                for (int i = 1; i <= a; i++)
                {
                    b *= i;
                }
                cout << "Вывод: " << b <<"\n\n";
                break;
            }
        }
        else if (c == 9)
        {
            exit(0);
        }
        else
        {
            cout << "Введите от 1 до 9\n\n";

            main();
        }
    }
}
