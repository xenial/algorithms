#include <bits/stdc++.h>
using namespace std;
int main() {
    long n, s;
    scanf("%ld", &n);
    s = n * (n + 1) / 2;
    for (int i = 0; i < (int)n - 1; i++) {
        int m;
        scanf("%d", &m);
        s -= m;
    }
    printf("%ld", s);
}