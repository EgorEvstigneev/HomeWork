#include <iostream>

using namespace std;

class Stack { // Класс стек
private:
  int *arr;
  int Max;
  int top;
public:
  Stack(int i){
    top = 0;
    Max = 100;
    if (i <= Max){
    arr = new int [i];
    Max = i;
    }
  }
  ~Stack()
  {
    delete[] arr;
  }

  bool Push(int i){
    if (top == Max)
      return false;
    else {
      arr[top] = i;
      top++;
      return true;
    }
  }
  int Pop(){
    if (top < 0)
      return 0;
    else {
        return arr[--top];

    }
  }

};

class Queue { // Класс очередь
private:
  int *arr;
  int Max;
  int top;
  int zero;
public:
  Queue(int i){
    zero = NULL;
    top = 0;
    Max = 100;
    if (i <= Max){
    arr = new int [i];
    Max = i;
    }
  }
  ~Queue()
  {
    delete[] arr;
  }

  bool Put(int i){
    if (top == Max)
      return false;
    else {
      arr[top] = i;
      top++;
      return true;
    }
  }
  int Get(){
    if (zero > Max)
      return 0;
    else
      return arr[zero++];

    }
};


int main()
{
    Stack st(2);
    st.Push(1);
    st.Push(2);
    cout << st.Pop() << endl;
    cout << st.Pop() << endl;

    Queue qu(2);
    qu.Put(3);
    qu.Put(4);
    cout << qu.Get() << endl;
    cout << qu.Get() << endl;

    return 0;
}
