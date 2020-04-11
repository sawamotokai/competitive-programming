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

  
int main() {
  int N,K;
  cin>>N>>K;
  vector<double> P;
  rep(i,N) {
    double p; cin>>p;
    double prob = (p+1)/2;
    P.push_back(prob);
  }
  // sort(P.begin(), P.end(), [](double a, double  b) {return a>b;});
  double ans = 0;
  rep(i,K) ans+=P[i];
  double sum = ans;

  for (int i=0; i<N-K; i++) {
    sum-=P[i];
    sum+=P[K+i];
    ans = max(ans, sum);
  }
  printf("%.10f\n", ans);
  return 0;
}