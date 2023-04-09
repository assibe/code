#pragma once

#include <iostream>
#include <queue>
#include <unistd.h>
#include <memory>
#include <cassert>
#include <pthread.h>
#include <sys/prctl.h>
#include "Log.hpp"

using namespace std;

int gThreadNum = 5;

template <class T>

class ThreadPool
{

    ThreadPool(int pthreadNum_ = gThreadNum) : threadNum(gThreadNum), isStart_(false)
    {

        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&cond_, nullptr);
    }

    static void *threadRoutine(void *args)
    {
        pthread_detach(pthread_self());
        ThreadPool<T> *tp = static_cast<T>(*args);
        prctl(PR_SET_NAME,"follower");
        while (1)
        {
            tp->lockQueue();
            while (!tp->haveTask())
            {
                tp->waitForTask();
            } 
            T t = tp->pop();
            tp->unlockQueue();

            int one,two;
            char oper;
            t.get(&one,&two,&oper);
            Log() << "新线程完成计算："  << one << oper << two << "=" t.run() << "\n";
        }
        

    }

    void start()
    {
        assert(!isStart);
        for (int i = 0; i < threadNum)
        {
            pthread_t tmp;
            pthread_create(&tmp, nullptr, threadRoutine, this);
        }
        isStart = true;
    }

    void push(const T &in)
    {
        lockQueue();
        taskQueue_.push(in);
        choiceThreadForHeader();
        unlockQueue();
    }

    ~ThreadPool()
    {
        pthread_attr_destroy(&mutex_);
        pthread_cond_destroy(&cond_);
    }

private:
    void lockQueue() { pthread_mutex_lock(&mutex_); }
    void unlockQueue() { pthread_spin_unlock(&mutex_); }
    bool haveTask() { return !taskQueue_.empty(); }
    void waitForTask() { pthread_cond_wait(&cond_, &mutex_); }
    void choiceThreadForHeader() { pthread_cond_signal(&cond_); }

    T pop()
    {
        T tmp = taskQueue_.front();
        taskQueue_.pop();
        return tmp;
    }

private:
    bool isStart;
    int threadNum_;
    queue<T> taskQueue_;
    pthread_mutex_t mutex_;
    pthread_cond_t cond_;
};