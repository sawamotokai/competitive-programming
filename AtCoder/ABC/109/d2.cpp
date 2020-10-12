
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

int H, W;
int grid[505][505];
int main() {
  cin >> H >> W;
  rep(i, H) {
    rep(j, W) {
      cin >> grid[i][j];
      grid[i][j] &= 1;
    }
  }
  vvi ans;
  rep(i, H) {
    if (!(i & 1)) {
      rep(j, W) {
        if (i == H - 1 && j == W - 1)
          continue;
        if (grid[i][j] == 1) {
          int nj = j + 1;
          int ni = i;
          if (nj == W) {
            ni++;
            nj--;
          }
          grid[ni][nj] ^= 1;
          vi temp(4);
          temp[0] = i + 1;
          temp[1] = j + 1;
          temp[2] = ni + 1;
          temp[3] = nj + 1;
          ans.pb(temp);
        }
      }
    } else {
      rep3(j, W - 1, 0) {
        if (i == H - 1 && j == 0)
          continue;
        if (grid[i][j] == 1) {
          int nj = j - 1;
          int ni = i;
          if (nj == -1) {
            nj++;
            ni++;
          }
          grid[ni][nj] ^= 1;
          vi temp(4);
          temp[0] = i + 1;
          temp[1] = j + 1;
          temp[2] = ni + 1;
          temp[3] = nj + 1;
          ans.pb(temp);
        }
      }
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size())
      printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
  return 0;
}
