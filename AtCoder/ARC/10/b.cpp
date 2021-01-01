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

int getDay(int m, int d) {
  // 0 := Sat
  int daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int days = 0;
  rep(i, m - 1) days += daysInMonth[i];
  days += d;
  return days;
}

int main() {
  int n;
  cin >> n;

  set<int> st;
  rep2(i, 1, 366) {
    if ((i + 7) % 7 == 0 || (i + 7) % 7 == 1)
      st.insert(i);
  }
  rep(i, n) {
    string s;
    cin >> s;
    int m, d;
    if (s[1] == '/') {
      m = s[0] - '0';
      d = stoi(s.substr(2));
    } else {
      m = stoi(s.substr(0, 2));
      d = stoi(s.substr(3));
    }
    int day = getDay(m, d);
    while (st.count(day))
      day++;
    if (day <= 366)
      st.insert(day);
  }
  int prev = -1;
  int cnt = 0;
  int ans = 2;
  queue<int> q;
  for (int num : st) {
    if (num - prev == 1) {
      cnt++;
      chmax(ans, cnt);
    } else
      cnt = 1;
    prev = num;
  }
  chmin(ans, 366);
  cout << ans << endl;
  return 0;
}
