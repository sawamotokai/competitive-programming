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

int solve(int n) {
    int ans =0;
    for (int a=1; a<=100; a++) {
      int poly = a*a;
      if (poly > n) break;
      for (int b=1; b<=100; b++) {
        poly += b*b;
        poly += a*b;
        if (poly > n) {
          poly -= b*b;
          poly -= a*b;
          break;
        }
        for (int c=1; c<=100; c++) {
          // int poly = a*a + b*b + c*c + a*b + a*c + b*c;
          poly += c*c;
          poly += a*c;
          poly += b*c;
          if (poly > n) {
            poly -= c*c;
            poly -= a*c;
            poly -= b*c;
            break;
          }
          if (poly == n) ans++;
        }
      }
    }
    return ans;
}

int main() {
  int n; cin >> n;
  rep(i,n) cout << solve(i+1) << endl;
  return 0;
}