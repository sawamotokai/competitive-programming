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

string s, t;
int main() {
  cin >> s >> t;
  map<char, char> mp;
  map<char, char> mp2;
  int n = s.size();
  bool ok = true;
  auto has = [&](map<char, char> mp, char c) {
    return !(mp.find(c) == mp.end());
  };
  rep(i, n) {
    if (has(mp, s[i])) {
      if (mp[s[i]] != t[i]) {
        ok = false;
      }
    } else {
      mp[s[i]] = t[i];
      if (has(mp2, t[i])) {
        if (mp[t[i]] != s[i]) {
          ok = false;
        }
      } else {
        mp2[t[i]] = s[i];
      }
    }
  }
  ok();
  return 0;
}
