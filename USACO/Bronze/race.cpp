#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define fstream

ll range_sum(int a, int b) {
    ll sum = 0;
    for (int i = a; i <= b; i++) sum += i;
    return sum;
}

int solve(int k, int x) {
    
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    #ifdef fstream
    ifstream cin("race.in"); 
	ofstream cout("race.out"); 
    #endif

    int k, n; cin >> k >> n;
    while (n--) {
        int x; cin >> x;
        cout << solve(k, x) << endl;
    }
}