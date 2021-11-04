#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define fstream

int solve(string a, string b) {
    int r = 0;
    bool row = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) row = true;
        else if (row) {
            row = false;
            r++;
        }
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    #ifdef fstream
    ifstream cin("breedflip.in");
    ofstream cout("breedflip.out");
    #endif

    

    int n; cin >> n;
    string a, b; cin >> a >> b;
    cout << solve(a, b);
}