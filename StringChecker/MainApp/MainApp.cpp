#include <iostream>
#include <windows.h>
#include <string>

typedef bool(__stdcall* CheckCharactersFunc)(const char*, const char*);

int main() {
    // Запрос строки и символов у пользователя
    std::string inputString, characters;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);
    std::cout << "Enter characters to find: ";
    std::getline(std::cin, characters);

    // Проверка ввода
    std::cout << "Input string: " << inputString << std::endl;
    std::cout << "Characters to find: " << characters << std::endl;

    // Загрузка библиотеки
    HMODULE hLib = LoadLibrary(TEXT("StringChecker.dll"));
    if (hLib == NULL) {
        std::cerr << "Could not load the DLL" << std::endl;
        return 1;
    }
    std::cout << "DLL loaded successfully." << std::endl;

    // Получение адреса функции
    CheckCharactersFunc checkCharacters = (CheckCharactersFunc)GetProcAddress(hLib, "CheckCharacters");
    if (!checkCharacters) {
        std::cerr << "Could not find the function" << std::endl;
        FreeLibrary(hLib);
        return 1;
    }
    std::cout << "Function address retrieved successfully." << std::endl;

    // Вызов функции
    bool result = checkCharacters(inputString.c_str(), characters.c_str());

    // Вывод результата
    if (result) {
        std::cout << "All characters were found in the string." << std::endl;
    }
    else {
        std::cout << "Not all characters were found in the string." << std::endl;
    }

    // Освобождение библиотеки
    FreeLibrary(hLib);
    return 0;
}