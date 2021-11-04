#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(int n, vector<int> a) {
    vector<int> path;
    vector<int>::iterator it = find(a.begin(), a.end(), 1);

    if (it == a.end()) {
        for (int i = 1; i <= n + 1; i++)
            path.push_back(i);
        return path;
    } else {
        for (int i = 0; i < n; i++) {
            int first = it - a.begin();

            if (i == first) {
                path.push_back(n + 1);
                path.push_back(i + 1);
            } else {
                path.push_back(i + 1);
            }
        }
    }

    return path;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int t;

    cin >> t;
    while (t--) {
        int n;
        vector<int> a, r;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int n2;
            cin >> n2;
            a.push_back(n2);
        }
        r = solve(n, a);
        for (auto n : r)
            cout << n << " ";
        cout << endl;
    }
}