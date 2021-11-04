#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fstream

vector<string> solve(vector<pair<string,string>> orders) {
    vector<string> horses {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    vector<vector<string>> possible;
    
    sort(horses.begin(), horses.end());
    do {
        bool valid = true;
        for (auto order : orders) {
            int x = find(horses.begin(), horses.end(), order.first) - horses.begin();
            int y = find(horses.begin(), horses.end(), order.second) - horses.begin();

            if (abs(x - y) != 1) {
                valid = false;
                break;
            }
        }
        if (valid)
            possible.push_back(horses);
    } while (next_permutation(horses.begin(), horses.end()));

    sort(possible.begin(), possible.end());
    return possible[0];
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    #ifdef fstream
    ifstream cin("lineup.in"); 
	ofstream cout("lineup.out"); 
    #endif
    
    int n; cin >> n;
    vector<pair<string,string>> orders;
    while (n--) {
        string x, y, s; cin >> x >> s >> s >> s >> s >> y;
        orders.push_back(make_pair(x, y));
    }

    vector<string> r = solve(orders);
    for (auto s : r)
        cout << s << endl;
}