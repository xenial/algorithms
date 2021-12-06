#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize
#define ii pair<int,int>

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

    vector<int> f(300);

    for (int i = 0; i < 300; i++) cin >> f[i];

    for (int i = 0; i < 80; i++) {
        int nb = 0;
        for (auto j = f.begin(); j != f.end(); j++) {
            if (!*j) {
                *j = 6;
                nb++;
            } else (*j)--;
        }

        while (nb--) f.pb(8);
    }

    cout << f.sz() << endl;
}
