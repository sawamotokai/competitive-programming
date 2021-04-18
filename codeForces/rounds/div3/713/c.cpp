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
inline void priv(vi a) {
  rep(i, (int)a.size())
      printf("%d%c", a[i], i == (int)a.size() - 1 ? '\n' : ' ');
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

void solve() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  int n = s.size();
  int o = 0;
  int z = 0;
  rep(i, n) {
    if (s[i] == '0')
      z++;
    if (s[i] == '1')
      o++;
  }
  for (int i = 0; i < (n) / 2; i++) {
    if (s[i] == s[n - 1 - i]) {
      continue;
    }
    if (s[i] == '?') {
      if (s[n - 1 - i] == '0') {
        s[i] = '0';
        z++;
      } else {
        s[i] = '1';
        o++;
      }
    } else if (s[n - 1 - i] == '?') {
      if (s[i] == '0') {
        s[n - 1 - i] = '0';
        z++;
      } else {
        s[n - 1 - i] = '1';
        o++;
      }
    } else {
      cout << -1 << nl;
      return;
    }
  }
  rep(i, n / 2) {
    if (s[i] != '?')
      continue;
    if (a - z >= 2) {
      s[i] = '0';
      s[n - 1 - i] = '0';
      z += 2;
    } else if (b - o >= 2) {
      s[i] = '1';
      s[n - 1 - i] = '1';
      o += 2;
    } else {
      cout << -1 << nl;
      return;
    }
  }
  if (n & 1) {
    if (o < b)
      s[n / 2] = '1';
    if (z < a)
      s[n / 2] = '0';
  }
  if (a < z or b < o) {
    cout << -1 << nl;
    return;
  }
  cout << s << nl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
