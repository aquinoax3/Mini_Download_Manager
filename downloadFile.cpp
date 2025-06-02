#include "downloadFile.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>



std::mutex coutMutex;

int count = 0;
// time_t timestamp;


void downloadFile(std::string fileName) {

    int delay = rand() % 1000 + 500; // 500ms to 1500ms
    std::string progressBar = "----------";
    int left = 0;
    int failChance = rand() % 50;

    auto start = std::chrono::high_resolution_clock::now();
    
    std::cout << "Failed number " << failChance << std::endl;
    for (int i = 0; i <= 100; i += 10) {
        // std::lock_guard<std::mutex> lock(coutMutex);
        // TODO: Add Progress Bar filling up
        // std::cout << "start: " << startTime  << std::endl;

        if (failChance < 20) {
            std::cout <<  "❌ Download failed for: " << fileName << " ❌" << std::endl;
            std::cout << "Retry Download for " << fileName << " ?" << " y/n" << std::endl;
            char userResponse;
            std::cin >> userResponse;

            if (userResponse == 'y') {
                std::cout << fileName << " will retry download" << std::endl;
                failChance = rand() % 50;
                downloadFile(fileName);
            } else {
                break;
            }
        }
        
        if (left < 10) {
            std::cout << "✨ " << "[" << fileName <<  "] " << "[" << progressBar << "] " << i << "%" << std::endl;
        } else {
            std::cout << "✨ " << "[" << fileName <<  "] " << "[" << progressBar << "] " << i << "% " << "COMPLETED" << std::endl;
        }
        progressBar[left] = '#' ;
        left++;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        
        // auto endTime = std::chrono::steady_clock::now();
        // std::cout << "DURATION: " << std::chrono::duration_cast<std::chrono::seconds>(endTime - begin).count() << "s\n";

        // const std::chrono::duration<double, std::milli> elapsedTime = endTime - startTime;
    }
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    // TODO: Display this message ONLY when a file successfulyy downloads
    std::cout << "⏰ Time taken for " << fileName << ": " << duration.count() << " seconds" << std::endl;

}
