/*
Use of join(), detach() and joinable in thread in C++ 11.

Join Notes:
0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
1. Double join will result into program termination.
2. If needed we should check thread is joinable before joining. (use joinable function)

Detach Notes:
0. This is used to detach newly created thread from the parent thread.
1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and double detach() will result into program termination.
2. If we have detached thread and main function is returning then the detached thread execution is suspended.

Notes:
Either join() or detach() should be called on thread object, otherwise during thread object's desctructor it will terminate the program. Because inside desctructor it checks if thread is still joinable? If yes then it terminates the program.

*/

#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void run(int count){
  while(count-->0)
    cout<<count<<" Yashwant Kr. Choudhary"<<endl;
  std::this_thread::sleep_for(chrono::seconds(3));
  cout<<"thread execution finished"<<endl;
}

int main(){
  std::thread t1(run,10);
  cout<<"main begins "<<endl;
  t1.join();
//   t1.detach();

  if(t1.joinable())
    t1.join();
  cout<<"main ends"<<endl;

  return 0;
}

/*
Output:
main begins 
9 Yashwant Kr. Choudhary
8 Yashwant Kr. Choudhary
7 Yashwant Kr. Choudhary
6 Yashwant Kr. Choudhary
5 Yashwant Kr. Choudhary
4 Yashwant Kr. Choudhary
3 Yashwant Kr. Choudhary
2 Yashwant Kr. Choudhary
1 Yashwant Kr. Choudhary
0 Yashwant Kr. Choudhary
thread execution finished
main ends

*/
