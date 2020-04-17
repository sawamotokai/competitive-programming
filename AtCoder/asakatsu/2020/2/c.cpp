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
  int a, e, b;

int main() {
  int n, m; cin >>n>>m;
  int right = m-2*n;
  bool impossible = false;
  if (right < 0) impossible = true;
  if (right&1) {
    e=1; b=(right-1)/2;
  }
  else {
    e =0;
    b=(right)/2;
  }
  a = n-e-b;
  if (a<0||b<0||e<0) impossible = true;
  if (impossible) printf("-1 -1 -1\n");
  else printf("%d %d %d\n", a,e,b);
  return 0;
}