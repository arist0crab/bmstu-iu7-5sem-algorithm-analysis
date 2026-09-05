#include "output.hpp"

void printArray(const int* arr, const size_t arrSize, const std::string& name);


void PrintMainMenu(const int *arr, const int *sortedArr, const size_t arrSize, const int x, const std::pair<int, int> &generationSpan)
{
    std::cout << "\n" <<
    "+=====================================================+" << std::endl <<
    "‖                    Главное меню                     ‖" << std::endl <<
    "+=====================================================+" << std::endl <<
    "‖ 1. Настройка входных данных                         ‖" << std::endl <<
    "‖ 2. Сгенерировать массив заново                      ‖" << std::endl <<
    "‖ 3. Линейный алгоритм поиска                         ‖" << std::endl <<
    "‖ 4. Классический бинарный алгоритм поиска            ‖" << std::endl <<
    "‖ 5. Модифицированный бинарный алгоритм поиска        ‖" << std::endl <<
    "‖ 6. Рекурсивный бинарный алгоритм поиска             ‖" << std::endl <<
    "‖ 7. Полная таблица сравнения эффективности           ‖" << std::endl <<
    "‖ 0. Выход                                            ‖" << std::endl <<
    "+=====================================================+" << std::endl <<
    "‖                   Текущие данные                    ‖" << std::endl <<
    "+=====================================================+" << std::endl;

    std::ostringstream oss;
    oss << arrSize;
    std::cout << "‖ Размер массива `N`: " << std::setw(31) << std::right << oss.str() << " ‖" << std::endl;
    
    oss.str("");
    oss << x;
    std::cout << "‖ Искомое число `X`: " << std::setw(32) << std::right << oss.str() << " ‖" << std::endl;
    
    oss.str("");
    oss << "[" << generationSpan.first << ", " << generationSpan.second << "]";
    std::cout << "‖ Диапазон значений: " << std::setw(32) << std::right << oss.str() << " ‖" << std::endl;
    
    std::cout << "+=====================================================+\n" << std::endl;

    printArray(arr, arrSize, "Несортированный массив");
    printArray(sortedArr, arrSize, "Отсортированный массив");
}


void PrintDataInputMenu()
{
    std::cout << "\n" <<
    "+=====================================================+" << std::endl <<
    "‖                Меню ввода данных                    ‖" << std::endl <<
    "+=====================================================+" << std::endl <<
    "‖ 1. Ввести количество элементов массива N            ‖" << std::endl <<
    "‖ 2. Ввести искомое число `x`                         ‖" << std::endl <<
    "‖ 3. Ввести диапазон значений массива                 ‖" << std::endl <<
    "‖ 0. Назад                                            ‖" << std::endl <<
    "+=====================================================+" << std::endl;
}


void PrintResultTable(const size_t *algosIterationsQuantity, const ssize_t *algosResultsIndexes)
{
    const char* algosNames[] = {
        "Линейный                   ",
        "Бинарный классический      ",
        "Бинарный модифицированный  ",
        "Бинарный рекурсивный       "
    };

    std::cout << 
    "+===========================================================+" << std::endl <<
    "‖              Результаты поиска элемента X                 ‖" << std::endl <<
    "+===========================================================+" << std::endl <<
    "‖ Алгоритм                    ‖ Индекс ‖ Итераций           ‖" << std::endl <<
    "+-----------------------------+--------+--------------------+" << std::endl;

    for (int i = 0; i < 4; ++i)
        std::cout << "‖ " << std::left << algosNames[i] << " ‖ " << std::setw(6) << std::right << (algosResultsIndexes[i] != -1 ? std::to_string(algosResultsIndexes[i]) : "  --  ") << " ‖ " << std::setw(18) << std::right << algosIterationsQuantity[i] << " ‖" << std::endl;
    std::cout << "+===========================================================+" << std::endl;
}


void printArray(const int* arr, const size_t arrSize, const std::string& name = "Массив")
{
    std::cout << "=== " << name <<  " === " << std::endl;
    
    if (arr == nullptr || arrSize == 0) {
        std::cout << "[Пусто]" << std::endl;
        return;
    }
    
    std::cout << "[";
    for (size_t i = 0; i < arrSize; ++i) {
        std::cout << arr[i];
        if (i < arrSize - 1)
            std::cout << ", ";
    }
    std::cout << "]\n" << std::endl;
}


void PrintLinearBaseSearchResult(size_t index)
{
    std::cout << "Индекс, найденный линейным алгоритмом: " << index << std::endl;
}

void PrintBinBaseSearchResult(size_t index)
{
    std::cout << "Индекс, найденный бинарным алгоритмом: " << index << std::endl;
}

void PrintBinImprovedSearchResult(size_t index)
{
    std::cout << "Индекс, найденный модифицированным бинарным алгоритмом: " << index << std::endl; 
}

void PrintBinRecursionSearchResult(size_t index)
{
    std::cout << "Индекс, найденный рекурсивным бинарным алгоритмом: " << index << std::endl; 
}