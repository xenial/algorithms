#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long llu;
llu power(llu x, llu y) {
    llu e = x;
    if (y == 0)
        return 1;
    while(--y) {
        e = e * x;
    }
    return e;
}

llu solve(llu n) {
    int l = log10(n), i;

    llu a;
    llu c = 1;

    do {
        a = 0;
        for (i = 0; i <= l; i++) {
            a += c * power(10, i);
        }
        if (a > n)
            return a;
        
        if (c == 9) {
            c = 1;
            l++;
        } else 
            c++;
    } while(a <= n);
    a = c * power(10, l) + a;
    return a;
}

int main() {
    llu t;
    scanf("%llu", &t);
    while(t--) {
        llu n;
        scanf("%llu", &n);
        printf("%llu\n", solve(n));
    }
}