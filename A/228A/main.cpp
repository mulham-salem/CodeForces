#include <iostream>

using namespace std;

int main()
{
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    int n = 0;

    if(s1==s2 && s2==s3 && s3==s4)
        n+=3;

    else if(s1==s2 && s3==s4)
        n+=2;

    else if(s1==s2 && s2==s3)
        n+=2;

    else if(s1==s4 && s2==s3)
        n+=2;

    else if(s1==s3 && s2==s4)
        n+=2;

    else if(s2==s3 && s3==s4)
        n+=2;

    else if(s1==s2 || s2==s3)
        n++;

    else if(s3==s4 || s2==s4)
        n++;

    else if(s1==s3 || s1==s4)
        n++;

    cout << n;
    return 0;
}