#include "Apartment.h"

Apartment::Apartment() : Property(), rooms(1), floor(1)
{
    category = "Квартира";
}

Apartment::Apartment(const std::string &name, const std::string &dealType, const std::string &location, const double area, const double price, const int rooms, const int floor, const int popularity, const int id)
    : Property(name, "Квартира", dealType, location, area, price, popularity, id), rooms(rooms), floor(floor) {}

int Apartment::getRooms() const noexcept
{
    return rooms;
}

int Apartment::getFloor() const noexcept
{
    return floor;
}

std::string Apartment::getInfo() const
{
    std::string result = Property::getInfo();
    result += "\n   Комнат: " + std::to_string(rooms);
    result += "\n   Этаж: " + std::to_string(floor);
    return result;
}