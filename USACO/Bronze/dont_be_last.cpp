#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define fstream

string solve(map<string,int> cows) {
    int s = INT_MAX, ss = INT_MAX, sc = 0;
    string r = "Tie";
    for (auto cow : cows) {
        s = min(s, cow.second);
    }
    for (auto cow : cows) {
        if (cow.second > s) {
            ss = min(ss, cow.second);
        }
    }
    for (auto cow : cows) {
        if (cow.second == ss) {
            sc++;
            r = cow.first;
        }
        if (sc > 1)
            return "Tie";
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    #ifdef fstream
    ifstream cin("notlast.in");
    ofstream cout("notlast.out");
    #endif

    map<string, int> cows {
        {"Bessie", 0},
        {"Elsie", 0},
        {"Daisy", 0},
        {"Gertie", 0},
        {"Annabelle", 0},
        {"Maggie", 0},
        {"Henrietta", 0}
    };

    int n; cin >> n;
    while (n--) {
        string name; cin >> name;
        int prod; cin >> prod;
        cows[name] += prod;
    }
    cout << solve(cows);
}