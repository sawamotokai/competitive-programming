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
vi ans;
struct edge {
  int to, id;
};
vector<vector<edge> > g;

void dfs(int v,int c=-1, int from=-1) {
  int k = 1;
  rep(i, g[v].size()) {
    int u = g[v][i].to;
    if (u==from) continue;
    int ei=g[v][i].id;
    if (k==c) k++;
    ans[ei] = k; k++;
    dfs(u,ans[ei], v);
  }
}

int main() {
  int N; cin>>N;
  ans.resize(N-1);
  g.resize(N);
  rep(i,N-1) {
    int a,b; cin>>a>>b;
    a--;b--;
    g[a].push_back((edge){b, i});
    g[b].push_back((edge){a, i});
  }
  dfs(0);
  int mx = 0;
  rep(i,N) mx = max(mx, (int) g[i].size());
  cout << mx << endl;
  rep(i, N-1) cout << ans[i] << endl;
  return 0;
}