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

int N;
ll K;
ll cost[10][10];
int visited[10];
int ans;
void dfs(int m = 0, int v = 0, ll sum = 0) {
  if (m == N - 1) {
    if (sum + cost[v][0] == K)
      ans++;
    return;
  }
  rep(i, N) {
    if (v == -1) {
      visited[i] = 1;
      dfs(1, i, 0);
      visited[i] = 0;
      continue;
    }
    if (visited[i])
      continue;
    visited[i] = 1;
    dfs(m + 1, i, sum + cost[v][i]);
    visited[i] = 0;
  }
}

int main() {
  cin >> N >> K;
  rep(i, N) {
    rep(j, N) { cin >> cost[i][j]; }
  }
  visited[0] = 1;
  dfs();
  cout << ans << endl;

  return 0;
}
