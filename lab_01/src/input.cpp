#include "input.hpp"


std::expected<int, ParseError> userInputN();
std::expected<int, ParseError> userInputX(const std::pair<int, int> &generationSpan);
std::expected<size_t, ParseError> userInputMenuOption(size_t menuOptionsQuantity);
std::expected<size_t, ParseError> userInputSpanStartInput();
std::expected<size_t, ParseError> userInputSpanEndInput();

std::expected<size_t, ParseError> sizeInput();
std::expected<int, ParseError> intInput();

void inputNInvitation();
void inputSpanEndInvatation();
void inputSpanStartInvatation();
void inputMenuOptionInvitation();
void inputXInvitation(const std::pair<int, int> &generationSpan);

void handleParseError(ParseError error);


void UserInputNForce(size_t &N)
{
    auto n = userInputN();
    while (!n.has_value())
    {
        handleParseError(n.error());
        n = userInputN();
    }
    
    N = n.value();
}


void UserInputXForce(int &X, const std::pair<int, int> &generationSpan)
{
    auto x = userInputX(generationSpan);
    while (!x.has_value())
    {
        handleParseError(x.error());
        x = userInputX(generationSpan);
    }
    
    X = x.value();
}


void UserInputMenuOptionForce(const size_t menuOptionsQuantity, size_t &result)
{
    auto opt = userInputMenuOption(menuOptionsQuantity);
    while (!opt.has_value())
    {
        handleParseError(opt.error());
        opt = userInputMenuOption(menuOptionsQuantity);
    }
    
    result = opt.value();
}

int UserInputSpanStartInputForce()
{
    auto span = userInputSpanStartInput();
    while (!span.has_value())
    {
        handleParseError(span.error());
        span = userInputSpanStartInput();
    }
    
    return span.value();
}

int UserInputSpanEndInputForce()
{
    auto span = userInputSpanEndInput();
    while (!span.has_value())
    {
        handleParseError(span.error());
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


std::expected<int, ParseError> userInputX(const std::pair<int, int> &generationSpan)
{
    inputXInvitation(generationSpan);

    auto userInput = intInput();

    if (!userInput.has_value())
        return std::unexpected(userInput.error());

    if (userInput.value() < generationSpan.first || userInput.value() > generationSpan.second)
        return std::unexpected(ParseError::InvalidInputDiapason);

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


void inputXInvitation(const std::pair<int, int> &generationSpan)
{
    std::cout << "Введите значение `X` от " << generationSpan.first << " до " << generationSpan.second << " включительно: ";
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
    switch (error)
    {
        case ParseError::InvalidInputValue:
            std::cout << RED << "Введено неверное значение, попробуйте еще раз." << RESET << std::endl;
            break;

        case ParseError::InvalidInputDiapason:
            std::cout << RED << "Введенное значение не принадлежит требуемому диапазону. Попробуйте еще раз." << RESET << std::endl;
            break;
        
        default:
            break;
    }
}