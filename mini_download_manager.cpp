#include <iostream>
#include <thread>
#include "downloadFile.h"


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