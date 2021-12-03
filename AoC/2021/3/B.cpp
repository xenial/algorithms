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

int main() {
    set_io("/home/xenial/Workspace/algorithms/AoC/3/A");

	vector<string> bits(1000);
	for (int i = 0; i < 1000; i++) {
		cin >> bits[i];
	}
	
	vector<string> ans[2];
	ans[0] = ans[1] = bits;

	for (int i = 0; i < 2; i++) {
		int j = 0;
		while (ans[i].sz() > 1) {
			int oc = 0;
			for (auto s : ans[i])
				if (s[j] == '1') oc++;
			
			char lb;
			lb = '0' + (int)(oc >= ans[i].sz() - oc);

			vector<string> buf;
			for (auto s : ans[i]) {
				if (i == 0) {
					if (s[j] == lb) buf.pb(s);
				} else {
					if (s[j] != lb) buf.pb(s);
				}
			}

			ans[i] = buf;
			j++;
		}
	}

	bitset<12> a1(ans[0][0]), a2(ans[1][0]);
	cout << a1.to_ulong() * a2.to_ulong() << endl;
}
