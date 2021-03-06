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
#define vi vector<int>
#define vvi vector<vector<int>>

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int N;

int main() {
	set_io("");

    cin >> N;
    vector<int> arr(N + 1), ans(N + 1);
    for (int i = 1; i <= N; i++) cin >> arr[i];

    stack<int> s;
    for (int i = 1; i <= N; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
        if (!s.empty()) ans[i] = s.top();

        s.push(i);
    }

    for (int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << endl;
}
