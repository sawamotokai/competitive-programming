#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define nl '\n'
#define endl '\n'
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
using vvll = vector<vll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vs = vector<string>;
using gt = greater<ii>;
using minq = priority_queue<ii, vector<ii>, gt>;
using P = pair<ll, ll>;
using vP = vector<P>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
inline void priv(vi a) {
  rep(i, (int)a.size())
      printf("%d%c", a[i], i == (int)a.size() - 1 ? '\n' : ' ');
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++

int n;
string s;
ll ans;
int to[10][10];

int getDist(string &key, int i, int j) {
  int id1 = -1;
  int id2 = -1;
  rep(k, 10) {
    if (key[k] - '0' == i)
      id1 = k;
    if (key[k] - '0' == j)
      id2 = k;
  }
  return abs(id1 - id2);
}
int used[10];
string fin;
void dfs(string key = "") {
  if (key.size() == 9) {
    ll sum = 0;
    rep2(i, 1, 9) {
      rep2(j, 1, 9) {
        if (i == j)
          continue;
        int d = getDist(key, i, j);
        // cout << key << " " << d << " " << j << " " << i << endl;
        sum += to[i][j] * d;
      }
    }
    rep(i, 9) if (key[i] == s[0]) sum += i;
    if (chmin(ans, sum))
      fin = key;
    return;
  }
  rep2(i, 1, 9) {
    if (used[i])
      continue;
    string ns = key + char(i + '0');
    used[i] = true;
    dfs(ns);
    used[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ans = LINF;
  cin >> s;
  n = s.size();
  rep(i, n - 1) {
    int a = s[i] - '0';
    int b = s[i + 1] - '0';
    to[a][b]++;
  }
  dfs();
  ans += n;
  cout << ans << endl;
  return 0;
}
