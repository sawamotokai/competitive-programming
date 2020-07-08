// abc113d
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
const int mod = 1e9 + 7;

ll dp[101][10];
int main() {
  int h,w,k; cin >> h >> w >> k;
  dp[0][0] = 1;
  rep(i, h) {
    rep(j, w) {
      rep(mask, 1<<(w-1)) {
        bool ok = true;
        rep(bit, w-2) {
          if ((mask >> bit)& 1 && (mask >> (bit+1)) & 1) ok = false;
        }
        if (!ok) continue;
        int nj = j;
        if ((mask >> j) & 1) nj++;
        else if ((mask >> (j - 1)) & 1 && j > 0) nj--;
        (dp[i+1][nj] += dp[i][j]) %= mod;
      }
    }
  }
  printf("%lld\n", dp[h][k-1]);
  return 0;
}