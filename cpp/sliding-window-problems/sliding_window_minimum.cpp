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
const int N = 1e7 + 5;

int n, k, x, a, b, c, arr[N], m, minimum_xor;
deque<int> dq;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> x >> a >> b >> c;

    arr[0] = x;
    dq.push_back(arr[0]);
    for (int i = 1; i < k; i++) {
        arr[i] = arr[i - 1] * a + b;
        arr[i] %= c;
        while (!dq.empty() && dq.back() > arr[i])dq.pop_back();
        dq.push_back(arr[i]);
    }
    minimum_xor ^= dq.front();

    for (int i = k; i < n; i++) {
        if (!dq.empty() && dq.front() == arr[i - k])dq.pop_front();
        arr[i] = arr[i - 1] * a + b;
        arr[i] %= c;
        while (!dq.empty() && dq.back() > arr[i])dq.pop_back();
        dq.push_back(arr[i]);
        minimum_xor ^= dq.front();
    }

    cout << minimum_xor << endl;

    return 0;
}
