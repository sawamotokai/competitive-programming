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
ll d(ll n) {
  return 1 + floor(log10(n));
}
int main() {
  int a,b; ll x; cin>>a>>b>>x;
  ll ans=0;
  ll h=1e9+1, l=0;
  while (h-l>1) {
    ans = (l+h) /2;
   if ((a*ans+b*d(ans)) <= x) l=ans;
   else h=ans;
  }
  ans = min(ans, (ll)1e9);
  cout << l << endl;
  return 0;
}