#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

pair<int, int> get_breaks(string wins) {
    pair<int, int> breaks;
    int counter = 0;
    bool aserving = true;    
    for (auto c : wins) {
        if ((c == 'b' && aserving) || (c == 'a' && !aserving))
            counter++;
        aserving = !aserving;
    }
    breaks.first = counter;
    counter = 0;
    aserving = false;
    for (auto c : wins) {
        if ((c == 'b' && aserving) || (c == 'a' && !aserving))
            counter++;
        aserving = !aserving;
    }
    breaks.second = counter;
    return breaks;
}

set<int> solve(int a, int b) {
    set<int> breaks;
    string wins;
    for (int i = 0; i < a; i++) {
        wins.push_back('a');
    }
    for (int i = 0; i < b; i++) {
        wins.push_back('b');
    }

    sort(all(wins));
    do {
        pair<int,int> wbreaks = get_breaks(wins);
        breaks.insert(wbreaks.first);
        breaks.insert(wbreaks.second);
    } while(next_permutation(all(wins)));

    return breaks;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        set<int> breaks = solve(a, b);
        cout << breaks.size() << endl;
        for (auto b : breaks) {
            cout << b << " ";
        }
        cout << endl;
    }
}