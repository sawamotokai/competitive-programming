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

int N, M;
ll X, Y;
int a[100006];
int b[100006];
int main() {
  cin >> N >> M >> X >> Y;
  rep(i, N) cin >> a[i];
  rep(i, M) cin >> b[i];
  int p1 = 0, p2 = 0;
  ll time = 0;
  int ans = 0;
  while (p1 < N && p2 < M) {
    bool inB = false;
    while (p1 < N) {
      if (a[p1] >= time) {
        time = X + a[p1];
        p1++;
        inB = true;
        break;
      }
      p1++;
    }
    while (p2 < M && inB) {
      if (b[p2] >= time) {
        time = Y + b[p2];
        p2++;
        ans++;
        break;
      }
      p2++;
    }
  }
  cout << ans << endl;
  return 0;
}
