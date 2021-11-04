#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define fstream

ll prefix[50001];

int solve(int n) {
    vector<int> l(7), r(7);
    for (int i = 1; i <= n; i++) {
        prefix[i] %= 7;
        if (!l[prefix[i]]) l[prefix[i]] = i;
        r[prefix[i]] = i;
    }
    int maxsz = 0;
    for (int i = 0; i < l.size(); i++) maxsz = max(r[i] - l[i], maxsz);
    return maxsz;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    #ifdef fstream
    ifstream cin("div7.in"); 
	ofstream cout("div7.out"); 
    #endif

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }
    cout << solve(n);
}