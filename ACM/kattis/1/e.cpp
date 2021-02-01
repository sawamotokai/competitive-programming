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

vi to[100005];
int n;
vi ans;

void dfs(int v = 0, int from = -1, int after = -1) {
  int c = to[v].size();
  if (from != -1)
    c--;
  int cnt = 0;
  bool done = false;
  if (!c)
    ans.pb(v);
  else {
    for (int u : to[v]) {
      if (from == u)
        continue;
      if (after) {
        if ((c / 2 == cnt) && !done) {
          ans.pb(v);
          done = true;
        }
      } else {
        if ((c - 1) / 2 + 1 == cnt && !done) {
          ans.pb(v);
          done = true;
        }
      }
      dfs(u, v, done);
      cnt++;
    }
  }
}

int main() {
  cin >> n;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  dfs();
  rep(i, ans.size()) {
    printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
  }
  return 0;
}
