#include <iostream>
#include <cmath>

using namespace std;

/// После разбора домашнего задания на уроке, мне понравилось
/// как Вы реализовали её части так , что я изменил программу
/// сделав её более похожеё на Вашу , но оставив свои части.

int NOD(int x, int y){
  if (y == 0)
    return x;
  return NOD(y, x % y);
}

class Rational {
  int num, deno;

  void reduction() {
    int r = NOD(num, deno);
    num /= r;
    deno /= r;

    if(deno < 0) {
      num = abs(num);
      deno = abs(deno);
    }
  }

 public:
  Rational(int num1, int deno1) : num(num1), deno(deno1) {
    reduction();
  };

  Rational(const char* message){
    cout << message << endl;
    char op; // переменная оператора
    int ch, zn; // числитель и знаменатель второй (возможной) дроби
    cout << "Numerator = ";
    cin >> num;
    cout << "Denominator = ";
    cin >> deno;
    //Можно ввести еще одну дробь и сложить её с уже имеющейся дробью, либо отнять её
    cout << "Enter (+) to add another rational, (-) to subtract another rational, " << endl ;
    cout << "or (=)to reduct your rational(after + or - your rational will be reduct): ";
    cin >> op;
    if (op == '=')
    reduction();
    else if (op == '+'){
    cout << "Enter numerator and denominator to add it to your first rational: " << endl;
    cout << "Numerator: ";
    cin >> ch;
    cout << "Denominator: ";
    cin >> zn;
        num = (num * zn) + (ch * deno);
        deno = deno * zn;
    }
      else if(op == '-'){
    cout << "Enter numerator and denominator to subtract it to your first rational: " << endl;
    cout << "Numerator: ";
    cin >> ch;
    cout << "Denominator: ";
    cin >> zn;
        num = (num * zn) - (ch * deno);
        deno = deno * zn;
      }
      reduction();
    }

  void show(ostream& os = cout) const {
    int r = NOD(num, deno);
    int num2 = num / r;
    int deno2 = deno / r;

    if(deno2 < 0) {
      num2 = abs(num2);
      deno2 = abs(deno2);
    }

    if(deno2 == 1)
      os << num2;
    else {
      int igr = num2 / deno2;

      if(igr != 0)
        os << igr << " ";
      else if(num2 < 0)
        os << "-";
      num2 -= igr * deno2;
      num2 = abs(num2);
      os << num2 << "/" << deno2;
    }
  }

  Rational operator+(Rational& r) {
    return Rational(num * r.deno + r.num * deno,deno * r.deno);
  }

  Rational operator+(int right) {
    return Rational(num + right * deno, deno);
  }

  friend Rational
  operator+(long left, Rational& r) {
    return Rational(left * r.deno + r.num, r.deno);
  }

  Rational operator-(Rational& r) {
    return Rational(num * r.deno - r.num * deno, deno * r.deno);
  }

};

int main() {
  Rational a(-9, 3), b(13, 7);
  cout << "a: "; a.show(); cout << endl;
  cout << "b: "; b.show(); cout << endl;

  int i = 24;

  Rational c = i + b;

  cout << "c: "; c.show(); cout << endl;

   Rational d("Please enter numerator and denominator: ");
   cout << "d: "; d.show(); cout << endl;

  return 0;
}
