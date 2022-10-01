/*
b. Maximum Continuous pickups: A factory has several boxes aligned in a row. You have a machine to pick up a subset of boxes. You are provided with N queries, where each query contains a range of boxes that need pickup. You need to determine the maximum number of continuous pickups the machine will have to make in the pickup process.

Input :  Q = 3
 Query Array: [[1,5],[6,9],[11,17]]  

Output : 9

Explanation: The interval 1-5 and 6-9 can be merged as 1-9. 
             Hence maximum continuous pickups = 9
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    sort(intervals.begin(), intervals.end());
    int start = intervals[0][0];
    int mxEnd = intervals[0][1];
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(mxEnd + 1 >= intervals[i][0]) {
            mxEnd = max(mxEnd, intervals[i][1]);
        }
        else {
            ans = max(ans, mxEnd - start + 1);
            start = intervals[i][0];
            mxEnd = intervals[i][1];
        }
    }
    ans = max(ans, mxEnd - start + 1);
    cout << ans << endl;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}