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


int N,M,L,Q; 


int main() {
  cin >>N>>M>>L;
  vector<vector<int>> dist(N, vector<int>(N, INF));
  rep(i,N) dist[i][i]=0;
  rep(i,M)   {
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    dist[a][b]=dist[b][a]=c; 
  }
  rep(k,N)rep(i,N)rep(j,N) dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
  vvi dist2(N,vi(N,INF));
  rep(i,N)rep(j,N) {
    if (dist[i][j] <= L) dist2[i][j] = 1;
  }
  rep(k,N)rep(i,N)rep(j,N) dist2[i][j] = min(dist2[i][j], dist2[i][k]+dist2[k][j]);
  cin >> Q;
  rep(i,Q){
    int s,t; cin >>s>>t;
    s--,t--;
    if (dist2[s][t] == INF) {
      cout << -1 << endl;
    }else {
      cout << dist2[s][t]-1 << endl;
    }
  }
  return 0;
}