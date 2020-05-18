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
  int a,b,h,m; cin >> a >> b >> h >> m;
  double theta = (h+ (double) m/60)*30;
  double phi = (m%60)*6;
  double x = abs(theta-phi);
  x = min(x, 360-x);
  x = (double) x * M_PI * 2/360.0; 
  // cout<<x<<endl;
  double c_sq = (double) a*a+b*b - 2*a*b*cos(x);
  // cout << cos(x) << endl;
  printf("%.20f\n", sqrt(c_sq));

  return 0;
}