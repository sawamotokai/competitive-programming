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
typedef priority_queue<double, vector<double>, gt> minq;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int n; cin >> n;
  minq pq;
  rep(i,n) {
    int v; cin >> v;
    pq.push(v);
  }
  double ans = 0;
  while (pq.size() > 1){
    double a = pq.top(); pq.pop();
    double b = pq.top(); pq.pop();
    pq.push((a+b)/(double)2);
  }
  ans = pq.top();
  printf("%.10f\n", ans);
  return 0;
}