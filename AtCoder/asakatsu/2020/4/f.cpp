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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int H,W; cin>>H>>W;
  vector<string> maze(H);
  rep(i,H) cin>>maze[i];
  int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
  queue<ii> next;
  queue<ii> process;
  next.push(ii(0,0));
  int level=1;
  int walls =0;
  rep(i,H) rep(j,W) {
    if (maze[i][j]=='#') walls++;
  }
  while (next.size()) {
    level++;
    while (next.size()) {
      process.push(next.front()); next.pop();
    }
    while (process.size()) {
      ii pos = process.front(); process.pop();
      for (int i=0; i<4;i++) {
        int x = pos.second+dx[i], y=pos.first+dy[i];
        if (x>=0&&x<W && y>=0 && y<H && maze[y][x] == '.') {
          next.push(ii(x,y));
          maze[y][x] = static_cast<char>(level);
        }
      }
      
    }
  }
  int path = maze[H-1][W-1];
  int ans=H*W-path-walls;
  cout << ans <<endl;
  return 0;
}