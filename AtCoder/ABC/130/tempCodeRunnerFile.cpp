
// ll n,k; cin >> n>>k;
//   vector<ll> a(n); 
//   rep(i,n) cin >> a[i];
//   int left =0, right=0;
//   ll ans = n*(n+1)/2;
//   ll sum = 0;
//   for (int left =0; left<n; left++) {
//     while(right<n && sum+a[right] < k) {
//       sum+=a[right]; right++;
//     }
//     ans -= (right-left);
//     sum-=a[left];
//   }
//   printf("%lld\n", ans);
//   return 0;