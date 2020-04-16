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

int main() {
  int N,A,B; cin>>N>>A>>B;
  vi scores(N);
  int mn=1e9, mx=0;
  double avg=0;
  rep(i,N){
 cin>>scores[i];
 avg+=scores[i];
 mx=max(mx, scores[i]);
 mn=min(mn, scores[i]);
  }
  avg/=N;
  int d = mx-mn;
  if (d==0.0) {
    cout << -1 << endl;
    return 0;
  }
  double p = (double) B/d;
  avg *= p;
  double q = A-avg;
  printf("%lf %lf\n", p,q);
  return 0;
}