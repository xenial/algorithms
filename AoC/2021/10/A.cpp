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

int points[]{3, 57, 1197, 25137};

int main() {
    set_io("");
	
	int ans = 0;
	for (int i = 0; i < 106; i++) {
		string l;
		getline(cin, l);

		stack<int> s;
		for (auto c : l) {
			if (open(c)) s.push(find(c));
			else if (s.top() == find(c)) s.pop();
			else {
				ans += points[find(c)];
				break;
			}
		}
	}
	cout << ans << endl;
}
