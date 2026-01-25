#include "blockChain.h"
#include "providedFiles.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


// Helper function to print test results
void printTestResult(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Test createBlock and basic structure
void testCreateBlock() {
    float** block = blockChain::createBlock();
    bool passed = true;

    if (block == NULL) passed = false;
    for (int i = 0; i < blockChain::blockSize-1; ++i) {
        if (block[i] != NULL) passed = false;
    }
    if (block[blockChain::blockSize-1] != NULL) passed = false;

    printTestResult("testCreateBlock", passed);
    blockChain::destroy(block);
}

// Test insertion logic
void testInsert() {
    float** block = NULL;
    bool passed = true;

    // First insertion
    int pos1 = blockChain::insert(block, 1.5f);
    if (pos1 != 0 || block == NULL) passed = false;

    // Fill first block
    for (int i = 1; i < blockChain::blockSize-1; ++i) {
        int pos = blockChain::insert(block, 2.0f);
        if (pos != i) passed = false;
    }

    // Should create new block
    int posNew = blockChain::insert(block, 3.0f);
    if (posNew != blockChain::blockSize-1) passed = false;

    printTestResult("testInsert", passed);
    blockChain::destroy(block);
}

// Test removal functionality
void testRemove() {
    float** block = NULL;
    bool passed = true;

    blockChain::insert(block, 5.0f);
    blockChain::insert(block, 5.0f);
    blockChain::insert(block, 3.0f);

    int removed = blockChain::remove(block, 5.0f);
    if (removed != 2) passed = false;

    // Verify remaining elements
    float total = blockChain::total(block);
    if (total != 3.0f) passed = false;

    printTestResult("testRemove", passed);
    blockChain::destroy(block);
}

// Test sorting functionality
void testSort() {
    float** block = NULL;
    bool passed = true;

    blockChain::insert(block, 3.0f);
    blockChain::insert(block, 1.0f);
    blockChain::insert(block, 2.0f);

    blockChain::sort(block);
    float* arr = blockChain::toArray(block);

    if (arr[0] != 1.0f || arr[1] != 2.0f || arr[2] != 3.0f)
        passed = false;

    printTestResult("testSort", passed);
    delete[] arr;
    blockChain::destroy(block);
}

// Test repack functionality
void testRepack() {
    float** block = NULL;
    bool passed = true;

    // Create sparse structure
    blockChain::insert(block, 1.0f);
    blockChain::insert(block, 2.0f);
    blockChain::remove(block, 2.0f);
    blockChain::repack(block);

    // Verify structure
    if (blockChain::numberOfFloats(block) != 1) passed = false;
    if (blockChain::numberOfBlocks(block) != 1) passed = false;

    printTestResult("testRepack", passed);
    blockChain::destroy(block);
}

// Test file loading
void testLoadFromFile() {
    bool passed = true;

    // Create test file
    std::ofstream outfile("test.csv");
    outfile << "1.5,2.5\n3.5,4.5,5.5";
    outfile.close();

    float** block = blockChain::loadFromFile("test.csv");

    if (blockChain::numberOfFloats(block) != 5) passed = false;
    if (blockChain::total(block) != 1.5f+2.5f+3.5f+4.5f+5.5f)
        passed = false;
    printTestResult("testLoadFromFile", passed);
    blockChain::destroy(block);
}

int main() {
    testCreateBlock();
    testInsert();
    testRemove();
    testSort();
    testRepack();
    testLoadFromFile();

    return 0;
}
