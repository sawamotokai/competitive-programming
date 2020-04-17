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
const ll INF = 1e18L + 1;
//clang++ -std=c++11 -stdlib=libc++ 
int grid[3][3];
int main() {
  int sum =0;
  rep(i,3)rep(j,3) {
    cin>>grid[i][j];
    sum+=grid[i][j];
  }
  rep (a1, 101) rep(a2,101) rep(a3, 101) {
    double b1,b2,b3;
    b1 = ((a1+a2+a3)*(-1)+grid[0][0]+grid[1][0]+grid[2][0])/(double)3;
    b2 = ((a1+a2+a3)*(-1)+grid[0][1]+grid[1][1]+grid[2][1])/(double)3;
    b3 = ((a1+a2+a3)*(-1)+grid[0][2]+grid[1][2]+grid[2][2])/(double)3;
    if (b1 == floor(b1) && b2 == floor(b2) && b3 == floor(b3)) {
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}