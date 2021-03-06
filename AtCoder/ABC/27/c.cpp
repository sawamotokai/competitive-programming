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

ll n;
int f(ll now, bool taka) {
  if (now > n)
    return taka;
  if (f(now * 2LL, !taka) and f(now * 2LL + 1LL, !taka) and !taka) {
    return 1;
  }
  if (!f(now * 2LL, !taka) and !f(now * 2LL + 1LL, !taka) and taka) {
    return 0;
  }
  return taka;
}

int main() {
  cin >> n;
  int k = 1;
  ll now = 1;
  rep(i, 64) {
    now <<= 1;
    if (now <= n)
      k++;
    else
      break;
  }
  ll x = 1;
  rep(i, k) {
    if ((i & 1) == (k & 1)) {
      x *= 2;
    } else {
      x *= 2;
      x++;
    }
    if (x > n) {
      if (i & 1) {
        puts("Takahashi");
      } else {
        puts("Aoki");
      }
      break;
    }
  }
  return 0;
}
