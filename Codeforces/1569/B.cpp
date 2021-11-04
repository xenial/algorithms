#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

void print_matrix(vector<string> matrix) {
    cout << "YES" << endl;
    for (auto s : matrix) {
        cout << s << endl;
    }
}

void solve(string s) {
    vector<int> wins;
    vector<pair<int,int>> edges;

    for (int i = 0; i < s.size(); i++) {
        if ((int)(s[i] - '0') != 1) wins.pb(i);
    }

    vector<string> matrix(s.size(), string(s.size(), '='));
    for (int i = 0; i < s.size(); i++) matrix[i][i] = 'X';

    if (wins.size() == 0) {
        print_matrix(matrix);
        return;
    } else if (wins.size() < 3) {
        cout << "NO" << endl;
        return;
    } else {
        sort(all(wins));
        edges.pb({wins[wins.size()-1], wins[0]});
        for (int i = 0; i < wins.size() - 1; i++) {
            edges.pb({wins[i], wins[i+1]});
        }

        for (auto edge : edges) {
            matrix[edge.fi][edge.se] = '+';
            matrix[edge.se][edge.fi] = '-';
        }

        print_matrix(matrix);
        return;
    }
}

int main() {
    set_io("");

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        solve(s);
    }
}