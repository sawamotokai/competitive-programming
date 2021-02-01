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

ll N;
ll A[10005];
ll f(int l, int r) {
  if (r < l)
    return 0;
  if (l < 0 || r >= N || l >= N || r < 0)
    return 0;
  if (l == r)
    return A[l];
  ll mn = INF;
  int idx = -1;
  rep2(i, l, r) if (chmin(mn, A[i])) idx = i;
  ll now = (ll)(r - l + 1) * mn;
  ll left = f(l, idx - 1);
  // cout << l << " " << r << endl;
  ll right = f(idx + 1, r);
  // cout << idx << endl;
  // cout << now << " " << left << " " << right << endl;
  chmax(now, left);
  chmax(now, right);
  return now;
}

int main() {
  cin >> N;
  rep(i, N) cin >> A[i];
  ll ans = 0;
  cout << f(0, N - 1) << endl;
  return 0;
}
