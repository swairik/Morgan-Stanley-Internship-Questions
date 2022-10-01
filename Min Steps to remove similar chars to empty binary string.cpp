/*
Given a binary string S of length N, the task is to find the minimum number of removal of adjacent similar characters required to empty the given binary string.

Examples:

Input: S = “1100011“
Output: 2
Explanation:
Operation 1: Removal of all 0s modifies S to “1111“.
Operation 2: Removal of all remaining 1s makes S empty.
Therefore, the minimum number of operations required is 2.

Input: S = “0010100“
Output: 3
Explanation:
Operation 1: Removal of all 1s modifies S to “000100“.
Operation 2: Removal of all 1s modifies S = “00000“.
Operation 3: Removal of all remaining 0s makes S empty.
Therefore, the minimum number of operations required is 3.
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    string temp = "";
    int pos = 0;
    while(pos < n) {
        temp += s[pos];
        int ptr = pos;
        while(pos < n && s[ptr] == s[pos]) pos++;
    }
    cout << ceil((temp.size() + 1) / 2.0) << endl;
}

int main() {
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}