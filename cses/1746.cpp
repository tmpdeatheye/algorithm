#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;
typedef int64_t i64;

#define MOD 1000000007

i32 t, n, m;

void solve() {
    cin >> n >> m;
    vector<i32> a(n);
    for (i32 i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<i64>> dp(n, vector<i64>(m + 1, 0));
    if (a[0] == 0) {
        fill(dp[0].begin(), dp[0].end(), 1);
    } else {
        dp[0][a[0]] = 1;
    }
    for (i32 i = 1; i < n; ++i) {
        if (a[i] == 0) {
            for (i32 j = 1; j <= m; ++j) {
                dp[i][j] += dp[i - 1][j];
                if (j - 1 >= 1) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                if (j + 1 <= m) {
                    dp[i][j] += dp[i - 1][j + 1];
                }
                dp[i][j] %= MOD;
            }
        } else {
            dp[i][a[i]] += dp[i - 1][a[i]];
            if (a[i] - 1 >= 1) {
                dp[i][a[i]] += dp[i - 1][a[i] - 1];
            }
            if (a[i] + 1 <= m) {
                dp[i][a[i]] += dp[i - 1][a[i] + 1];
            }
            dp[i][a[i]] %= MOD;
        }
    }
    i64 result = 0;
    for (i32 i = 1; i <= m; ++i) {
        result += dp[n - 1][i];
        result %= MOD;
    }
    cout << result << '\n';
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
