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

int n, m, arr[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxi = max(arr[i], maxi);
    }

    int low = maxi;
    int high = n * maxi;

    while (low < high) {
        int mid = (low + high) / 2;
        int cnt = 1;
        int sum = 0;


        for (int i = 0; i < n; i++) {
            if (arr[i] + sum > mid) {
                cnt++;
                sum = 0;
            }

            sum += arr[i];

        }

        if (cnt > m) {
            low = mid + 1;
        }
        else {
            high = mid;
        }

        //cout << low << " " << high << " " << mid << " " << cnt << endl;
    }

    cout << low << endl;


    return 0;
}
