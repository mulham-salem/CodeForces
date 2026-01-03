#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int ansTotal = 0, ansDays = 0;

    while(a > 0 || b > 0)
    {
        if(a>0 && b>0)
        {
            a--;
            b--;
            ansTotal++;
        }
        else if(a==0 && b>=2)
        {
            b -= 2;
            ansDays++;
        }
        else if(b==0 && a>=2)
        {
            a -= 2;
            ansDays++;
        }
        else
            break;
    }
    cout << ansTotal << " " << ansDays;
    return 0;
}