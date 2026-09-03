#include "input.hpp"


std::expected<int, ParseError> userInputN();
std::expected<int, ParseError> userInputX(int spanStart, int spanEnd);
std::expected<size_t, ParseError> userInputMenuOption();
std::expected<size_t, ParseError> userInputSpanStartInput();
std::expected<size_t, ParseError> userInputSpanEndInput();

std::expected<size_t, ParseError> sizeInput();
std::expected<int, ParseError> intInput();

void inputXInvitation(int spanStart, int spanEnd);
void inputNInvitation();
void inputMenuOptionInvitation();
void inputSpanStartInvatation();
void inputSpanEndInvatation();

void handleParseError(ParseError error);


size_t UserInputNForce()
{
    auto n = userInputN();
    while (!n.has_value())
    {
        handleParseError(n.error());
        n = userInputN();
    }
    
    return n.value();
}


int UserInputXForce(int spanStart, int spanEnd)
{
    auto x = userInputX(spanStart, spanEnd);
    while (!x.has_value())
    {
        handleParseError(x.error());
        x = userInputX(spanStart, spanEnd);
    }
    
    return x.value();
}


size_t UserInputMenuOptionForce()
{
    auto opt = userInputMenuOption();
    while (!opt.has_value())
    {
        handleParseError(opt.error());
        opt = userInputMenuOption();
    }
    
    return opt.value();
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


std::expected<int, ParseError> userInputX(int spanStart, int spanEnd)
{
    inputXInvitation(spanStart, spanEnd);

    auto userInput = intInput();

    if (!userInput.has_value())
        return std::unexpected(userInput.error());

    if (userInput.value() < spanStart || userInput.value() > spanEnd)
        return std::unexpected(ParseError::InvalidInputDiapason);

    return userInput.value();
}


std::expected<int, ParseError> userInputN()
{
    inputNInvitation();
    return intInput();
}


std::expected<size_t, ParseError> userInputMenuOption()
{
    inputMenuOptionInvitation();

    auto userInput = sizeInput();

    if (!userInput.has_value())
        return std::unexpected(userInput.error());

    if (userInput.value() > MENU_OPTIONS_QUANTITY - 1)
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