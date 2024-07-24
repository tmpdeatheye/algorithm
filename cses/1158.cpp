#include <bits/stdc++.h>

using namespace std;

int t, n, x;

void solve() {
    cin >> n >> x;
    vector<int> price(n), page(n);
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> page[i];
    }
    vector<long long> dp(x + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= 1; --j) {
            if (j - price[i] >= 0) {
                dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
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
