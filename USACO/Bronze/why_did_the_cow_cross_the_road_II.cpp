#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s) {
    int r = 0;
    for (int i = 0; i < s.size(); i++) {
        int a, b;
        a = s.find(s[i], i + 1);
        if (a == -1)
            continue;

        for (int j = i + 1; j < s.size(); j++) {
            b = s.find(s[j], j + 1);
            if (b == -1)
                continue;
            if (j > a)
                break;

            if (a < b)
                r++;
        }
    }

    return r;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    ifstream fin("circlecross.in"); 
	ofstream fout("circlecross.out"); 
    
    string s;
    fin >> s;
    fout << solve(s);
}