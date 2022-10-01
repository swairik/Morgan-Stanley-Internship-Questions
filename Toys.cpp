/*
a. Toys: A group of children(N) has the same (type-0) toy. You have been provided with Q queries. Each query has 3 integers L, R, and M. For each query you have to replace the toy of children between the range of L and R (inclusive) with M. At the end of each query print the toy that is most common amongst the children alongside the number of children that have the toy. ( Format = <integer representing most common toys>-<number of children with that toy>)

Input :  N = 4 Q = 3 toy types = 3
Query Array: [[1,1,1],[2,4,2],[1,4,3]]  

Output : 0-3 2-3 3-4

Explanation: We have 4 children and 3 queries. At the beginning every 
             kid has the same toy 0.
             1) After the first query is triggered, child 1's toy is 
                replaced with 1, yet 0 is the most common 
                toy as rest of the 3 children have it.
             2) After the second query is triggered, 2,3, and 4's toy is
                replaced with 2. Now, 2 is the most 
                common toy as 3 children have it.
             2) After the third query is triggered, everyone has their 
                toy replaced with 3. Now, 3 is the most 
                common toy.

Approach: I would classify the question as easy as hashing was a viable and intuitive solution to it. One just needed to store the child-toy pairs in an array with children as indices and then story the toy-children pairs in a hashmap. Then, it just required a variable to track the most common toy. For each query, we just needed to update the values (for all children between L and R), and compare them with the variable.

*/

// SOLUTION WRONG HERE!!!!!!!!!!!!!
// CHECK HERE : https://www.geeksforgeeks.org/morgan-stanley-interview-experience-for-6-months-internship-fte-on-campus-2021/#:~:text=a.-,Toys,-%3A%20A%20group

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, qq, types;
    cin >> n >> qq >> types;
    // mapping from chilren to toys
    vector<int> children(n, 0);
    // toy to children mapping
    map<int, set<int>> mp;
    int mxToy = 0;
    while(qq--) {
        int l, r, type;
        cin >> l >> r >> type;
        for(int i = l; i <= r; i++) {
            mp[children[i]].erase(i);
            children[i] = type;
            mp[children[i]].insert(i);
        }
        for(int i = 0; i < n; i++) {
            // not done
        }
    }
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}