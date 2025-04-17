#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';

void solve() {
    int N;
    cin >> N;
    cin.ignore();

    vector<vector<string>> ls(N); 
    map<string, vector<int>> mp; 

 
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string s;
        while (ss >> s) {
            ls[i].push_back(s);
            mp[s].push_back(i);
        }
    }

    string S, T;
    cin >> S >> T;

   
    queue<tuple<string, int, int, vector<string>>> q; 
    set<pair<string, int>> st; 

    
    for (int e : mp[S]) {
        q.push({S, e, 0, {S}});
        st.insert({S, e});
    }

    bool ok = 0;
    vector<string> res;
    int mi = INT_MAX;

    while (!q.empty()) {
        auto [tex, l, r, path] = q.front();
        q.pop();

        if (tex == T) {
            if (!ok || r < mi || (r == mi && path.size() < res.size())) {
                ok = true;
                mi = r;
                res = path;
            }
            continue;
        }

       
        const vector<string>& ss = ls[l];
        auto it = find(ss.begin(), ss.end(), tex);
        if (it != ss.end()) {
            if (it != ss.begin()) {
                string pre = *(it - 1);
                if (!st.count({pre, l})) {
                    st.insert({pre, l});
                    q.push({pre, l, r, path});
                }
            }
            if (it + 1 != ss.end()) {
                string nex = *(it + 1);
                if (!st.count({nex, l})) {
                    st.insert({nex, l});
                    q.push({nex, l, r, path});
                }
            }
        }

        for (int nle : mp[tex]) {
            if (nle == l) continue;
            if (!st.count({tex, nle})) {
                st.insert({tex, nle});
                vector<string> np = path;
                np.push_back(tex); 
                q.push({tex, nle, r + 1, np});
            }
        }
    }

    if (ok) {
        
        for (size_t i = 0; i < res.size(); ++i) {
            cout << res[i];
            if (i + 1 < res.size()) cout << '-';
        }
        cout << "-";
        cout << T << nl;
      
       
        cout << 2 + mi << nl;
        
    } else {
        cout << "NA" << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}
