#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<vector<bool>> res) {
    vector<int> cols = {0,1,2,3,4,5,6,7};
    int p = 0;
    do {
        bool valid = true;
        vector<int> diags1(8, -20);
        vector<int> diags2(8, -20);
        for (int i = 0; i < 8; i++) {
            if (res[i][cols[i]]) {
                valid = false;
                break;
            }
            for (auto diag : diags1) {
                if (diag == i - cols[i]) {
                    valid = false;
                    break;
                }
            }
            for (auto diag : diags2) {
                if (diag == i + cols[i]) {
                    valid = false;
                    break;
                }
            }
            diags1[i] = i - cols[i];
            diags2[i] = i + cols[i];
        }
        if (valid)
            p++;
    } while(next_permutation(cols.begin(), cols.end()));
    
    return p;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    vector<vector<bool>> res(8, vector<bool>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            res.at(i).at(j) = c == '.' ? false : true;
        }
    }
    cout << solve(res);
}