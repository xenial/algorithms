#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long llu;

llu solve(llu y, llu x) {
    llu sq;

    if (x == y) {
        sq = x * x;
        return sq - (x - 1);
    }

    if (x > y) {
        sq = x * x;
        if (x % 2 != 0) {
            return sq - (y - 1);
        } else {
            return sq - (x - 1) * 2 + (y - 1);
        }
    } else {
        sq = y * y;
        if (y % 2 == 0) {
            return sq - (x - 1);
        } else {
            return sq - (y - 1) * 2 + (x - 1);
        }
    }
}

int main() {
    llu t, y, x;
    scanf("%llu", &t);
    while(t--) {
        scanf("%llu", &y);
        scanf("%llu", &x);
        printf("%llu\n", solve(y, x));
    }
}