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
  int N; cin >>N;
  vi d(N);
  rep(i,N) cin>>d[i];
  int mx = 0;
  rep(i,N) mx+=d[i];
  int partialSum = 0;
  int longest = 0;
  int mn=INF;
  rep(i,N) {
    partialSum+=d[i];
    longest=max(longest, d[i]);
    if (partialSum*2==mx) {
      mn = 0;
      printf("%d\n%d\n", mx, mn);
      return 0; 
    }
  }
  int longestI=0;
  rep(i,N) {
    if (d[i]==longest) {
      longestI=i;
    }
  }
  int left=0, right=0;
  rep(i,N) {
    if (i<longestI) left+=d[i];
    if (i>longestI) right+=d[i];
  }
  if (left+right>=longest && N>2) {
    mn=0;
  } else {
    mn = longest - (left+right);
  }
  printf("%d\n%d\n", mx,mn);

  

  return 0;
}