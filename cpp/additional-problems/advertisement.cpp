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

int n, m, t, arr[N];
vector<int> v;
pair<int, int> ans[2][N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    stack<int> st;
    int ans = 0;
    st.push(-1);
    for (int i = 0; i <= n; i++) {
        if (i < n) cin >> arr[i];
        else arr[i] = -1;
        while (st.top() != -1 && arr[st.top()] >= arr[i]) {
            int a = st.top();
            st.pop();
            ans = max(ans, (i - st.top() - 1) * arr[a]);
        }
        st.push(i);
    }

    cout << ans << endl;



    return 0;
}
