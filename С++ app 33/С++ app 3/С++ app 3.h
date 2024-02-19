using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "RUS");

    int gg[2][4];

    int ggh;

    cout << "введите числа в 1 элемент:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ":";
        cin >> gg[0][i];
    }

    cout << "введите числа в 2 элемент:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ":";
        cin >> gg[1][i];
    }

    cout << "введите числа в 2 элемент:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ":";
        cin >> gg[2][i];
    }

    double summa = 0;

    for (int i = 0; i < 5; i++)
    {
        summa += gg[0][i];
    }

    cout << "среднее значение 1-ой строчки:" << summa / 5;
    summa = 0;
    for (int i = 0; i < 5; i++)
    {
        summa += gg[1][i];
    }

    cout << "среднее значение 2-ой строчки:" << summa / 5;
    summa = 0;
    for (int i = 0; i < 5; i++)
    {
        summa += gg[2][i];
    }

    cout << "среднее значение 3-ой строчки:" << summa / 5;
}