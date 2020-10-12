#include <bits/stdc++.h> 
using namespace std; 

class myStack {
    public: 
        stack<int> mainStack; 
        stack<int> maxStack;

        void Push(int x){
            mainStack.push(x); 
            if (maxStack.empty())
                maxStack.push(x);
            else {
                int y = maxStack.top(); 
                if (y > x)
                    maxStack.push(y); 
                else 
                    maxStack.push(x);
            }
        }

        void Pop() {
            mainStack.pop(); 
            maxStack.pop();
        }

        void Max() {
            cout << maxStack.top() << endl; 
        }
}; 

int main() {
    myStack st; 
    int n; cin >> n; 
    for (int i = 0; i < n; ++i) {
        string op; cin >> op; 

        if (op == "push") {
            int x; cin >> x; 
            st.Push(x); 
        }

        if (op == "max") 
            st.Max(); 

        if (op == "pop")
            st.Pop(); 
    }

    return 0; 
}

// The idea is using a second stack for storing the current maximum. 
// If at some moment I push a number smaller than my current maximum, 
// I will have to pop it before the maximum to change...