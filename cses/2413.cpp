#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007 // 1e9 + 7
#define N 1000000 // 1e6

int t, n;
vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));

void build() {
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = 4 * dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + 2 * dp[i - 1][1];
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
    }
}

void solve() {
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    // t = 1;
    build();
    while (t--) {
        solve();
    }
    return 0;
}
