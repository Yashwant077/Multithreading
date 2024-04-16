#include <iostream>
#include <thread>

using namespace std;

// // 1. Function Pointer

// void fun(int x){
//     while(x-- > 0){
//         cout<<x<<endl;
//     }
// }

// int main()
// {
//     std::thread t(fun,10);
//     t.join();

//     return 0;
// }



// // 2. Lambda Function

// int main(){
//     // we can directly inject lambda at thread creation time.
//     // auto fun = [](int x){
//     //     while(x-- > 0){
//     //         cout<< x << endl;
//     //     }
//     // };
    
//     // std::thread t(fun,10);
    
//     std::thread t([](int x){
//         while(x-- > 0){
//             cout<< x << endl;
//         }
//     },10);
    
//     t.join();
//     return 0;
// }

// // 4. Functor (Function Object)

// class Base {
//     public:
//         void operator()(int x){
//             while(x-- > 0){
//                 cout<< x <<endl;
//             }
//         }
// };

// int main(){
//     std::thread t((Base()), 10);
//     t.join();
    
//     return 0;
// }


// // 4. Non-static Member function

// class Base {
//     public:
//         void run(int x){
//             while(x-- > 0){
//                 cout<< x <<endl;
//             }
//         }
// };

// int main(){
//     Base b;
//     std::thread t(&Base::run, &b, 10);
//     t.join();
    
//     return 0;
// }


// 5. Static Member function

class Base {
    public:
        static void run(int x){
            while(x-- > 0){
                cout<< x <<endl;
            }
        }
};

int main(){
    std::thread t(&Base::run, 10);
    t.join();
    
    return 0;
}


/* Output:
9
8
7
6
5
4
3
2
1
0

*/
