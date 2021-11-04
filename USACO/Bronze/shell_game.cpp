#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<vector<int>> swaps) {
    int max = 0;
    for (int i = 1; i <= 3; i++) {
        int pts = 0;
        int pebble = i;
        for (int j = 0; j < swaps.size(); j++) {
            if (pebble == swaps[j][0])
                pebble = swaps[j][1];
            else if (pebble == swaps[j][1])
                pebble = swaps[j][0];
            
            if (pebble == swaps[j][2])
                pts++;
        }
        if (pts > max)
            max = pts;
    }

    return max;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    ifstream fin("shell.in"); 
	ofstream fout("shell.out"); 
    
    int n; fin >> n;
    vector<vector<int>> swaps;

    while (n--) {
        int a, b, g; fin >> a >> b >> g;
        swaps.push_back(vector<int>{a, b, g});
    }

    fout << solve(swaps);
}