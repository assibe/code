#pragma once 

#include <iostream>
#include <ctime>
#include <pthread.h>

std::ostream &Log(){

    std::cout << "Fot Debug | " << " timestamp: " << (uint16_t)time(nullptr) << "|" << "Thread[" << pthread_self() << "]|";
    return std::cout;
    
    }