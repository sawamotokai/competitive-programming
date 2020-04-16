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
  int H,W; cin>>H>>W;
  vector<string> maze(H);
  rep(i,H) {
    cin >> maze[i];
  }
  rep(i,H) rep(j,W) {
    if (maze[i][j] == '#') continue;
    int cnt = 0;
    int dx[]={0, 1, 1, 1, 0, -1, -1, -1}, dy[]={1,1,0,-1,-1,-1,0,1};
    for (int k=0; k<8; k++) {
      int x = j+dx[k], y = i+dy[k];
      if (x>=0 && x<W && y>=0 && y<H && maze[y][x] == '#') cnt++;
    }
    maze[i][j] = '0'+cnt;
    // maze[i][j] = static_cast<char>(cnt);
  }
  rep(i,H) cout << maze[i] << endl;
  return 0;
}