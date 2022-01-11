#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string path_mask;
int callcount = 0;

bool test_mask(string path) {
    if (path.size() != path_mask.size())
        return false;
    for (int i = 0; i < path_mask.size(); i++) {
        if (path_mask[i] == '?')
            continue;
        else if (path_mask[i] != path[i])
            return false;
    }

    return true;
}

string get_possible_dirs(vector<pair<int,int>> taken, pair<int,int> cur_pos) {
    string possible_dirs;
    
    if (cur_pos.second + 1 < 7 && count(taken.begin(), taken.end(), make_pair(cur_pos.first, cur_pos.second + 1)) < 1)
        possible_dirs.push_back('D');

    if (cur_pos.second - 1 >= 0 && count(taken.begin(), taken.end(), make_pair(cur_pos.first, cur_pos.second - 1)) < 1)
        possible_dirs.push_back('U');

    if (cur_pos.first - 1 >= 0 && count(taken.begin(), taken.end(), make_pair(cur_pos.first - 1, cur_pos.second)) < 1)
        possible_dirs.push_back('L');

    if (cur_pos.first + 1 < 7 && count(taken.begin(), taken.end(), make_pair(cur_pos.first + 1, cur_pos.second)) < 1)
        possible_dirs.push_back('R');

    return possible_dirs;
}

int solve(string cur_path, vector<pair<int,int>> taken, int pcount) {
    callcount++;
    pair<int,int> cur_pos = make_pair(
        count(cur_path.begin(), cur_path.end(), 'R') - count(cur_path.begin(), cur_path.end(), 'L'),
        count(cur_path.begin(), cur_path.end(), 'D') - count(cur_path.begin(), cur_path.end(), 'U')
    );

    if (cur_pos == make_pair(0, 6)) {
        if (test_mask(cur_path)) {
            return 1 + pcount;
        } else {
            return 0 + pcount;
        }
    }

    string possible_dirs = get_possible_dirs(taken, cur_pos);
    if (possible_dirs.size() == 2 && count(possible_dirs.begin(), possible_dirs.end(), 'R') > 0 && count(possible_dirs.begin(), possible_dirs.end(), 'L') > 0) {
        return 0 + pcount;
    } else if (possible_dirs.size() == 2 && count(possible_dirs.begin(), possible_dirs.end(), 'D') > 0 && count(possible_dirs.begin(), possible_dirs.end(), 'U') > 0) {
        return 0 + pcount;
    }
        
    for (auto dir : possible_dirs) {
        string t_path = cur_path; t_path.push_back(dir);
        vector<pair<int,int>> t_taken = taken; t_taken.push_back(cur_pos);
        pcount += solve(t_path, t_taken, pcount);
    }

    return pcount;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> path_mask;
    if (path_mask[0] != 'D' && path_mask[0] != 'R' && path_mask[0] != '?') {
        cout << 0;
        cout << callcount << endl;
        return 0;
    } else if (path_mask[0] == '?') {
        int c1, c2;
        c1 = solve("D", vector<pair<int,int>>{make_pair(0,0)}, 0);
        c2 = solve("R", vector<pair<int,int>>{make_pair(0,0)}, 0);
        cout << callcount << endl;
        cout << c1 + c2;
        return 0;
    } else {
        cout << solve(string(1,path_mask[0]), vector<pair<int,int>>{make_pair(0,0)}, 0);
        cout << callcount << endl;
        return 0;
    }
}