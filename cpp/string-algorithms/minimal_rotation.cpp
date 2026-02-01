#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
#define mod(a) (((a) >= n) ? a - n : a)
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

string s;
int idx[N], c[N], cc[N], n;
static int freq[N], pos[N], new_idx[N];



void counting_sort(int offset, int maxC) {

    fill(freq, freq + maxC + 1, 0);
    for (int i = 0; i < n; i++)
        freq[c[mod(idx[i] + offset)]]++;
    pos[0] = 0;
    for (int i = 1; i <= maxC; i++)
        pos[i] = pos[i - 1] + freq[i - 1];
    for (int i = 0; i < n; i++) {
        int k = c[mod(idx[i] + offset)];
        new_idx[pos[k]++] = idx[i];
    }
    memcpy(idx, new_idx, n * sizeof(int));
}

int repair_class(int offset) {
    cc[idx[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (c[i] < n && (c[idx[i]] != c[idx[i - 1]] || c[mod(idx[i] + offset)] != c[mod(idx[i - 1] + offset)])) {
            cc[idx[i]] = cc[idx[i - 1]] + 1;
        }
        else {
            cc[idx[i]] = cc[idx[i - 1]];
        }
    }

    for (int i = 0; i < n; i++) {
        c[i] = cc[i];
    }

    return c[idx[n - 1]];
}


int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i++) {
        c[i] = s[i] - 'a' + 0;
        idx[i] = i;
    }
    int cnt = 30;

    for (int k = 1; k < 2 * n; k <<= 1) {
        counting_sort(k / 2, cnt);
        counting_sort(0, cnt);
        cnt = repair_class(k / 2);
    }

    for (int i = 0; i < n; i++) {
        cout << s[mod(idx[0] + i)];
    }

    return 0;
}
