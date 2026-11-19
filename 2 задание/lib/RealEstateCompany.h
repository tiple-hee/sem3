#pragma once
#include "Property.h"
#include "House.h"
#include "Apartment.h"
#include "Client.h"
#include "DealRecord.h"
#include <vector>

/**
 * @brief Класс RealEstateCompany (Компания по продаже недвижимости)
 */
class RealEstateCompany
{
private:
    /**
     * @brief Процент комиссии компании с каждой сделки (x%)
     */
    double commissionPercent;

    /**
     * @brief Массив базовых объектов недвижимости
     */
    std::vector<Property> properties;

    /**
     * @brief Массив домов
     */
    std::vector<House> houses;

    /**
     * @brief Массив квартир
     */
    std::vector<Apartment> apartments;

    /**
     * @brief Массив клиентов
     */
    std::vector<Client> clients;

    /**
     * @brief Массив совершенных сделок
     */
    std::vector<DealRecord> deals;

    /**
     * @brief Проверить наличие объекта с данным ID в компании
     * @param id - ID объекта
     * @return true, если объект с таким ID уже есть
     */
    bool containsId(const int id) const;

public:
    /**
     * @brief Конструктор
     * @param commissionPercent - процент компании со сделки (по умолчанию 5%)
     */
    explicit RealEstateCompany(const double commissionPercent = 5.0);

    /**
     * @brief Деструктор
     */
    ~RealEstateCompany() = default;

    /**
     * @brief Получить процент комиссии компании
     * @return процент комиссии
     */
    double getCommissionPercent() const noexcept;

    /**
     * @brief Добавить базовый объект недвижимости
     * @param property - объект недвижимости
     */
    void addProperty(const Property &property);

    /**
     * @brief Добавить дом через базовый интерфейс
     * @param house - дом
     */
    void addProperty(const House &house);

    /**
     * @brief Добавить квартиру через базовый интерфейс
     * @param apartment - квартира
     */
    void addProperty(const Apartment &apartment);

    /**
     * @brief Добавить дом
     * @param house - дом
     */
    void addHouse(const House &house);

    /**
     * @brief Добавить квартиру
     * @param apartment - квартира
     */
    void addApartment(const Apartment &apartment);

    /**
     * @brief Добавить клиента
     * @param client - клиент
     */
    void addClient(const Client &client);

    /**
     * @brief Добавить запись о сделке
     * @param deal - запись о сделке
     */
    void addDeal(const DealRecord &deal);

    /**
     * @brief Получить список базовых объектов недвижимости
     * @return ссылку на массив объектов
     */
    const std::vector<Property> &getProperties() const noexcept;

    /**
     * @brief Получить список домов
     * @return ссылку на массив домов
     */
    const std::vector<House> &getHouses() const noexcept;

    /**
     * @brief Получить список квартир
     * @return ссылку на массив квартир
     */
    const std::vector<Apartment> &getApartments() const noexcept;

    /**
     * @brief Получить список клиентов
     * @return ссылку на массив клиентов
     */
    const std::vector<Client> &getClients() const noexcept;

    /**
     * @brief Получить список сделок
     * @return ссылку на массив сделок
     */
    const std::vector<DealRecord> &getDeals() const noexcept;

    /**
     * @brief Выдавать данные о всех объектах недвижимости
     */
    void printAll() const;

    /**
     * @brief Показывать все предложения на данный вид недвижимости
     * @param category - вид недвижимости (например, Дом или Квартира)
     */
    void printOffersByCategory(const std::string &category) const;

    /**
     * @brief Показывать спрос на данный вид недвижимости
     * @param category - вид недвижимости (например, Дом или Квартира)
     */
    void printDemandsByCategory(const std::string &category) const;

    /**
     * @brief Показывать сведения о клиенте по его № паспорта (ФИО)
     * @param query - номер паспорта или ФИО клиента
     */
    void printClientByPassportOrName(const std::string &query) const;

    /**
     * @brief Находить спрос (предложение) по выбранной цене, расположению, площади
     * @param dealType - тип (Предложение или Спрос)
     * @param price - цена
     * @param location - расположение
     * @param area - площадь
     */
    void printByPriceLocationArea(const std::string &dealType, const double price, const std::string &location, const double area) const;

    /**
     * @brief Вычислить прибыль компании за отчетный период
     * @param period - период в виде строки
     * @return сумма прибыли компании
     */
    double calculateProfitByPeriod(const std::string &period) const noexcept;

    /**
     * @brief Показывать прибыль компании (без учета налогов и т. д.) за отчетный период
     * @param period - период в виде строки
     */
    void printProfitByPeriod(const std::string &period) const;

    /**
     * @brief Показывать список самых популярных спросов (предложений)
     * @param dealType - тип (Предложение или Спрос)
     * @param topCount - количество выводимых популярных объектов
     */
    void printMostPopular(const std::string &dealType, const int topCount = 3) const;
};