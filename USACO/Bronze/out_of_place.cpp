#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define fstream

int solve(vector<int> vnums) {
    vector<int> sorted = vnums;
    sort(all(sorted));
    int oop = -1;
    for (int i = 0; i < vnums.size(); i++) {
        if (sorted[i] != vnums[i]) {
            oop++;
        }
    }

    return oop;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    #ifdef fstream
    ifstream cin("outofplace.in"); 
	ofstream cout("outofplace.out"); 
    #endif

    int n; cin >> n;
    int prev = -1;
    vector<int> nums;
    while (n--) {
        int num; cin >> num;

        if (prev != num) {
            nums.push_back(num);
            prev = num;
        }
    }

    cout << solve(nums);
}