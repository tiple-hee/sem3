#pragma once

#include <string>

/**
 * @brief класс DealRecord (запись о сделке)
 */
class DealRecord
{
private:
    /**
     * @brief ФИО клиента
     */
    std::string clientName;

    /**
     * @brief Дата сделки
     */
    std::string date;

    /**
     * @brief Сумма сделки
     */
    double amount;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    DealRecord() = default;

    /**
     * @brief Конструктор
     * @param clientName - ФИО клиента
     * @param date - дата сделки
     * @param amount - сумма сделки
     */
    DealRecord(const std::string &clientName, const std::string &date, const double amount);

    /**
     * @brief Получить ФИО клиента
     * @return ФИО клиента
     */
    const std::string &getClientName() const noexcept;

    /**
     * @brief Получить дату сделки
     * @return дата сделки
     */
    const std::string &getDate() const noexcept;

    /**
     * @brief Получить сумму сделки
     * @return сумма сделки
     */
    double getAmount() const noexcept;

    /**
     * @brief Получить строку с информацией о сделке
     * @return строка с информацией о сделке
     */
    std::string toString() const;
};