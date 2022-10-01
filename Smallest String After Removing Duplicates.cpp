/*
Given a string S consisting of lowercase alphabets, the task is to find the lexicographically smallest string that can be obtained by removing duplicates from the given string S.
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> cnt(26, 0);
    
    // Mark visited characters
    set<char> vis;
    // Stores count of each character
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
 
    // Stores the resultant string
    string ans = "";
    int i = 0;
    while(i < n) {
        cnt[s[i] - 'a']--;
 
        // If character is not already
        // in answer
        if(vis.find(s[i]) == vis.end()) {
            // Last character > S[i]
            // and its count > 0
            while(ans.size() > 0 && ans.back() > s[i] && cnt[ans.back() - 'a'] > 0) {
                // Mark letter unvisited
                vis.erase(ans.back());
                ans.pop_back();
            }
 
            // Add s[i] in ans and
            // mark it visited
            ans.push_back(s[i]);
            vis.insert(s[i]);
        }
        i++;
    }
 
    // Return the ansultant string
    cout << ans << endl;
}

int main() {
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}