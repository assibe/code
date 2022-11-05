//
//  main.cpp
//  抛异常
//
//  Created by 周仁玺 on 2022/11/5.
//

#include <iostream>

using namespace std;

int Add(int a){
    
    if (a == 0) {
        throw "a等于0";
    }
    else{
        
        return a;
    }
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    try {
        Add(1);
    } catch (const char* reemsg) {
        cout << "reemsg"<<endl;
    }
    catch(const char){
        
        
    }
    
    
    return 0;
}
