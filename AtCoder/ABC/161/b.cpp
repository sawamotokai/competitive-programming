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



int a[1006];
int main() {
  int N,M;cin>>N>>M;
  int count=0;
  int sum=0;
  rep(i,N) {cin>>a[i]; sum+=a[i];}
  rep (i,N) {
    double cond = (double) sum/(4*M);
    if (a[i]>= cond) count++;
}
  puts(count>=M? "Yes":"No");


  return 0;
}