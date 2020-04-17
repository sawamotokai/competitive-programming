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

int main() {
  string s; cin>>s;
   vector<int> L(s.length()+1);
  vector<int> R(s.length()+1);
  L[0]=0;R[s.length()]=0;
  rep(i, L.size()-1) {
   if (s[i]=='<') L[i+1]=L[i]+1;
   else L[i+1] = 0;
  }
  for (int i=R.size()-1; i>0; i--) {
    if (s[i-1] == '>') R[i-1] = R[i] + 1;
    else R[i-1] = 0;
  }
  int ans =0;
  rep(i, R.size()) {
    ans  += max(L[i], R[i]);
  }
  // ans+=preNum+1;
  cout << ans << endl;
  return 0;
}