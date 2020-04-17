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
int H,W; vector<string> grid;
vvi mem;

int solve(int i, int j) {
  if (i>=H || j>=W || grid[i][j] == '#') {
    return 1;
  } else if (mem[i][j] == -1) {
    int result = 0;
    if (solve(i,j+1) == 0) result = 1;
    if (solve(i+1,j) == 0) result = 1;
    if (solve(i+1,j+1) == 0) result = 1;
    return mem[i][j] = result;
  }
  return mem[i][j];
}

int main() {
  cin>>H>>W;
  grid.resize(H);
  mem.resize(H, vi(W,0-1));
  rep(i,H) cin>>grid[i];
  if (solve(0,0) == 1) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}