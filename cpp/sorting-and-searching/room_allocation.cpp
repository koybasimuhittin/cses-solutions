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

typedef struct Customer {
    int time, index;
    bool arrival_or_departure;

    Customer(int _time, bool _arrival_or_departure, int _index) {
        time = _time;
        index = _index;
        arrival_or_departure = _arrival_or_departure;
    }

    bool operator< (const Customer& other) const {
        if (time == other.time) {
            return arrival_or_departure;
        }
        return time < other.time;
    }
} Customer;

int n, a, b, cnt, ans[N];
vector<Customer> v;
stack<int> st;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        st.push(n - i + 1);
        cin >> a >> b;
        v.push_back(Customer(a, true, i));
        v.push_back(Customer(b, false, i));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 2 * n; i++) {
        if (v[i].arrival_or_departure) {
            int room = st.top();
            st.pop();
            cnt = max(cnt, room);
            ans[v[i].index] = room;
        }
        else {
            st.push(ans[v[i].index]);
        }
    }

    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}
