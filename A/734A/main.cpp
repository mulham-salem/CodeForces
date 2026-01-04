#include <iostream>

using namespace std;

int main()
{
    double n;
    char ad;
    int counter1 = 0;
    int counter2 = 0;

    cin >> n;
    for(int i=0; i<n; i++)
    {
      cin >> ad;

      if(ad == 'A')
       counter1++;
      else
       counter2++;
    }
    if(counter1 > counter2)
     cout << "Anton" << endl;

    else if(counter1 < counter2)
     cout << "Danik" << endl;

    else
     cout << "Friendship" << endl;

    return 0;
}
