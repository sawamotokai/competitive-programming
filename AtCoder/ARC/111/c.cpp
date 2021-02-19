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
  int N;
  cin >> N;
  vii C(N);
  vi cnt(400005);
  rep(i, N) {
    cin >> C[i].fi >> C[i].se;
    if (C[i].fi == C[i].se)
      cnt[C[i].fi]++;
    else {
      cnt[C[i].fi]++;
      cnt[C[i].se]++;
    }
  }
  priority_queue<vector<pair<ii, int>>, pair<ii, int>, greater<pair<ii, int>>>
      pq;
  vector<bool> added(400006);
  rep(i, N) {
    pq.emplace(cnt[C[i].fi], {i, 0});
    pq.emplace(cnt[C[i].se], {i, 1});
  }
  vector<bool> used(400006);
  int ans = 0;
  while (pq.size()) {
    auto p = pq.top();
    pq.pop();
    int num = 0;
    if (p.se.se)
      num = C[p.se.fi].se;
    else
      num = C[p.se.fi].fi;
    if (used[num] || p.fi == 0)
      continue;
    ans++;
    pq.emplace(p.fi - 1, {p.se.fi, p.se.se});
    int other = 0;
    if (p.se.se)
      other = C[p.se.fi].fi;
    else
      other = C[p.se.fi].se;
    pq.emplace()
  }
  return 0;
}
