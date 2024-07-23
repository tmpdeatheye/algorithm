#include <bits/stdc++.h>

using namespace std;

typedef int32_t i32;
typedef int64_t i64;

#define MOD 1000000007

i32 t, n, m;
i64 result = 1;

void solve() {
    cin >> n >> m;
    vector<i32> value(n);
    for (i32 i = 0; i < n; ++i) {
        cin >> value[i];
    }
    unordered_map<i32, i32> one, two;
    for (i32 i = 0; i < n; ++i) {
        if (value[i] == 0) {
            if (i == 0) {
                for (i32 j = 1; j <= m; ++j) {
                    one[j] += 1;
                    one[j] %= MOD;
                }
            } else {
                if (value[i - 1] == 0) {
                    two.clear();
                    for (auto [k, v]: one) {
                        if (1 <= k - 1 && k - 1 <= m) {
                            two[k - 1] += v;
                            two[k - 1] %= MOD;
                        }
                        if (1 <= k && k <= m) {
                            two[k] += v;
                            two[k] %= MOD;
                        }
                        if (1 <= k + 1 && k + 1 <= m) {
                            two[k + 1] += v;
                            two[k + 1] %= MOD;
                        }
                    }
                    one = two;
                } else {
                    if (1 <= value[i - 1] - 1 && value[i - 1] - 1 <= m) {
                        one[value[i - 1] - 1] += 1;
                        one[value[i - 1] - 1] %= MOD;
                    }
                    if (1 <= value[i - 1] && value[i - 1] <= m) {
                        ++one[value[i - 1]];
                        one[value[i - 1]] %= MOD;
                    }
                    if (1 <= value[i - 1] + 1 && value[i - 1] + 1 <= m) {
                        ++one[value[i - 1] + 1];
                        one[value[i - 1]] %= MOD;
                    }
                }
            }
        } else {
            if (i > 0) {
                if (value[i - 1] == 0) {
                    i64 x = 0;
                    if (1 <= value[i] - 1 && value[i] - 1 <= m) {
                        x += one[value[i] - 1];
                    }
                    if (1 <= value[i] && value[i] <= m) {
                        x += one[value[i]];
                    }
                    if (1 <= value[i] + 1 && value[i] + 1 <= m) {
                        x += one[value[i] + 1];
                    }
                    if (x == 0) {
                        cout << '0' << '\n';
                        return;
                    }
                    result *= x % MOD;
                    result %= MOD;
                    one.clear();
                } else {
                    if (abs(value[i] - value[i - 1]) > 1) {
                        cout << '0' << '\n';
                        return;
                    }
                }
            }
        }
    }
    i64 x = 0;
    for (i32 i = 1; i <= m; ++i) {
        x += one[i];
    }
    if (x != 0) {
        result *= x % MOD;
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
