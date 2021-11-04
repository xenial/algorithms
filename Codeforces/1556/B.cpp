#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int solve(vector<int> arr) {
    if (arr.size() == 1) return 0;
    int div = floor(arr.size() / 2);
    int odds = 0;
    for (auto n : arr) {
        if (n % 2 != 0) odds++;
    }
    if (odds != div && odds != div + 1) return -1;

    int swaps = 0;
    if (arr.size() % 2 != 0) div++;
    while (div--) {
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i-1] % 2 == arr[i] % 2) {
                swap(arr[i], arr[i+1]);
                swaps++;
                break;
            }
        }
    }
    return swaps;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr;
        while (n--) {
            int x; cin >> x;
            arr.push_back(x);
        }
        cout << solve(arr) << endl;
    }
}