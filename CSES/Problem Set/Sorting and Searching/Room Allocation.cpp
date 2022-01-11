#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define sz size

void set_io(string filename = "") {
    ios::sync_with_stdio(0);
	cin.tie(0);

    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}



int main() {
    set_io("");

    int N; cin >> N;
    vector<pair<pair<int,int>,int>> customers(N);
    for (int i = 0; i < N; i++) {
        cin >> customers[i].fi.fi;
        cin >> customers[i].fi.se;
        customers[i].se = i;
    }

    set<pair<int,int>, greater<pair<int,int>>> rooms;
    sort(all(customers));

    rooms.insert({customers[0].fi.se, 1});
    int roomCount = 1, ans[N];
    ans[customers[0].se] = 1;
    for (int i = 1; i < customers.sz(); i++) {
        auto customer = customers[i];
        set<pair<int,int>>::iterator room = rooms.upper_bound({customer.fi.fi, 0});

        if (room == rooms.end()) {
            roomCount++;
            rooms.insert({customer.fi.se, roomCount});
            ans[customer.se] = roomCount;
        } else {
            ans[customer.se] = (*room).se;
            rooms.erase(room);
            rooms.insert({customer.fi.se, ans[customer.se]});
        }
    }

    cout << roomCount << endl;
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
}