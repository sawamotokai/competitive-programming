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

int used[100006];

int main() {
  int N, X, M;
  cin >> N >> X >> M;
  auto f = [&](int prev) {
    ll ret = prev % M;
    if (prev < 0)
      prev += M;
    (ret *= prev) %= M;
    if (prev < 0)
      prev += M;
    return ret;
  };
  ll prev = X;
  ll sum = 0;
  ll cycle = 0;
  ll ans = 0;
  rep2(i, 1, N) {
    if (used[prev]) {
      // TODO
      ll rest = N - i + 1;
      ll loop = rest / cycle; // add loop*sum
      ll k = rest % cycle;    // add from a1 to ak
      (ans += ((sum * loop) % M)) %= M;
      ll p = X;
      rep(i, k) {
        (ans += prev) %= M;
        prev = f(prev);
      }

    } else {
      used[prev] = true;
      (sum += prev) %= M;
      if (sum < 0)
        sum += M;
      cycle++;
    }
    prev = f(prev);
    cout << prev << endl;
  }
  if (ans == 0)
    ans = sum;
  cout << ans << endl;
  return 0;
}
