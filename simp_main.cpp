#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define endl "\n"
#define fast_ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define readInp(fileName) freopen(fileName, "r", stdin)
#define writeOut(fileName) freopen(fileName , "w", stdout)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int LimN = 1e5 + 5;
const int LimM = 1e6 + 5;
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int MAX_A = 1e6;

signed main() {
    fast_ios;
    // freopen("test.txt", "r", stdin); 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int > cnt(MAX_A + 1, 0);
        for (int num : a) {
            cnt[num]++;
        }
        vector<int> dp(MAX_A + 1, 0);
        for (int g = 1; g <= MAX_A; ++g) {
            int sum = 0;
            for (int k = g; k <= MAX_A; k += g) {
                sum = (sum + cnt[k]) % MOD;
            }
            if (sum > 0) {
                int sub = (1LL << sum) - 1; 
                sub = (sub + MOD) % MOD;
                dp[g] = sub;
            }
        }
        for (int g = MAX_A; g >= 1; --g) {
            for (int k = 2 * g; k <= MAX_A; k += g) {
                dp[g] = (dp[g] - dp[k] + MOD) % MOD;
            }
        }
        cout << dp[1] << endl;
    }
    return 0;
}