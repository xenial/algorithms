#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<pair<int, int>> points) {
    int biggest = 0;

    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            if (i == j)
                continue;
            int distx = abs(points[i].first - points[j].first);
            int disty = abs(points[i].second - points[j].second);
            int square = distx * distx + disty * disty;

            if (square > biggest)
                biggest = square;
        }
    }

    return biggest;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int n;
    vector<int> xs, ys;
    vector<pair<int, int>> points;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        xs.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        ys.push_back(y);
    }
    
    for (int i = 0; i < n; i++) {
        points.push_back(make_pair(xs[i], ys[i]));
    }

    cout << solve(points);
}