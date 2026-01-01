#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char ch;
    cin >> ch;

    string s1 = "qwertyuiopasdfghjkl;zxcvbnm,./";

    string s2;
    cin >> s2;

    char s3[100] = "";

    for(int i=0; i<s2.size(); i++)
    {
        for(int j=0; j<30; j++)
        {
            if(ch == 'R')
            {
                if(s2[i] == s1[j])
                {
                    s3[i] = s1[j-1];
                    cout << s3[i];

                    break;
                }

            }
            else if(ch == 'L')
            {
                if(s2[i] == s1[j])
                {
                    s3[i] = s1[j+1];
                    cout << s3[i];

                    break;
                }
            }
        }
    }
    return 0;
}