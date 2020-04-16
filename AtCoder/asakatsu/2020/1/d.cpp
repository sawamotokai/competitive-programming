#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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
const ll INF = 1e18L + 1;
//clang++ -std=c++11 -stdlib=libc++ 
int H,W; 
vector<string> maze;
int ans =0;
int L[2001][2001];
int R[2001][2001];
int D[2001][2001];
int U[2001][2001];
void dfs(int h, int r) {
  int cnt = L[h][r]+R[h][r]+U[h][r]+D[h][r]-3;
  ans = max(ans, cnt);
}

int main() {
  cin >>H>>W;
  maze.resize(H);
  rep(i,H) cin>>maze[i];
  rep(i, H) rep(j,W) {
    if(maze[i][j]=='#') L[i][j]=R[i][j]=U[i][j]=D[i][j]=0;
    else {
      if (j==0) L[i][j] = 1;
      else L[i][j]=L[i][j-1]+1;
      if(i==0) U[i][j]=1;
      else U[i][j]=U[i-1][j]+1;
    }
  }
    for(int i=H-1; i>=0; i--) for (int j=W-1; j>=0;j--) {
    if(maze[i][j]=='#') L[i][j]=R[i][j]=U[i][j]=D[i][j]=0;
    else {
       if(j==W-1) R[i][j]=1;
      else R[i][j] = R[i][j+1]+1;
      if(i==H-1) D[i][j]=1;
      else D[i][j]=D[i+1][j]+1;
    }
  }

 
   rep(i, H) rep(j,W) {
    if (maze[i][j] == '.') {
     dfs(i,j);
    }
  }
 cout << ans << endl;
  return 0;
}