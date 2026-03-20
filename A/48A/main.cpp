#include <iostream>

using namespace std;

bool check(string ch1, string ch2) {
    if (ch1 == "scissors" && ch2 == "paper")
        return true;
    else if (ch1 == "paper" && ch2 == "rock")
        return true;
    else if (ch1 == "rock" && ch2 == "scissors")
        return true;
    return false;

}

int main() {
    string F, M, S;
    cin >> F >> M >> S;

    if (M == S && check(F, M))
        cout << "F" << "\n";
    else if (F == S && check(M, F))
        cout << "M" << "\n";
    else if (F == M && check(S, F))
        cout << "S" << "\n";
    else
        cout << "?" << "\n";
    return 0;
}
