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
#define vi vector<int>
#define vvi vector<vector<int>>
 
void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}
 
int N, M;
 
int main() {
	set_io("");
 
    cin >> N >> M;
    char map[N][M];
    vector<ii> cows;
 
    ii fc(-1, -1), lc(-1, -1);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            char c = map[i][j];
            if (c == '@')
                cows.pb(ii(i, j));
 
            if (c == '*' && fc == ii(-1, -1))
                fc = ii(i, j);
 
            if (map[i-1][j] == '*' && map[i][j-1] == '*')
                lc = ii(i, j);
        }
 
    int ans = 0;
    for (auto cow : cows) 
        if (cow.fi > fc.fi && cow.se > fc.se && cow.fi < lc.fi && cow.se < lc.se)
            ans++;
    
    cout << ans << endl;
}