/*
Topic: mutex::try_lock() on Mutex in c++

0. try_lock() tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns false.
1. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
2. If try_lock() is called again by the same thread which owns the mutex, the behaviour is undefined.
    It is a dead lock situation with undefined behaviour. (if you want to be able to lock tha same mutex by same thread
    more than one time the go for recursive_mutex)

*/

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
std::mutex mtx;

void increaseTheCounterFor100000Time(){
    for(int i=0; i<100000; ++i){
        if(mtx.try_lock()){
            ++counter;
            mtx.unlock();
        }
    }
}

int main(){
  std::thread t1(increaseTheCounterFor100000Time);
  std::thread t2(increaseTheCounterFor100000Time);
  
  t1.join();
  t2.join();
  
  cout<<counter<<endl;

  return 0;
}
