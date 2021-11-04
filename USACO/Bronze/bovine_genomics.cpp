#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<string> sgenes, vector<string> pgenes) {
    int m = sgenes[0].size();
    int r = 0;

    for (int i = 0; i < m; i++) {
        bool potential = true;
        map<char, int> counts {
            {'A', 0},
            {'C', 0},
            {'G', 0},
            {'T', 0}
        };

        for (int j = 0; j < sgenes.size(); j++) {
            counts.find(sgenes[j][i])->second++;
        }
        
        for (int j = 0; j < pgenes.size(); j++) {
            if (counts.find(pgenes[j][i])->second > 0)
                potential = false;
        }

        if (potential)
            r++;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    ifstream fin("cownomics.in"); 
	ofstream fout("cownomics.out"); 
    
    int n, m; fin >> n >> m;
    vector<string> sgenes;
    vector<string> pgenes;

    for (int i = 0; i < n; i++) {
        string s; fin >> s;
        sgenes.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        string s; fin >> s;
        pgenes.push_back(s);
    }

    fout << solve(sgenes, pgenes);
}