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

int decode(char c) {
	if ('A' <= c && c <= 'Z') {
		return c - 'A';
	} else if ('a' <= c && c <= 'z') {
		return 26 + c - 'a';
	} else if ('0' <= c && c <= '9') {
		return 52 + c - '0';
	} else if (c == '+') return 62;
	return 63;
}

char encode(int n) {
	if (0 <= n && n <= 25) {
		return 'A' + n;
	} else if (26 <= n && n <= 51) {
		return 'a' + n - 26;
	} else if (52 <= n && n <= 61) {
		return '0' + n - 52;
	} else if (n == 62) return '+';
	return '/';
}

int n; 
bool check(vector<vector<int>> &Ad, vector<vector<int>> &Xd, int x, int y) {
	int r = 0;
	for (int k = 0; k < n; k++) {
		r = r % 64 + Ad[x][k] * Ad[y][k] % 64;
	}
	if (r == Xd[x][y]) return true;
	return false;
}

int main() {
    set_io("");

	int t; cin >> t;
	
	while (t--) {
		cin >> n;
		vector<vector<int>> A(n, vector<int>(n)), X(n, vector<int>(n));
		vector<vector<int>> Ad(n, vector<int>(n)), Xd(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char x; cin >> x;
				A[j][i] = x;
				Ad[j][i] = decode(x);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char x; cin >> x;
				X[j][i] = x;
				Xd[j][i] = decode(x);
			}
		}
		
		bool valid = true;
		for (int i = 0; i < 10; i++) {
			int x = rand() % n, y = rand() % n;
			if (!check(Ad, Xd, x, y)) valid = false;
		}
		cout << valid << endl;
	}
}
