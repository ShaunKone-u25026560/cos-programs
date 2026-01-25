#include "ConcurrentSorting.h"

std::vector<int> buffer;
std::vector<int> indices;
std::vector<std::thread> threadPool;
int currentPhase = 0;
int totalSwaps = 0;
int totalThreadsUsed = 0;

std::string buffertoString(){
    std::string res = "";
    for(std::size_t i=0; i<buffer.size(); i++) res += "| " + std::to_string(buffer[i]) + " ";
    res += "|";
    return res;
}
/*The above is given do not change*/
void initBuffer(std::vector<int>& vec)
{
    buffer = vec;

}

bool isSorted()
{
    bool isSmallerThanNext = true; // This variable should remain true for the entirety of the loop for the buffer to be sorted

    // Loop through vector
    int vectSize = buffer.size();

    for (int i = 0; i < vectSize - 1; i++)
    {
        if (buffer[i] > buffer[i + 1])
            isSmallerThanNext = false;
    }

    return isSmallerThanNext;
}

int maxPhasesExpected()
{
    int vectSize = buffer.size();
    return vectSize;
}

int maxSwapsExpected()
{
    int vectSize = buffer.size();
    //applys appropriate formula: Tn = 1/2*(n - 2)^2 + 3/2*(n-2) + 1
    // This works for special cases of size of 1 or 2 as well
    float maxSize = (0.5f * (float(vectSize) - 2.0f)*(float(vectSize) - 2.0f)) + (1.5f * (float(vectSize) - 2.0f)) + 1.0f;
    int result = maxSize;
    return result;
}

void setIndices()
{
    // Format of setIndices vector < First Index To be swapped, Second Index To be swapped> E.g <0, 2>
    // First clear the vector
    indices.clear();
    // Determine the indices using the formula:
    int size = buffer.size();
    int iterations = int(size) / 2;

    if (size % 2 == 0 && currentPhase % 2 != 0)
        --iterations;

    for (int i = 0; i < iterations; i++)
    {
        (currentPhase % 2 == 0)? indices.push_back(i * 2) : indices.push_back(i * 2 + 1);
    }
}

void swap(int index1, int index2)
{
    std::cout << "Thread " << std::this_thread::get_id() << " is using indices " << index1 << " and " << index2 << std::endl;

    if (buffer[index1] > buffer[index2]) // Check if they must be swapped
    {
        // Print message stating values are being swapped
        std::cout << "Thread " << std::this_thread::get_id() << " is swapping " << buffer[index1] << " and " << buffer[index2] << std::endl;

        // Swap the values
        int temp = buffer[index1];
        buffer[index1] = buffer[index2];
        buffer[index2] = temp;

        ++totalSwaps;
    }
}

void clearThreadPool()
{
    threadPool.clear();
}

void SetAndRunThreads()
{
    /////////////////////////////////////////////////////// MAKE PROVISION FOR ONLY 1 ELEMENT/ITEM IN BUFFER
    clearThreadPool();
    int numThreads = indices.size();

    // Print out how many threads will be executed
    std::cout << numThreads << " threads about to execute" << std::endl;

    // Assign each threads task
    for (int i = 0; i < numThreads; i++)
    {
        ++totalThreadsUsed;
        threadPool.push_back( std::thread(swap, indices[i], indices[i] + 1) );
    }

    for (int i = 0; i < numThreads; i++) // May have to check if joinable
    {
        if (threadPool[i].joinable())
            threadPool[i].join();
    }
}

void concurrentSort()
{
    while (!isSorted())
    {
        setIndices();
        std::cout << "Current phase : " << currentPhase << std::endl;
        SetAndRunThreads();
        std::cout << "Phase results = " << buffertoString() << std::endl;
        std::cout << "Is sorted = ";

        if (isSorted())
        {
            std::cout << "Yes" << std::endl;
        }else
        {
            std::cout << "No" << std::endl;
            ++currentPhase;
        }
    }
}

void printResults()
{
    std::cout << "\nPost sort results : " << std::endl;
    std::cout << "Total threads used = " << totalThreadsUsed << std::endl;
    std::cout << "Maximum swaps expected = " << maxSwapsExpected() << std::endl;
    std::cout << "Total swaps = " << totalSwaps << std::endl;
    std::cout << "Maximum phases expected = " << maxPhasesExpected() << std::endl;
    std::cout << "Amount of phases entered = " << currentPhase << std::endl;
    std::cout << "After = " << buffertoString() << std::endl;
}
