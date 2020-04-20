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
  int n; string s; cin >> n>> s;
  vi L(n);
  vi R(n);
  L[0] = 0;
  R[n-1]=0;
  int b =0, w=0;
  for (int i=1; i<n; i++) {
   L[i] = L[i-1];
   if (s[i-1] == '#') {
     L[i]++;
   }
  }
  for (int i=n-2; i>=0;i--) {
    R[i] = R[i+1];
    if (s[i+1] == '.') R[i]++;
  }
  int ans = INF;
  rep (i, n-1) {
    if (s[i] != s[i+1]) {
      ans = min(ans, R[i+1]+L[i+1]);
    }
  }
  ans=min(ans,R[0]+L[0]);
  ans=min(ans,R[n-1]+L[n-1]);
  cout << ans << endl;
  return 0;

}