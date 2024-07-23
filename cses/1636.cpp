#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;

#define MOD 1000000007

i32 t, n, x;

void solve() {
    cin >> n >> x;
    vector<i32> coins(n);
    for (i32 i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    vector<i32> dp(x + 1, 0);
    dp[0] = 1;
    for (i32 i = 0; i < n; ++i) {
        for (i32 j = 1; j <= x; ++j) {
            if (j - coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}

i32 main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
