#include "downloadFile.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <atomic>


std::mutex coutMutex;
int count = 0;
std::atomic<int> completedDownloads(0);
std::atomic<int> unCompletedDownloads(0);



void downloadFile(std::string fileName) {

    int delay = rand() % 1000 + 500; // 500ms to 1500ms
    std::string progressBar = "----------";
    int left = 0;
    int failChance = rand() % 50;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i <= 100; i += 10) {
        // std::lock_guard<std::mutex> lock(coutMutex);
        
        if (failChance < 20) {
            while (true) {
                std::cout <<  "❌ Download failed for: " << fileName << " ❌" << std::endl;
                std::cout << "Retry Download for " << fileName << " ?" << " y/n" << std::endl;
                
                char userResponse;
                std::cin >> userResponse;

                if (userResponse == 'y') {
                    std::cout << fileName << " will retry download" << std::endl;
                    failChance = rand() % 50;
                    break;
                } else if (userResponse == 'n') {
                    unCompletedDownloads++;
                    std::cout << "Download for " << fileName << " has been terminated" << "\n";
                    return;
                } else {
                    continue;
                }
            }
        }
        
        if (left < 10) {
            std::cout << "✨ " << "[" << fileName <<  "] " << "[" << progressBar << "] " << i << "%" << std::endl;
        } else {
            std::cout << "✅ " << "[" << fileName <<  "] " << "[" << progressBar << "] " << i << "% " << "🎊 COMPLETED 🎊" << std::endl;
        }
        
        progressBar[left] = '#' ;
        left++;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }

    completedDownloads++;
    
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::cout << "⏰ Time taken for " << fileName << ": " << duration.count() << " seconds" << std::endl;
    std::cout << "Total Completed Downloads: " << completedDownloads << std::endl;
    std::cout << "Terminated Downloads: " << unCompletedDownloads <<  std::endl;
}


