
#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ok() puts(ok?"Yes":"No");
template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }
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

int m,n;
int grid[100][100];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int visited[100][100];
int num = 1;
int ans = 0;

void dfs(int si, int sj) {
    if (grid[si][sj] == 0) return ;
    chmax(ans,num);
    rep(k,4) {
      int ni = si + dy[k];
      int nj = sj + dx[k];
      if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
      if (visited[ni][nj] || grid[ni][nj] == 0) continue;
      assert(grid[ni][nj]);
      num++;
      visited[ni][nj] = 1;
      dfs(ni,nj);
      num--;
      visited[ni][nj] = 0;
    }
}

int main() {
  cin >> m >> n;
  rep(i, n)rep(j,m) cin >> grid[i][j];
  rep(i,n) {
    rep(j,m) {
      visited[i][j] = true;
      dfs(i,j);
      visited[i][j] = false;
    }
  }
  cout << ans << endl;
  return 0;
}