#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   string n;
   cin >> n;
   int counter = 0;
   int l = n.length();

   sort(n.begin(), n.end());

   for(int i=0; i<l; i++)
   {
     if(n[i] != n[i+1])
        counter++;
   }
   if(counter % 2 == 0)
    cout << "CHAT WITH HER!";
   else
    cout << "IGNORE HIM!";

    return 0;
}
