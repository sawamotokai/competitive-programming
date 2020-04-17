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

int main() {
  int n, a,b; cin>>n>>a>>b;
  int a_cnt=0, b_cnt=0, c_cnt=0;
  rep(i,n) {
    int p; cin>>p;
    if (p<=a) a_cnt++;
    else if (p<=b) b_cnt++;
    else c_cnt ++;
  }
  int mn = min(a_cnt, b_cnt); 
  mn = min(mn, c_cnt);
  cout << mn << endl;
  return 0;
}