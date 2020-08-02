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
  // bin search
  int N,K; cin >> N >> K;
  vll A(N);
  rep(i,N)cin>>A[i];
  double hi = 1e9;
  double lo = 0;
  double ans = 0;
  auto f = [&](double t) {
    ll cnt = 0;
    rep(i,N){
      cnt += ceil(A[i]/t);
      cnt--;
    }
    return cnt <= K;
  };
  rep(i,100) {
    double mid = (hi+lo)/2.;
    if (f(mid)) hi = mid;
    else lo = mid;
    ans = mid;
  }
  int out = ceil(ans);
  cout << out << endl;
  return 0;
}