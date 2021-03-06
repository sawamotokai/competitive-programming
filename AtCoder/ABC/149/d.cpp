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
  int N,K; cin >>N>>K;
  int r,s,p; cin >>r>>s>>p;
  string T; cin >>T;
  ll ans = 0;
  vector<string> groups(K, "");
  rep(i, N) {
    groups[i%K] += T[i];
  }
  rep(i,K) {
    for(int j=0; j<groups[i].length(); j++) {
      if (groups[i][j] == 'r') ans += p;
      if (groups[i][j] == 'p') ans += s;
      if (groups[i][j] == 's') ans += r;
      if (j+1 < groups[i].length() && groups[i][j] == groups[i][j+1]) j++;
    }
  }
  cout << ans << endl;
  return 0;
}