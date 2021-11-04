#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    int i, s, ans[n], sum[3] = {0,0,0}, ctr[3] = {0,0,0};

    if ((n * (n + 1) / 2) % 3 != 0) {
        printf("IMPOSSIBLE");
        return;
    }
    
    sum[1] = (n * (n + 1) / 2) / 3;
    sum[0] = sum[1] - 1;
    sum[2] = sum[1] + 1;

    for (i = n; i > 0; i--) {
        if (ctr[0] + i <= sum[0]) {
            ctr[0] += i;
            ans[i-1] = 1;
        } else if (ctr[1] + i <= sum[1]) {
            ctr[1] += i;
            ans[i-1] = 2;
        } else if (ctr[2] + i <= sum[2]) {
            ctr[2] += i;
            ans[i-1] = 3;
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n);
}