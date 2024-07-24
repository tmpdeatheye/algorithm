#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int t, n;

void solve() {
    cin >> n;
    vector<int> dp(n + 1, MOD);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int j = i;
        while (j > 0) {
            int k = j % 10;
            if (k != 0 && i - k >= 0) {
                dp[i] = min(dp[i], dp[i - k] + 1);
            }
            j /= 10;
        }
    }
    cout << dp[n] << '\n';
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
