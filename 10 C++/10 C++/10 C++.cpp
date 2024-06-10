#include <iostream>
#include <vector>
#include <thread>
#include <functional>

// Класс MergeSort, содержащий метод Sort для сортировки массива с использованием сортировки слиянием.
class MergeSort {
public:
    // Метод Sort реализует алгоритм сортировки слиянием.
    void Sort(std::vector<int>& array) {
        if (array.size() > 1) {
            // Делим массив на две части.
            std::vector<int> left(array.begin(), array.begin() + array.size() / 2);
            std::vector<int> right(array.begin() + array.size() / 2, array.end());

            // Создаем потоки для сортировки каждой части массива.
            std::thread leftThread(&MergeSort::Sort, this, std::ref(left));
            std::thread rightThread(&MergeSort::Sort, this, std::ref(right));

            // Ждем завершения работы потоков.
            leftThread.join();
            rightThread.join();

            // Объединяем отсортированные части.
            Merge(array, left, right);
        }
    }

private:
    // Метод Merge объединяет два отсортированных массива в один.
    void Merge(std::vector<int>& array, const std::vector<int>& left, const std::vector<int>& right) {
        size_t i = 0, j = 0, k = 0;

        // Слияние двух частей в один отсортированный массив.
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                array[k++] = left[i++];
            }
            else {
                array[k++] = right[j++];
            }
        }

        // Копируем оставшиеся элементы из левой части, если они есть.
        while (i < left.size()) {
            array[k++] = left[i++];
        }

        // Копируем оставшиеся элементы из правой части, если они есть.
        while (j < right.size()) {
            array[k++] = right[j++];
        }
    }
};

int main() {
    // Инициализируем массив из 10 элементов.
    std::vector<int> array(10);

    // Запрашиваем у пользователя ввод 10 целых чисел.
    std::cout << "Enter 10 integers:" << std::endl;
    for (int& num : array) {
        std::cin >> num;
    }

    // Создаем экземпляр класса MergeSort.
    MergeSort mergeSort;

    // Определяем лямбда-функцию для вызова метода Sort экземпляра класса MergeSort.
    auto sortLambda = [&mergeSort](std::vector<int>& arr) {
        mergeSort.Sort(arr);
        };

    // Создаем поток для выполнения сортировки.
    std::thread mergeSortThread(sortLambda, std::ref(array));

    // Ждем завершения потока.
    mergeSortThread.join();

    // Выводим отсортированный массив на экран.
    std::cout << "Sorted array:" << std::endl;
    for (const int& num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}