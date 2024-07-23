#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;

#define MOD 1000000007

i32 t, n;

void solve() {
    cin >> n;
    vector<i32> dp(n + 1, MOD);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            } else {
                break;
            }
        }
    }
    cout << dp[n] << '\n';
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
