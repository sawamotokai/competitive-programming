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
  int H,W,K; cin>>H>>W>>K;
  vector<string> maze(H);
  int black = 0;
  rep(i,H) cin >> maze[i];
  rep(i,H) rep(j,W) if (maze[i][j] == '#') black++;

  int ans =0;
  rep(h, 1<<H) {
    rep(w, 1<<W) {
      int black2 = black;
      vector<string> maze2 = maze;
      rep(i, H) {
        if ((h>>i)&1) {
          rep(x, W) {
            if (maze2[i][x] == '#') {
              maze2[i][x] = '.';
              black2--;
            }
          }
        }
      }
      
      rep(j, W) {
        if ((w>>j)&1) {
          rep(y, H) {
            if (maze2[y][j] == '#') {
              maze2[y][j] = '.';
              black2--;
            }
          }
        }
      }

      if (black2==K) {
        ans++;
      }

    }
  }
  cout << ans << endl;
  return 0;
}