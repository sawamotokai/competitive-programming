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
  int N,M,A,B; cin>>N>>M>>A>>B;
  int no = 0;
  rep(i,M) {
    int c; cin>>c;
    if (N<=A) N+=B;
   if (c>N && !no) no = i+1;
    N-=c;
  }
  if (no) cout << no << endl;
  else cout << "Complete" << endl;
  return 0;
}