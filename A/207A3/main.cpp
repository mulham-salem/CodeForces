#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Problem {
    long long val;
    int group_id;
    int scientist_id;

    bool operator<(const Problem& other) const {
        if (group_id != other.group_id) {
            return group_id < other.group_id;
        }
        if (val != other.val) {
            return val < other.val;
        }
        return scientist_id < other.scientist_id;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    struct ScientistInput {
        long long k, a1, x, y, m;
    };
    vector<ScientistInput> scientists(n);

    long long total_problems = 0;
    for (int i = 0; i < n; ++i) {
        cin >> scientists[i].k >> scientists[i].a1 >> scientists[i].x >> scientists[i].y >> scientists[i].m;
        total_problems += scientists[i].k;
    }

    if (total_problems <= 200000) {
        vector<Problem> all_problems;
        all_problems.reserve(total_problems);

        for (int i = 0; i < n; ++i) {
            long long k = scientists[i].k;
            long long current_val = scientists[i].a1;
            long long x = scientists[i].x, y = scientists[i].y, m = scientists[i].m;
            int group = 0;

            all_problems.push_back({current_val, group, i + 1});

            for (int j = 2; j <= k; ++j) {
                long long next_val = (current_val * x + y) % m;
                if (next_val < current_val) {
                    group++;
                }
                all_problems.push_back({next_val, group, i + 1});
                current_val = next_val;
            }
        }

        sort(all_problems.begin(), all_problems.end());

        int bad_pairs = 0;
        for (size_t i = 1; i < all_problems.size(); ++i) {
            if (all_problems[i].val < all_problems[i - 1].val) {
                bad_pairs++;
            }
        }

        cout << bad_pairs << "\n";
        for (const auto& prob : all_problems) {
            cout << prob.val << " " << prob.scientist_id << "\n";
        }
    }
    else {
        int max_global_group = 0;

        for (int i = 0; i < n; ++i) {
            long long k = scientists[i].k;
            long long current_val = scientists[i].a1;
            long long x = scientists[i].x;
            long long y = scientists[i].y;
            long long m = scientists[i].m;

            int group = 0;

            for (int j = 2; j <= k; ++j) {
                long long next_val = (current_val * x + y) % m;

                if (next_val < current_val)
                    group++;

                current_val = next_val;
            }

            max_global_group = max(max_global_group, group);
        }

        cout << max_global_group << "\n";
    }
    return 0;
}
