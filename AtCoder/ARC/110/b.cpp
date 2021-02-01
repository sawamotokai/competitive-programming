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

int N;
string S;

int main() {
  cin >> N >> S;
  if (S == "1") {
    ll out = 2e10;
    printf("%lld\n", out);
    return 0;
  }
  if (S == "11" or S == "0") {
    ll out = 1e10;
    printf("%lld\n", out);
    return 0;
  }
  if (S == "00") {
    cout << 0 << endl;
    return 0;
  }
  if (S == "01") {
    ll out = 1e10 - 1;
    printf("%lld\n", out);
    return 0;
  }
  if (S == "10") {
    ll out = 1e10;
    printf("%lld\n", out);
    return 0;
  }
  int f = -1;
  rep(i, 3) {
    if (S[i] == '0') {
      f = i;
      break;
    }
  }
  if (f == -1) {
    cout << 0 << endl;
    return 0;
  }
  int z = 0;
  int c = 0;
  rep2(i, f, N - 1) {
    if (c == 0) {
      z++;
      if (S[i] != '0') {
        cout << 0 << endl;
        return 0;
      }
    } else {
      if (S[i] != '1') {
        cout << 0 << endl;
        return 0;
      }
    }
    c++;
    c %= 3;
  }
  ll ans = 1e10 - z + (S.back() == '0');
  cout << ans << endl;
  return 0;
}
