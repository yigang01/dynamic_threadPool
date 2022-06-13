#include <iostream>
#include "threadPool.cpp"

void taskFunc(void* arg){
    int num = *(int*)arg;
    std::cout << "thread " << pthread_self() << " is working" << "number is : " << num << std::endl;
    sleep(1);
}
int main(){
    ThreadPool<int> pool(2, 10);
    for(int i = 0; i < 50; i++){
        int* num = new int(i+100);
        Task<int>* tt = new Task<int>(taskFunc, num);
        pool.addTask(tt);
    }
    sleep(30);
    return 0;
}
