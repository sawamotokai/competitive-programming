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
template <class T> using minq = priority_queue<T, vector<T>, greater<T>>;
using vP = vector<P>;
inline ll in() {
  ll x;
  scanf("%lld", &x);
  return x;
}
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
inline void priv(vll a) {
  rep(i, (int)a.size() - 1) cout << a[i] << " ";
  cout << a.back() << nl;
}
inline void priv(vi a) {
  rep(i, (int)a.size() - 1) cout << a[i] << " ";
  cout << a.back() << nl;
}
const ll LINF = 8e18L + 1;
const int INF = 8e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// g++ -std=c++17 -stdlib=libc++
// This slows down the execution; even the time complexity, since it checks if
// std funcs such as lower_bound meets prereqs
int flag[51][2501];
int grundy[51][2501];

int rec(int w, int b) {
  if (flag[w][b])
    return grundy[w][b];
  flag[w][b] = 1;
  set<int> st;
  rep2(i, 1, b / 2) {
    if (b - i >= 0)
      st.insert(rec(w, b - i));
  }
  if (w)
    st.insert(rec(w - 1, b + w));
  int nx = 0;
  int ret = 0;
  for (int num : st) {
    if (nx != num) {
      break;
    }
    nx++;
  }
  ret = nx;
  return grundy[w][b] = ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int n;
  cin >> n;
  vi W(n);
  vi B(n);
  rep(i, n) cin >> W[i];
  rep(i, n) cin >> B[i];
  flag[0][0] = 1;
  flag[0][1] = 1;
  int ans = 0;
  rep(i, n) { ans ^= rec(W[i], B[i]); }
  if (ans) {
    cout << "First" << nl;
  } else {
    cout << "Second" << nl;
  }
  return 0;
}
