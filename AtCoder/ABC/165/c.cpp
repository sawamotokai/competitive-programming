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

bool used[11];
int a[52];
int b[52];
int c[52];
int d[52];
int N,M,Q; 
int ans = 0;
void dfs(int t, vi &perm) {
  if (t == N) {
    int sum = 0;
    rep (i,Q) {
      if (perm[b[i]] - perm[a[i]] == c[i]) sum += d[i];
    } 
    ans = max(ans, sum);
    return ;
  }
  for (int i=perm[t-1]; i<=M; i++) {
    perm[t] = i;
    dfs(t+1, perm);
    perm[t] = INF;
  }
}

int main() {
  cin >>N>>M>>Q;
  rep(i,Q){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--; b[i]--;
  }
  vi perm(N, INF);
  for (int i=1; i<=M;i++) {
    perm[0] = i;
    dfs(1,perm);
    perm[0] = INF;
  }
  cout << ans << endl;
  return 0;
}