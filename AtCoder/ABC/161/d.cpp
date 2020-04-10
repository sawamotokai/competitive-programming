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


int dp[100005][2];
int main() {
  int K; cin>>K;
  vector<ll> ans;
  queue<ll> q; 
  for(int i=1; i<10; i++) q.push(i);
  while (ans.size() <= K) {
    ll a = q.front(); q.pop();
    ans.push_back(a);
    int first = a%10;
    if (first-1>=0) {
      ll target=a*10+first-1;
      q.push(target);
    }
    q.push(a*10+first);

    if (first+1<10) {
      ll target=a*10+1+first;
      q.push(target);
    }
  }
  cout << ans[K-1] << endl;
  return 0;
}