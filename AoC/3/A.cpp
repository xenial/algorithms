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

	string bits[1000];
	for (int i = 0; i < 1000; i++) {
		cin >> bits[i];
	}

	bitset<12> mc, lc;
	for (int i = 0; i < 12; i++) {
		int oc = 0, zc = 0;
		for (int j = 0; j < 1000; j++) {
			if (bits[j][i] == '1') oc++;
			else zc++;
		}
		if (oc > zc) {
			mc.set(11 - i, 1);
			lc.set(11 - i, 0);
		} else {
			mc.set(11 - i, 0);
			lc.set(11 - i, 1);
		}
	}
	cout << mc.to_ulong() * lc.to_ulong() << endl;
}
