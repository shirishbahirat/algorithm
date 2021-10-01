#include <iostream>

typedef struct
{
  int day, month, year;
} date;

typedef struct
{
  date manu_date, purc_date;
  double purc_price;
} car;

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

  car toyata = {
      .manu_date.day = 6,
      .manu_date.month = 9,
      .manu_date.year = 2018,
      .purc_date.day = 12,
      .purc_date.month = 3,
      .purc_date.year = 2020,
      .purc_price = 25000,
  };
  return 0;
}