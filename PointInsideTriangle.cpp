// Q-2 Three vertices of a triangle were given along with one more point.We have to check whether a given point lies inside a triangle or not.

// Area formula - Use shoelace theorem
// x1 y1
// x2 y2
// x3 y3
// x1 y1

// area = |x1y2 - x2y1 + x2y3 - x3y2 + x3y1 - x1y3| / 2
//      = |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| / 2
//      = abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0

#include <bits/stdc++.h>

using namespace std;

// float area(int x1, int y1, int x2, int y2, int x3, int y3) {
//     return abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
// }

void solve() {
    auto area = [&](int x1, int y1, int x2, int y2, int x3, int y3) {
                        return abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
                    };
    int x1, y1, x2, y2, x3, y3, px, py;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> px >> py;

    auto total = area(x1, y1, x2, y2, x3, y3);

    auto p1 = area(px, py, x2, y2, x3, y3);
    auto p2 = area(x1, y1, px, py, x3, y3);
    auto p3 = area(x1, y1, x2, y2, px, py);

    if(total == p1 + p2 + p3) {
        cout << "inside" << endl;
    }
    else {
        cout << "Outside" << endl;
    }
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}