#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> h(n + 1), p(n + 1);
    for (ll i = 1; i <= n; i++) cin >> h[i];
    for (ll i = 1; i <= n; i++) cin >> p[i];

    vector<ll> dp(x + 1, 0), curr(x + 1, 0);

    for (ll id = 1; id <= n; id++) {
        // reset curr each iteration instead of reusing old values
        for (ll sum = 0; sum <= x; sum++) {
            curr[sum] = dp[sum]; // not max with curr[sum], just copy dp[sum]
            if (sum >= h[id])
                curr[sum] = max(curr[sum], dp[sum - h[id]] + p[id]);
        }
        swap(dp, curr); // fast pointer swap instead of full copy
    }

    cout << dp[x];
    return 0;
}

