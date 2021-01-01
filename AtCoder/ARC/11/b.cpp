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

int n;

int main() {
  map<char, int> mp;
  mp['b'] = 1;
  mp['c'] = 1;
  mp['d'] = 2;
  mp['w'] = 2;
  mp['t'] = 3;
  mp['j'] = 3;
  mp['f'] = 4;
  mp['q'] = 4;
  mp['v'] = 5;
  mp['l'] = 5;
  mp['s'] = 6;
  mp['x'] = 6;
  mp['p'] = 7;
  mp['m'] = 7;
  mp['h'] = 8;
  mp['k'] = 8;
  mp['n'] = 9;
  mp['g'] = 9;
  mp['z'] = 0;
  mp['r'] = 0;
  cin >> n;
  auto isCons = [](char c) {
    char ng[] = {'a', 'e', 'i', 'o', 'u', 'y', ' ', ',', '.'};
    for (char c2 : ng) {
      if (c == c2)
        return false;
    }
    return true;
  };
  bool any = false;
  while (n--) {
    string s;
    cin >> s;
    int len = s.size();
    string res = "";
    rep(i, len) {
      char c = tolower(s[i]);
      if (isCons(c)) {
        res += mp[c] + '0';
      }
    }
    if (res != "") {
      if (any)
        cout << " ";
      any = true;
      cout << res;
    }
  }
  cout << endl;
  return 0;
}
