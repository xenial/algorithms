#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<vector<int>> rankings) {
    int cpairs = 0;
    for (int i = 1; i <= rankings[0].size(); i++) {
        for (int j = 1; j <= rankings[0].size(); j++) {
            if (i == j)
                j++;
            if (j > rankings[0].size())
                break;

            bool consistent = true;
        
            for (auto ranking : rankings) {
                if (find(ranking.begin(), ranking.end(), i) > find(ranking.begin(), ranking.end(), j)) {
                    consistent = false;
                    break;
                }
            }
        
            if (consistent)
                cpairs++;
        }
    }

    return cpairs;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    ifstream fin("gymnastics.in"); 
	ofstream fout("gymnastics.out"); 
    
    int k, n; fin >> k >> n;
    vector<vector<int>> rankings;

    while (k--) {
        vector<int> ranking;
        for (int i = 0; i < n; i++) {
            int r; fin >> r;
            ranking.push_back(r);
        }
        rankings.push_back(ranking);
    }
    fout << solve(rankings);
}