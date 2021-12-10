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

int N, T; 
unsigned long long speeds[200005];

bool check(unsigned long long t) {
    unsigned long long total = 0;
    for (int i = 0; i < N; i++) 
        total += t / speeds[i];
    return total >= T;
}

int main() {
    set_io("");

    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> speeds[i];
    }

    unsigned long long l = 1, r = 1e18;
    while (l + 1 < r) {
        unsigned long long m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    cout << r << endl;
}
