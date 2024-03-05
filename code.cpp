#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
int main(){
    mutex m1;
    thread th1([&m1]()->void{
        lock_guard<mutex>lock(m1);
        cout << "Thread1" << endl;
        });
    thread th2([&m1]()->void{
        lock_guard<mutex>lock(m1);
        cout << "Thread2" << endl;
        });
    th1.join();
    th2.join();
    cout << "End of Main Thread" << endl;
    return 0;
}
