#include <iostream>

using namespace std;

int main()
{
    const int nmax = 1000;
    int n, h;
    int ai[nmax];
    int sum = 0;


    cin >> n;
    cin >> h;
    cout << endl;

    for(int i=0; i<n; i++)
   {
     cin >> ai[i];

     if(ai[i] <= h)
      ai[i] = 1;
     else
      ai[i] = 2;

    sum+= ai[i];
   }
   cout << endl;
   cout << sum << endl;

    return 0;
}
