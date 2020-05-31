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
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int n; cin >> n;
  vii p(n);
  rep(i,n) {
    int a,b; cin >> a >> b;
    p[i] = ii(a,b);
  }
  ll ans = 0; 
  if (n&1) {
    int target = n/2;
    sort(p.begin(), p.end(), [](ii a, ii b) {return a.first < b.first;});
    int left = p[target].first;
    sort(p.begin(), p.end(), [](ii a, ii b) {return a.second > b.second;});
    int right = p[target].second; 
    ans = right-left+1;
  } else {
    int target = (n-2)/2;
    sort(p.begin(), p.end(), [](ii a, ii b) {return a.first < b.first;});
    int left = p[target].first;
    sort(p.begin(), p.end(), [](ii a, ii b) {return a.second > b.second;});
    int right = p[target].second; 
    ll dif = right - left + 1;
    ans = dif*(dif-1)/2;
  }
  cout << ans << endl;
  return 0;
}