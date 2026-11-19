#include "RealEstateCompany.h"
#include <iostream>
#include <algorithm>
#include <functional>

RealEstateCompany::RealEstateCompany(const double commissionPercent)
    : commissionPercent(commissionPercent) {}

double RealEstateCompany::getCommissionPercent() const noexcept
{
    return commissionPercent;
}

bool RealEstateCompany::containsId(const int id) const
{
    bool inHouses = std::any_of(houses.begin(), houses.end(), [id](const House &h)
                                { return h.getId() == id; });
    if (inHouses)
        return true;

    bool inApartments = std::any_of(apartments.begin(), apartments.end(), [id](const Apartment &a)
                                    { return a.getId() == id; });
    if (inApartments)
        return true;

    return std::any_of(properties.begin(), properties.end(), [id](const Property &p)
                       { return p.getId() == id; });
}

void RealEstateCompany::addProperty(const Property &property)
{
    if (containsId(property.getId()))
        return;
    properties.push_back(property);
}

void RealEstateCompany::addProperty(const House &house)
{
    addHouse(house);
}

void RealEstateCompany::addProperty(const Apartment &apartment)
{
    addApartment(apartment);
}

void RealEstateCompany::addHouse(const House &house)
{
    if (containsId(house.getId()))
        return;
    houses.push_back(house);
}

void RealEstateCompany::addApartment(const Apartment &apartment)
{
    if (containsId(apartment.getId()))
        return;
    apartments.push_back(apartment);
}

void RealEstateCompany::addClient(const Client &client)
{
    auto it = std::find_if(clients.begin(), clients.end(), [&client](const Client &c)
                           { return c.getPassportNumber() == client.getPassportNumber(); });
    if (it != clients.end())
        return;
    clients.push_back(client);
}

void RealEstateCompany::addDeal(const DealRecord &deal)
{
    deals.push_back(deal);
}

const std::vector<Property> &RealEstateCompany::getProperties() const noexcept { return properties; }
const std::vector<House> &RealEstateCompany::getHouses() const noexcept { return houses; }
const std::vector<Apartment> &RealEstateCompany::getApartments() const noexcept { return apartments; }
const std::vector<Client> &RealEstateCompany::getClients() const noexcept { return clients; }
const std::vector<DealRecord> &RealEstateCompany::getDeals() const noexcept { return deals; }

void RealEstateCompany::printAll() const
{
    for (const Property &p : properties)
    {
        std::cout << p.getInfo() << std::endl;
    }
    for (const House &h : houses)
    {
        std::cout << h.getInfo() << "\n"
                  << std::endl;
    }
    for (const Apartment &a : apartments)
    {
        std::cout << a.getInfo() << "\n"
                  << std::endl;
    }
}

void RealEstateCompany::printOffersByCategory(const std::string &category) const
{
    std::cout << "Предложения на вид недвижимости: " << category << std::endl;
    bool found = false;

    for (const Property &p : properties)
    {
        if (p.getDealType() == "Предложение" && p.getCategory() == category)
        {
            std::cout << p.getInfo() << std::endl;
            found = true;
        }
    }
    for (const House &h : houses)
    {
        if (h.getDealType() == "Предложение" && h.getCategory() == category)
        {
            std::cout << h.getInfo() << std::endl;
            found = true;
        }
    }
    for (const Apartment &a : apartments)
    {
        if (a.getDealType() == "Предложение" && a.getCategory() == category)
        {
            std::cout << a.getInfo() << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Предложений на данный вид недвижимости не найдено." << std::endl;
    }
    std::cout << std::endl;
}

void RealEstateCompany::printDemandsByCategory(const std::string &category) const
{
    std::cout << "Спрос на вид недвижимости: " << category << std::endl;
    bool found = false;

    for (const Property &p : properties)
    {
        if (p.getDealType() == "Спрос" && p.getCategory() == category)
        {
            std::cout << p.getInfo() << std::endl;
            found = true;
        }
    }
    for (const House &h : houses)
    {
        if (h.getDealType() == "Спрос" && h.getCategory() == category)
        {
            std::cout << h.getInfo() << std::endl;
            found = true;
        }
    }
    for (const Apartment &a : apartments)
    {
        if (a.getDealType() == "Спрос" && a.getCategory() == category)
        {
            std::cout << a.getInfo() << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Спроса на данный вид недвижимости не найдено." << std::endl;
    }
    std::cout << std::endl;
}

void RealEstateCompany::printClientByPassportOrName(const std::string &query) const
{
    std::cout << "Поиск клиента по запросу: " << query << std::endl;
    bool found = false;
    for (const Client &c : clients)
    {
        if (c.getPassportNumber() == query || c.getFullName() == query)
        {
            std::cout << c.toString() << std::endl;
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "Клиент не найден." << std::endl;
    }
    std::cout << std::endl;
}

void RealEstateCompany::printByPriceLocationArea(const std::string &dealType, const double price, const std::string &location, const double area) const
{
    std::cout << "Поиск [" << dealType << "] по цене: " << price << ", району: " << location << ", площади: " << area << std::endl;
    bool found = false;

    for (const Property &p : properties)
    {
        if (p.getDealType() == dealType && p.getPrice() == price && p.getLocation() == location && p.getArea() == area)
        {
            std::cout << p.getInfo() << std::endl;
            found = true;
        }
    }
    for (const House &h : houses)
    {
        if (h.getDealType() == dealType && h.getPrice() == price && h.getLocation() == location && h.getArea() == area)
        {
            std::cout << h.getInfo() << std::endl;
            found = true;
        }
    }
    for (const Apartment &a : apartments)
    {
        if (a.getDealType() == dealType && a.getPrice() == price && a.getLocation() == location && a.getArea() == area)
        {
            std::cout << a.getInfo() << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Подходящих вариантов не найдено." << std::endl;
    }
    std::cout << std::endl;
}

double RealEstateCompany::calculateProfitByPeriod(const std::string &period) const noexcept
{
    double totalProfit = 0.0;
    for (const DealRecord &deal : deals)
    {
        if (deal.getDate().find(period) != std::string::npos)
        {
            totalProfit += deal.getAmount() * (commissionPercent / 100.0);
        }
    }
    return totalProfit;
}

void RealEstateCompany::printProfitByPeriod(const std::string &period) const
{
    std::cout << "Прибыль компании за период [" << period << "] (комиссия " << commissionPercent << "%):" << std::endl;
    bool found = false;
    double totalProfit = 0.0;

    for (const DealRecord &deal : deals)
    {
        if (deal.getDate().find(period) != std::string::npos)
        {
            double dealProfit = deal.getAmount() * (commissionPercent / 100.0);
            std::cout << deal.toString() << " -> Прибыль: " << dealProfit << " руб." << std::endl;
            totalProfit += dealProfit;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Сделок за этот период не найдено." << std::endl;
    }
    else
    {
        std::cout << "Итоговая прибыль: " << totalProfit << " руб." << std::endl;
    }
    std::cout << std::endl;
}

void RealEstateCompany::printMostPopular(const std::string &dealType, const int topCount) const
{
    std::cout << "Самые популярные объекты (" << dealType << "):" << std::endl;
    std::vector<std::reference_wrapper<const Property>> filtered;

    for (const Property &p : properties)
    {
        if (p.getDealType() == dealType)
            filtered.push_back(std::cref(p));
    }
    for (const House &h : houses)
    {
        if (h.getDealType() == dealType)
            filtered.push_back(std::cref(h));
    }
    for (const Apartment &a : apartments)
    {
        if (a.getDealType() == dealType)
            filtered.push_back(std::cref(a));
    }

    if (filtered.empty())
    {
        std::cout << "Популярных объектов не найдено." << std::endl;
        std::cout << std::endl;
        return;
    }

    std::sort(filtered.begin(), filtered.end(), [](const Property &a, const Property &b)
              { return a.getPopularity() > b.getPopularity(); });

    int limit = static_cast<int>(filtered.size());
    if (topCount > 0 && topCount < limit)
    {
        limit = topCount;
    }

    for (int i = 0; i < limit; ++i)
    {
        std::cout << "- " << filtered[i].get().getName()
                  << " (" << filtered[i].get().getCategory()
                  << ", популярность: " << filtered[i].get().getPopularity() << ")" << std::endl;
    }
    std::cout << std::endl;
}