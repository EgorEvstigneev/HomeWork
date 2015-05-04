#include <iostream>
#include <cmath>

using namespace std;

struct Point{
    int x, y;
};

typedef Point Vector;

void sum(Vector A, Vector B){
    Point O;
    O.x = A.x + B.x;
    O.y = A.y + B.y;
    cout << "Sum (o.x = " << O.x << "; O.y = " << O.y << ") \n";
}

void diff(Vector A, Vector B){
    Point O;
    O.x = B.x - A.x;
    O.y = B.y - A.y;
    cout << "Difference (o.x = " << O.x << "; O.y = " << O.y << ") \n";
}

void dot_prod(Vector A, Vector B){
    cout << "Dot product = " << (A.x * B.x) + (A.y * B.y) << endl;
}

void dist(Vector A, Vector B){
    cout << "Distance between = " << sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2)) << endl;
}

int main(){
    Vector A, B;

    cout << "Please enter coordinates of vectors A and B: \n"
    << "A.x = ";
    cin >> A.x;
    cout << "A.y = ";
    cin >> A.y;
    cout << "B.x = ";
    cin >> B.x;
    cout << "B.y = ";
    cin >> B.y;
    if(cin){
    sum(A, B);
    diff(A, B);
    dot_prod(A, B);
    dist(A, B);
    }
    else{
    cout << "\nStop it!";
    }
    return 0;
}
