#include <fstream>
#include "fileMan.h"

bool saveVecToFile(void* vec, int size, const char* filePath) {
    std::ofstream myFile(filePath, std::ios::binary);
    if (myFile.is_open()) {
        myFile.write(reinterpret_cast<const char*>(vec), size);
        myFile.close();
        return true;
    }
    return false;
}

bool readVecFromFile(void* vecToLoad, int sizeToRead, const char* filePath) {
    std::ifstream myFile(filePath, std::ios::binary);
    if (myFile.is_open()) {
        myFile.read(reinterpret_cast<char*>(vecToLoad), sizeToRead);
        myFile.close();
        return true;
    }
    return false;
}