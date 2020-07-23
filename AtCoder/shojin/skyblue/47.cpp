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



int color[100005]; // 0:=fennic 1:=snule
vi to[100005];

int n;
vi path;

void dfs(int v, int from=-1, int len=0) {
  if (v==n-1) {
    len--;
    int f=(len-1)/2 +1 ;
    rep(i,f) if (color[path[i]] != 2) color[path[i]] = 3;
    if (path.size()>f) color[path[f]] = 4;
    return;
  }
  for (int u: to[v]) {
    if (u==from) continue;
    path.push_back(u);
    dfs(u, v, len+1);
    path.pop_back();
  }
}

int main() {
  cin >> n;
  rep(i,n-1) {
  int a,b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  color[0] = 1;
  color[n-1] = 2;

// find where is the intersection of black and white 
  dfs(0); 

  queue<int> q;

  // fill Black region
  q.push(0);
  while (q.size()) {
    int v=q.front(); q.pop();
    for (int u: to[v]) {
      if (color[u]==1 || color[u]==4 || color[u] == 2) continue;
      color[u] = 1;
      q.push(u);
    }
  }
  // fill white region
  q.push(n-1);
  while (q.size()) {
    int v=q.front(); q.pop();
    for (int u: to[v]) {
      if (color[u]==1||color[u]==2||color[u]==3) continue;
      color[u] = 2;
      q.push(u);
    }
  }

  // count black and white 
  int F=0, S=0;
  q.push(0);
  while (q.size()) {
    int v=q.front(); q.pop();
    if (color[v] == 1) F++;  
    if (color[v] == 2) S++;
    color[v] = 0;
    for (int u:to[v]) {
      if (color[u] == 0) continue;
      q.push(u);
    }
  }
  string winner = "Fennec";
  if (F>S) winner = "Fennec";
  if (F<S) winner = "Snuke";
  if (F==S) {
    winner = "Snuke";
  }
  cout << winner << endl;
  return 0;
}