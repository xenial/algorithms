#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    std::cin >> a;
    long x = 1, y = 1;
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] == a[i + 1]) 
            x++;
        else {
            y = max(x, y);
            x = 1;
        }
    }
    cout << max(x, y);
}