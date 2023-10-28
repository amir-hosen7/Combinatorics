#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 1e6 + 50, mod = 1e9 + 7;

ll fact[N];

ll bigMod(ll b, ll p) {
    if (p == 0) return 1;
    if (p % 2) {
        return (b * bigMod(b, p - 1)) %mod;
    }
    else {
        ll a = bigMod(b, p / 2);
        return (a * a) % mod;
    }
}

ll nCr(ll n, ll r) {
    if (n < r) return 0;
    if (r == 0) return 1;
    ll up = fact[n];
    ll down = (bigMod(fact[r], mod - 2) * bigMod(fact[n - r], mod - 2)) % mod;
    return (up * down) % mod;
}

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    fact[0] = 1;
    for (ll i = 1; i <= N - 5; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

  ll t = 1;
  cin >> t;
  for (ll T = 1; T <= t; T++) {
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll zero = 0;
    for (ll i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] == 0) zero++;
    }
    ll l = 0, cnt = 0, res = 1;
    for (ll i = 0; i < n; i++) {
      if (v[i]) {
        ll aa = v[i] - l - 1;
        ll r = cnt;
        res = (res * nCr(aa, r)) % mod;
        l = v[i];
        cnt = 0;
      }
      else {
        cnt++;
      }
    }
    if (res == 0) cout << "0\n";
    else if (v[n - 1] == 0) cout << "-1\n";
    else cout << res << "\n";
  }
  return 0;
}
