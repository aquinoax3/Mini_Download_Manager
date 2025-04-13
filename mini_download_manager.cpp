#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>

std::mutex coutMutex;
int count = 0;

void downloadFile(std::string fileName) {

    int delay = rand() % 1000 + 500; // 500ms to 1500ms
    
    for (int i = 0; i <= 100; i += 10) {
        // std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "✨ " << "[" << fileName <<  "] " << i << "%" << std::endl;
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
    
    return 0;
}