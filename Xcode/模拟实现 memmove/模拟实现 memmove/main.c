//
//  main.c
//  模拟实现 memmove
//
//  Created by zhourenxi on 2022/2/10.
//

#include <assert.h> //防止空指针出现
#include <stddef.h>

void *my_memmove ( void * destination, const void * source, size_t num ){//num为字节数量
    void *ret = destination;
    assert(source && destination);
    if (source < destination) {
        while (num--) {
            *((char*)destination + num) =  *((char*)source + num);
        }
     }
    else
        while (num--) {
            *(char*)destination = *(char*)source;
            destination = destination + 1;
            source = source + 1;
        }
    return ret;
}
