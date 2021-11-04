#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



bool valid(int pz, int k, set<int> infected, vector<vector<int>> records) {
    #ifdef fstream
    ifstream cin("tracing.in"); 
    ofstream cout("tracing.out"); 
    #endif

    sort(records.begin(), records.end());
    set<int> s_infected;
    s_infected.insert(pz);

    for (int i = 0, j = 0; i < records.size(); i++) {
        if (s_infected.count(records[i][1]) && j < k) {
            s_infected.insert(records[i][2]);
            j++;
        } else if (s_infected.count(records[i][2]) && j < k) {
            s_infected.insert(records[i][1]);
            j++;
        }
    }

    if (s_infected != infected)
        return false;
    else
        return true;
}

void solve(set<int> infected, vector<vector<int>> records) {
    #ifdef fstream
    ifstream cin("tracing.in"); 
    ofstream cout("tracing.out"); 
    #endif

    int kmin = INT_MAX, kmax = 0;
    set<int> pz_pos;
    for (auto inf : infected) {
        for (int i = 1; i <= records.size(); i++) {
            if (valid(inf, i, infected, records)) {
                kmin = min(kmin, i);
                kmax = i;
                pz_pos.insert(inf);
            }
        }
    }
    if (kmax != records.size())
        cout << pz_pos.size() << " " << kmin << " " << kmax;
    else
        cout << pz_pos.size() << " " << kmin << " " << "Infinity";
}

int main() {
    #ifdef fstream
    ifstream cin("tracing.in"); 
    ofstream cout("tracing.out"); 
    #endif

    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int n, t; cin >> n >> t;
    set<int> infected;
    vector<vector<int>> records;
    string states; cin >> states;
    for (int i = 1; i <= n; i++) {
        if (states[i - 1] == '1')
            infected.insert(i);
    }

    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        records.push_back(vector<int>{a, b, c});
    }

    solve(infected, records);
}