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
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 


int N,M,S;
int visited[55];
vector<pll> stations;
struct edge {
  int to;
  ll cost, t;
};

vector<vector<edge>> g;
vector<ll> ans;

void dfs(int from, int goal, ll time, int bestStation, int pocket) {
  if (from == goal) {
    ans[goal] = min(ans[goal], time);
    return; 
  }
  rep(i, g[from].size()) {
    edge nextEdge = g[from][i];
    int next = g[from][i].to;
    if (visited[next]==2) continue;
    double b4 = stations[bestStation].first / stations[bestStation].second;
    double st = stations[from].first / stations[from].second;
    if (st > b4) {
      bestStation = from;
    }
    ll time_ = time;
    int pocket_ = pocket;
    if (pocket_<nextEdge.cost) {
      int coinNeeded = nextEdge.cost-pocket_;
      int extraTime = (coinNeeded / stations[bestStation].first + 1) * stations[bestStation].second;
      time_+=extraTime;
      pocket_+=(coinNeeded / stations[bestStation].first + 1) * stations[bestStation].first;
    }
    pocket_-=nextEdge.cost;
    time_+=nextEdge.t;
    
    visited[next]++;
    dfs(next, goal, time_, bestStation, pocket_);
    visited[next]--; 
  }

}

int main() {  
  cin >> N>>M>>S;
  stations.resize(N+1);
  ans.resize(N, LINF);
  g.resize(N+1, vector<edge>());
  rep(i,M) {
    int u,v; ll a,b; cin>>u>>v>>a>>b;
    u--;v--;
    g[u].push_back(edge{v,a,b});
    g[v].push_back(edge{u,a,b});
  } 
  rep(i, N) {
    ll c,d; cin>>c>>d;
    stations[i] = pll(c,d);
  }
  visited[0] = 1;
  rep(i,N-1) {
    dfs(0, i+1, 0, 0, S);
  }
  rep(i, N-1) cout << ans[i+1] << endl;
  return 0;
}