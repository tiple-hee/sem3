#include "Property.h"

int Property::nextId = 1;

Property::Property()
    : id(nextId++), area(0.0), price(0.0), popularity(0) {}

Property::Property(const std::string &name, const std::string &category, const std::string &dealType, const std::string &location, const double area, const double price, const int popularity, const int id)
    : id(id > 0 ? id : nextId++), name(name), category(category), dealType(dealType), location(location), area(area), price(price), popularity(popularity)
{
    if (this->id >= nextId)
    {
        nextId = this->id + 1;
    }
}

int Property::getId() const noexcept
{
    return id;
}

const std::string &Property::getName() const noexcept
{
    return name;
}

const std::string &Property::getCategory() const noexcept
{
    return category;
}

const std::string &Property::getDealType() const noexcept
{
    return dealType;
}

const std::string &Property::getLocation() const noexcept
{
    return location;
}

double Property::getArea() const noexcept
{
    return area;
}

double Property::getPrice() const noexcept
{
    return price;
}

int Property::getPopularity() const noexcept
{
    return popularity;
}

void Property::incrementPopularity() noexcept
{
    ++popularity;
}

std::string Property::getInfo() const
{
    return "ID: " + std::to_string(id) +
           " Объект: " + name +
           " Вид: " + category +
           " Тип: " + dealType +
           " Район: " + location +
           " Площадь: " + std::to_string(area) + " кв.м" +
           " Цена: " + std::to_string(price) + " руб." +
           " Популярность: " + std::to_string(popularity);
}