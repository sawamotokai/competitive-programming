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

int main() {
  string s;
  cin >> s;
  int n = s.size();
  string t = "";
  rep(i, n) {
    if (s[i] != 'x')
      t += s[i];
  }
  int lo = 0;
  int hi = t.size() - 1;
  while (lo <= hi) {
    if (t[lo] != t[hi]) {
      cout << -1 << endl;
      return 0;
    }
    lo++;
    hi--;
  }
  int tlen = t.size();
  if (tlen == 0) {
    cout << 0 << endl;
    return 0;
  }
  int le = (tlen - 1) / 2 + 1;
  int ri = le;
  int cnt = 0;
  if (tlen % 2 == 0)
    ri++;
  int p1 = -1, p2 = -1;
  rep(i, n) {
    if (s[i] != 'x') {
      cnt++;
    }
    if (cnt == le && p1 == -1) {
      p1 = i;
    }
    if (cnt == ri && p2 == -1) {
      p2 = i;
    }
  }
  int ans = 0;
  queue<char> q1;
  queue<char> q2;
  while (p1 >= 0 && p2 < n) {
    q1.push(s[p1--]);
    q2.push(s[p2++]);
    if (p1 < 0) {
      while (p2 < n)
        q2.push(s[p2++]);
    }
    if (p2 >= n) {
      while (p1 >= 0)
        q1.push(s[p1--]);
    }
  }
  while (q1.size() && q2.size()) {
    if (q1.front() == q2.front()) {
      q1.pop();
      q2.pop();
    } else if (q1.front() == 'x') {
      ans++;
      q1.pop();
    } else {
      ans++;
      q2.pop();
    }
  }
  ans += q1.size() + q2.size();
  cout << ans << endl;
  return 0;
}
