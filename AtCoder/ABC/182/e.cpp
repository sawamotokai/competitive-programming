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

int blocks[1505][1505];
int lights[1505][1505];
int seen[1505][1505];

int main() {
  int H, W, N, M;
  cin >> H >> W >> N >> M;
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    lights[a][b] = 1;
  }
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    blocks[a][b] = 1;
  }
  int ans = 0;
  rep(i, H) {
    int now = 0;
    int li = 0;
    rep(j, W) {
      if (blocks[i][j]) {
        if (li) {
          ans += now;
        } else {
          rep(k, j) seen[i][k] = 0;
        }
        now = 0;
        li = 0;
      } else {
        if (!seen[i][j]) {
          now++;
          seen[i][j] = 1;
        }
      }
      if (lights[i][j])
        li = 1;
      if (j == W - 1) {
        if (li)
          ans += now;
        else {
          int b = 0;
          rep(k, W) if (blocks[i][k]) b = k;
          rep2(k, b, W - 1) seen[i][k] = 0;
        }
      }
    }
  }
  rep(j, W) {
    int now = 0;
    int li = 0;
    rep(i, H) {
      if (blocks[i][j]) {
        if (li) {
          ans += now;
        }
        now = 0;
        li = 0;
      } else {
        if (!seen[i][j]) {
          now++;
        }
      }
      if (lights[i][j])
        li = 1;
      if (i == H - 1 && li) {
        ans += now;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
