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
int cnt[30];

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'A']++;
    }
    int first_max, first_max_c, second_max, second_max_c;
    first_max = second_max = 0;
    first_max_c = second_max_c = -1;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] > first_max) {
            second_max = first_max;
            second_max_c = first_max_c;
            first_max = cnt[i];
            first_max_c = i;
        }
        else if (cnt[i] > second_max) {
            second_max = cnt[i];
            second_max_c = i;
        }
    }
    string res = "";
    int prev = -1;
    for (int i = 0; i < s.size(); i++) {
        bool flag = false;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] > 0 && prev != j) {
                int new_max = 0;
                if (j == first_max_c) {
                    new_max = max(first_max - 1, second_max);
                }
                else {
                    new_max = first_max;
                }
                if (new_max > (s.size() - i) / 2) {
                    continue;
                }
                else {
                    res += (char)(j + 'A');
                    prev = j;
                    cnt[j]--;
                    flag = true;

                    first_max = second_max = 0;
                    first_max_c = second_max_c = -1;
                    for (int k = 0; k < 26; k++) {
                        if (cnt[k] > first_max) {
                            second_max = first_max;
                            second_max_c = first_max_c;
                            first_max = cnt[k];
                            first_max_c = k;
                        }
                        else if (cnt[k] > second_max) {
                            second_max = cnt[k];
                            second_max_c = k;
                        }
                    }

                    break;
                }
            }
        }
        if (!flag) {
            cout << -1 << endl;
            return 0;
        }

    }

    cout << res << endl;


    return 0;
}
