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

typedef struct Project {
    int start, end, money;

    Project(int _start, int _end, int _money) {
        start = _start;
        end = _end;
        money = _money;
    }

    bool operator< (const Project& other) const {
        return start < other.start;
    }
} Project;

int n, a, b, c, dp[N];
vector<Project> projects;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        projects.pb(Project(a, b, c));
    }

    sort(projects.begin(), projects.end());

    for (int i = n - 1; i >= 0; i--) {
        auto it = upper_bound(projects.begin(), projects.end(), Project(projects[i].end, 0, 0));
        dp[i] = max(dp[i + 1], dp[it - projects.begin()] + projects[i].money);
    }

    cout << dp[0] << endl;



    return 0;
}
