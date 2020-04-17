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
  int L,X,Y,S,D;
  cin >>L>>X>>Y>>S>>D;
  if (S==D) {
    cout << 0<< endl; return 0;
  }
  double cw, ccw =0;
  if (S>D) {
    cw = (D+L-S)/(double)(X+Y);
    ccw = (S-D)/(double)(Y-X);
  } else {
    cw = (D-S)/(double)(X+Y);
    ccw = (L-D+S)/(double)(Y-X);
  }
  double ans = 0;
  if (ccw<0) ans = cw;
  else ans = min(cw, ccw);
  printf("%.10lf\n",ans);
  return 0;
}