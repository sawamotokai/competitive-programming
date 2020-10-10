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
  vi exists(1000);
  int n = s.size();
  bool ok = true;
  rep(i, n) exists[t[i]] = true;
  rep(i, n) {
    if (mp.find(t[i]) == mp.end()) {
      if (t[i] != s[i]) {
        if (exists[s[i]]) {
          if (mp.find(s[i]) != mp.end() && mp[s[i]] != t[i])
            ok = false;
          mp[t[i]] = s[i];
          mp[s[i]] = t[i];
        }
      } else {
        if (mp.find(t[i]) != mp.end() && mp[t[i]] != t[i])
          ok = false;
        mp[t[i]] = t[i];
      }
      if (t[i] == s[i])
        mp[t[i]] = t[i];
      else if (exists[s[i]] && mp.find(s[i]) == mp.end() ||
               (mp.find(s[i]) != mp.end() && mp[s[i]] == t[i]))
        mp[t[i]] = s[i];
    } else {
      if (mp[t[i]] == s[i])
        continue;
      ok = false;
    }
  }
  ok();
  return 0;
}
