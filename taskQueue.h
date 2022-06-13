#ifndef _TASKQUEUE_H
#define _TASKQUEUE_H

#include <iostream>
#include <queue>
#include <pthread.h>

typedef void(*callback)(void*);

template<class T>
struct Task{
    Task(){
        _function = NULL;
    }
    Task(callback f, void* arg){
        _function = f;
        _arg = (T*)arg;
    }
    void run(){
        _function(_arg);
    }
    callback _function;
    T* _arg;
};

template<class T>
class TaskQueue{
public:
    TaskQueue();
    ~TaskQueue();
    // 添加任务
    void addTask(Task<T>* task);
    void addTask(callback func, void* arg);
    // 获取任务
    Task<T>* getTask();
    // 获取当前任务数量
    inline int getTaskNum(){
        return _t_queue.size();
    }
private:
    std::queue<Task<T>*> _t_queue; 
    pthread_mutex_t _t_mutex;
};

#endif 
