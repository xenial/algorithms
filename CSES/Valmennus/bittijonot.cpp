#include <iostream>
#include <math.h>
using namespace std;
int main() {
    unsigned long long a;
    unsigned long long n;
    unsigned long long mod = (unsigned long long)pow(10, 9) + 7;
    cin >> a;
    n = 2;
    for (int i = 1; i < a; i++) {
        n = (n * 2) % mod;
    }
    cout << n;
}