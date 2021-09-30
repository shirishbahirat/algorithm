#include <iostream>

typedef struct
{
  int day, month, year;
} date;

typedef struct
{
  date manu_date, pur_date;
  double pur_price;
} car;

int main(int argc, char const *argv[])
{

  car honda;
  car tesla;

  return 0;
}