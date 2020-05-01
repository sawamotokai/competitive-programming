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
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int n = s.length();
    ll mod = 2019;
    vector<ll> prefixSum(s.length()+1);
    vector<ll> ans(mod);
    ll tot = 0, keta = 1;
    prefixSum[0] = 0;
    // rep(i,s.length()) {
      for (int i=0;i<n;i++) {
    ll x = s[i]-'0';
      tot += x * keta;
      tot %= mod;
      keta *= 10;
      keta %= mod;
      prefixSum[i+1] = tot;
    }
    for (int i=0;i<=n;i++) {
      ans[prefixSum[i]]++;
    }
    ll out = 0;
    auto comb = [] (ll n) -> ll {
      if (n<=1) return 0;
      return (n-1)*n/2;
    };
    // rep(i, prefixSum.size()) cout << prefixSum[i] << endl;
    for (int i=0; i<mod; i++) {
      out += comb(ans[i]);
    }

    printf("%lld\n", out);
    return 0;
  }