#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    int val = 0;
    stack<int> t;
    while(!input.empty()){
        val = input.top();
        t.push(val);
    	input.pop();
    }
    while(!t.empty()){
        val = t.top();
        extra.push(val);
    	t.pop();
    }
    while(!extra.empty()){
        val = extra.top();
        input.push(val);
    	extra.pop();
    }
    
   // val = input.pop();
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}