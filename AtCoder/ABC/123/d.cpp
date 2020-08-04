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
  int X,Y,Z,K; cin >> X>> Y >> Z >> K;
  vll A(X), B(Y), C(Z);
  rep(i,X)cin>>A[i];
  rep(i,Y)cin>>B[i];
  rep(i,Z)cin>>C[i];

  vll T;
  rep(i,X)rep(j,Y)T.push_back(A[i]+B[j]);
  sort(T.rbegin(), T.rend());
  vll T2(K);
  rep(i,min(K, (int)T.size())) T2[i] = T[i];
  vll T3;
  rep(i,T2.size())rep(j,Z)T3.push_back(T2[i]+C[j]);
  sort(T3.rbegin(), T3.rend());
  rep(i,K) printf("%lld\n",T3[i]);
  return 0;
}