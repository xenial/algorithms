#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(int w) {
    if (w < 3)
        return false;
    return (w % 2 == 0 ? true : false);
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int a;
    cin >> a;
    cout << (solve(a) ? "YES" : "NO");
}