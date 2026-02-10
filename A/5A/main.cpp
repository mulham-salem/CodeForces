#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    long long traffic = 0;
    int current_users_count = 0;
    int message_length = 0;

    while (getline(cin, s))
    {
        if (!s.empty() && s[0] == '+') {
            current_users_count++;
        } else if (!s.empty() && s[0] == '-') {
            current_users_count--;
        } else {
            size_t pos = s.find(":");
            string message = s.substr(pos + 1);
            message_length = message.length();
            traffic += message_length * current_users_count;
        }
    }
    cout << traffic;

    return 0;
}
