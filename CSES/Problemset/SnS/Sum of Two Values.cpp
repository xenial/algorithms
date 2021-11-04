#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

void solve(vector<int> arr, int x) {
    vector<pair<int,int>> comp;
    for (int i = 0; i < arr.size(); i++) {
        comp.push_back({arr[i], i});
    }
    sort(all(comp));
    int i = 0, j = comp.size() - 1;
    while (i < j) {
        if (comp[i].first + comp[j].first > x) j--;
        else if (comp[i].first + comp[j].first == x) {
            cout << comp[i].second + 1 << " " << comp[j].second + 1;
            return;
        } else i++;
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> arr;
    while (n--) {
        int y; cin >> y;
        arr.push_back(y);
    }
    solve(arr, x);
}