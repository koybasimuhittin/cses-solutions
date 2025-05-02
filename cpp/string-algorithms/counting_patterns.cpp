#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
#define mod(x, m) ((x) >= (m) ? (x) - (m) : (x))

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int q, suffix_array[N], c[N], cc[N];
string s, qs;

void counting_sort(int offset, int n, int class_count) {
    vector<int> buckets[class_count];
    for (int i = 0; i < n; i++) {
        int cl = c[mod(suffix_array[i] + offset, n)];
        buckets[cl].pb(suffix_array[i]);
    }
    int ptr = 0;
    for (int cl = 0; cl < class_count; cl++) {
        for (int idx : buckets[cl]) {
            suffix_array[ptr++] = idx;
        }
    }
}

int repair_classes(int offset, int n) {
    cc[suffix_array[0]] = 0;
    for (int i = 1; i < n; i++) {
        int cur = suffix_array[i], prev = suffix_array[i - 1];
        if (c[cur] != c[prev] ||
            c[mod(cur + offset, n)] != c[mod(prev + offset, n)]) {
            cc[cur] = cc[prev] + 1;
        }
        else {
            cc[cur] = cc[prev];
        }
    }
    for (int i = 0; i < n; i++) c[i] = cc[i];
    return c[suffix_array[n - 1]] + 1;
}

void build_suffix_array(const string& str) {
    s = "$" + str;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        c[i] = (s[i] == '$' ? 0 : s[i] - 'a' + 1);
        suffix_array[i] = i;
    }

    int class_count = 27;
    for (int h = 1; h < 2 * n; h <<= 1) {
        counting_sort(h, n, class_count);
        counting_sort(0, n, class_count);
        class_count = repair_classes(h, n);
    }
}

int find_pattern(const string& pat) {
    int n = s.size(), m = pat.size();
    int low = 1, high = n;
    while (low < high) {
        int mid = (low + high) >> 1;
        int flag = 0;
        for (int i = 0; i < m; i++) {
            char sc = s[mod(suffix_array[mid] + i, n)];
            if (pat[i] < sc) { flag = -1; break; }
            if (pat[i] > sc) { flag = 1; break; }
        }
        if (flag == 0) {
            flag = -1;
        }
        if (flag == -1) high = mid;
        else            low = mid + 1;
    }
    return low;
}

int main() {
    //fri("in.txt");
    //fro("out.txt");

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    build_suffix_array(s);

    cin >> q;
    while (q--) {
        cin >> qs;
        int lo = find_pattern(qs);
        qs.push_back(char('z' + 1));
        int hi = find_pattern(qs);
        cout << hi - lo << "\n";
    }
    return 0;
}
