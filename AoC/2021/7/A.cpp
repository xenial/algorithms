#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size
#define rsz resize
#define ii pair<int,int>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

vector<int> in(1000);
int fc(int p) {
	int ans = 0;
	for (auto n : in) ans += abs(n - p);
	return ans;
}

int main() {
    set_io("/home/xenial/Workspace/algorithms/AoC/7/x");

	for (int i = 0; i < 1000; i++) cin >> in[i];

	int prev = fc(0);
	for (int i = 1; i < 10000; i++) {
		int cur = fc(i);
		if (prev <= cur) {
			cout << prev << endl;
			break;
		}
		prev = cur;
	}
}
