#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Team {
    int points = 0;
    int goals_scored = 0;
    int goals_against = 0;
};

map<string, Team> teams;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        teams[name] = Team();
    }

    int total_matches = n * (n - 1) / 2;

    for (int i = 0; i < total_matches; i++) {
        string teams_part, score_part;
        cin >> teams_part >> score_part;

        int dash_pos = teams_part.find('-');
        string team1 = teams_part.substr(0, dash_pos);
        string team2 = teams_part.substr(dash_pos + 1);

        int colon_pos = score_part.find(':');
        int goals1 = stoi(score_part.substr(0, colon_pos));
        int goals2 = stoi(score_part.substr(colon_pos + 1));

        teams[team1].goals_scored += goals1;
        teams[team1].goals_against += goals2;

        teams[team2].goals_scored += goals2;
        teams[team2].goals_against += goals1;

        if (goals1 > goals2) {
            teams[team1].points += 3;
        }
        else if (goals1 < goals2) {
            teams[team2].points += 3;
        }
        else {
            teams[team1].points += 1;
            teams[team2].points += 1;
        }
    }

    vector<pair<string, Team>> ranking(teams.begin(), teams.end());

    sort(ranking.begin(), ranking.end(), [](auto &a, auto &b) {

        Team t1 = a.second;
        Team t2 = b.second;

        if (t1.points != t2.points)
            return t1.points > t2.points;

        int diff1 = t1.goals_scored - t1.goals_against;
        int diff2 = t2.goals_scored - t2.goals_against;

        if (diff1 != diff2)
            return diff1 > diff2;

        return t1.goals_scored > t2.goals_scored;
    });

    vector<string> qualified;

    for (int i = 0; i < n / 2; i++) {
        qualified.push_back(ranking[i].first);
    }

    sort(qualified.begin(), qualified.end());

    for (auto &name : qualified)
        cout << name << endl;

    return 0;
}
