#include "io.hpp"


std::expected<size_t, ParseError> sizeInput();
std::expected<int, ParseError> intInput();

void inputXInvitation(int spanStart, int spanEnd);
void inputNInvitation();
void inputMenuOptionInvitation();


std::expected<int, ParseError> UserInputN()
{
    inputNInvitation();
    return intInput();
}


std::expected<int, ParseError> UserInputX(int spanStart, int spanEnd)
{
    inputXInvitation(spanStart, spanEnd);

    auto userInput = intInput();

    if (!userInput.has_value())
        return std::unexpected(userInput.error());

    if (userInput.value() < spanStart || userInput.value() > spanEnd)
        return std::unexpected(ParseError::InvalidInputDiapason);

    return userInput.value();
}


std::expected<size_t, ParseError> UserInputMenuOption(size_t menuOptionsQuantity)
{
    inputMenuOptionInvitation();

    auto userInput = sizeInput();

    if (!userInput.has_value())
        return std::unexpected(userInput.error());

    if (userInput.value() > menuOptionsQuantity - 1)
        return std::unexpected(ParseError::InvalidInputDiapason);

    return userInput.value();
}


std::expected<size_t, ParseError> sizeInput()
{
    size_t number = 0;
    std::string input;

    std::getline(std::cin, input);

    try 
    {
        number = std::stoi(input);
    } 
    catch (const std::invalid_argument& e) 
    {
        return std::unexpected(ParseError::InvalidInputValue);
    } 
    
    return number;
}


std::expected<int, ParseError> intInput()
{
    int number = 0;
    std::string input;

    std::getline(std::cin, input);

    try 
    {
        number = std::stoi(input);
    } 
    catch (const std::invalid_argument& e) 
    {
        return std::unexpected(ParseError::InvalidInputValue);
    } 
    
    return number;
}


void PrintMainMenu()
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
    "+=====================================================+" << std::endl;
}


void PrintDataInputMenu()
{
    std::cout << 
    "+=====================================================+" << std::endl <<
    "‖                Меню ввода данных                    ‖" << std::endl <<
    "+=====================================================+" << std::endl <<
    "‖ 1. Ввести количество элементов массива N            ‖" << std::endl <<
    "‖ 2. Ввести искомое число `x`                         ‖" << std::endl <<
    "+=====================================================+" << std::endl;

}


void inputXInvitation(int spanStart, int spanEnd)
{
    std::cout << "Введите значение `X` от " << spanStart << " до " << spanEnd << " включительно: ";
}


void inputNInvitation()
{
    std::cout << "Введите количество элементов массива `N`: ";
}


void inputMenuOptionInvitation()
{
    std::cout << "Введите пункт меню: ";
}