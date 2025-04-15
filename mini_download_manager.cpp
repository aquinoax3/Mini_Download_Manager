#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>

std::mutex coutMutex;
int count = 0;

void downloadFile(std::string fileName) {

    int delay = rand() % 1000 + 500; // 500ms to 1500ms
    std::string progressBar = "----------";
    int left = 0;
    
    for (int i = 0; i <= 100; i += 10) {
        // std::lock_guard<std::mutex> lock(coutMutex);
        // TODO: Add Progress Bar filling up
        if (left < 10) {
            std::cout << "✨ " << "[" << fileName <<  "] " << "[" << progressBar << "] " << i << "%" << std::endl;
        } else {
            std::cout << "✨ " << "[" << fileName <<  "] " << "[" << progressBar << "] " << i << "% " << "COMPLETED" << std::endl;
        }
        progressBar[left] = '#' ;
        left++;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }

    // std::system("clear"); // Clears terminal
    std::cout << "✅ " << "File: " << fileName <<  " Downloaded" << std::endl;
}

int main() {

    std::thread file1(downloadFile,"Hunter x Hunter");
    std::thread file2(downloadFile,"Pokemon Gold");
    std::thread file3(downloadFile, "Mega-Man X4");

    file1.join();
    file2.join();
    file3.join();

    std::cout << "🏁 All files have completed download 🏁" << std::endl;
    
    return 0;
}