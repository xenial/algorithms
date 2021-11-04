#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<int> a) {
    int modd = -1;
    for (int i = 0; i < a.size(); i++) {
        if (modd < 0) {
            if (a.at(i) % 2 == a.at(i + 1) % 2)
                modd = a.at(i) % 2;
            else if (a.at(i) % 2 == a.at(i + 2) % 2)
                return i + 1;
            else
                return i;
        }

        if (modd) {
            if (a.at(i) % 2 == 0)
                return i;
        }
        else if (a.at(i) % 2 != 0)
            return i;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int t, n;
    vector<int> a;
    cin >> t;
    while (t--) {
        cin >> n;
        a.push_back(n);
    }
    cout << (solve(a) + 1);
}