#include "Client.h"

Client::Client(const std::string &fullName, const std::string &passportNumber, const std::string &phone)
    : fullName(fullName), passportNumber(passportNumber), phone(phone) {}

const std::string &Client::getFullName() const noexcept
{
    return fullName;
}

const std::string &Client::getPassportNumber() const noexcept
{
    return passportNumber;
}

const std::string &Client::getPhone() const noexcept
{
    return phone;
}

std::string Client::toString() const
{
    return "Клиент: " + fullName + "/ Паспорт: " + passportNumber + "/ Телефон: " + phone;
}