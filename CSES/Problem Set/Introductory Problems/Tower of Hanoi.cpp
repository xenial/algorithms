#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> solve(int n, int b, int e) {
    vector<vector<int>> a, t;
    int aux = 6 - (b + e);
    if (n == 1)
        return vector<vector<int>> {{b, e}};

    a = solve(n - 1, b, aux);
    
    t = solve(1, b, e);
    a.insert(a.end(), t.begin(), t.end());
    t = solve(n - 1, aux, e);
    a.insert(a.end(), t.begin(), t.end());

    return a;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> a;
    a = solve(n, 1, 3);
    printf("%d\n", a.size());
    for (auto p : a)
        printf("%d %d\n", p.at(0), p.at(1));
}