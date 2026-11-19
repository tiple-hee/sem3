#include "DealRecord.h"

DealRecord::DealRecord(const std::string &clientName, const std::string &date, const double amount)
    : clientName(clientName), date(date), amount(amount) {}

const std::string &DealRecord::getClientName() const noexcept
{
    return clientName;
}

const std::string &DealRecord::getDate() const noexcept
{
    return date;
}

double DealRecord::getAmount() const noexcept
{
    return amount;
}

std::string DealRecord::toString() const
{
    return "Клиент: " + clientName + "/ Дата: " + date + "/ Сумма: " + std::to_string(amount) + " руб.";
}