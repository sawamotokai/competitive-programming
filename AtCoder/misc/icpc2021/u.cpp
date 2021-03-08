
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
using gt = greater<ii>;
using minq = priority_queue<ii, vector<ii>, gt>;
using P = pair<ll, ll>;
using vP = vector<P>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
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

int charToInt(char c) {
  int ret = 0;
  if (c == 'a')
    ret = 10;
  else if (c == 'b')
    ret = 11;
  else if (c == 'c')
    ret = 12;
  else if (c == 'd')
    ret = 13;
  else if (c == 'e')
    ret = 14;
  else if (c == 'f')
    ret = 15;
  else
    ret = c - '0';
  return ret;
}

char xorChar(char a, char b) {
  int aa = charToInt(a);
  int bb = charToInt(b);
  int ret = aa ^ bb;
  char c;
  if (ret >= 10) {
    c = char('a' + ret - 10);
  } else {
    c = char('0' + ret);
  }
  return c;
}

string XOR(string s, string t) {
  int n = s.size();
  assert(s.size() == t.size());
  string ret = "";
  rep(i, n) { ret += xorChar(s[i], t[i]); }
  return ret;
}

int f(vs &val, string s, string t) {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  vs b(n);
  vs a(m);
  rep(i, n) cin >> b[i];
  rep(i, m) cin >> a[i];
  vs val(n);
  val[0] = b[0];
  rep2(i, 1, n - 1) { val[i] = XOR(val[i - 1], b[i]); }
  rep(i, m) {
    bool ok = 0;
    rep(j, n) {
      if (val[j] == a[i]) {
        cout << i + 1 << endl;
        ok = 1;
        break;
      }
    }
    if (!ok)
      cout << -1 << endl;
  }
  rep(i, n) cout << val[i] << endl;
  return 0;
}
