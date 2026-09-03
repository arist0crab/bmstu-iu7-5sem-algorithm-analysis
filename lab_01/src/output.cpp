#include "output.hpp"



void PrintMainMenu(const int *arr, const size_t arrSize, const int x, const int generationSpanStart, const int generationSpanEnd)
{
    std::cout << 
    "+=====================================================+" << std::endl <<
    "‖                    Главное меню                     ‖" << std::endl <<
    "+=====================================================+" << std::endl <<
    "‖ 1. Настройка входных данных                         ‖" << std::endl <<
    "‖ 2. Линейный алгоритм поиска                         ‖" << std::endl <<
    "‖ 3. Классический бинарный алгоритм поиска            ‖" << std::endl <<
    "‖ 4. Модифицированный бинарный алгоритм поиска        ‖" << std::endl <<
    "‖ 5. Рекурсивный бинарный алгоритм поиска             ‖" << std::endl <<
    "‖ 6. Полная таблица сравнения эффективности           ‖" << std::endl <<
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
    oss << "[" << generationSpanStart << ", " << generationSpanEnd << "]";
    std::cout << "‖ Диапазон значений: " << std::setw(32) << std::right << oss.str() << " ‖" << std::endl;
    
    std::cout << "+=====================================================+\n" << std::endl;

    std::cout << "Текущий массив значений:" << std::endl;
    
    if (arr == nullptr || arrSize == 0)
        std::cout << "[Массив пуст]" << std::endl;
    else
    {
        std::cout << "[";
        for (size_t i = 0; i < arrSize; ++i)
        {
            std::cout << arr[i];
            if (i < arrSize - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    
    std::cout << std::endl;
}


void PrintDataInputMenu()
{
    std::cout << 
    "+=====================================================+" << std::endl <<
    "‖                Меню ввода данных                    ‖" << std::endl <<
    "+=====================================================+" << std::endl <<
    "‖ 1. Ввести количество элементов массива N            ‖" << std::endl <<
    "‖ 2. Ввести искомое число `x`                         ‖" << std::endl <<
    "‖ 3. Ввести диапазон значений массива                 ‖" << std::endl <<
    "‖ 0. Назад                                            ‖" << std::endl <<
    "+=====================================================+" << std::endl;
}