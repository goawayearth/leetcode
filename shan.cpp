#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    int p[105] = {0};
    int q[105] = {0};
    int q1[105] = {0};
    int r[105] = {0};
    bool flag = 0;
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> q[i];
        q1[i] = q[i];
    }
    for (int i = 1; i <= m; i++) {
        if (p[i] == 0)
            cout << 1 << " ";
        else {
            cout << q[p[i]] + 1 << " ";
            if (q[p[i]]  + q[i] > n)
                flag = 1;
            q[i] += q[p[i]] ;
        }            
    }
    if (!flag) {
        cout << endl;
        for (int i = m; i >= 1; i--) {
            r[i] += q1[i];
            if (p[i])
                r[p[i]] = max(r[i], r[p[i]]);
        }
        for (int i = 1; i <= m; i++) {
            r[i] = n - r[i] + 1;
            cout << r[i]<<" ";
        }
    }
    return 0;
}