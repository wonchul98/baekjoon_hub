#include <vector>

using namespace std;

const int MOD = 1'000'000'007;

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int coin : money) {
        for (int j = coin; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - coin]) % MOD;
        }
    }

    return dp[n];
}
