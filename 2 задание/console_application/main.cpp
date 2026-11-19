#include <iostream>
#include <vector>
#include <functional>
#include "../lib/RealEstateCompany.h"
#include "../lib/Property.h"
#include "../lib/House.h"
#include "../lib/Apartment.h"
#include "../lib/Client.h"
#include "../lib/DealRecord.h"

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main() {
	system("chcp 65001 > nul");

	RealEstateCompany company(5.0);

	company.addClient(Client("Иванов Иван Иванович", "4510 123456", "+7-900-111-22-33"));
	company.addClient(Client("Петров Пётр Петрович", "4511 654321", "+7-900-444-55-66"));

	House house1("Коттедж Сосновый Бор", "Предложение", "Пригород", 180.0, 12500000.0, 2, 10.0, 25);
	House house2("Дача у реки", "Спрос", "Южный район", 120.0, 7500000.0, 1, 6.0, 12);

	Apartment apt1("ЖК Центральный", "Предложение", "Центр", 65.0, 9200000.0, 2, 7, 40);
	Apartment apt2("Квартира на Ленина", "Спрос", "Центр", 54.0, 7800000.0, 2, 4, 30);

	Property land1("Участок ИЖС", "Участок", "Предложение", "Северный район", 1000.0, 2500000.0, 8);

	company.addHouse(house1);
	company.addHouse(house2);
	company.addApartment(apt1);
	company.addApartment(apt2);
	company.addProperty(land1);

	company.addDeal(DealRecord("Иванов Иван Иванович", "15.10.2023", 9200000.0));
	company.addDeal(DealRecord("Петров Пётр Петрович", "25.10.2023", 12500000.0));
	company.addDeal(DealRecord("Сидоров Сидор", "05.11.2023", 7800000.0));

	std::cout << "Все объекты недвижимости в компании:" << std::endl;
	company.printAll();

	std::cout << "\nПредложения по видам недвижимости:" << std::endl;
	company.printOffersByCategory("Дом");
	company.printOffersByCategory("Квартира");

	std::cout << "\nСпрос по видам недвижимости:" << std::endl;
	company.printDemandsByCategory("Квартира");

	std::cout << "\nСведения о клиенте:" << std::endl;
	company.printClientByPassportOrName("4510 123456");
	company.printClientByPassportOrName("Петров Пётр Петрович");

	std::cout << "\nПоиск по цене, расположению и площади:" << std::endl;
	company.printByPriceLocationArea("Предложение", 9200000.0, "Центр", 65.0);
	company.printByPriceLocationArea("Спрос", 7800000.0, "Центр", 54.0);

	std::cout << "\nПрибыль компании за отчетный период:" << std::endl;
	company.printProfitByPeriod(".10.2023");
	company.printProfitByPeriod(".11.2023");

	std::cout << "\nСамые популярные предложения и спрос:" << std::endl;
	company.printMostPopular("Предложение", 2);
	company.printMostPopular("Спрос", 2);

	Property baseItem("Гараж кирпичный", "Гараж", "Предложение", "Восточный район", 24.0, 850000.0, 5);
	House derivedHouse("Таунхаус Парковый", "Предложение", "Западный район", 150.0, 11000000.0, 2, 4.0, 18);
	Apartment derivedApartment("Студия Академическая", "Предложение", "Центр", 32.0, 5600000.0, 1, 9, 35);

	std::vector<std::reference_wrapper<const Property>> baseCollection;
	baseCollection.push_back(std::cref(baseItem));
	baseCollection.push_back(std::cref(derivedHouse));
	baseCollection.push_back(std::cref(derivedApartment));

	std::cout << "\nКоллекция базового типа:" << std::endl;
	for (const Property& item : baseCollection) {
		std::cout << item.getInfo() << "\n" << std::endl;
	}

	return 0;
}