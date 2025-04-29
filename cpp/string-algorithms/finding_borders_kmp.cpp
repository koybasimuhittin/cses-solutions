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
const int N = 1e6 + 5;

string s;
int pi[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }

    vector<int> borders;

    int idx = pi[s.size() - 1];
    while (idx > 0) {
        borders.pb(idx);
        idx = pi[idx - 1];
    }
    sort(borders.begin(), borders.end());

    for (auto border : borders) {
        cout << border << " ";
    }
    cout << endl;



    return 0;
}
