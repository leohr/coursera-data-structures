#include<bits/stdc++.h> 
using namespace std; 

int main() {
    int n; cin >> n; 
    unordered_map<int, string> ph; 
    for (int i = 0; i < n; ++i) {
        string q; cin >> q; 
        if (q == "add") {
            int num; cin >> num; 
            string name; cin >> name; 
            ph[num] = name; 
        }
        if (q == "find") {
            int num; cin >> num; 
            if (ph.find(num) == ph.end()) 
                cout << "not found" << endl; 
            else 
                cout << ph[num] << endl; 
        }
        if (q == "del") {
            int num; cin >> num; 
            ph.erase(num); 
        } 
    }
    return 0; 
}