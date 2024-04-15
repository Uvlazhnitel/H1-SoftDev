#include <iostream>
#include <vector>
#include <algorithm> // Для std::sort

int main() {
    // Инициализация вектора с буквами в случайном порядке
    std::vector<char> letters = {'e', 'a', 'c', 'b', 'd'};
    
    // Сортировка вектора
    // std::sort(letters.begin(), letters.end());
    
    // Вывод отсортированного списка
    for (char letter : letters) {
        std::cout << letter << ' ';
    }
    
    return 0;
}
