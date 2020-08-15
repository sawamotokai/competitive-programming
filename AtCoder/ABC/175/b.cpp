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

int N; int L[104];
int main() {
  cin >> N;
  rep(i,N) cin >> L[i];
  int ans = 0;
  rep(i,N) for (int j=i+1; j<N; j++) for (int k=j+1; k<N; k++) {
    vi x(3);
    x[0] = L[i];
    x[1] = L[j];
    x[2] = L[k];
    if (x[0] == x[1] || x[0] == x[2] || x[1] == x[2])continue;
    sort(x.begin(),x.end()); 
    if (x[2] < x[1] + x[0]) ans++;
  }
  cout << ans << endl;
  return 0;
}