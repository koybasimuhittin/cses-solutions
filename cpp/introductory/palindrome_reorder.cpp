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
const int N = 30;

string s;
int cnt[N];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for (auto& c : s) {
        cnt[c - 'A']++;
    }


    int index = -1;

    for (int i = 0; i < N; i++) {
        if (index != -1 && (cnt[i] & 1)) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        else if (cnt[i] & 1) {
            index = i;
        }
    }


    for (int i = 0; i < N; i++) {
        if (index == i) {
            continue;
        }
        for (int j = 0; j < cnt[i] / 2; j++) {
            cout << (char)('A' + i);
        }
    }

    if (index != -1) {
        for (int j = 0; j < cnt[index]; j++) {
            cout << (char)('A' + index);
        }
    }

    for (int i = N; i >= 0; i--) {
        if (index == i) {
            continue;
        }
        for (int j = 0; j < cnt[i] / 2; j++) {
            cout << (char)('A' + i);
        }
    }




    return 0;
}
