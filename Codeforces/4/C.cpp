#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(vector<string> a) {
    vector<string> t;
    vector<int> tc;
    
    for (auto s : a) {
        vector<string>::iterator it = find(t.begin(), t.end(), s);
        if (it == t.end()) {
            cout << "OK" << endl;
            t.push_back(s);
            tc.push_back(1);
            continue;
        } else {
            int i = it - t.begin();
            cout << t.at(i) << tc.at(i) << endl;
            tc.at(i)++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int t;
    vector<string> a;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        a.push_back(s);
    }
    solve(a);
}