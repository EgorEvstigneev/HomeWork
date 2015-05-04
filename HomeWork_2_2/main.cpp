#include <iostream>
#define MIN(x, y) (x < y) ? x : y

using namespace std;

int sum[10000];

void terms (int n, int a, int position){
    int i;
    if(n > 0){
    for(int i = 1; i <=a; i++){
        sum[position] = i;
        terms (n - i, MIN(i, n - i), position + 1);
    }
  }
  else{
    for(i = 0; i < position - 1; i++)
        cout << sum[i] << "+";
        cout << sum[i] << endl;
    }
  }



int main(){
    int n = 0;
    cout << "n = ";
    cin >> n;
    terms (n, n - 1,0);
    return 0;
}
