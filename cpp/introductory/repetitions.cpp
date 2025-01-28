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

string s;
int ans;

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;


    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            ans = max(ans, cnt);
            cnt = 0;
        }
        cnt++;

    }

    ans = max(ans, cnt);

    cout << ans << endl;



    return 0;
}
