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
ll gcd(ll a, ll b) { return b?gcd(b, a%b):a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }
//clang++ -std=c++11 -stdlib=libc++ 

int f(int n) {
  int ans =0;
  while (n>0 && !(n&1)) {
    n>>=1;
    ans++;
  }
  return ans;
}

int main() {
  int N,M; cin>>N>>M;
  vi A(N);
  rep(i,N) {
    cin>>A[i];
  }
  rep(i, N) {
    if (A[i]&1) {
      cout << 0 <<endl;
      return 0;
    }
    A[i] >>=1;
  }
  int t = f(A[0]);
  rep(i, N) {
    if (f(A[i]) != t) {
      cout << 0 << endl;
      return 0;
    }
    A[i] >>= t;
  }
  M >>= t;
  ll l=1;
  rep(i,N){
    l = lcm(l, A[i]);
    if (l>M) {
      cout << 0 << endl;
      return 0;
    }
  }
  int ans = M / l;
  ans = (ans+1)/2;
  cout << ans << endl;
  return 0;
}