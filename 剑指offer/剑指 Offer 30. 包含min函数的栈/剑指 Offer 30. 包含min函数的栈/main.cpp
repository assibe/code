//
//  main.cpp
//  剑指 Offer 30. 包含min函数的栈
//
//  Created by 周仁玺 on 2023/3/20.
//
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> St;
    stack<int> minStack;
    
public:
    MinStack() {
        
        while (!St.empty()) {
            St.pop();
        }
        
        while (!minStack.empty()) {
            minStack.pop();
        }
        
        minStack.push(INT_MAX);//空最小的栈不可以进行比较，会造成报错
        
    }
    
    void push(int x) {
        
        St.push(x);
        minStack.push(std::min(minStack.top(), x));//min比较大小返回最小的那一个
    }
    
    void pop() {
        
        St.pop();
        minStack.pop();
        
    }
    
    
    int top() {
        return  St.top();
    };
    
    int min() {
        return minStack.top();
    };
};
