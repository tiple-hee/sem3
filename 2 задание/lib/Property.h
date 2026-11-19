#pragma once

#include <string>

/**
 * @brief Класс Property (базовый класс недвижимости)
 */
class Property
{
protected:
    /**
     * @brief Статический счетчик ID
     */
    static int nextId;

    /**
     * @brief id объекта недвижимости
     */
    int id;

    /**
     * @brief Название объекта
     */
    std::string name;

    /**
     * @brief Вид недвижимости (Дом, Квартира и т.д.)
     */
    std::string category;

    /**
     * @brief Тип заявки (Предложение или Спрос)
     */
    std::string dealType;

    /**
     * @brief Расположение (район/адрес)
     */
    std::string location;

    /**
     * @brief Площадь объекта
     */
    double area;

    /**
     * @brief Цена объекта
     */
    double price;

    /**
     * @brief Популярность (количество просмотров/обращений)
     */
    int popularity;

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Property();

    /**
     * @brief Конструктор
     * @param name - название объекта
     * @param category - вид недвижимости
     * @param dealType - тип заявки (Предложение / Спрос)
     * @param location - расположение
     * @param area - площадь
     * @param price - цена
     * @param popularity - популярность
     * @param id - id объекта (0 для автогенерации)
     */
    Property(const std::string &name, const std::string &category, const std::string &dealType, const std::string &location, const double area, const double price, const int popularity = 0, const int id = 0);

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Property() = default;

    /**
     * @brief Получить id объекта
     * @return id объекта
     */
    int getId() const noexcept;

    /**
     * @brief Получить название объекта
     * @return название объекта
     */
    const std::string &getName() const noexcept;

    /**
     * @brief Получить вид недвижимости
     * @return вид недвижимости
     */
    const std::string &getCategory() const noexcept;

    /**
     * @brief Получить тип заявки (Предложение / Спрос)
     * @return тип заявки
     */
    const std::string &getDealType() const noexcept;

    /**
     * @brief Получить расположение объекта
     * @return расположение
     */
    const std::string &getLocation() const noexcept;

    /**
     * @brief Получить площадь объекта
     * @return площадь
     */
    double getArea() const noexcept;

    /**
     * @brief Получить цену объекта
     * @return цена
     */
    double getPrice() const noexcept;

    /**
     * @brief Получить популярность объекта
     * @return популярность
     */
    int getPopularity() const noexcept;

    /**
     * @brief Увеличить счетчик популярности на 1
     */
    void incrementPopularity() noexcept;

    /**
     * @brief Виртуальный метод получения информации
     * @return строка с информацией об объекте
     */
    virtual std::string getInfo() const;
};