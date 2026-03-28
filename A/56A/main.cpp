#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string alcohol[11] =
    {
        "ABSINTH", "BEER", "BRANDY",
        "CHAMPAGNE", "GIN", "RUM", "SAKE",
        "TEQUILA", "VODKA", "WHISKEY", "WINE"
    };

    string desc;
    int must_check = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> desc;

        if (isdigit(desc[0])) {
            int age = stoi(desc);
            if (age < 18) {
                must_check++;
            }
        }
        else {
            bool isAlcohol = false;
            for (int j = 0; j < 11; j++) {
                if (desc == alcohol[j]) {
                    isAlcohol = true;
                    break;
                }
            }

            if (isAlcohol) {
                must_check++;
            }
        }
    }

    cout << must_check << "\n";
    return 0;
}
