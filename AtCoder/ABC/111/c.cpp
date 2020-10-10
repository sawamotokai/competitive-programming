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

int main() {
  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];
  map<int, int> mp1;
  map<int, int> mp2;
  rep(i, n) {
    if (i & 1) {
      mp2[a[i]]++;
    } else
      mp1[a[i]]++;
  }
  int mx11 = 0;
  int mx12 = 0;
  int mxNum1 = -1;
  int mx21 = 0;
  int mx22 = 0;
  int mxNum2 = -1;
  for (auto num : mp1) {
    if (mx11 <= num.se) {
      mxNum1 = num.fi;
      mx12 = mx11;
      mx11 = num.se;
    }
  }
  for (auto num : mp2) {
    if (mx21 <= num.se) {
      mxNum2 = num.fi;
      mx22 = mx21;
      mx21 = num.se;
    }
  }
  int ans = n;
  if (mxNum1 == mxNum2) {
    chmin(ans, n - mx11 - mx22);
    chmin(ans, n - mx12 - mx21);
  } else {
    ans -= mx11 + mx21;
  }
  cout << mxNum1 << " " << mxNum2 << endl;
  cout << mx11 << " " << mx12 << endl;
  cout << mx21 << " " << mx22 << endl;
  cout << ans << endl;
  return 0;
}
