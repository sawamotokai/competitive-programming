#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ok() puts(ok ? "Yes" : "No");
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll, ll>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++

ll n, k;
ll A[2004];
ll whole[2005];
ll r[2005];

int main() {
  cin >> n >> k;
  rep(i, n) cin >> A[i];
  rep(i, n) {
    ll cnt = 0;
    rep3(j, n - 1, i) {
      if (A[i] > A[j])
        cnt++;
    }
    r[i] = cnt;
  }
  rep(i, n) {
    ll cnt = 0;
    rep(j, n) {
      if (A[i] > A[j])
        cnt++;
    }
    whole[i] = cnt;
  }
  ll ans = 0;
  ll mod = 1e9 + 7;
  rep(i, n) {
    ans += r[i] * k;
    ans %= mod;
    ans += whole[i] * (((k - 1) * k / 2) % mod);
    ans %= mod;
  }
  if (ans < 0)
    ans += mod;
  cout << ans << endl;
  return 0;
}
