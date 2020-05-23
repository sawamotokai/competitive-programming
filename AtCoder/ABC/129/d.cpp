#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
typedef map<string, int> msi;
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int H,W; cin >> H >> W;
  vector<string> maze(H);
  rep(i,H) {
    cin >> maze[i];    
  }
  vvi up(H, vi(W));
  vvi down(H, vi(W));
  vvi right(H, vi(W));
  vvi left(H, vi(W));
  rep(i, H) {
    rep(j,W) {
      if (maze[i][j] == '#') {
        up[i][j] = down[i][j] = right[i][j] = left[i][j] = 0;
        continue;
      }
      if (i) {
        if (maze[i-1][j] == '#') up[i][j] = 0;
        else up[i][j]=up[i-1][j]+1;
      } 
     if (j) {
        if (maze[i][j-1] == '#') left[i][j] = 0;
        else left[i][j] = left[i][j-1]+1;
      }
   }
  }
  for (int i=H-1; i>=0; i--) {
    for (int j=W-1; j>=0; j--) {
      if (j<W-1) {
        if (maze[i][j + 1] == '#') right[i][j] = 0;
        else right[i][j] = right[i][j+1] + 1;
      }
       if (i<H-1) {
        if (maze[i+1][j] == '#') down[i][j] = 0;
        else down[i][j] = down[i+1][j] + 1;
      }
    }
  }
  int ans = 0;
  rep(i,H) {
    rep(j,W) {
      if (maze[i][j] == '#') continue;
      int foo = up[i][j]+down[i][j]+right[i][j]+left[i][j]+1;
      ans = max(ans, foo);
    }
  }
  cout<<ans<<endl;
  return 0;
}