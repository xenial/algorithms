#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
//#define fstream

vector<int> stacks;

int solve(int n) {
    for (int i = 1; i <= n; i++) {
        stacks[i] += stacks[i - 1];
    }
    sort(all(stacks));
    return stacks[ceil(n / 2)];
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    #ifdef fstream
    ifstream cin("stacking.in"); 
	ofstream cout("stacking.out"); 
    #endif

    int n, k; cin >> n >> k;
    stacks = vector<int>(n);
    while (k--) {
        int a, b; cin >> a >> b;
        stacks[min(a, b)]++;
        stacks[max(a, b) + 1]--;
    }
    cout << solve(n);
}