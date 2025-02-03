#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define int long long
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, a, b, arr[N], pref[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pref[i + 1] = pref[i] + arr[i];
    }

    int ans = LLONG_MIN;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(mp(0, 0));

    for (int i = a; i <= n; i++) {
        while (!pq.empty() && pq.top().s2 < i - b) {
            pq.pop();
        }

        ans = max(ans, pref[i] - pq.top().f1);

        //cout << pref[i] << " " << pq.top().f1 << " " << pq.top().s2 << endl;
        pq.push({ pref[i - a + 1], i - a + 1 });
    }

    cout << ans << endl;


    return 0;
}
