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
#define pcnt(x) __builtin_popcountll(x)
#define df(x) ll x = in();
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
void solve() {
  string s;
  int n;
  cin >> s >> n;
  vi b(n);
  rep(i, n) cin >> b[i];
  string ans('#', n);
  vi cnt(26);
  rep(i, s.size()) cnt[s[i] - 'a']++;
  priority_queue<char> pq;
  rep(i, s.size()) pq.push(s[i]);
  vi used(n);
  vi confirmedPos;
  rep(i, n) if (s[i] == '0') {
    confirmedPos.pb(i);
    ans[i] = pq.top();
    pq.pop();
    break;
  }
  auto f = [&](int i) {
    int ret = 0;
    for (int num : confirmedPos)
      ret += abs(i - num);
    return ret;
  };
  int t = 1;
  while (t < n) {
    vi toadd;
    rep(i, n) {
      if (f(i) == b[i]) {
        toadd.pb(i);
        ans[i] = pq.top();
        pq.pop();
        t++;
      }
    }
    for (int ad : toadd)
      confirmedPos.pb(ad);
  }
  rep(i, n) cout << ans[i];
  cout << nl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
