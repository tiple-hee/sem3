#include <gtest/gtest.h>
#include "RealEstateCompany.h"
#include "Property.h"
#include "House.h"
#include "Apartment.h"
#include "Client.h"
#include "DealRecord.h"
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <typeinfo>

TEST(ClientTest, DefaultConstructor) {
    Client c;
    EXPECT_EQ(c.getFullName(), "");
    EXPECT_EQ(c.getPassportNumber(), "");
    EXPECT_EQ(c.getPhone(), "");
}

TEST(ClientTest, ParameterizedConstructorAndGetters) {
    Client c("Иванов И.И.", "4510 123456", "+79001112233");
    EXPECT_EQ(c.getFullName(), "Иванов И.И.");
    EXPECT_EQ(c.getPassportNumber(), "4510 123456");
    EXPECT_EQ(c.getPhone(), "+79001112233");

    std::string s = c.toString();
    EXPECT_NE(s.find("Иванов И.И."), std::string::npos);
    EXPECT_NE(s.find("4510 123456"), std::string::npos);
    EXPECT_NE(s.find("+79001112233"), std::string::npos);
}

TEST(DealRecordTest, DefaultConstructor) {
    DealRecord deal;
    EXPECT_EQ(deal.getClientName(), "");
    EXPECT_EQ(deal.getDate(), "");
    EXPECT_DOUBLE_EQ(deal.getAmount(), 0.0);
}

TEST(DealRecordTest, GettersAndToString) {
    DealRecord deal("Иванов И.И.", "15.10.2023", 8500000.0);

    EXPECT_EQ(deal.getClientName(), "Иванов И.И.");
    EXPECT_EQ(deal.getDate(), "15.10.2023");
    EXPECT_DOUBLE_EQ(deal.getAmount(), 8500000.0);

    std::string s = deal.toString();
    EXPECT_NE(s.find("Иванов И.И."), std::string::npos);
    EXPECT_NE(s.find("15.10.2023"), std::string::npos);
    EXPECT_NE(s.find("8500000"), std::string::npos);
}

TEST(PropertyTest, DefaultConstructorHasValidId) {
    Property p;
    EXPECT_GT(p.getId(), 0);
    EXPECT_EQ(p.getName(), "");
    EXPECT_EQ(p.getCategory(), "");
    EXPECT_EQ(p.getDealType(), "");
    EXPECT_EQ(p.getLocation(), "");
    EXPECT_DOUBLE_EQ(p.getArea(), 0.0);
    EXPECT_DOUBLE_EQ(p.getPrice(), 0.0);
    EXPECT_EQ(p.getPopularity(), 0);
}

TEST(PropertyTest, GettersAutoIdAndIncrementPopularity) {
    Property p("Участок", "Земля", "Предложение", "Пригород", 600.0, 1200000.0, 5);

    EXPECT_GT(p.getId(), 0);
    EXPECT_EQ(p.getName(), "Участок");
    EXPECT_EQ(p.getCategory(), "Земля");
    EXPECT_EQ(p.getDealType(), "Предложение");
    EXPECT_EQ(p.getLocation(), "Пригород");
    EXPECT_DOUBLE_EQ(p.getArea(), 600.0);
    EXPECT_DOUBLE_EQ(p.getPrice(), 1200000.0);
    EXPECT_EQ(p.getPopularity(), 5);

    p.incrementPopularity();
    EXPECT_EQ(p.getPopularity(), 6);
}

TEST(PropertyTest, ConstructorWithExplicitId) {
    Property p("Гараж", "Гараж", "Предложение", "Центр", 20.0, 500000.0, 2, 42);
    EXPECT_EQ(p.getId(), 42);
    EXPECT_EQ(p.getName(), "Гараж");
    EXPECT_DOUBLE_EQ(p.getPrice(), 500000.0);
}

TEST(PropertyTest, GetInfo) {
    Property p("Кладовая", "Помещение", "Предложение", "Север", 10.0, 300000.0, 1, 10);
    std::string info = p.getInfo();

    EXPECT_NE(info.find("ID: 10"), std::string::npos);
    EXPECT_NE(info.find("Кладовая"), std::string::npos);
    EXPECT_NE(info.find("300000"), std::string::npos);
}

TEST(HouseTest, DefaultConstructorHasValidId) {
    House h;
    EXPECT_GT(h.getId(), 0);
    EXPECT_EQ(h.getCategory(), "Дом");
    EXPECT_EQ(h.getFloors(), 1);
    EXPECT_DOUBLE_EQ(h.getLandArea(), 0.0);
}

TEST(HouseTest, GettersAndGetInfo) {
    House h("Коттедж", "Предложение", "Одинцово", 160.0, 14000000.0, 2, 12.5, 10, 77);

    EXPECT_EQ(h.getId(), 77);
    EXPECT_EQ(h.getName(), "Коттедж");
    EXPECT_EQ(h.getCategory(), "Дом");
    EXPECT_EQ(h.getDealType(), "Предложение");
    EXPECT_EQ(h.getLocation(), "Одинцово");
    EXPECT_DOUBLE_EQ(h.getArea(), 160.0);
    EXPECT_DOUBLE_EQ(h.getPrice(), 14000000.0);
    EXPECT_EQ(h.getFloors(), 2);
    EXPECT_DOUBLE_EQ(h.getLandArea(), 12.5);
    EXPECT_EQ(h.getPopularity(), 10);

    std::string info = h.getInfo();
    EXPECT_NE(info.find("ID: 77"), std::string::npos);
    EXPECT_NE(info.find("Коттедж"), std::string::npos);
    EXPECT_NE(info.find("Этажей: 2"), std::string::npos);
}

TEST(ApartmentTest, DefaultConstructorHasValidId) {
    Apartment a;
    EXPECT_GT(a.getId(), 0);
    EXPECT_EQ(a.getCategory(), "Квартира");
    EXPECT_EQ(a.getRooms(), 1);
    EXPECT_EQ(a.getFloor(), 1);
}

TEST(ApartmentTest, GettersAndGetInfo) {
    Apartment a("ЖК Восток", "Спрос", "Центр", 72.0, 10500000.0, 3, 8, 15, 88);

    EXPECT_EQ(a.getId(), 88);
    EXPECT_EQ(a.getName(), "ЖК Восток");
    EXPECT_EQ(a.getCategory(), "Квартира");
    EXPECT_EQ(a.getDealType(), "Спрос");
    EXPECT_EQ(a.getLocation(), "Центр");
    EXPECT_DOUBLE_EQ(a.getArea(), 72.0);
    EXPECT_DOUBLE_EQ(a.getPrice(), 10500000.0);
    EXPECT_EQ(a.getRooms(), 3);
    EXPECT_EQ(a.getFloor(), 8);
    EXPECT_EQ(a.getPopularity(), 15);

    std::string info = a.getInfo();
    EXPECT_NE(info.find("ID: 88"), std::string::npos);
    EXPECT_NE(info.find("ЖК Восток"), std::string::npos);
    EXPECT_NE(info.find("Комнат: 3"), std::string::npos);
    EXPECT_NE(info.find("Этаж: 8"), std::string::npos);
}

static bool companyHasName(const RealEstateCompany& comp, const std::string& name) {
    bool inProperties = std::any_of(comp.getProperties().begin(), comp.getProperties().end(), [&name](const Property& p) {
        return p.getName() == name;
    });
    if (inProperties) return true;

    bool inHouses = std::any_of(comp.getHouses().begin(), comp.getHouses().end(), [&name](const House& h) {
        return h.getName() == name;
    });
    if (inHouses) return true;

    return std::any_of(comp.getApartments().begin(), comp.getApartments().end(), [&name](const Apartment& a) {
        return a.getName() == name;
    });
}

TEST(RealEstateCompanyTest, DefaultConstructorEmptyCollections) {
    RealEstateCompany comp(5.0);
    EXPECT_DOUBLE_EQ(comp.getCommissionPercent(), 5.0);
    EXPECT_TRUE(comp.getProperties().empty());
    EXPECT_TRUE(comp.getHouses().empty());
    EXPECT_TRUE(comp.getApartments().empty());
    EXPECT_TRUE(comp.getClients().empty());
    EXPECT_TRUE(comp.getDeals().empty());
}

TEST(RealEstateCompanyTest, AddItemsAndDuplicateIdRejected) {
    RealEstateCompany comp;

    Property p1("Участок 1", "Участок", "Предложение", "Север", 500.0, 1000000.0, 1, 100);
    Property p2("Участок 2", "Участок", "Предложение", "Юг", 600.0, 1200000.0, 1, 100);
    House hSameId("Дом 1", "Предложение", "Запад", 120.0, 8000000.0, 2, 6.0, 5, 100);
    Apartment aSameId("Квартира 1", "Предложение", "Центр", 50.0, 6000000.0, 2, 3, 5, 100);

    comp.addProperty(p1);
    comp.addProperty(p2);
    comp.addHouse(hSameId);
    comp.addApartment(aSameId);

    EXPECT_EQ(comp.getProperties().size(), 1u);
    EXPECT_EQ(comp.getHouses().size(), 0u);
    EXPECT_EQ(comp.getApartments().size(), 0u);
    EXPECT_TRUE(companyHasName(comp, "Участок 1"));
    EXPECT_FALSE(companyHasName(comp, "Участок 2"));
    EXPECT_FALSE(companyHasName(comp, "Дом 1"));
    EXPECT_FALSE(companyHasName(comp, "Квартира 1"));
}

TEST(RealEstateCompanyTest, AddClientDeduplicationByPassport) {
    RealEstateCompany comp;

    comp.addClient(Client("Иванов И.И.", "4510 111111", "+79001111111"));
    comp.addClient(Client("Иванов И.И. (дубль)", "4510 111111", "+79002222222"));
    comp.addClient(Client("Петров П.П.", "4510 222222", "+79003333333"));

    ASSERT_EQ(comp.getClients().size(), 2u);
    EXPECT_EQ(comp.getClients()[0].getFullName(), "Иванов И.И.");
    EXPECT_EQ(comp.getClients()[1].getFullName(), "Петров П.П.");
}

TEST(RealEstateCompanyTest, PolymorphismByReference) {
    Property p("Гараж", "Гараж", "Предложение", "Центр", 20.0, 500000.0, 1);
    House h("Коттедж", "Предложение", "Пригород", 150.0, 12000000.0, 2, 10.0, 5);
    Apartment a("Студия", "Предложение", "Центр", 30.0, 4500000.0, 1, 4, 8);

    const Property& pRef = p;
    const Property& hRef = h;
    const Property& aRef = a;

    EXPECT_THROW((void)dynamic_cast<const House&>(pRef), std::bad_cast);
    EXPECT_NO_THROW((void)dynamic_cast<const House&>(hRef));
    EXPECT_NO_THROW((void)dynamic_cast<const Apartment&>(aRef));

    EXPECT_EQ(pRef.getInfo().find("Этажей:"), std::string::npos);
    EXPECT_NE(hRef.getInfo().find("Этажей:"), std::string::npos);
    EXPECT_NE(aRef.getInfo().find("Комнат:"), std::string::npos);
}

TEST(RealEstateCompanyTest, PrintOffersAndDemandsByCategoryOutput) {
    RealEstateCompany comp;
    comp.addHouse(House("Коттедж Лесной", "Предложение", "Пригород", 180.0, 12500000.0, 2, 10.0, 10));
    comp.addApartment(Apartment("ЖК Солнечный", "Спрос", "Центр", 60.0, 8500000.0, 2, 5, 15));

    testing::internal::CaptureStdout();
    comp.printOffersByCategory("Дом");
    std::string outOffer = testing::internal::GetCapturedStdout();
    EXPECT_NE(outOffer.find("Коттедж Лесной"), std::string::npos);

    testing::internal::CaptureStdout();
    comp.printDemandsByCategory("Квартира");
    std::string outDemand = testing::internal::GetCapturedStdout();
    EXPECT_NE(outDemand.find("ЖК Солнечный"), std::string::npos);
}

TEST(RealEstateCompanyTest, PrintClientByPassportOrNameOutput) {
    RealEstateCompany comp;
    comp.addClient(Client("Иванов Иван Иванович", "4510 123456", "+79001112233"));

    testing::internal::CaptureStdout();
    comp.printClientByPassportOrName("4510 123456");
    std::string out1 = testing::internal::GetCapturedStdout();
    EXPECT_NE(out1.find("Иванов Иван Иванович"), std::string::npos);

    testing::internal::CaptureStdout();
    comp.printClientByPassportOrName("Неизвестный");
    std::string out2 = testing::internal::GetCapturedStdout();
    EXPECT_NE(out2.find("Клиент не найден"), std::string::npos);
}

TEST(RealEstateCompanyTest, PrintByPriceLocationAreaOutput) {
    RealEstateCompany comp;
    comp.addApartment(Apartment("ЖК Центральный", "Предложение", "Центр", 65.0, 9200000.0, 2, 7, 20));

    testing::internal::CaptureStdout();
    comp.printByPriceLocationArea("Предложение", 9200000.0, "Центр", 65.0);
    std::string out1 = testing::internal::GetCapturedStdout();
    EXPECT_NE(out1.find("ЖК Центральный"), std::string::npos);

    testing::internal::CaptureStdout();
    comp.printByPriceLocationArea("Предложение", 5000000.0, "Центр", 65.0);
    std::string out2 = testing::internal::GetCapturedStdout();
    EXPECT_NE(out2.find("Подходящих вариантов не найдено"), std::string::npos);
}

TEST(RealEstateCompanyTest, ProfitByPeriodCalculationAndOutput) {
    RealEstateCompany comp(5.0);
    comp.addDeal(DealRecord("Иванов И.И.", "15.10.2023", 10000000.0));
    comp.addDeal(DealRecord("Петров П.П.", "20.10.2023", 6000000.0));
    comp.addDeal(DealRecord("Сидоров С.С.", "05.11.2023", 8000000.0));

    EXPECT_DOUBLE_EQ(comp.calculateProfitByPeriod(".10.2023"), 800000.0);
    EXPECT_DOUBLE_EQ(comp.calculateProfitByPeriod(".11.2023"), 400000.0);
    EXPECT_DOUBLE_EQ(comp.calculateProfitByPeriod(".12.2023"), 0.0);

    testing::internal::CaptureStdout();
    comp.printProfitByPeriod(".10.2023");
    std::string out = testing::internal::GetCapturedStdout();
    EXPECT_NE(out.find("Итоговая прибыль:"), std::string::npos);
}

TEST(RealEstateCompanyTest, PrintMostPopularOutput) {
    RealEstateCompany comp;
    comp.addApartment(Apartment("Квартира Эконом", "Предложение", "Юг", 40.0, 4500000.0, 1, 2, 10));
    comp.addApartment(Apartment("Квартира Люкс", "Предложение", "Центр", 90.0, 15000000.0, 3, 10, 50));

    testing::internal::CaptureStdout();
    comp.printMostPopular("Предложение", 1);
    std::string out = testing::internal::GetCapturedStdout();

    EXPECT_NE(out.find("Квартира Люкс"), std::string::npos);
    EXPECT_EQ(out.find("Квартира Эконом"), std::string::npos);
}