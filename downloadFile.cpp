#include "downloadFile.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>
#include <ctime>



std::mutex coutMutex;
int count = 0;
time_t timestamp;


void downloadFile(std::string fileName) {

    int delay = rand() % 1000 + 500; // 500ms to 1500ms
    std::string progressBar = "----------";
    int left = 0;
    time(&timestamp);
    std::cout << "TIME: " << ctime(&timestamp) << std::endl;
    // const auto startTime = std::chrono::steady_clock::now();
    
    for (int i = 0; i <= 100; i += 10) {
        // std::lock_guard<std::mutex> lock(coutMutex);
        // TODO: Add Progress Bar filling up
        // std::cout << "start: " << startTime  << std::endl;
        
        if (left < 10) {
            std::cout << "✨ " << "[" << fileName <<  "] " << "[" << progressBar << "] " << i << "%" << std::endl;
        } else {
            std::cout << "✨ " << "[" << fileName <<  "] " << "[" << progressBar << "] " << i << "% " << "COMPLETED" << std::endl;
        }
        progressBar[left] = '#' ;
        left++;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        
        // const auto endTime = std::chrono::steady_clock::now();
        // const std::chrono::duration<double, std::milli> elapsedTime = endTime - startTime;
    }

}
