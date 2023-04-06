#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <semaphore.h>
#include <pthread.h>

using namespace std;

const int gCap = 10;

template <class T>
class RingQueue{

public:
    RingQueue(int cap = ) :ringqueue_(cap),pIndex_(0),cIndex_(0)
    {

        sem_init(&roomSem_,0,RingQueue_.size);
        sem_init(&dataSem_,0,0);   

        pthread_mutex_init(pmutex);
        pthread_mutex_init(cmutex);
    }

    void push(const T &in){

        sem_wait(&roomSem_);
        phread_mutx_lock(pmutex);

        ringqueue_[pIndex_] = in;
        pIndex_++;
        pIndex_ %= ringqueue_.size();
        sem_post(&dataSem_);

        pthread_mutex_unlock(pmutex);
    }

    T pop(){

        sem_wait(&dataSem_);
        pthread_mutex_lock(pmutex);
        T temp = ringqueue_[cIndex_];
        cIndex_++;
        cIndex_ %= ringqueue_[cIndex_].size();
        sem_post(&dataSem);
        pthread_mutex_unlock(pmutex);

        return temp;
    }

    ~RingQueue(){
        sem_destroy(roomSem_);
        sem_destroy(dataSem_);
        pthread_mutex_destroy(pmutex);
        pthread_mutex_destroy(cmutex);        
    }


private:
    vector<T> ringqueue_;
    sem_t roomSem_;u
    sem_t dataSem_;
    uint32_t pIndex_;
    uint32_t cIndex_;

    pthread_mutex_t pmutex;
    pthread_mutex_t cmutex;

};