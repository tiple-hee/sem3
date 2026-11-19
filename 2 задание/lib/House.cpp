#include "House.h"

House::House() : Property(), floors(1), landArea(0.0)
{
    category = "Дом";
}

House::House(const std::string &name, const std::string &dealType, const std::string &location, const double area, const double price, const int floors, const double landArea, const int popularity, const int id)
    : Property(name, "Дом", dealType, location, area, price, popularity, id), floors(floors), landArea(landArea) {}

int House::getFloors() const noexcept
{
    return floors;
}

double House::getLandArea() const noexcept
{
    return landArea;
}

std::string House::getInfo() const
{
    std::string result = Property::getInfo();
    result += "\n   Этажей: " + std::to_string(floors);
    result += "\n   Площадь участка: " + std::to_string(landArea) + " сот.";
    return result;
}