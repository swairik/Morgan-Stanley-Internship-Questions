// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again). 
// Note : 1 transaction means buying & selling together

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    int k;
    cin >> k;
    if(n <= 1) {
        cout << 0 << endl;
        return;
    }
    if(k >= n / 2) {
        int ans = 0, pos = 1;
        while(pos < n) {
            ans += (prices[pos] > prices[pos - 1]) * (prices[pos] - prices[pos - 1]);
            pos++;
        }
        cout << ans << endl;
        return;
        
    }
    int dp[k + 1][n];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= k; i++) {
        int temp = -prices[0];
        for(int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i][j - 1], prices[j] + temp);
            temp = max(temp, dp[i - 1][j - 1] - prices[j]);
        }
    }
    cout << dp[k][n - 1] << endl;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}