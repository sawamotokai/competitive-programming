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
bool used[8];
double dist_sum;
int N; 
vii coords;

void dfs(int prev, int m) {
  if (m==N) {
    
   return ; 
  }
  rep(i, N) {
    if (!used[i]) {
      ii prevCity = coords[m];
      ii currCity = coords[i];
      double dist = sqrt(pow(prevCity.first-currCity.first,2) + pow(prevCity.second-currCity.second, 2));
      dist_sum+=dist;
      used[i] = true;
      dfs(i, m+1);
      used[i] = false;
    }
  }
}

int main() {
  cin>>N;
  coords.resize(N);
  rep(i,N) {
    int x, y; cin>>x>>y;
    coords[i]= ii(x,y);
  }

  rep(i,N) {
    used[i]=true;
    dfs(i, 1);
    used[i]=false;
  }

  ll denom = 1;
  rep(i,N) denom*=(i+1);
  double ans = dist_sum / denom; 

  cout << ans << endl;

  return 0;
}