using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "RUS");

    int gg[2][4];

    int ggh;

    cout << "������� ����� � 1 �������:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ":";
        cin >> gg[0][i];
    }

    cout << "������� ����� � 2 �������:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ":";
        cin >> gg[1][i];
    }

    cout << "������� ����� � 2 �������:\n";

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

    cout << "������� �������� 1-�� �������:" << summa / 5;
    summa = 0;
    for (int i = 0; i < 5; i++)
    {
        summa += gg[1][i];
    }

    cout << "������� �������� 2-�� �������:" << summa / 5;
    summa = 0;
    for (int i = 0; i < 5; i++)
    {
        summa += gg[2][i];
    }

    cout << "������� �������� 3-�� �������:" << summa / 5;
}