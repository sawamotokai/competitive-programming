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
int A,B,C,D,E,F;
int main() {
  cin >>A>>B>>C>>D>>E>>F;
  double mx = (double) E/(100+E);
  vb sugar(F+1);
  vb water(F+1);
  // sugar[0]=water[0]=true;
  rep(i,F+1) rep(j,F+1) {
    int x = A*i+B*j; x*=100;
    if (x<=F) {
      water[x]=true;
    }
  }
   rep(i,F+1) rep(j,F+1) {
    int x=C*i+D*j;
    if (x<=F) {
      sugar[x]=true;
    }
  }
  int sugarAmount = 0;
  pair<int, double> ans(100,0);
  rep(i,F+1)rep(j,F+1) {
    if (water[i]) {
      int s = j; if (!sugar[j]) s=0;
      int amount = i+s;
      if (amount == 0) continue;
      double conc = (double) s/amount;
      if (amount>F) continue;
      if (conc>mx) continue;
      if (ans.second <= conc) {
        ans = make_pair(amount, conc);
        sugarAmount = max(sugarAmount, s);
      }
    }
  }
  printf("%d %d\n", ans.first, sugarAmount);
  return 0;
}