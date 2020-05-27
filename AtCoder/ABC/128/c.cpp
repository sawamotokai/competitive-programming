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


int n,m;
int lights[11][11];
vi p;
int sw[11];
int ans =0;
void dfs(int k=0){
  if (k==n) {
    // do something
    vi p2(m,0);
    rep(i,n) {
      int on = sw[i];
      if (!on) continue;
      rep(j,m) {
        if (lights[j][i]) p2[j]++; 
      }
    }
    rep(i,m) {
      if (p2[i]%2!=p[i]) return;
    }
    ans++;
    return ;
  } 
  sw[k] = true;
  dfs(k+1);
  sw[k] = false;
  dfs(k+1);
   
}

int main() {
  cin >> n >> m;
  rep(i,m) {
    int k;cin>>k;
    rep(j,k) {
      int hoge; cin >> hoge;
      hoge--;
      lights[i][hoge]=1;
    }
  } 
  p.resize(m);
  rep(i,m) cin >> p[i];
  dfs();
  cout << ans << endl;
  return 0;
}