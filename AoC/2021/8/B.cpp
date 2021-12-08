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

    for (int i = 0; i < 200; i++) {
        set<char> digits[10];
        string in[10];
        for (int j = 0; j < 10; j++) {
            cin >> in[j];
            string s = in[j];
            int ss = in[j].sz();

            if (ss == 2) digits[1].insert(all(s));
            else if (ss == 3) digits[7].insert(all(s));
            else if (ss == 4) digits[4].insert(all(s));
            else if (ss == 7) digits[8].insert(all(s));
        }
        bool solved = false;
        int j = 0;
        while (!solved) {   
            string s = in[j];
            int ss = s.sz();
            if (ss == 5) {
                vector<int> pos {4, 9};
                for (auto k : pos) {
                    bool valid = true;
                    for (auto c : digits[k]) 
                        if (s.find(c) == s.npos) valid = false;
                    if (valid) digits[k].insert(all(s));
                }
            }

            if (j == 9)
                j = 0;
            else
                j++;
        }
        for (int j = 0; j < 4; j++) {
        }
    }

    int ans = 0;

    cout << ans << endl;
}
