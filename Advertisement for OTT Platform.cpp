/*
c. Advertisement for OTT platform: You are the head of an OTT platform. You have two shows that are set to be released on the same date. You realized that the advertisement department has accidentally booked up more slots for the first show than they have for the second show. Recognizing that this mess-up could favor the first show, you justly ask them to modify the slots so that both the shows have identical advertisement slots. Unfortunately, this process would cause loss of advertisement slots that have already been bought, hence you need to minimize the losses in the process by selecting as many identical slots as possible. An example of the advertisement schedule AD1 is abcdedgh, the cost of each slot C1 is 10. Given that you cannot change the order of advertisements, print the minimum possible loss.

Input :  AD1 = abcdedgh C1 = 10 AD2 = abcdgbksmn C2 = 20 

Output : 130

Explanation: The final advertisement schedule is abcdg. So (8-5)3 
             slots were lost in AD1 and (10-5)5 slots were lost in AD2.
             Final loss = 3*10 + 5*20 = 130
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s1, s2;
    int c1, c2;
    cin >> s1 >> c1 >> s2 >> c2;
    
    int n = (int)s1.size();
    int m = (int)s2.size();
    
    int dp[n + 1][m + 1];

    memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(!i || !j)    continue;
            else if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int commonLength = dp[n][m];
    int ans = (n - commonLength) * c1 + (m - commonLength) * c2;
    cout << ans << endl;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}