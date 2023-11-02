#include <vector>
#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

int numSquares(int n) {
    std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= std::sqrt(i); j++) {
            dp[i] = std::min(dp[i], dp[i - j*j] + 1);
        }
    }

    return dp[n];
}

int main()
{
    cout << numSquares(251) << endl;
    return 0;
}
