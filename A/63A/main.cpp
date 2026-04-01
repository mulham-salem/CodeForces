#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    string captain;

    vector<string> rats;
    vector<string> women_children;
    vector<string> men;

    for (int i = 0; i < n; i++) {
        string name, status;
        cin >> name >> status;

        if (status == "rat") {
            rats.push_back(name);
        }
        else if (status == "woman" || status == "child") {
            women_children.push_back(name);
        }
        else if (status == "man") {
            men.push_back(name);
        }
        else if (status == "captain") {
            captain = name;
        }
    }

    for (auto r : rats)
        cout << r << "\n";

    for (auto w_c : women_children)
        cout << w_c << "\n";

    for (auto m : men)
        cout << m << "\n";

    cout << captain << "\n";

    return 0;
}
