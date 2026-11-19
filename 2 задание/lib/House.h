#pragma once
#include "Property.h"

/**
 * @brief Класс House (Дом) - наследник класса Property
 */
class House : public Property
{
private:
    /**
     * @brief Количество этажей в доме
     */
    int floors;

    /**
     * @brief Площадь земельного участка (в сотках)
     */
    double landArea;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    House();

    /**
     * @brief Конструктор
     * @param name - название дома
     * @param dealType - тип заявки (Предложение / Спрос)
     * @param location - расположение
     * @param area - площадь дома
     * @param price - цена
     * @param floors - количество этажей
     * @param landArea - площадь участка
     * @param popularity - популярность
     * @param id - ID объекта (0 для автогенерации)
     */
    House(const std::string &name, const std::string &dealType, const std::string &location, const double area, const double price, const int floors, const double landArea, const int popularity = 0, const int id = 0);

    /**
     * @brief Получить количество этажей
     * @return количество этажей
     */
    int getFloors() const noexcept;

    /**
     * @brief Получить площадь участка
     * @return площадь участка
     */
    double getLandArea() const noexcept;

    /**
     * @brief Получение информации о доме
     * @return Информацию о доме
     */
    std::string getInfo() const override;
};