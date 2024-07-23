#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;
typedef int64_t i64;

i32 t, n, x;

void solve() {
    cin >> n >> x;
    vector<i32> price(n), page(n);
    for (i32 i = 0; i < n; ++i) {
        cin >> price[i];
    }
    for (i32 i = 0; i < n; ++i) {
        cin >> page[i];
    }
    vector<i64> dp(x + 1, 0);
    for (i32 i = 0; i < n; ++i) {
        for (i32 j = x; j >= 1; --j) {
            if (j - price[i] >= 0) {
                dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
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
