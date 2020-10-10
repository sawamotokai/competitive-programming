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
  int h1 = stoi(s.substr(0, 2));
  int m1 = stoi(s.substr(3, 2));
  int h2 = stoi(t.substr(0, 2));
  int m2 = stoi(t.substr(3, 2));
  int tot = h2 * 60 + m2 - h1 * 60 - m1;
  tot /= 2;
  tot += m1;
  int h3 = (h1 + tot / 60) % 24;
  int m3 = tot % 60;
  if (h3 < 10)
    cout << "0";
  cout << h3 << ":";
  if (m3 < 10)
    cout << "0";
  cout << m3 << endl;
  return 0;
}
