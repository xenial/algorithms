#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<string> sgenes, vector<string> pgenes) {
    int m = sgenes[0].size();
    int r = 0;

    for (int i = 0; i < m - 2; i++) {
        for (int j = i + 1; j < m - 1; j++) {
            for (int k = j + 1; k < m; k++) {
                bool potential = true;

                set<string> ssel;
                for (auto gene : sgenes) {
                    string sel {gene[i], gene[j], gene[k]};
                    ssel.insert(sel);
                }
                
                for (auto gene : pgenes) {
                    string sel {gene[i], gene[j], gene[k]};
                    if (ssel.count(sel) > 0) {
                        potential = false;
                        break;
                    }
                }

                if (potential)
                    r++;
            }
        }
    }

    return r;
}

int main() {
    //ifstream cin("cownomics.in"); 
	//ofstream cout("cownomics.out"); 

    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<string> sgenes, pgenes;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        sgenes.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        pgenes.push_back(s);
    }

    cout << solve(sgenes, pgenes);
}