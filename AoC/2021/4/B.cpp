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


bool marked[100][5][5];
int vals[100][5][5];

int main() {
    set_io("");

    vector<int> marks(100);
    for (int i = 0; i < 100; i++) cin >> marks[i];

    unordered_map<int, vector<pair<int, ii>>> locs;
    for (int i = 0; i < 100; i++) 
        for (int y = 0; y < 5; y++)
            for (int x = 0; x < 5; x++) {
                int n; cin >> n;
                locs[n].pb({i, {x, y}});
                vals[i][x][y] = n;
            }
    
    set<int> won;
    for (auto mark : marks) {
        for (auto board : locs[mark]) {
            int i = board.fi, x = board.se.fi, y = board.se.se;
            marked[i][x][y] = true;
            if (won.count(i) > 0) continue;

            bool fr = true, fc = true;
            for (int j = 0; j < 5; j++) {
                if (marked[i][j][y] != true) fr = false;
                if (marked[i][x][j] != true) fc = false;
            }
            if (!fr && !fc) continue;

            won.insert(i);
            if (won.sz() != 100) continue;

            int sum = 0;
            for (int y = 0; y < 5; y++) {
                for (int x = 0; x < 5; x++) {
                    if (!marked[i][x][y]) sum += vals[i][x][y];
                }
            }
            cout << sum * mark << endl;
            return 0;
        }
    }
}
