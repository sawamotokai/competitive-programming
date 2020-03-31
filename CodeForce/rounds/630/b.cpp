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


void solve (){ 
  int n;cin>>n;
  vi a(n);
  vi seg(11, -1);
  rep(i,n) cin>>a[i];
  if (n<=11) {
    rep(i,n) cout<<i+1;
    cout<< endl;
    return;
  }
  function<void(int, int)> compress = [&](int a, int b) {
    if (a!=b && seg[b] == a) {
      while (seg[seg[b]] != -1) seg[b] = seg[a];
    }
  };
  function<void(int, int)> unite = [&](int a, int b) {
    if (a!=b && __gcd(a,b) != 1) seg[b] = a; compress(a,b);
  };
  rep(i, n) {
    rep(j,n) {
      unite(a[i], a[j]);
      if (seg[i] == seg[j]) cout << seg[i];
    }
  }
  cout << endl;
}

int main() {
  int t; cin>>t;rep(i,t)solve();
  return 0;
}