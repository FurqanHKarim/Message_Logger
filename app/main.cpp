#include<iostream>
#include<../inc/Message_Logger.hpp>
#include <chrono>

using namespace std;
void busy_wait(int seconds) {
    auto end = std::chrono::steady_clock::now() + std::chrono::seconds(seconds);
    while (std::chrono::steady_clock::now() < end) {
        // Busy-wait
    }
}


int main(){
    // // file.seekp()
    
    Log_stream log_1553("./1553.txt",50);
    Log_stream bro("./bro.txt",50);
    Log_stream boi("./boi.txt",50);

    for (size_t i = 0; i < 1000000; i++)
    {
        log_1553<<"1553 Logger Works"<<i<<"\n";
        boi<<"BOII Will Work"<<i<<"\n";
        bro<<"Bro is Working"<<i<<"\n";
        // busy_wait(1);
    }
    
    // helpLogs<<"Suppose this will work";
    return 0;
}