#include<bits/stdc++.h> 
using namespace std; 

int main() {
    string pat, txt; cin >> pat >> txt; 
    int n = txt.size(), m = pat.size(); 
    int d = 256, q = 101;  
    int p = 0, t = 0, h = 1; 
    for (int i = 0; i < m-1; ++i) {
        h = (h*d)%q; 
    }
    for (int i = 0; i < m; ++i) { 
        p = (d*p + pat[i]) % q; 
        t = (d*t + txt[i]) % q; 
    }
    int j; 
    for (int i = 0; i < n-m+1; ++i) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (txt[i+j] != pat[j])
                    break; 
            }
            if (j == m) 
                cout << i << " "; 
        }
        if (i < n-m ){
            t = (d*(t - txt[i]*h) + txt[i+m]) % q; 
            if (t < 0) 
                t = t + q; 
        }
    }
    return 0; 
}