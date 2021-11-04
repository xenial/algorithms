#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

int solve(vector<int> e_cards) {
    vector<int> cards;
    for (int i = 1; i <= e_cards.sz() * 2; i++) cards.pb(i);

    set<int> b_cards(all(cards));
    for (auto card : e_cards) b_cards.erase(card);

    vector<int> highest(e_cards.begin(), e_cards.begin() + e_cards.sz() / 2);
    vector<int> lowest(e_cards.begin() + e_cards.sz() / 2, e_cards.end());
    sort(all(highest), greater<int>());
    sort(all(lowest));

    int ans = 0;
    for (auto card : lowest) {
        auto it = b_cards.begin();
        if (*it > card) continue;

        b_cards.erase(it);
        ans++;
    }
    for (auto card : highest) {
        auto it = b_cards.upper_bound(card);
        if (it == b_cards.end()) {
            continue;
        }

        b_cards.erase(it);
        ans++;
    }
    
    return ans;
}

int main() {
    set_io("cardgame");

    int n; cin >> n;
    vector<int> cards;
    while (n--) {
        int x; cin >> x;
        cards.pb(x);
    }
    cout << solve(cards);
}