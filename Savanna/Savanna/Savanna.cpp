#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <locale> // Для setlocale

using namespace std;

class Animal {
protected:
    string species;
    string size;
    string diet;
    bool isAlive;

public:
    Animal(string sp, string sz, string dt) : species(sp), size(sz), diet(dt), isAlive(true) {}

    string getSpecies() const { return species; }
    string getSize() const { return size; }
    string getDiet() const { return diet; }
    bool getIsAlive() const { return isAlive; }

    void setIsAlive(bool alive) { isAlive = alive; }

    void setSize(string newSize) { size = newSize; }

    virtual void eat(Animal& prey) {}
    virtual void reproduce() {}
};

class Herbivore : public Animal {
public:
    Herbivore(string sp, string sz) : Animal(sp, sz, "Трава") {}

    void eat(Animal& plant) {
        if (plant.getDiet() == "Трава")
            cout << species << " ест " << plant.getSpecies() << ".\n";
        else
            cout << species << " не может съесть " << plant.getSpecies() << ".\n";
    }
};

class Predator : public Animal {
public:
    Predator(string sp, string sz) : Animal(sp, sz, "Животные") {}

    void eat(Animal& prey) {
        if (prey.getSpecies() != "Трава")
            cout << species << " охотится на " << prey.getSpecies() << ".\n";
        else
            cout << species << " не может охотиться на " << prey.getSpecies() << ".\n";
    }
};

class Bird : public Animal {
public:
    Bird(string sp, string sz) : Animal(sp, sz, "Зерно") {}

    void eat(Animal& food) {
        if (food.getDiet() == "Зерно")
            cout << species << " питается " << food.getSpecies() << ".\n";
        else
            cout << species << " не может питаться " << food.getSpecies() << ".\n";
    }
};

class Reptile : public Animal {
public:
    Reptile(string sp, string sz) : Animal(sp, sz, "Мелкие животные") {}

    void eat(Animal& prey) {
        if (prey.getDiet() == "Мелкие животные")
            cout << species << " охотится на " << prey.getSpecies() << ".\n";
        else
            cout << species << " не может охотиться на " << prey.getSpecies() << ".\n";
    }
};

class Fish : public Animal {
public:
    Fish(string sp, string sz) : Animal(sp, sz, "Рыба") {}

    void eat(Animal& prey) {
        if (prey.getDiet() == "Рыба")
            cout << species << " питается " << prey.getSpecies() << ".\n";
        else
            cout << species << " не может питаться " << prey.getSpecies() << ".\n";
    }
};

class Savanna {
private:
    vector<Animal*> inhabitants;

public:
    void feedAnimals() {
        cout << "Кормим животных на саванне...\n";
        for (auto animal : inhabitants) {
            if (Herbivore* herbivore = dynamic_cast<Herbivore*>(animal)) {
                cout << "Кормим " << herbivore->getSpecies() << ".\n";
            }
            else if (Bird* bird = dynamic_cast<Bird*>(animal)) {
                cout << "Кормим " << bird->getSpecies() << ".\n";
            }
            else if (Reptile* reptile = dynamic_cast<Reptile*>(animal)) {
                cout << "Кормим " << reptile->getSpecies() << ".\n";
            }
            else if (Fish* fish = dynamic_cast<Fish*>(animal)) {
                cout << "Кормим " << fish->getSpecies() << ".\n";
            }
            else {
                cout << "Не удалось определить тип животного для кормления.\n";
            }
        }
        cout << "Животные на саванне накормлены.\n";
    }

    void reproduceAnimals() {
        cout << "Размножаем животных на саванне...\n";
        vector<Animal*> newborns;
        for (auto animal : inhabitants) {
            if (Herbivore* herbivore = dynamic_cast<Herbivore*>(animal)) {
                if (rand() % 2 == 0) { // 50% шанс размножения
                    cout << "Новый потомок " << herbivore->getSpecies() << " родился.\n";
                    newborns.push_back(new Herbivore(herbivore->getSpecies(), herbivore->getSize()));
                }
            }
            else if (Predator* predator = dynamic_cast<Predator*>(animal)) {
                if (rand() % 2 == 0) { // 50% шанс размножения
                    cout << "Новый потомок " << predator->getSpecies() << " родился.\n";
                    newborns.push_back(new Predator(predator->getSpecies(), predator->getSize()));
                }
            }
            else if (Bird* bird = dynamic_cast<Bird*>(animal)) {
                if (rand() % 2 == 0) { // 50% шанс размножения
                    cout << "Новый потомок " << bird->getSpecies() << " родился.\n";
                    newborns.push_back(new Bird(bird->getSpecies(), bird->getSize()));
                }
            }
            else if (Reptile* reptile = dynamic_cast<Reptile*>(animal)) {
                if (rand() % 2 == 0) { // 50% шанс размножения
                    cout << "Новый потомок " << reptile->getSpecies() << " родился.\n";
                    newborns.push_back(new Reptile(reptile->getSpecies(), reptile->getSize()));
                }
            }
            else if (Fish* fish = dynamic_cast<Fish*>(animal)) {
                if (rand() % 2 == 0) { // 50% шанс размножения
                    cout << "Новый потомок " << fish->getSpecies() << " родился.\n";
                    newborns.push_back(new Fish(fish->getSpecies(), fish->getSize()));
                }
            }
        }
        inhabitants.insert(inhabitants.end(), newborns.begin(), newborns.end());
    }

    void ageAnimals() {
        cout << "Животные на саванне стареют...\n";
        for (auto animal : inhabitants) {
            // Уменьшаем размер животных на каждом шаге
            string size = animal->getSize();
            if (size == "маленький") {
                animal->setSize("очень маленький");
            }
            else if (size == "средний") {
                animal->setSize("маленький");
            }
            else if (size == "большой") {
                animal->setSize("средний");
            }
            else if (size == "очень большой") {
                animal->setSize("большой");
            }
        }
        cout << "Животные на саванне постарели.\n";
    }

    void addAnimal() {
        string species, size;
        cout << "Введите название животного: ";
        cin >> species;
        cout << "Введите размер животного: ";
        cin >> size;
        inhabitants.push_back(new Herbivore(species, size));
        cout << "Добавлено новое животное: " << species << ".\n";
    }

    void addPredator() {
        string species, size;
        cout << "Введите название хищника: ";
        cin >> species;
        cout << "Введите размер хищника: ";
        cin >> size;
        inhabitants.push_back(new Predator(species, size));
        cout << "Добавлен новый хищник: " << species << ".\n";
    }

    void addBird() {
        string species, size;
        cout << "Введите название птицы: ";
        cin >> species;
        cout << "Введите размер птицы: ";
        cin >> size;
        inhabitants.push_back(new Bird(species, size));
        cout << "Добавлена новая птица: " << species << ".\n";
    }

    void addReptile() {
        string species, size;
        cout << "Введите название рептилии: ";
        cin >> species;
        cout << "Введите размер рептилии: ";
        cin >> size;
        inhabitants.push_back(new Reptile(species, size));
        cout << "Добавлена новая рептилия: " << species << ".\n";
    }

    void addFish() {
        string species, size;
        cout << "Введите название рыбы: ";
        cin >> species;
        cout << "Введите размер рыбы: ";
        cin >> size;
        inhabitants.push_back(new Fish(species, size));
        cout << "Добавлена новая рыба: " << species << ".\n";
    }

    void changeAnimalSize() {
        string species, newSize;
        cout << "Введите название животного, размер которого нужно изменить: ";
        cin >> species;
        cout << "Введите новый размер: ";
        cin >> newSize;
        for (auto animal : inhabitants) {
            if (animal->getSpecies() == species) {
                animal->setSize(newSize);
                cout << "Размер животного " << species << " изменен на " << newSize << ".\n";
                return;
            }
        }
        cout << "Животное с видом " << species << " не найдено.\n";
    }

    void showSavannaStatus() {
        int totalAnimals = inhabitants.size();
        if (totalAnimals == 0) {
            cout << "На саванне нет животных.\n";
            return;
        }
        cout << "Всего животных на саванне: " << totalAnimals << "\n";

        // Количество различных видов животных
        vector<string> speciesList;
        for (auto animal : inhabitants) {
            if (find(speciesList.begin(), speciesList.end(), animal->getSpecies()) == speciesList.end()) {
                speciesList.push_back(animal->getSpecies());
            }
        }
        cout << "Различных видов животных: " << speciesList.size() << "\n";

        // Размеры животных
        cout << "Размеры животных:\n";
        for (auto species : speciesList) {
            int count = 0;
            string sizes;
            for (auto animal : inhabitants) {
                if (animal->getSpecies() == species) {
                    count++;
                    sizes += animal->getSize() + ", ";
                }
            }
            cout << "Вид: " << species << ", Количество: " << count << ", Размеры: " << sizes.substr(0, sizes.size() - 2) << "\n";
        }
    }

    void simulateInteractions() {
        srand(time(0));
        int size = inhabitants.size();
        if (size < 2) {
            cout << "Слишком мало животных для взаимодействия.\n";
            return;
        }
        int index1 = rand() % size;
        int index2 = rand() % size;
        while (index1 == index2) {
            index2 = rand() % size;
        }
        Animal* animal1 = inhabitants[index1];
        Animal* animal2 = inhabitants[index2];
        if (animal1->getIsAlive() && animal2->getIsAlive()) {
            if (Predator* predator = dynamic_cast<Predator*>(animal1)) {
                predator->eat(*animal2);
                if (animal2->getIsAlive())
                    animal2->setIsAlive(false);
            }
            else if (Predator* predator = dynamic_cast<Predator*>(animal2)) {
                predator->eat(*animal1);
                if (animal1->getIsAlive())
                    animal1->setIsAlive(false);
            }
            else if (Herbivore* herbivore = dynamic_cast<Herbivore*>(animal1)) {
                herbivore->eat(*animal2);
                if (animal2->getIsAlive())
                    animal2->setIsAlive(false);
            }
            else if (Herbivore* herbivore = dynamic_cast<Herbivore*>(animal2)) {
                herbivore->eat(*animal1);
                if (animal1->getIsAlive())
                    animal1->setIsAlive(false);
            }
            else if (Bird* bird = dynamic_cast<Bird*>(animal1)) {
                bird->eat(*animal2);
                if (animal2->getIsAlive())
                    animal2->setIsAlive(false);
            }
            else if (Bird* bird = dynamic_cast<Bird*>(animal2)) {
                bird->eat(*animal1);
                if (animal1->getIsAlive())
                    animal1->setIsAlive(false);
            }
            else if (Reptile* reptile = dynamic_cast<Reptile*>(animal1)) {
                reptile->eat(*animal2);
                if (animal2->getIsAlive())
                    animal2->setIsAlive(false);
            }
            else if (Reptile* reptile = dynamic_cast<Reptile*>(animal2)) {
                reptile->eat(*animal1);
                if (animal1->getIsAlive())
                    animal1->setIsAlive(false);
            }
            else if (Fish* fish = dynamic_cast<Fish*>(animal1)) {
                fish->eat(*animal2);
                if (animal2->getIsAlive())
                    animal2->setIsAlive(false);
            }
            else if (Fish* fish = dynamic_cast<Fish*>(animal2)) {
                fish->eat(*animal1);
                if (animal1->getIsAlive())
                    animal1->setIsAlive(false);
            }
        }
    }

    void handleEvents() {
        for (auto it = inhabitants.begin(); it != inhabitants.end();) {
            Animal* animal = *it;
            if (!animal->getIsAlive()) {
                cout << animal->getSpecies() << " погибло.\n";
                it = inhabitants.erase(it);
                delete animal;
            }
            else {
                ++it;
            }
        }
    }
};



int main() {
    setlocale(LC_ALL, "ru_RU"); // Устанавливаем локаль

    Savanna savanna;

    while (true) {
        cout << "\n1. Добавить животное\n";
        cout << "2. Добавить хищника\n";
        cout << "3. Добавить птицу\n";
        cout << "4. Добавить рептилию\n";
        cout << "5. Добавить рыбу\n";
        cout << "6. Изменить размер животного\n";
        cout << "7. Показать статус саванны\n";
        cout << "8. симуляция\n";
        cout << "9. покормить\n";
        cout << "10. размножить\n";
        cout << "11. состарить\n";
        cout << "12. выйти\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;
        cin.ignore(); // Очищаем буфер ввода

        switch (choice) {
            case 1:
                savanna.addAnimal();
                break;
            case 2:
                savanna.addPredator();
                break;
            case 3:
                savanna.addBird();
                break;
            case 4:
                savanna.addReptile();
                break;
            case 5:
                savanna.addFish();
                break;
            case 6:
                savanna.changeAnimalSize();
                break;
            case 7:
                savanna.showSavannaStatus();
                break;
            case 8:
                savanna.simulateInteractions();
                savanna.handleEvents();
                break;
            case 9:
                savanna.feedAnimals();
                break;
            case 10:
                savanna.reproduceAnimals();
                break;
            case 11:
                savanna.ageAnimals();
                break;
            case 12:
                return 0;
            default: {
                cout << "Некорректный ввод. Попробуйте снова.\n";
                break;
            }
        }
    }
}