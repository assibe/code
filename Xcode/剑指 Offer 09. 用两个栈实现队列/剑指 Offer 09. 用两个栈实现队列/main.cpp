//
//  main.cpp
//  剑指 Offer 09. 用两个栈实现队列
//
//  Created by 周仁玺 on 2023/3/20.
//

#include <stack>


using namespace std;

class CQueue {
    private:
    stack<int> stack1,stack2;
public:
    
   
    
    void appendTail(int value) {
        
        stack1.push(value);
    }

 int deleteHead() {
        
        if (stack2.empty()) {
            
            while (!stack1.empty()) {
                
                stack2.push(stack1.top());
                stack1.pop();
                
            }
            
        }
        if (stack2.empty()) {
            return -1;
        }
        else{
            
            int deleteItem = stack2.top();
            stack2.pop();
            return deleteItem;
        }
        
    };
};
