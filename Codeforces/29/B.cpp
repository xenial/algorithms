#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int solve(int n, vector<int> w) {
    int bstab = INT_MAX;
    sort(all(w));
    for (int i = 0; i < w.size(); i++) {
        for (int j = i + 1; j < w.size(); j++) {
            int stab = 0;
            vector<int> tw = w;
            tw.erase(tw.begin() + j);
            tw.erase(tw.begin() + i);
            for (int k = 0; k < tw.size(); k += 2) {
                stab += abs(tw[k + 1] - tw[k]);
            }
            bstab = min(stab, bstab);
        }
    }
    return bstab;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n; cin >> n;
    vector<int> weights;
    for (int i = 0; i < n * 2; i++) {
        int w; cin >> w;
        weights.push_back(w);
    }
    cout << solve(n, weights);
}