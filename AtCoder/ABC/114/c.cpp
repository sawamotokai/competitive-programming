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

ll N;
ll dfs(ll n) {
  if (n > N)
    return 0;
  ll ret = 0;
  n *= 10;
  ret += dfs(n + 3);
  ret += dfs(n + 5);
  ret += dfs(n + 7);
  bool t = false;
  bool f = false;
  bool s = false;
  while (n) {
    int d = n % 10;
    n /= 10;
    if (d == 3)
      t = true;
    if (d == 5)
      f = true;
    if (d == 7)
      s = true;
  }
  if (t && s && f)
    ret++;
  return ret;
}

int main() {
  cin >> N;
  cout << dfs(0) << endl;
  return 0;
}
