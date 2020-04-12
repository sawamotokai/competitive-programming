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
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
 
int main() {
  int K; cin>>K;
  ll sum =0;
  for(int i=1; i<=K;i++) for(int j=1;j<=K;j++) for(int k=1; k<=K;k++) {
    ll left = gcd(i,j);
    ll right = gcd(left, k);
    sum+=right;
  }
cout << sum << endl;
  return 0;
}