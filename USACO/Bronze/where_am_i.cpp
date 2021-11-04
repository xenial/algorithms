#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define fstream

int solve(string colors) {
    int r;
    for (int k = 0; k < colors.size(); k++) {
        bool valid = true;
        set<string> t_colors;
        for (int i = 0; i < colors.size(); i++) {
            string cur_sq = colors.substr(i, k);
            if (t_colors.count(cur_sq) <= 0) t_colors.insert(cur_sq);
            else {
                valid = false;
                break;
            }
        }
        if (valid) {
            r = k;
            break;
        }
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    #ifdef fstream
    ifstream cin("whereami.in");
    ofstream cout("whereami.out");
    #endif

    int n; cin >> n;
    string colors; cin >> colors;

    cout << solve(colors);
}