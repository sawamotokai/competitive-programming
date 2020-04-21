ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
auto factorize = [](ll n) {
    vector<pair<ll,int>> res;
    for (ll i=2; i*i<=n; i++) {
      if (n%i) continue;
      res.push_back(make_pair(i, 0));
      while (n%i==0) {
        n/=i;
        res.back().second++;
      }
    }
    if (n!=1) res.push_back(make_pair(n,1));
    return res;
  };