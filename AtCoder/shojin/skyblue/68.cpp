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
  int N; cin>>N;
  vector<string> grid(N);
  rep(i,N)cin>>grid[i];

  int ans = 0;
  rep(i,N){
    for(int j=N-1;j>=0;j--) {
      if (grid[i][j] == '.') {
        ans++;
        rep(k,j+1) {
          grid[i][k] = 'o';
        }
        if (i!=N-1) for (int k=j;k<N;k++) grid[i+1][k] = 'o';
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}