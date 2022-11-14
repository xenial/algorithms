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
 
int main() {
	set_io("");
 
    int ns[10], td = 0;
 
    for (int i = 0; i < 10; i++) {
        cin >> ns[i];
        td += ns[i];
    }
 
    int ans = 0;
    if (td == 1 && ns[2]) ans = 2;
    if (td == 1 && ns[6]) ans = 3;
    if (td == 2 && ns[4]) ans = 4;
    if (td == 3 && ns[1]) ans = 5;
    if (td == 3 && ns[7]) ans = 6;
    if (ans) {
        cout << ans << endl;
        return 0;
    }
 
    double d = 0;
    int x = 1;
    while (true) {
        d += log10(x);
        if (floor(d) + 1 == td) {
            ans = x;
            break;
        }
        x++;
    }
 
    cout << ans << endl;
}