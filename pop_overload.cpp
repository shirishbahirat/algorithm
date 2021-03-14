#include <iostream>
using namespace std;

class complex
{
public:
  complex(int a, int b) : real(a), imag(b) {}

  int get_real() { return real; }
  int get_imag() { return imag; }

private:
  int real;
  int imag;
};

complex &operator+(complex &x, complex &y)
{
  int r = x.get_real() + y.get_real();
  int i = x.get_imag() + y.get_imag();

  complex temp = complex(r, i);

  return temp;
}

int main(int argc, char const *argv[])
{
  complex *x = new complex(5, 10);
  complex *y = new complex(20, 25);

  complex z = *x + *y;

  cout << z.get_real() << " " << z.get_imag() << endl;

  return 0;
}