#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> angka(n);
        for (int i = 0; i < n; i++) cin >> angka[i];

        vector<int> freqs;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && angka[j] == angka[i]) j++;
            freqs.push_back(j - i);
            i = j;
        }

        int maxLen = 0;
        int maxFreq = *max_element(freqs.begin(), freqs.end());

        for (int f = 1; f <= maxFreq; f++) {
            int count = 0;
            for (int c : freqs) {
                if (c >= f) count++;
            }
            maxLen = max(maxLen, count * f);
        }

        cout << maxLen << "\n";
    }

    return 0;
}
