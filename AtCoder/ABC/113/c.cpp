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
  int N, M;
  cin >> N >> M;
  vector<set<pair<int, int>>> sets(N);
  vector<string> ans(M);
  rep(i, M) {
    int p, y;
    cin >> p >> y;
    p--;
    sets[p].insert(make_pair(y, i));
  }
  rep(i, N) {
    int t = 1;
    for (auto it = sets[i].begin(); it != sets[i].end(); it++) {
      pair<int, int> p = *it;
      int idx = p.se;
      int y = p.fi + 1;
      string ord = to_string(t++);
      string pref = to_string(i + 1);
      ord.insert(0, 6 - ord.size(), '0');
      pref.insert(0, 6 - pref.size(), '0');
      ans[idx] = pref + ord;
    }
  }
  rep(i, M) cout << ans[i] << endl;
  return 0;
}
