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
  string s; cin>>s; int n=s.length();
  vector<int> a;
  int cnt = 1;
  char prev = s[0];
  for(int i=1; i<n; i++) {
    if (s[i] == prev) cnt++; 
    else {
      a.push_back(cnt);
      prev = s[i];
      cnt = 1;
    }
  }
  a.push_back(cnt);
 for (int i=0; i<a.size(); i+=2) {
   rep(j, a[i]-1) {
     cout << 0 << ' ';
   }
   cout << ceil((double) a[i]/2) + a[i+1]/2 << ' ';
   cout << ceil((double) a[i+1]/2) + a[i]/2 << ' ';
   rep(j, a[i+1]-1) cout << 0 << ' ';
 } 
 puts("");
  return 0;
}