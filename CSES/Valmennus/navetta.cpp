#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int main() {
    set_io("");

    int n, m; cin >> n >> m;

    map<int, bool> cows;
    while (m--) {
        char op; int cow; cin >> op >> cow;
        if (op == '?') cout << (cows[cow] ? "10-4" : "QAQ") << endl;
        else if (op == '+') cows[cow] = true;
        else if (op == '-') cows[cow] = false;
    }
}