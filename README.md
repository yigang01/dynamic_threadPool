# dynamic_threadPool
c++实现的动态线程池，自动根据任务数量进行线程数量的调节，主要特性：  
* 使用简单。
* 任务数量 > 存活线程数量时线程池会自动创建线程执行任务。
* 任务数量 < 存活线程数量时线程池会自动回收空闲线程。
* 支持线程复用、提升性能。

## 编译
g++ main.cpp -o thread_pool

## 运行
./thread_pool

