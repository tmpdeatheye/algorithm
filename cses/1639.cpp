#include <bits/stdc++.h>

using namespace std;

typedef string str;

int t;
str one, two;

void solve() {
    cin >> one >> two;
    const int zo = static_cast<int>(one.size()), zt = static_cast<int>(two.size());
    vector<vector<int> > dp(zo + 1, vector<int>(zt + 1, INT32_MAX));
    dp[0][0] = 0;
    for (int i = 0; i <= zo; ++i) {
        for (int j = 0; j <= zt; ++j) {
            if (i != 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if (j != 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            if (i != 0 && j != 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (one[i - 1] != two[j - 1]));
            }
        }
    }
    cout << dp[zo][zt] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
