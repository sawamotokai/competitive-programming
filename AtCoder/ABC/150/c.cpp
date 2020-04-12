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

ll gcd(ll a, ll b) { return b?gcd(b, b%a):a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }
//clang++ -std=c++11 -stdlib=libc++ 
ll Q,P;
int N;
vector<ll> nums;
bool flag[10];

void dfs(ll a, int len) {
  if (len == N) {
    nums.push_back(a); 
    return;
  }
  for (int i=1; i<=N; i++) {
    if (flag[i]) continue;
    flag[i] = true;
    dfs(a*10+i, 1+len);
    flag[i] = false;
  }
}


int main() {
  cin>>N;
  rep(i,N) {
    int a ;cin>>a;
    P*=10; P+=a;
  }
  rep(i,N) {
    int a; cin>>a;
    Q*=10; Q+=a;
  }
  dfs(0,0);
  int a=0,b=0;
  for (int i=0; i<nums.size();i ++)  {
    if (nums[i]==P) a=i;
    if (nums[i]==Q) b=i;
  }
  sort(nums.begin(), nums.end());
  cout << abs(a-b) << endl;
  return 0;
}