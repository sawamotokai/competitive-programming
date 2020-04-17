#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

ll f(ll n) {
  int ret =0;
  while(n) {
    ret+=n%10;
    n/=10;
  }
  return ret;
}

int main() {
  ll N; cin>>N;
  int keta = 2+floor(log10(N));
  int range = 9*keta;
  vector<ll> ans;
  int k=0;
  for (ll i=0; i<=range; i++) {
    ll x = N-i;
    if (x+f(x) == N) {
      k++; 
      ans.push_back(x);
    }
  }
  reverse(ans.begin(), ans.end());
  cout << k << endl;
  rep(i,k) {
    cout << ans[i] << endl;
  }
  return 0;
}