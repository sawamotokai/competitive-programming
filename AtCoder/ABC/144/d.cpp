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
  int a,b,x; cin>>a>>b>>x;
  int empty = a*a*b - x;
  double theta;
  if (x*2 > a*a*b) {
    theta = atan(2*empty/pow(a,3))*180/M_PI;
  } else {
    theta = 90 - atan(2*x/(double)(a*b*b))*180/M_PI;
  }
  printf("%.10f\n", theta);
  return 0;
}