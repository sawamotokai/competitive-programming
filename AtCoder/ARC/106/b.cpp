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

vi to[200005];
ll A[200005];
ll B[200005];
int visited[200005];

bool bfs(int st) {
  ll sumA = A[st];
  ll sumB = B[st];
  queue<int> q;
  q.push(st);
  visited[st] = true;
  while (q.size()) {
    int v = q.front();
    q.pop();
    for (int u : to[v]) {
      if (visited[u])
        continue;
      visited[u] = true;
      sumB += B[u];
      sumA += A[u];
      q.push(u);
    }
  }
  if (sumA == sumB)
    return true;
  return false;
}

int main() {
  int N, M;
  cin >> N >> M;
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  bool ok = true;
  rep(i, N) {
    if (visited[i])
      continue;
    ok &= bfs(i);
  }
  ok();
  return 0;
}
