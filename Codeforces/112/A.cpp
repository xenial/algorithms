#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s1, string s2) {
    int e = 0;
    for (int i = 0; i < s1.size(); i++) {
        s1.at(i) = tolower(s1.at(i));
        s2.at(i) = tolower(s2.at(i)); 
    }

    for (int i = 0; i < s1.size(); i++) {

        if (s1.at(i) < s2.at(i))
            return -1;
        
        if (s1.at(i) > s2.at(i))
            return 1;
    }

    return 0;
    
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    cout << solve(s1, s2);
}