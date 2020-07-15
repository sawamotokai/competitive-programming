#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  // abc99d
  int N,C; cin >> N >> C;
  vvi d(C, vi(C));
  vvi c(N, vi(N));
  rep(i,C) rep(j, C) cin >> d[i][j];
  rep(i,N) rep(j, N) cin >> c[i][j];
  vector<map<int, int>> mps(3);
  rep(y, N) rep(x, N) {
    int md = (x+y+2) % 3;
    int color = c[y][x];
    mps[md][color]++;
  }
  int ans = INF;
  rep(i, C) {
    rep(j, C) {
      if (i==j) continue;
      rep(k, C) {
        if (j==k || i == k) continue;
        int num = 0;
        rep(mp, 3) {
          for (auto p: mps[mp]) {
            int before = p.first;
            int cnt = p.second;
            --before;
            int after = -1;
            if (mp == 0) after = i;
            if (mp == 1) after = j;
            if (mp == 2) after = k;
            num += cnt * d[before][after];
          }
        }
        chmin(ans, num);
      }
    }
  }
  cout << ans << endl;
  return 0;
}