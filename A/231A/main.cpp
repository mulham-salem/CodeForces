#include <iostream>

using namespace std;

int main()
{
    int n;
    int a, b, c;
    int counter = 0;
    cin >> n;
    cout << endl;
    for(int i=0; i<n; i++)
    {
      cin >> a >> b >> c;
      if(a == 1 && b == 1)
      counter++;

      else if(a == 1 && c == 1)
      counter++;

      else if(b == 1 && c == 1)
      counter++;

      cout << endl;
    }
    cout << endl;
    cout << counter << endl;
    return 0;
}
