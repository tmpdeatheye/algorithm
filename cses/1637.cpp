#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;

#define MOD 1000000007

i32 t, n;

void solve() {
    cin >> n;
    vector<i32> dp(n + 1, MOD);
    dp[0] = 0;
    for (i32 i = 1; i <= n; ++i) {
        i32 j = i;
        while (j > 0) {
            i32 k = j % 10;
            if (k != 0 && i - k >= 0) {
                dp[i] = min(dp[i], dp[i - k] + 1);
            }
            j /= 10;
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
