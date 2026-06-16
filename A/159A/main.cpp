#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

struct Message {
    string from, to;
    int time;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    vector<Message> messages(n);

    for (int i = 0; i < n; i++) {
        cin >> messages[i].from >> messages[i].to >> messages[i].time;
    }

    set<pair<string, string>> friends;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = messages[j].time - messages[i].time;

            if (diff > d)
                break;

            if (messages[i].from == messages[j].to &&
                messages[i].to == messages[j].from &&
                diff > 0) {

                string a = messages[i].from;
                string b = messages[i].to;

                if (a > b)
                    swap(a, b);

                friends.insert({a, b});
            }
        }
    }

    cout << friends.size() << '\n';

    for (auto &p : friends) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
