#include <algorithm>
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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++

int f(double n, int deno, int prec) {
  double tole = 1;
  rep(i, prec) tole /= 10;
  rep2(i, 1, deno - 1) {
    double now = double(i) / double(deno);
    double dif = now - n;
    if (abs(dif) <= tole) {
      printf("%d/%d\"\n", i, deno);
      return 1;
    }
  }
  return 0;
}

void solve() {
  string s;
  cin >> s;
  double n = stod(s);
  int t;
  int prec;
  int dot = -1;
  rep(i, s.size()) if (s[i] == '.') dot = i;
  if (dot != -1) {
    if (dot) {
      string sub = s.substr(0, dot);
      t = stoi(sub);
    }
    prec = s.size() - dot - 1;
  } else {
    t = stoi(s);
    prec = 0;
  }
  if (t) {
    cout << t;
    if (prec == 0) {
      cout << "\"" << endl;
      return;
    } else {
      cout << " ";
    }
  }
  s = "0" + s.substr(dot);
  n = stod(s);
  cout << n << " " << s << " " << prec << endl;
  rep2(i, 1, 7) {
    if (f(n, 1 << i, prec))
      return;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
