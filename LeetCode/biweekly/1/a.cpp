#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 
int helper(int l, int r, vector<int>&target) {
        int mn=1e9;
        if (l > r) return 0;
        int n = r-l+1;
        for (int i=0; i<n; i++) {
            mn = min(mn, target[l+i]);
        }
        vector<int> mins;
        for (int i=0; i<n; i++) {
            if (target[l+i] == mn) mins.push_back(i+l); 
        }
        int ans = mn;
        for (int i=0; i<n; i++) target[i+l]-=mn;
        for(int i=0; i<mins.size(); i++) {
            int idx=mins[i];
            ans += helper(l, idx-1, target);
            l = idx + 1;
        }
        ans += helper(l, r, target);
        return ans;
    }
    
    int minNumberOperations(vector<int>& target) {
        if (target.size() == 0) return 0;
        return helper(0, target.size()-1, target);
    }
int main() {
  int n; cin >> n;
  vi a(n);
  rep(i, n) cin>>a[i];
  cout << minNumberOperations(a) << endl;
  return 0;
}