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

bool open(char c) {
	return c == '(' || c == '[' || c == '{' || c == '<';
}

int find(char c) {
	if (c == '(' || c == ')') return 0;
	if (c == '[' || c == ']') return 1;
	if (c == '{' || c == '}') return 2;
	return 3;
}

int points[]{1, 2, 3, 4};

int main() {
    set_io("");
	
	vector<ll> ans;
	for (int i = 0; i < 106; i++) {
		string l;
		getline(cin, l);

		stack<int> s;
		bool corrupted = false;
		for (auto c : l) {
			if (open(c)) s.push(find(c));
			else if (s.top() == find(c)) s.pop();
			else {
				corrupted = true;
				break;
			}
		}

		if (corrupted) continue;

		ll ts = 0;
		while (s.sz() > 0) {
			ts *= 5;
			ts += points[s.top()];
			s.pop();
		}
		ans.pb(ts);
	}
	sort(all(ans));
	cout << ans[ans.sz() / 2] << endl;
}
