#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <locale>
#include <codecvt>

// Функция, которая выводит слово задом наперед
void Otraziti(const std::wstring& slovo)
{
    std::wstring otraziti = slovo;
    std::reverse(otraziti.begin(), otraziti.end());
    std::wcout << "Слово задом наперед: " << otraziti << std::endl;
}

// Функция, которая выводит слово без гласных
void No_glass(const std::wstring& slovo) 
{
    std::wstring kopia = slovo;
    kopia.erase(std::remove_if(kopia.begin(), kopia.end(), [](char c) 
    {
        return std::tolower(c) == 'а' || std::tolower(c) == 'е' || std::tolower(c) == 'и' || std::tolower(c) == 'о' || std::tolower(c) == 'й' || std::tolower(c) == 'у' || std::tolower(c) == 'ы' || std::tolower(c) == 'э' || std::tolower(c) == 'я' || std::tolower(c) == 'ю';
    }), kopia.end());
    std::wcout << "Слово без гласных: " << kopia << std::endl;
}

// Функция, которая выводит слово без согласных
void No_soglass(const std::wstring& slovo)
{
    std::wstring kopia = slovo;
    kopia.erase(std::remove_if(kopia.begin(), kopia.end(), [](char c) {
        return std::tolower(c) != 'ц' && std::tolower(c) != 'к' && std::tolower(c) != 'н' && std::tolower(c) != 'г' && std::tolower(c) != 'ш' && std::tolower(c) != 'щ' && std::tolower(c) != 'з' && std::tolower(c) != 'х' && std::tolower(c) != 'ъ' && std::tolower(c) != 'ф' && std::tolower(c) != 'в' && std::tolower(c) != 'п' && std::tolower(c) != 'р' && std::tolower(c) != 'л' && std::tolower(c) != 'д' && std::tolower(c) != 'ж' && std::tolower(c) != 'ч' && std::tolower(c) != 'с' && std::tolower(c) != 'м' && std::tolower(c) != 'т' && std::tolower(c) != 'ь' && std::tolower(c) != 'б';
        }), kopia.end());
    std::wcout << "Слово без согласных: " << kopia << std::endl;
}

// Функция, которая рандомно раскидывает буквы заданного слова
void random(const std::wstring& slovo) 
{
    std::wstring randomslovo = slovo;
    std::shuffle(randomslovo.begin(), randomslovo.end(), std::mt19937(std::random_device()()));
    std::wcout << "Слово с перемешанными буквами: " << randomslovo << std::endl;
}

int main() {
    std::setlocale(LC_ALL, "Russian");
    std::wstring slovo;
    int chislo;

    std::wcout << "Введите слово: ";
    std::wcin >> slovo;

    std::wcout << "Выберите операцию:" << std::endl;
    std::wcout << "1. Слово задом наперед" << std::endl;
    std::wcout << "2. Вывести слово без гласных" << std::endl;
    std::wcout << "3. Вывести слово без согласных" << std::endl;
    std::wcout << "4. Рандомно раскидывать буквы заданного слова" << std::endl;
    std::wcout << "Ваш выбор: ";
    std::wcin >> chislo;

    switch (chislo) {
    case 1:
        Otraziti(slovo);
        break;
    case 2:
        No_glass(slovo);
        break;
    case 3:
        No_soglass(slovo);
        break;
    case 4:
        random(slovo);
        break;
    default:
        std::wcout << "Неверный выбор." << std::endl;
    }

    return 0;
}