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
using gt = greater<ii>;
using minq = priority_queue<ii, vector<ii>, gt>;
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

struct edge {
  int to, w;
  edge(int to, int w) : to(to), w(w){};
};

vector<edge> to[2003];

int main() {
  int N, M;
  cin >> N >> M;
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    to[a].eb(b, c);
  }
  rep(i, N) {
    minq q;
    vector<int> dist(N);
    rep(j, N) dist[j] = INF;
    dist[i] = 0;
    int ans = INF;
    q.emplace(0, i);
    while (q.size()) {
      auto [c, v] = q.top();
      q.pop();
      if (v != i && dist[v] < c)
        continue;
      for (edge u : to[v]) {
        if (chmin(dist[u.to], dist[v] + u.w))
          q.emplace(c + u.w, u.to);
        if (u.to == i)
          chmin(ans, c + u.w);
      }
    }
    if (ans == INF)
      ans = -1;
    cout << ans << endl;
  }
  return 0;
}
