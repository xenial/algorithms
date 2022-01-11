#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n) {
    if (n == 0)
        return;

    vector<vector<bool>> g1 {{0}, {1}}, g2;

    for (int i = 1; i < n; i++) {
        int max = pow(2, i + 1);

        g2 = g1;
        reverse(g2.begin(), g2.end());
        for (int j = 0; j < g1.size(); j++)
            g1[j].insert(g1[j].begin(), 0);
        for (int j = 0; j < g2.size(); j++)
            g2[j].insert(g2[j].begin(), 1);

        g1.insert(g1.end(), g2.begin(), g2.end());
    }

    for (auto c : g1) {
        for (auto c2 : c)
            printf("%d", (int)c2);
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n);
}