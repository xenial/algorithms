#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

vector<int> arr;

ll solve(int l, int r) {
    if (arr.size() == 2) return 1;

    int open = 0;
    ll odds = 0, evens = 0, subs = 0;
    for (int i = l; i <= r; i++) {
        if (!open && i % 2 == 0) continue;
        if (!open && i % 2 != 0) open = i;
        if (i % 2 != 0) odds += arr[i-1]; 
        else evens += arr[i-1];

        if (open && i == r) {
            
        }

        if (evens >= odds) {
            subs++;
            subs += solve(open, i);
            evens = odds = open = 0;
        }
    }
    return subs;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        arr.push_back(x);
    }
    cout << solve(1, arr.size()) << endl;
}