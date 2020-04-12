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
int main() {
  int H,W; cin >>H>>W;
  vector<string> maze;
  rep(i,H) {
    string t;
    cin >> t;
    maze.push_back(t);
  }

  auto bfs = [&](ii start, ii goal) {
    if (start == goal) return 0;
    queue<ii> q;
    queue<ii> next;
    vector<vb> visited(H, vb(W, false));
    int dx[] = {1,0,-1,0}, dy[]={0,-1,0,1};
    next.push(start);
    int level =0;
    while(next.size()) {
      while(next.size()) {
        q.push(next.front()); next.pop();
      }
      while (q.size()) {
        ii p = q.front(); q.pop();
        if (p == goal) return level;
        for (int m=0; m<4; m++) {
          if (p.first + dy[m] >=0 && p.first + dy[m] < H && p.second + dx[m]>= 0 && p.second+dx[m] < W && maze[p.first + dy[m]][p.second+dx[m]] == '.' && !visited[p.first + dy[m]][p.second+dx[m]]) {
            next.push(ii(p.first+dy[m], p.second + dx[m]));
            visited[p.first + dy[m]][p.second+dx[m]] = true;
          }
        }
      }
      level++;
    }
    return --level;
  };
  int ans=0;
  rep(i,H) {
    rep(j,W) {
      if (maze[i][j]=='#') continue;
      rep(k, H) rep(l, W) {
        int result = bfs(ii(i,j),ii(k,l));
        ans = max(ans, result);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}