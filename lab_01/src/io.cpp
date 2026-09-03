#include "io.hpp"


std::expected<size_t, ParseError> sizeInput();
std::expected<int, ParseError> intInput();

void inputXInvitation(int spanStart, int spanEnd);
void inputNInvitation();
void inputMenuOptionInvitation();
void inputSpanStartInvatation();
void inputSpanEndInvatation();
void handleParseError(ParseError error);


std::expected<int, ParseError> UserInputN()
{
    inputNInvitation();
    return intInput();
}


size_t UserInputNForce()
{
    auto n = UserInputN();
    while (!n.has_value())
    {
        handleParseError(n.error());
        n = UserInputN();
    }
    
    return n.value();
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


int UserInputXForce(int spanStart, int spanEnd)
{
    auto x = UserInputX(spanStart, spanEnd);
    while (!x.has_value())
    {
        handleParseError(x.error());
        x = UserInputX(spanStart, spanEnd);
    }
    
    return x.value();
}


std::expected<size_t, ParseError> UserInputMenuOption()
{
    inputMenuOptionInvitation();

    auto userInput = sizeInput();

    if (!userInput.has_value())
        return std::unexpected(userInput.error());

    if (userInput.value() > MENU_OPTIONS_QUANTITY - 1)
        return std::unexpected(ParseError::InvalidInputDiapason);

    return userInput.value();
}

size_t UserInputMenuOptionForce()
{
    auto opt = UserInputMenuOption();
    while (!opt.has_value())
    {
        handleParseError(opt.error());
        opt = UserInputMenuOption();
    }
    
    return opt.value();
}


std::expected<size_t, ParseError> UserInputSpanStartInput()
{
    inputSpanStartInvatation();
    return intInput();
}


std::expected<size_t, ParseError> UserInputSpanEndInput()
{
    inputSpanEndInvatation();
    return intInput();
}

int UserInputSpanStartInputForce()
{
    auto span = UserInputSpanStartInput();
    while (!span.has_value())
    {
        handleParseError(span.error());
        span = UserInputSpanStartInput();
    }
    
    return span.value();
}

int UserInputSpanEndInputForce()
{
    auto span = UserInputSpanEndInput();
    while (!span.has_value())
    {
        handleParseError(span.error());
        span = UserInputSpanEndInput();
    }
    
    return span.value();
}

std::pair<int, int> UserInputDiapasonForce()
{
    int spanStart = 0;
    int spanEnd = 0;

    while (spanStart >= spanEnd)
    {
        spanStart = UserInputSpanStartInputForce();
        spanEnd = UserInputSpanEndInputForce();
        // TODO обработать случай, когда spanStart >= spanEnd            
    }

    return std::pair<int, int>(spanStart, spanEnd);
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
    std::cout << "‖ Размер массива `N`: " << std::setw(34) << std::right << oss.str() << " ‖" << std::endl;
    
    oss.str("");
    oss << x;
    std::cout << "‖ Искомое число `X`: " << std::setw(35) << std::right << oss.str() << " ‖" << std::endl;
    
    oss.str("");
    oss << "[" << generationSpanStart << ", " << generationSpanEnd << "]";
    std::cout << "‖ Диапазон значений: " << std::setw(28) << std::right << oss.str() << " ‖" << std::endl;
    
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


void inputSpanStartInvatation()
{
    std::cout << "Задайте начало диапазона: ";
}


void inputSpanEndInvatation()
{
    std::cout << "Задайте конец диапазона: ";
}


void handleParseError(ParseError error)
{
    // TODO add red color
    switch (error)
    {
        case ParseError::InvalidInputValue:
            std::cout << "Введено неверное значение, попробуйте еще раз." << std::endl;
            break;

        case ParseError::InvalidInputDiapason:
            std::cout << "Введенное значение не принадлежит требуемому диапазону. Попробуйте еще раз." << std::endl;
            break;
        
        default:
            break;
    }
}