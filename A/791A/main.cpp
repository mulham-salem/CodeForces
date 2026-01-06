#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int counter = 0;
    cin >> a;
    cin >> b;
    while(a <= b)
  {
    a = a * 3;
    b = b * 2;
    counter++;
  }
  cout << endl;
  cout << counter << endl;

    return 0;
}
