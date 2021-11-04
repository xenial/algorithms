#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

vector<int> solve(string b) {
    int div = floor(b.size() / 2), zi;
    for (int i = 1; i <= div; i++) {
        if (b[i - 1] == '0') return vector<int>{i, (int)b.size(), i + 1, (int)b.size()};
    }
    for (int i = div + 1; i <= b.size(); i++) {
        if (b[i - 1] == '0') return vector<int>{1, i, 1, i - 1};
    }

    return vector<int>{1, (int)b.size() - 1, 2, (int)b.size()};
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string b; cin >> b;
        vector<int> ranges = solve(b);
        for (auto r : ranges) cout << r << " ";
        cout << endl;
    }
}