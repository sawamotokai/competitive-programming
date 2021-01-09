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

int N;
string grid[2];
ll dp[55][2];
int mod = 1e9 + 7;

int main() {
  cin >> N;
  rep(i, 2) cin >> grid[i];
  if (N == 1) {
    cout << 3 << endl;
    return 0;
  }
  int s = 0;
  ll ans = 3;
  if (grid[0][0] == grid[0][1]) {
    s = 2;
    ans = 6;
  }
  if (grid[0][0] == grid[1][0])
    s = 1;
  rep2(i, s, N - 1) {
    if (grid[0][i] == grid[0][i + 1]) {
      // yoko
      if (grid[0][i - 1] == grid[1][i - 1]) {
        (ans *= 2) %= mod;
      } else {
        (ans *= 3) %= mod;
      }
      i++;
    } else {
      if (grid[0][i - 1] == grid[1][i - 1]) {
        (ans *= 2) %= mod;
      } else {
        (ans *= 1) %= mod;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
