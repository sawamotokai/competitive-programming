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

int n, m;
int main() {
  cin >> n >> m;
  vll b(n);
  vll p(m);
  rep(i, n) cin >> b[i];
  rep(i, m) cin >> p[i];
  set<ll> ans;
  vector<ll> pw;
  function<void(int, ll, ll)> f = [&](int idx = 0, ll left = 0,
                                      ll right = 0) -> void {
    if (idx == m) {
      if (left == right) {
        pw.pb(right + left);
      }
      return;
    }
    f(idx + 1, left + p[idx], right);
    f(idx + 1, left, right + p[idx]);
    f(idx + 1, left, right);
  };
  f(0, 0, 0);
  rep(i, n) {
    for (ll w : pw) {
      ans.insert(w + b[i]);
    }
  }
  for (ll a : ans)
    cout << a << endl;
  return 0;
}
