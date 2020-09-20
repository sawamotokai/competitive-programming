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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
// clang++ -std=c++11 -stdlib=libc++

ll dp[200005];
int used[200006];
int main() {
  int N, K;
  cin >> N >> K;
  int mod = 998244353;
  vi s;
  rep(i, K) {
    int a, b;
    cin >> a >> b;
    rep2(j, a, b) {
      if (!used[j])
        s.pb(j);
      used[j] = true;
    }
  }
  sort(all(s));
  dp[1] = 1;
  rep2(i, 1, N) {
    bool changed = false;
    for (int num : s) {
      int ns = i + num;
      if (ns <= N) {
        (dp[ns] += dp[i]) %= mod;
        changed = true;
      } else
        break;
    }
    if (!changed)
      break;
  }
  cout << dp[N] << endl;
  return 0;
}
