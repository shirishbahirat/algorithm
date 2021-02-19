#include <iostream>
using namespace std;

class ParkingSystem
{
public:
  ParkingSystem(int big, int medium, int small)
      : big_car_capacity(big), medium_car_capacity(medium),
        small_car_cpacity(small), big_cars(0), medium_cars(0), small_cars(0)
  {
  }

  bool addCar(int carType)
  {

    bool status = false;

    switch (carType)
    {
    case 1:
      if (big_cars < big_car_capacity)
      {
        big_cars++;
        status = true;
      }
      break;
    case 2:
      if (medium_cars < medium_car_capacity)
      {
        medium_cars++;
        status = true;
      }
      break;
    case 3:
      if (small_cars < small_car_cpacity)
      {
        small_cars++;
        status = true;
      }
      break;
    default:
      status = false;
    }

    return status;
  }

private:
  int big_car_capacity;
  int medium_car_capacity;
  int small_car_cpacity;

  int big_cars;
  int medium_cars;
  int small_cars;
};

int main(int argc, char const *argv[])
{
  ParkingSystem *obj = new ParkingSystem(2, 2, 2);

  obj->addCar(1);

  return 0;
}
