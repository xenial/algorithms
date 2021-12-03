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

    int x = 0, y = 0, aim = 0;
    for (int i = 0; i < 1000; i++) {
        string op; cin >> op;
        int n; cin >> n;

        if (op == "forward") {
            x += n;
            y += aim * n;
        }
        else if (op == "down") aim += n;
        else if (op == "up") aim -= n;
    }

    cout << x * y << endl;
}
