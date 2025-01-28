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

int cnt[30];
string s;

int fact(int num) {
    if (num == 0) {
        return 1;
    }
    return num * fact(num - 1);
}

void solve(string curr) {
    if (curr.size() == s.size()) {
        cout << curr << endl;
        return;
    }

    for (int i = 0; i < 30; i++) {
        if (cnt[i] > 0) {
            cnt[i] -= 1;
            solve(curr + (char)(i + 'a'));
            cnt[i] += 1;
        }
    }
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for (auto& c : s) {
        cnt[c - 'a']++;
    }
    int ans = fact(s.size());
    for (int i = 0; i < 30; i++) {
        ans /= fact(cnt[i]);
    }
    cout << ans << endl;
    solve("");


    return 0;
}
