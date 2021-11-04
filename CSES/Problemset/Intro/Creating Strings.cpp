#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> solve(string s) {
    vector<string> u;
    sort(s.begin(),  s.end());

    do {
        u.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    
    return u;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    string s;
    vector<string> a;
    cin >> s;

    a = solve(s);
    cout << a.size() << endl;
    for (auto i : a)
        cout << i << endl;
}