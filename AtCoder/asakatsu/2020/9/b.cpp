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
  int d=n%10; n/=10;
  int c=n%10; n/=10;
  int b=n%10; n/=10;
  int a=n%10; n/=10;
  for (int i=0; i<(1<<3) ; i++) {
    int sum =a;
    char first = a+'0';
    string ans=""; ans += first; 
    if ((i)&1) sum+=d;
    else sum-=d;
    if ((i>>1)&1) sum+=c;
    else sum-=c;
    if ((i>>2)&1) sum+=b;
    else sum-=b;
    if ((i>>2)&1) ans+='+';
    else ans+='-';
    ans += b+'0';
    if ((i>>1)&1) ans+='+';
    else ans+='-';
    ans += c+'0';
    if ((i)&1) ans += '+';
    else ans+='-';
    ans += d+'0'; 
    if (sum == 7) {
      cout << ans << "=7" << endl;
      return 0;
    }
    
  }
  return 0;
}