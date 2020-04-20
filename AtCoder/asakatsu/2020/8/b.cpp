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
  int N,M,L,P,Q,R; cin>>N>>M>>L>>P>>Q>>R;
  int ans = (N/P) * (M/Q) * (L/R);
  ans = max (ans, (N/P) * (M/R)* (L/Q) );
  ans = max (ans, (N/Q) * (M/R) * (L/P));
  ans = max (ans, (N/Q) *(M/P) * (L/R) );
  ans = max (ans, (N/R) *(M/P) * (L/Q) );
  ans = max (ans, (N/R) *(M/Q) * (L/P) );
  cout << ans << endl;
  return 0;
}