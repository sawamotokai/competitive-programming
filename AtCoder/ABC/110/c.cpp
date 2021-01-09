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
  int n = s.size();
  rep(i, n) {
    if (mp.find(s[i]) != mp.end())
      s[i] = mp[s[i]];
    if (s[i] != t[i]) {
      if (mp.find(s[i]) != mp.end() && mp[t[i]] != s[i]) {
        cout << s[i] << " " << t[i] << endl;
        puts("No");
        return 0;
      }
      mp[s[i]] = t[i];
      mp[t[i]] = s[i];
    } else {
      if (mp.find(s[i]) != mp.end()) {
        cout << s[i] << " " << t[i] << endl;
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  return 0;
}
