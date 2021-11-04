#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s) {
    string a;
    ll pc = 0, l = s.size(), j = 0, k = l - 1;
    map<char, ll> c;

    for (ll i = 'A'; i <= 'Z'; i++) {
        c.insert(pair<char, ll>((char)i, 0));
    }

    for (ll i = 0; i < l; i++) {
        c.find(s.at(i))->second += 1;
    }

    map<char, ll>::iterator it;
    for (map<char, ll>::iterator i = c.begin(); i != c.end(); i++) {
        if (i->second == 0)
            continue;
        if ((i->second % 2 != 0 && l % 2 == 0))
            return "NO SOLUTION";
        if (i->second % 2 != 0) {
            pc++;
            if (pc > 1)
                return "NO SOLUTION";
        }

        a.resize(l);
        ll prv = j;
        for (; j < prv + floor(i->second / 2); j++)
            a.at(j) = i->first;
        if (i->second % 2 != 0) 
            a.at(l / 2) = i->first;
        for (; k > l - floor(i->second / 2) - prv - 1; k--)
            a.at(k) = i->first;
    }
    if (pc == 0 && l % 2 != 0)
        return "NO SOLUTION";
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    cout << solve(s);
}