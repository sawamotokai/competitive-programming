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
inline void priv(vll a) {
  rep(i, (int)a.size())
      printf("%lld%c", a[i], i == (int)a.size() - 1 ? '\n' : ' ');
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
  int n;
  cin >> n;
  vvll c(n, vll(n));
  rep(i, n) { rep(j, n) cin >> c[i][j]; }
  vll a(n);
  vll b(n);

  ll mn = LINF;
  rep(j, n) chmin(mn, c[0][j]);
  rep(j, n) b[j] = c[0][j] - mn;
  rep2(i, 1, n - 1) {
    ll nowmn = LINF;
    rep(j, n) chmin(nowmn, c[i][j]);
    rep(j, n) {
      if (b[j] != c[i][j] - nowmn) {
        puts("No");
        return 0;
      }
    }
  }

  mn = LINF;
  rep(i, n) chmin(mn, c[i][0]);
  rep(i, n) a[i] = c[i][0] - mn;
  rep2(i, 1, n - 1) {
    ll nowmn = LINF;
    rep(j, n) chmin(nowmn, c[j][i]);
    rep(j, n) {
      if (a[j] != c[j][i] - nowmn) {
        puts("No");
        return 0;
      }
    }
  }

  ll d = c[0][0] - b[0] - a[0];
  rep(i, n) b[i] += d;
  printf("Yes\n");
  priv(a);
  priv(b);
  return 0;
}
