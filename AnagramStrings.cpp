// Q-1 Check whether the given strings are anagram of each other. Space has to be neglected.

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    vector<char> s_chars(26, 0), t_chars(26, 0);
    for(auto x : s) {
        s_chars[x - 'a']++;
    }
    for(auto x : t) {
        t_chars[x - 'a']++;
    }
    if(s_chars == t_chars) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}