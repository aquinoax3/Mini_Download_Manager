#include "downloadFile.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>



std::mutex coutMutex;

int count = 0;
// time_t timestamp;


void downloadFile(std::string fileName) {

    int delay = rand() % 1000 + 500; // 500ms to 1500ms
    std::string progressBar = "----------";
    int left = 0;
    auto begin = std::chrono::steady_clock::now();
    
    // time(&timestamp);
    // std::cout << "TIME: " << ctime(&timestamp) << std::endl;
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
        
        auto endTime = std::chrono::steady_clock::now();
        std::cout << "DURATION: " << std::chrono::duration_cast<std::chrono::seconds>(endTime - begin).count() << "s\n";

        // const std::chrono::duration<double, std::milli> elapsedTime = endTime - startTime;
    }

}


// int longestSubArr (std::vector<int> arr, int k) {
//     int left = 0;
//     int currSum = 0;
//     int result = 1;

//     for (int right = 0; right < arr.size(); right++) {
//         currSum += arr[right];
//         std::cout << currSum << std::endl;

//         while (currSum > k) {
//             currSum -= arr[left];
//             left++;
//         }

//         result = std::max(result, right - left + 1);
//     }

//     return result;
// }


// int main() {

//     std::vector<int> numArr = {3, 1, 2, 7, 4, 2, 1, 1, 5};

//     std::cout << longestSubArr(numArr, 8);

//     return 0;
// }
