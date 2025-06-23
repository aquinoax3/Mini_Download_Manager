#include <string>

void downloadFile(std::string fileName);
extern std::atomic<int> completedDownloads;
extern std::atomic<int> unCompletedDownloads;