#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<pair<int, int>> coords, int cmax) {
    int possible = ceil((float)coords.size() / 4);
    int smallest = INT_MAX;
    for (int x = 0; x < coords.size(); x++) {
        for (int y = 0; y < coords.size(); y++) {
            pair<int, int> fence = make_pair(coords[x].first + 1, coords[y].second + 1);
            vector<int> groups;
            for (auto coord : coords) {
                if (coord.first < fence.first) {
                    if (coord.second < fence.second)
                        groups.push_back(1);
                    else
                        groups.push_back(3);

                } else {
                    if (coord.second < fence.second)
                        groups.push_back(2);
                    else
                        groups.push_back(4);
                }
            }
            int g1, g2, g3, g4;
            g1 = count(groups.begin(), groups.end(), 1);
            g2 = count(groups.begin(), groups.end(), 2);
            g3 = count(groups.begin(), groups.end(), 3);
            g4 = count(groups.begin(), groups.end(), 4);
            int biggest = max(max(g1, g2), max(g3, g4));

            if (biggest < smallest)
                smallest = biggest;
        }
        if (possible == smallest)
                break;
    }
    return smallest;
}

int main() {
    ifstream cin("balancing.in"); 
    ofstream cout("balancing.out"); 

    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int n, b; cin >> n >> b;
    vector<pair<int, int>> coords;
    while (n--) {
        int x, y; cin >> x >> y;
        coords.push_back(make_pair(x, y));
    }
    cout << solve(coords, b);
}