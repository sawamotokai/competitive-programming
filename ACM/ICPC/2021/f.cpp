#include <bits/stdc++.h>
#include <cassert>
#include <string>
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

vector<string> get() {
  cout << "hi" << endl;
  vector<string> ret;
  string line;
  getline(cin, line);
  flush(cout);
  int st = 0;
  int ln = 0;
  // cout << line << endl;
  rep(i, line.size()) {
    if (line[i] == ' ') {
      ret.pb(line.substr(st, ln));
      ln = 0;
      st = i + 1;
    }
    ln++;
  }
  ret.pb(line.substr(st));
  // for (string str : ret)
  // cout << str << endl;
  return ret;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) { vector<string> words = get(); }
  return 0;
}
