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
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int n,m; cin >> n >> m;
  vii jobs(n);

  rep(i,n) {

    int a,b; cin >> a >> b;
    jobs[i] = ii(a,b);
  }
  sort(jobs.begin(), jobs.end(), [](ii a, ii b) {return a.first < b.first;});

  priority_queue<int> candidates;
  int idx = 0;
  ll money = 0;
  for (int day = 1; day <= m; day++) {
    while (idx < n && jobs[idx].first <= day) {
      candidates.push(jobs[idx++].second);
    }
    if (candidates.size()) {
      money += candidates.top(); candidates.pop(); 
    }
  }
  cout << money << endl;
  return 0;
}