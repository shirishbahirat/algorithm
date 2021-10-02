#include <iostream>

using namespace std;

typedef struct
{
  int day, month, year;
} date;

typedef struct
{
  date manu_date, purc_date;
  double purc_price;
} car;

typedef struct
{
  car tax_rate;
  string state;
} road_tax;

typedef void (*func)(int);

typedef void (*apo)(func);

int main(int argc, char const *argv[])
{

  car honda = {
      .manu_date.day = 10,
      .manu_date.month = 2,
      .manu_date.year = 2020,
      .purc_date.day = 22,
      .purc_date.month = 12,
      .purc_date.year = 2021,
      .purc_price = 22000,
  };

  car tesla = {
      .manu_date.day = 6,
      .manu_date.month = 9,
      .manu_date.year = 2021,
      .purc_date.day = 12,
      .purc_date.month = 3,
      .purc_date.year = 2020,
      .purc_price = 65000,
  };

  road_tax ca = {
      .state = "CA",
      .tax_rate.manu_date.day = 10,
      .tax_rate.manu_date.month = 2,
      .tax_rate.manu_date.year = 2020,
      .tax_rate.purc_date.day = 22,
      .tax_rate.purc_date.month = 12,
      .tax_rate.purc_date.year = 2021,
      .tax_rate.purc_price = 22000,
  };

  car toyata = {
      .manu_date.day = 6,
      .manu_date.month = 9,
      .manu_date.year = 2018,
      .purc_date.day = 12,
      .purc_date.month = 3,
      .purc_date.year = 2020,
      .purc_price = 20000,
  };

  return 0;
}