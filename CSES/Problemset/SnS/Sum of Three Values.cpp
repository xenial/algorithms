#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second

void solve(vector<int> arr, int x) {
    vector<pair<int,int>> comp;
    for (int i = 0; i < arr.size(); i++) comp.pb({arr[i], i});
    sort(all(comp));
    
    for (int k = 0; k < arr.size(); k++) {
        int i = 0, j = arr.size() - 1;
        while (i < j) {
            if (k == i || k == j) {
                k++;
                continue;
            }
            int s = comp[i].fi + comp[j].fi + comp[k].fi;
            if (s == x) {
                cout << comp[i].se + 1 << " " << comp[j].se + 1 << " " << comp[k].se + 1;
                return;
            } else if (s > x) j--;
            else i++;
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    vector<int> arr;
    int n, x; cin >> n >> x;
    while (n--) {
        int y; cin >> y;
        arr.pb(y);
    }
    solve(arr, x);
}