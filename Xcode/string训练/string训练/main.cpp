//
//  main.cpp
//  string训练
//
//  Created by zhourenxi on 2022/7/6.
//

#include <iostream>
#include <string>

using std::cout;
using std::endl;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::string s("ffapf");
    
    std::cout << s[3];
    s += "faf";
    cout << s << std ::endl;
    s.insert(3, "ds");
    cout << s << endl;
    s.erase(1000);
    cout << s;
    return 0;
}



