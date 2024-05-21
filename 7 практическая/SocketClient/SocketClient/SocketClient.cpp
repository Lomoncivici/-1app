#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsaData;
    ADDRINFO hints;
    ADDRINFO* addrResult = nullptr;
    SOCKET ConnectSocket = INVALID_SOCKET;
    char recvBuffer[512];

    // Инициализируем Winsock
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        cout << "WSAStartup failed with result: " << result << endl;
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;         // Используем IPv4
    hints.ai_socktype = SOCK_STREAM;   // Устанавливаем тип сокета - потоковый
    hints.ai_protocol = IPPROTO_TCP;   // Используем протокол TCP

    // Получаем адрес информации
    result = getaddrinfo("localhost", "666", &hints, &addrResult);
    if (result != 0) {
        cout << "getaddrinfo failed with error: " << result << endl;
        WSACleanup();
        return 1;
    }

    // Создаем сокет для соединения
    ConnectSocket = socket(addrResult->ai_family, addrResult->ai_socktype, addrResult->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
        cout << "Socket creation failed with error: " << WSAGetLastError() << endl;
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }

    // Подключаемся к серверу
    result = connect(ConnectSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);
    if (result == SOCKET_ERROR) {
        cout << "Unable to connect to server with error: " << WSAGetLastError() << endl;
        closesocket(ConnectSocket);
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(addrResult);

    // Вводим данные для отправки с клавиатуры
    string input1, input2;
    cout << "Enter first message: ";
    getline(cin, input1);
    cout << "Enter second message: ";
    getline(cin, input2);

    // Отправляем первое сообщение
    result = send(ConnectSocket, input1.c_str(), (int)input1.length(), 0);
    if (result == SOCKET_ERROR) {
        cout << "Send failed with error: " << WSAGetLastError() << endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }
    cout << "Sent: " << result << " bytes" << endl;

    // Отправляем второе сообщение
    result = send(ConnectSocket, input2.c_str(), (int)input2.length(), 0);
    if (result == SOCKET_ERROR) {
        cout << "Send failed with error: " << WSAGetLastError() << endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }
    cout << "Sent: " << result << " bytes" << endl;

    // Завершаем отправку данных
    result = shutdown(ConnectSocket, SD_SEND);
    if (result == SOCKET_ERROR) {
        cout << "Shutdown failed with error: " << WSAGetLastError() << endl;
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // Принимаем ответ от сервера
    do {
        ZeroMemory(recvBuffer, 512);
        result = recv(ConnectSocket, recvBuffer, 512, 0);
        if (result > 0) {
            cout << "Received " << result << " bytes" << endl;
            cout << "Received data: " << recvBuffer << endl;
        }
        else if (result == 0) {
            cout << "Connection closed" << endl;
        }
        else {
            cout << "Recv failed with error: " << WSAGetLastError() << endl;
        }
    } while (result > 0);

    // Закрываем соединение
    closesocket(ConnectSocket);
    WSACleanup();
    return 0;
}