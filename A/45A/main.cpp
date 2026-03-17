#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string month;
    cin >> month;

    int k;
    cin >> k;

    vector<string> months =
    {
        "January", "February", "March",
        "April", "May", "June", "July",
        "August", "September", "October",
        "November", "December"
    };

    int index = 0;

    for (int i = 0; i < 12; i++) {
        if (months[i] == month) {
            index = i;
            break;
        }
    }

    index = (index + k) % 12;

    cout << months[index];

    return 0;
}
