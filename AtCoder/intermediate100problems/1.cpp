#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }
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
  while (1) {
    int n,x;
    cin >> n >> x;
    if (n==0&&x==0) break;
    int ans =0;
    for (int i=1;i<=n;i++) {
      for (int j=i+1;j<=n;j++) {
        for (int k=j+1;k<=n;k++) {
          if (i == k || i == j || j == k) continue;
          if (i+k+j == x) ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}