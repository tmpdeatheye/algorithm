#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int t, n, x;

void solve() {
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= x; ++j) {
            if (j - coins[i] >= 0) {
                dp[j] += dp[j - coins[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
