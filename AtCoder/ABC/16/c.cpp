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

int main() {
  int n, m;
  cin >> n >> m;
  vi numFriends(n);
  vector<set<int>> f(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    numFriends[a]++;
    numFriends[b]++;
    f[a].insert(b);
    f[b].insert(a);
  }
  auto isFriend = [&](int a, int b) {
    if (f[a].find(b) == f[a].end())
      return false;
    return true;
  };
  rep(i, n) {
    int now = 0;
    vi ff(n);
    rep(j, n) {
      if (i == j)
        continue;
      if (!isFriend(i, j))
        continue;
      rep(k, n) {
        if (k == i)
          continue;
        if (k == j)
          continue;
        if (isFriend(j, k) && !isFriend(k, i)) {
          ff[k] = 1;
        }
      }
    }
    rep(j, n) if (ff[j] == 1) now++;
    cout << now << endl;
  }
  // rep(i, n) cout << f[i].size() << endl;

  return 0;
}
