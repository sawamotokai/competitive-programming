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
using gt = greater<ii>;
using minq = priority_queue<ii, vector<ii>, gt>;
using P = pair<ll, ll>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
inline void priv(vi a) {
  rep(i, (int)a.size())
      printf("%d%c", a[i], i == (int)a.size() - 1 ? '\n' : ' ');
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
ll ten[] = {1, 10, 100, 1000, 10000, 100000};
// clang++ -std=c++11 -stdlib=libc++

int main() {
  ll K;
  string S, T;
  cin >> K >> S >> T;
  ll deno = (ll)(9 * K - 8) * (ll)(9 * K - 9);
  vll rest(10, K);
  vll cntT(10);
  vll cntA(10);
  rep(i, 4) {
    rest[S[i] - '0']--;
    rest[T[i] - '0']--;
    cntT[S[i] - '0']++;
    cntA[T[i] - '0']++;
  }
  ll nume = 0;
  rep2(i, 1, 9) {
    rep2(j, 1, 9) {
      if (i == j) {
        if (rest[i] - 2 < 0)
          continue;
      } else {
        if (rest[i] - 1 < 0 || rest[j] - 1 < 0)
          continue;
      }
      vll t = cntT;
      t[i]++;
      vll a = cntA;
      a[j]++;
      ll st = 0;
      ll sa = 0;
      rep(k, 10) {
        st += k * ten[t[k]];
        sa += k * ten[a[k]];
      }
      if (st > sa) {
        if (i == j) {
          ll add = (rest[i]) * (rest[i] - 1);
          nume += add;
        } else {
          nume += rest[i] * rest[j];
        }
      }
    }
  }
  double ans = double(nume) / double(deno);
  printf("%.10f\n", ans);
  //  cout << nume << " " << deno << endl;
  return 0;
}
