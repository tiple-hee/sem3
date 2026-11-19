#pragma once
#include "Property.h"

/**
 * @brief Класс Apartment (Квартира) - наследник класса Property
 */
class Apartment : public Property
{
private:
    /**
     * @brief Количество комнат
     */
    int rooms;

    /**
     * @brief Этаж
     */
    int floor;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Apartment();

    /**
     * @brief Конструктор
     * @param name - название квартиры
     * @param dealType - тип заявки (Предложение / Спрос)
     * @param location - расположение
     * @param area - площадь квартиры
     * @param price - цена
     * @param rooms - количество комнат
     * @param floor - этаж
     * @param popularity - популярность
     * @param id - ID объекта (0 для автогенерации)
     */
    Apartment(const std::string &name, const std::string &dealType, const std::string &location, const double area, const double price, const int rooms, const int floor, const int popularity = 0, const int id = 0);

    /**
     * @brief Получить количество комнат
     * @return количество комнат
     */
    int getRooms() const noexcept;

    /**
     * @brief Получить этаж
     * @return этаж
     */
    int getFloor() const noexcept;

    /**
     * @brief Получение информации о квартире
     * @return Информацию о квартире
     */
    std::string getInfo() const override;
};