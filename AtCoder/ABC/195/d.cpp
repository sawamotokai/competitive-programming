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
using P = pair<ll, ll>;
using gt = greater<P>;
using minq = priority_queue<P, vector<P>, gt>;
using vP = vector<P>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
template <class T> void print(const initializer_list<T> &il) {
  for (auto x : il) {
    cout << x << " ";
  }
  cout << "\n";
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, Q;
  cin >> N >> M >> Q;
  vi W(N);
  vi V(N);
  vii I(N);
  vi X(M);
  rep(i, N) cin >> I[i].fi >> I[i].se;
  rep(i, M) cin >> X[i];
  sort(all(I));
  while (Q--) {
    int L, R;
    cin >> L >> R;
    // dp[i][j][k]:=max value s.t., seen i items, j th box has k space
    L--, R--;
    vi B;
    rep(i, M) {
      if (i <= R and i >= L)
        continue;
      B.pb(X[i]);
    }
    sort(all(B));
    int p = 0;
    priority_queue<int> valq;
    ll ans = 0;
    rep(i, B.size()) {
      while (p < N and I[p].fi <= B[i]) {
        valq.push(I[p].se);
        p++;
      }
      if (valq.empty()) {
        continue;
      }
      int v = valq.top();
      valq.pop();
      ans += v;
    }
    cout << ans << endl;
  }
  return 0;
}
