//
//  main.c
//  模拟实现strstr
//
//  Created by zhourenxi on 2022/1/22.
//

#include <stdio.h>
#include <assert.h>

char* my_strstr(const char* str, const char* substr)
{
    const char* s1 = str;
    const char* s2 = substr;
    const char* cur = str;

    assert(str && substr);
    if (*substr == '\0')
    {
        return (char*)str;
    }
    while (*cur)
    {
        s1 = cur;
        s2 = substr;
        while (*s1 &&  *s2 && *s1 == *s2)
        {
            s1++;
            s2++;
        }
        if (*s2 == '\0')
            return (char*)cur;

        cur++;
    }
    return NULL;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
