#include <iomanip>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main() {
    float r;
    cin >> r;
    cout << std::fixed << (4.0 * M_PI * pow(r, 3)) / 3;
}