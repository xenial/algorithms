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

    ll ans = 0;
    for (int i = 0; i < 200; i++) {
        set<char> digits[10];
        vector<char> segments(10);
        vector<set<char>> fives, sixes;
        string in[10];
        for (int j = 0; j < 10; j++) {
            cin >> in[j];
            string s = in[j];
            int ss = in[j].sz();

            if (ss == 2) digits[1].insert(all(s));
            else if (ss == 3) digits[7].insert(all(s));
            else if (ss == 4) digits[4].insert(all(s));
            else if (ss == 5) fives.pb(set<char>(all(s)));
            else if (ss == 6) sixes.pb(set<char>(all(s)));
            else if (ss == 7) digits[8].insert(all(s));
        }

        for (int j = 0; j < sixes.sz(); j++) {
            auto s = sixes[j];
            auto buf = digits[7];
            for (auto c : s) {
                buf.erase(c);
            }
            if (buf.sz() == 1) {
                segments[2] = *buf.begin();
                digits[6] = s;
                sixes.erase(sixes.begin() + j);
            }
        }

        for (auto s : sixes) {
            auto temp = s;
            for (auto c : digits[4]) temp.erase(c);
            if (temp.sz() == 3) digits[0] = s;
            else digits[9] = s;
        }

        for (auto f : fives) {
            auto temp = digits[4];
            for (auto c : f) temp.erase(c);
            if (temp.sz() == 2) digits[2] = f;
            else if (*temp.begin() == segments[2]) digits[5] = f;
            else digits[3] = f;
        }

        string a(4, '*');
        for (int j = 0; j < 4; j++) {
            string s; cin >> s;
            sort(all(s));
            for (int k = 0; k < 10; k++) {
                string d(all(digits[k]));
                if (s == d) a[j] = '0' + k;
            }
        }
        ans += stoi(a);
    }
    cout << ans << endl;
}
