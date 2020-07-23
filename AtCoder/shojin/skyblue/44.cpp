#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  // abc74c
  int A,B,C,D,E,F;cin>>A>>B>>C>>D>>E>>F;
  vi water, salt;
  rep(a,F+1) rep(b, F+1) { 
    int w = 100*a*A+100*b*B;
    if (w > F) break;
    water.push_back(w);
  }
  rep(c,F+1) rep(d,F+1) {
    int s = c*C + d*D;
    if (s > F) break;
    salt.push_back(s);
  }
  double maxConc=0.0;
  int ansW=0, ansS=0;
  rep(i, water.size()) {
    rep(j, salt.size()) {
      int w = water[i];
      int s = salt[j];
      if (w+s > F) continue;
      int maxSalt = E*(w/100);
      if (maxSalt < s) continue;
      double c = 100*s/(double) (w+s);
      if (maxConc <= c) {
        ansW=w;
        ansS=s;
        chmax(maxConc, c);
      }
    }
  }
  printf("%d %d\n", ansW+ansS, ansS);
  return 0;
}