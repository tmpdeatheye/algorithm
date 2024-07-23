#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;
typedef string str;

#define MOD 1000000007

i32 t, n;
str row;

void solve() {
    cin >> n;
    vector<vector<i32>> dp(n, vector<i32>(n, 1));
    i32 u = n, v = n;
    for (i32 i = 0; i < n; ++i) {
        cin >> row;
        for (i32 j = 0; j < n; ++j) {
            if (row[j] == '*') {
                dp[i][j] = -1;
                if (i == 0 && u == n) {
                    u = j;
                }
                if (j == 0 && v == n) {
                    v = i;
                }
            }
        }
    }
    for (i32 i = u; i < n; ++i) {
        dp[0][i] = -1;
    }
    for (i32 i = v; i < n; ++i) {
        dp[i][0] = -1;
    }
    for (i32 i = 1; i < n; ++i) {
        for (i32 j = 1; j < n; ++j) {
            if (dp[i][j] != -1) {
                dp[i][j] = max(dp[i - 1][j], 0) + max(dp[i][j - 1], 0);
                dp[i][j] %= MOD;
            }
        }
    }
    cout << max(dp[n - 1][n - 1], 0) << '\n';
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
