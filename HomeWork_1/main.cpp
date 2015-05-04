#include <iostream>
#include <cmath>

using namespace std;

void solve_equation(double a, double b, double c) {
    if(cin){
    //Бесконечное множество(Все нули)
    if (a == 0 && b == 0 && c == 0)
    cout << "Equation " << a << "*x^2 + " << b << "*x + " << c << " = 0"
    << " has infinitely many solutions." << endl;

    //Не имеет решения(Все нули кроме С)
    if (a == 0 && b == 0 && c != 0)
    cout << "Equation " << a << "*x^2 + " << b << "*x + " << c << " = 0"
    << " has no solution." << endl;

    //Линейное уравнение(А равен нулю)
    if (a == 0 && b != 0 && c != 0){
        double x = -c / b;
        cout << "In equation " << a << "*x^2 + " << b << "*x + " << c << " = 0"
        << ", x = " << x << "." << endl;
    }

    if (a != 0 && b == 0 && c != 0)
    {
        double x = sqrt(a / b);
        cout << "In equation " << a << "*x^2 + " << b << "*x + " << c << " = 0"
        << ", x = " << x << "." << endl;

    }

    if (a != 0 && b != 0 && c != 0){

    double d, x1, x2;
    d = pow(b, 2) - (4 * a * c);

    //Действительные корни
    if (d >= 0)
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);

        cout << "In equation " << a << "*x^2 + " << b << "*x + " << c << " = 0"
        << ", x1 = " << x1 << " and " << "x2 = " << x2 << "." << endl;
    }

    //Комплексные корни
    else
    {
        cout << "Equation " << a << "*x^2 + " << b << "*x + " << c << " = 0"
        << " has no real roots but it has complex roots that equals, ";
        double bComplex = -b / (2 * a);
        d = fabs(-d);
        x1 = sqrt(d);
        x2 = sqrt(d);
        cout << "x1 = " << bComplex << " + " << x1 << "*i" " and "
        << "x2 = " << bComplex << " + " << x2 << "*i." << endl;

    }
   }
  }
  else
    cout << "Why did you do it?! :( I asked you for coefficients not for words or letters.";
 }

int main() {

  double a, b, c;
  cout << "Please enter your coefficients: " << endl;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  cout << "c = ";
  cin >> c;
  cout << endl;

  solve_equation(a, b, c);

  return 0;
}
