#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include <iostream>
#include "taskQueue.cpp"

template<class T>
class ThreadPool{
public:
    ThreadPool(int minNUm, int maxNUm);
    ~ThreadPool();
    void addTask(Task<T>* task);
private:
    //int getBusyNum();
    //int getAliveNum();
    static void* worker(void* arg);
    static void* manager(void* arg);
    void threadExit();
private:
    pthread_mutex_t _p_mutex;
    pthread_cond_t _p_cond;
    pthread_t _managerId;
    pthread_t* _workerIds;
    TaskQueue<T>* _task_queue;
    int _minNum;
    int _maxNum;
    int _busyNum;
    int _aliveNum;
    int _exitNum;
    bool _stop;
};

#endif
