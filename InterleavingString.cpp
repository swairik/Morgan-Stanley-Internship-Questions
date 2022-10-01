// Q-3 Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. C is said to be interleaving of A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    if(c.size() != a.size() + b.size()) {
        cout << "NO" << endl;
        return;
    }
    int n = (int)a.size();
    int m = (int)b.size();

    bool dp[n + 1][m + 1];          // dp[i][j] is true if we can form first i + j - 1 of c using first i - 1 chars from a and first j - 1 chars from b
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            int curr = i + j - 1;
            if(i)   dp[i][j] |= (dp[i - 1][j] && a[i - 1] == c[curr]);
            if(j)   dp[i][j] |= (dp[i][j - 1] && b[j - 1] == c[curr]);
        }
    }

    // MORE INTUITIVE VERSION:
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= m; j++) {
    //         int curr = i + j - 1;
    //         if(!i) {
    //             dp[i][j] = dp[i][j - 1] && (b[j - 1] == c[curr]);
    //         }
    //         else if(!j) {
    //             dp[i][j] = dp[i - 1][j] && (a[i - 1] == c[curr]);
    //         }
    //         else {
    //             dp[i][j] = ((dp[i - 1][j] && a[i - 1] == c[curr]) || dp[i][j - 1] && b[j - 1] == c[curr]);
    //         }
    //     }
    // }

    if(dp[n][m]) {
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