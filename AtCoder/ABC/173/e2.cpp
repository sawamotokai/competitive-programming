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
  int n,k; cin >> n >> k;
  vll a(n);
  rep(i,n) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), [](ll a, ll b) {return abs(a) > abs(b);});
  int neg = 0;
  int pos = 0;
  int zero = 0;
  rep(i,k) {
    if (a[i] == 0) zero++;
    if (a[i] < 0) neg++;
    if (a[i] > 0) pos++;
  }
  if (neg&1) {
    int posFirstNeg=-1, posFirstPos=-1;
    for (int i=k; (posFirstNeg==-1 || posFirstPos==-1)&& i<n; i++) {
      if (posFirstNeg == -1 && a[i] < 0) posFirstNeg = i;
      if (posFirstPos == -1 && a[i] > 0) posFirstPos = i;
    }
  }
  if (zero) {
    cout << 0 << endl; 
    return 0;
  } 
  k-neg
  if (pos>0 && &1) {
    // have to use
  }
  return 0;
}