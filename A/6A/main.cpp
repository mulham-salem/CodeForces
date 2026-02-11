#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int arr[] = {a, b, c, d};

    sort(arr, arr + 4);

    a = arr[0];
    b = arr[1];
    c = arr[2];
    d = arr[3];

    if (a + b > c || a + c > d || b + c > d)
        cout << "TRIANGLE";

    else if (a + b == c || a + c == d || b + c == d)
        cout << "SEGMENT";

    else
        cout << "IMPOSSIBLE";


    return 0;
}
