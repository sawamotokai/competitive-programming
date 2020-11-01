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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
// clang++ -std=c++11 -stdlib=libc++

int main() {
  string s;
  cin >> s;
  int n = s.length();
  map<char, int> mp;
  rep(i, n) { mp[s[i]]++; }
  bool ok = false;
  if (n == 1) {
    if (s == "8")
      ok = true;
  } else if (n == 2) {
    if (stoi(s) % 8 == 0)
      ok = true;
    string rev = s;
    reverse(all(rev));
    if (stoi(rev) % 8 == 0)
      ok = true;
  } else {
    rep2(i, 104, 999) {
      map<char, int> mp2 = mp;
      if (i % 8 != 0)
        continue;
      int now = i;
      bool isEight = true;
      while (now) {
        int dig = now % 10;
        now /= 10;
        char c = '0' + dig;
        if (mp2[c] > 0)
          mp2[c]--;
        else {
          isEight = false;
          break;
        }
      }
      if (isEight) {
        ok = true;
        break;
      }
    }
  }
  ok();

  return 0;
}
