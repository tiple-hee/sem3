#pragma once

#include <string>

/**
 * @brief Класс Клиент
 */
class Client
{
private:
    /**
     * @brief ФИО клиента
     */
    std::string fullName;

    /**
     * @brief Номер паспорта
     */
    std::string passportNumber;

    /**
     * @brief Номер телефона
     */
    std::string phone;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Client() = default;

    /**
     * @brief Конструктор
     * @param fullName - ФИО клиента
     * @param passportNumber - номер паспорта
     * @param phone - телефон
     */
    Client(const std::string &fullName, const std::string &passportNumber, const std::string &phone);

    /**
     * @brief Получить ФИО клиента
     * @return ФИО клиента
     */
    const std::string &getFullName() const noexcept;

    /**
     * @brief Получить номер паспорта
     * @return номер паспорта
     */
    const std::string &getPassportNumber() const noexcept;

    /**
     * @brief Получить телефон клиента
     * @return телефон
     */
    const std::string &getPhone() const noexcept;

    /**
     * @brief Получить строку со сведениями о клиенте
     * @return строка с информацией о клиенте
     */
    std::string toString() const;
};