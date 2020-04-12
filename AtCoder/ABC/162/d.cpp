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
 
// 0 -> R, 1 -> G, 2 -> B
 
map<char, bool> usedColors;
int N; string s;
int R[4005];
int G[4005];
int B[4005];
ll ans = 0;
void dfs(int j, int diff) {
  if(!usedColors['R']) {
      ans+=R[j+1];
      if (j+diff<N && s[j+diff] == 'R') ans--;
  }
  if(!usedColors['G']) {
      ans+=G[j+1];
      if (j+diff<N && s[j+diff] == 'G') ans--;
  }
  if(!usedColors['B']) {
      ans+=B[j+1];
      if (j+diff<N && s[j+diff] == 'B') ans--;
  }
}
 
int main() {
  usedColors['R'] = false;
  usedColors['G'] = false;
  usedColors['B'] = false;
  cin>>N>>s;
  int r=0,g=0,b=0;
  rep(i,N) {
    if (s[i] == 'R') r++;
    if (s[i] == 'G') g++;
    if (s[i] == 'B') b++;
  }
  R[0] = r;
  G[0] = g;
  B[0] = b;
  rep(i,N) {
    R[i+1] = R[i];
    G[i+1] = G[i];
    B[i+1] = B[i];
    if (s[i]=='R') R[i+1]--;
    if (s[i]=='G') G[i+1]--;
    if (s[i]=='B') B[i+1]--;
  }
 
  rep(i,N) {
    usedColors[s[i]] = true;
    for (int j=i+1; j<N; j++) {
      if (usedColors[s[j]]) continue;
      usedColors[s[j]] = true;
      dfs(j, j-i);
      usedColors[s[j]] = false;
    }
    usedColors[s[i]] = false;
  }
  cout << ans << endl;
  return 0;
}