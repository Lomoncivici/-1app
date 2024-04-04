#include <iostream>
#include <locale>

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

    public:
    // Конструктор с параметрами
        BankAccount(int accNumber, double initialBalance, double interest)
            : accountNumber(accNumber), balance(initialBalance), interestRate(interest) {
            std::cout.imbue(std::locale(""));
        }

    // Внесение средств на счет
        void deposit(double amount) {
            if (amount <= 0) {
                std::cout << "Сумма взноса должна быть положительной." << std::endl;
                return;
            }
            this->balance += amount; 
        }


    // Списание средств со счета
        bool withdraw(double amount) {
            if (amount <= 0) {
                std::cout << "Сумма списания должна быть положительной." << std::endl;
                return false;
            }
            if (this->balance < amount) {
                std::cout << "Недостаточно средств для списания." << std::endl;
                return false;
            }
            this->balance -= amount;
            return true;
        }

    // Получение текущего баланса
        double getBalance() const {
            return this->balance;
        }

    // Получение суммы процентов
        double getInterest() const {
            return this->balance * this->interestRate * (1.0 / 12.0) / 100.0;
        }

    // Обновление процентной ставки
        void setInterestRate(double newInterestRate) {
            if (newInterestRate < 0) {
                std::cout << "Процентная ставка должна быть неотрицательной." << std::endl;
                return;
            }
            this->interestRate = newInterestRate;
        }

        // Получение номера банковского счета
        int getAccountNumber() const {
            return this->accountNumber;
        }

    // Дружественная функция для перевода средств между счетами
    friend bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount);

    // Вывод информации о счете
    void display() const {
        std::cout << "Номер счета: " << this->accountNumber << std::endl
            << "Баланс: " << this->balance << std::endl
            << "Процентная ставка: " << this->interestRate << "%" << std::endl;
    }
};

// Реализация дружественной функции transfer
bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount) {
    if (amount <= 0) {
        std::cout << "Сумма перевода должна быть положительной." << std::endl;
        return false;
    }
    if (fromAccount.getBalance() >= amount) {
        fromAccount.withdraw(amount);
        toAccount.deposit(amount);
        return true;
    }
    else {
        std::cout << "Недостаточно средств для перевода." << std::endl;
        return false;
    }
}

// Добавление средств на счет
void addBalance(BankAccount& account, double amount) {
    account.deposit(amount);
    std::cout << "Средства успешно добавлены на счет." << std::endl;
}

// Перевод между счетами
void makeTransfer(BankAccount& fromAccount, BankAccount& toAccount, double amount) {
    if (transfer(fromAccount, toAccount, amount))
        std::cout << "Перевод выполнен успешно." << std::endl;
    else
        std::cout << "Ошибка при переводе." << std::endl;
}

int main() {
    // Установка локали по умолчанию
    std::locale::global(std::locale(""));

    // Создание объектов банковских счетов
    BankAccount account1(123456, 500.0, 5.0);
    BankAccount account2(654321, 500.0, 3.0);

    // Переменные для ввода данных пользователем
    std::string command;
    int accountNumber;
    double amount;

    while (true) {
        std::cout << "Введите команду ('add' для добавления средств, 'perevod' для перевода, 'check_balance' для просмотра баланса или 'exit' для выхода): ";
        std::cin >> command;

        if (command == "add") {
            std::cout << "Введите номер счета: ";
            std::cin >> accountNumber;
            if (accountNumber == account1.getAccountNumber() || accountNumber == account2.getAccountNumber()) {
                std::cout << "Введите сумму для добавления: ";
                std::cin >> amount;
                if (accountNumber == account1.getAccountNumber())
                    addBalance(account1, amount);
                else
                    addBalance(account2, amount);
            }
            else {
                std::cout << "Счет с указанным номером не найден." << std::endl;
            }
        }
        else if (command == "perevod") {
            int fromAccountNumber, toAccountNumber;
            std::cout << "Введите номер вашего счета: ";
            std::cin >> fromAccountNumber;
            std::cout << "Введите номер счета, на который нужно перевести средства: ";
            std::cin >> toAccountNumber;
            if ((fromAccountNumber == account1.getAccountNumber() && toAccountNumber == account2.getAccountNumber()) || (fromAccountNumber == account2.getAccountNumber() && toAccountNumber == account1.getAccountNumber())) {
                std::cout << "Введите сумму для перевода: ";
                std::cin >> amount;
                if (fromAccountNumber == account1.getAccountNumber())
                    makeTransfer(account1, account2, amount);
                else
                    makeTransfer(account2, account1, amount);
            }
            else {
                std::cout << "Счета с указанными номерами не найдены или перевод между ними невозможен." << std::endl;
            }
        }
        if (command == "check_balance") {
            std::cout << "Введите номер вашего счета: ";
            std::cin >> accountNumber;
            if (accountNumber == account1.getAccountNumber()) {
                std::cout << "Информация о вашем счете:" << std::endl;
                account1.display();
            }
            else if (accountNumber == account2.getAccountNumber()) {
                std::cout << "Информация о вашем счете:" << std::endl;
                account2.display();
            }
            else {
                std::cout << "Счет с указанным номером не найден." << std::endl;
            }
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Неизвестная команда." << std::endl;
        }
        

    }

    return 0;
}