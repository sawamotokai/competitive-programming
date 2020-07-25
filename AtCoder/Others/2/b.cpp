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
  int r,g,b,k; cin >> r >> g >> b >> k;
  // int xG =  ceil(log2(r/(double)g));
  // if (xG > k) {
  //   cout << "No" << endl;
  //   return 0;
  // }
  // k -= xG;
  // g *= pow(2, xG);
  // int xB =  ceil(log2(g/(double)b));
  // if (xB > k) {
  //   cout << "No" << endl;
  //   return 0;
  // } 
  // cout << "Yes" << endl;
  while (r >= g) {
    k--;
    g <<= 1; 
  }
  while (g >= b) {
    k--;
    b <<= 1;
  }
  if (k >=0 && b > g && g > r) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}