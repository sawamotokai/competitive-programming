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

int N, R;
string s;
int main() {
  cin >> N >> R >> s;
  int ans = 0;
  int rightMost = -1;
  int done = -1;
  rep(i, N) if (s[i] == '.') rightMost = i;
  if (rightMost == -1) {
    cout << 0 << endl;
    return 0;
  }
  int walk = max(rightMost - R + 1, 0);
  bool need = false;
  int leftMost = INF;
  rep(i, N) if (s[i] == '.') {
    leftMost = i;
    break;
  }
  for (int i = leftMost; i <= rightMost; i++) {
    if (s[i] == '.') {
      ans++;
      i += R - 1;
    }
  }
  ans += walk;
  cout << ans << endl;
  return 0;
}
