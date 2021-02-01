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

int dp[1004];
int visited[1004];
ii coords[1005];
int R[1004];
int n;

bool touching(int i, int j) {
  ll distSq = (coords[i].fi - coords[j].fi) * (coords[i].fi - coords[j].fi) +
              (coords[i].se - coords[j].se) * (coords[i].se - coords[j].se);
  if (distSq == (R[i] + R[j]) * (R[i] + R[j]))
    return 1;
  return 0;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  cin >> n;
  rep(i, n) cin >> coords[i].fi >> coords[i].se >> R[i];
  rep(i, 1003) { dp[i] = INF; }
  dp[0] = 1;
  queue<ii> q;
  q.push({0, -1});
  while (q.size()) {
    auto [v, from] = q.front();
    q.pop();
    rep(u, n) {
      if (from == u)
        continue;
      if (!touching(v, u))
        continue;
      if (dp[u] == INF) {
        q.emplace(u, v);
        continue;
      }
      if (dp[u] != dp[from]) {
        puts("The input gear cannot move.");
        return 0;
      }
    }
    if (from == -1)
      dp[v] = 1;
    else
      dp[v] = -dp[from];
  }
  if (dp[n - 1] == INF) {
    puts("The input gear is not connected to the output gear.");
    return 0;
  }
  int a = R[n - 1];
  int b = R[0];
  int g = gcd(a, b);
  a /= g;
  b /= g;
  a *= dp[n - 1];
  printf("%d:%d\n", a, b);
  return 0;
}
