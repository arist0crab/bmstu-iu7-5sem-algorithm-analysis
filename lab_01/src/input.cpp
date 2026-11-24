#include "input.hpp"


std::expected<int, ParseError> userInputN();
std::expected<int, ParseError> userInputX();
std::expected<size_t, ParseError> userInputMenuOption(size_t menuOptionsQuantity);
std::expected<size_t, ParseError> userInputSpanStartInput();
std::expected<size_t, ParseError> userInputSpanEndInput();

std::expected<size_t, ParseError> sizeInput();
std::expected<int, ParseError> intInput();

void inputNInvitation();
void inputSpanEndInvatation();
void inputSpanStartInvatation();
void inputMenuOptionInvitation();
void inputXInvitation();
void inputArrayElementInvitation(size_t index, size_t arrSize);

void HandleParseError(ParseError error);


void UserInputNForce(size_t &N)
{
    auto n = userInputN();
    while (!n.has_value())
    {
        HandleParseError(n.error());
        n = userInputN();
    }
    
    N = n.value();
}


void UserInputXForce(int &X)
{
    auto x = userInputX();
    while (!x.has_value())
    {
        HandleParseError(x.error());
        x = userInputX();
    }
    
    X = x.value();
}


void UserInputMenuOptionForce(const size_t menuOptionsQuantity, size_t &result)
{
    auto opt = userInputMenuOption(menuOptionsQuantity);
    while (!opt.has_value())
    {
        HandleParseError(opt.error());
        opt = userInputMenuOption(menuOptionsQuantity);
    }
    
    result = opt.value();
}

int UserInputSpanStartInputForce()
{
    auto span = userInputSpanStartInput();
    while (!span.has_value())
    {
        HandleParseError(span.error());
        span = userInputSpanStartInput();
    }
    
    return span.value();
}

int UserInputSpanEndInputForce()
{
    auto span = userInputSpanEndInput();
    while (!span.has_value())
    {
        HandleParseError(span.error());
        span = userInputSpanEndInput();
    }
    
    return span.value();
}

void UserInputDiapasonForce(std::pair<int, int> &generationSpan)
{
    int spanStart = 0;
    int spanEnd = 0;

    while (spanStart >= spanEnd)
    {
        spanStart = UserInputSpanStartInputForce();
        spanEnd = UserInputSpanEndInputForce();
        // TODO обработать случай, когда spanStart >= spanEnd            
    }

    generationSpan = std::pair<int, int>(spanStart, spanEnd);
}


void UserInputArrayForce(int*& arr, int*& sortedArr, const size_t arrSize)
{
    delete[] arr;
    delete[] sortedArr;

    arr = new int[arrSize];
    sortedArr = new int[arrSize];

    for (size_t i = 0; i < arrSize; ++i)
    {
        inputArrayElementInvitation(i, arrSize);
        auto elem = intInput();
        while (!elem.has_value())
        {
            HandleParseError(elem.error());
            inputArrayElementInvitation(i, arrSize);
            elem = intInput();
        }
        arr[i] = elem.value();
    }

    std::copy(arr, arr + arrSize, sortedArr);
    std::sort(sortedArr, sortedArr + arrSize);
}


std::expected<int, ParseError> userInputX()
{
    inputXInvitation();

    auto userInput = intInput();

    if (!userInput.has_value())
        return std::unexpected(userInput.error());

    return userInput.value();
}


std::expected<int, ParseError> userInputN()
{
    inputNInvitation();
    return intInput();
}


std::expected<size_t, ParseError> userInputMenuOption(size_t menuOptionsQuantity)
{
    inputMenuOptionInvitation();

    auto userInput = sizeInput();

    if (!userInput.has_value())
        return std::unexpected(userInput.error());

    if (userInput.value() > menuOptionsQuantity - 1)
        return std::unexpected(ParseError::InvalidInputDiapason);

    return userInput.value();
}


std::expected<size_t, ParseError> userInputSpanStartInput()
{
    inputSpanStartInvatation();
    return intInput();
}


std::expected<size_t, ParseError> userInputSpanEndInput()
{
    inputSpanEndInvatation();
    return intInput();
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


void inputXInvitation()
{
    std::cout << "Введите любое значение `X`: ";
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


void inputArrayElementInvitation(size_t index, size_t arrSize)
{
    std::cout << "Введите элемент массива [" << (index + 1) << "/" << arrSize << "]: ";
}