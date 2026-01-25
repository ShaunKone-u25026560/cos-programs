#include <fstream>
#include <sstream>
#include "blockChain.h"
#include "providedFiles.h"

namespace blockChain {

float** createBlock() {
    float** block = new float*[blockSize];
    for (int i = 0; i < blockSize; ++i) {
        block[i] = NULL;
    }
    return block;
}

void clearData(float** block) {
    if (block == NULL) return;
    for (int i = 0; i < blockSize - 1; ++i) {
        if (block[i] != NULL) {
            delete block[i];
            block[i] = NULL;
        }
    }
    float** next = providedFunctions::convert(block[blockSize - 1]);
    clearData(next);
}

int insert(float**& block, const float value) {
    if (block == NULL) {
        block = createBlock();
        block[0] = new float(value);
        return 0;
    }

    int count = 0;
    float** current = block;
    float** prev = NULL;

    while (current != NULL) {
        for (int i = 0; i < blockSize - 1; ++i) {
            if (current[i] != NULL) {
                ++count;
            } else {
                current[i] = new float(value);
                return count;
            }
        }
        prev = current;
        current = providedFunctions::convert(current[blockSize - 1]);
    }

    float** newBlock = createBlock();
    prev[blockSize - 1] = providedFunctions::convert(newBlock);
    newBlock[0] = new float(value);
    return count;
}

int remove(float**& block, const float value) {
    if (block == NULL) return 0;

    int removed = 0;
    float** current = block;

    while (current != NULL) {
        for (int i = 0; i < blockSize - 1; ++i) {
            if (current[i] != NULL && *(current[i]) == value) {
                delete current[i];
                current[i] = NULL;
                ++removed;
            }
        }
        current = providedFunctions::convert(current[blockSize - 1]);
    }

    return removed;
}

void sort(float** block) {
    if (block == NULL) return;

    float* arr = toArray(block);
    int size = numberOfFloats(block);

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    clearData(block);

    float** current = block;
    int index = 0;

    for (int i = 0; i < size; ++i) {
        while (index >= blockSize - 1) {
            float** next = providedFunctions::convert(current[blockSize - 1]);
            if (next == NULL) {
                next = createBlock();
                current[blockSize - 1] = providedFunctions::convert(next);
            }
            current = next;
            index = 0;
        }
        current[index] = new float(arr[i]);
        ++index;
    }

    for (; index < blockSize - 1; ++index) {
        current[index] = NULL;
    }

    delete[] arr;
}

float* toArray(float** block) {
    if (block == NULL) return NULL;

    int count = numberOfFloats(block);
    float* arr = new float[count];
    int index = 0;

    float** current = block;
    while (current != NULL) {
        for (int i = 0; i < blockSize - 1; ++i) {
            if (current[i] != NULL) {
                arr[index++] = *(current[i]);
            }
        }
        current = providedFunctions::convert(current[blockSize - 1]);
    }

    return arr;
}

void destroy(float**& block) {
    float** prev = NULL;
    float** current = block;

    while (current != NULL) {
        bool empty = true;
        for (int i = 0; i < blockSize - 1; ++i) {
            if (current[i] != NULL) {
                empty = false;
                break;
            }
        }

        float** next = providedFunctions::convert(current[blockSize - 1]);

        if (empty) {
            if (prev == NULL) {
                block = next;
            } else {
                prev[blockSize - 1] = providedFunctions::convert(next);
            }
            delete[] current;
            current = next;
        } else {
            prev = current;
            current = next;
        }
    }
}

bool isEmpty(float**& block) {
    if (block == NULL) return true;
    for (int i = 0; i < blockSize - 1; ++i) {
        if (block[i] != NULL) {
            return false;
        }
    }
    return true;
}

void repack(float**& block) {
    if (block == NULL) return;

    float* arr = toArray(block);
    int size = numberOfFloats(block);

    clearData(block);

    float** current = block;
    int index = 0;

    for (int i = 0; i < size; ++i) {
        while (index >= blockSize - 1) {
            float** next = providedFunctions::convert(current[blockSize - 1]);
            if (next == NULL) {
                next = createBlock();
                current[blockSize - 1] = providedFunctions::convert(next);
            }
            current = next;
            index = 0;
        }
        current[index] = new float(arr[i]);
        ++index;
    }

    for (; index < blockSize - 1; ++index) {
        current[index] = NULL;
    }

    destroy(block);
    delete[] arr;
}

bool search(float** block, const float value) {
    if (block == NULL) return false;

    float** current = block;
    while (current != NULL) {
        for (int i = 0; i < blockSize - 1; ++i) {
            if (current[i] != NULL && *(current[i]) == value) {
                return true;
            }
        }
        current = providedFunctions::convert(current[blockSize - 1]);
    }
    return false;
}

float* get(float** block, int position) {
    if (block == NULL || position < 0) return NULL;

    int currentPos = 0;
    float** current = block;

    while (current != NULL) {
        for (int i = 0; i < blockSize - 1; ++i) {
            if (current[i] != NULL) {
                if (currentPos == position) {
                    return current[i];
                }
                ++currentPos;
            }
        }
        current = providedFunctions::convert(current[blockSize - 1]);
    }
    return NULL;
}

int numberOfBlocks(float** block) {
    if (block == NULL) return 0;

    int count = 0;
    float** current = block;
    while (current != NULL) {
        ++count;
        current = providedFunctions::convert(current[blockSize - 1]);
    }
    return count;
}

int numberOfFloats(float** block) {
    if (block == NULL) return 0;

    int count = 0;
    float** current = block;
    while (current != NULL) {
        for (int i = 0; i < blockSize - 1; ++i) {
            if (current[i] != NULL) {
                ++count;
            }
        }
        current = providedFunctions::convert(current[blockSize - 1]);
    }
    return count;
}

int maxPossibleFloats(float** block) {
    return numberOfBlocks(block) * (blockSize - 1);
}

float total(float** block) {
    if (block == NULL) return 0.0f;

    float sum = 0.0f;
    float** current = block;
    while (current != NULL) {
        for (int i = 0; i < blockSize - 1; ++i) {
            if (current[i] != NULL) {
                sum += *(current[i]);
            }
        }
        current = providedFunctions::convert(current[blockSize - 1]);
    }
    return sum;
}

float average(float** block) {
    int count = numberOfFloats(block);
    if (count == 0) return 0.0f;
    return total(block) / count;
}

void adjust(float** block, float value) {
    if (block == NULL) return;

    float** current = block;
    while (current != NULL) {
        for (int i = 0; i < blockSize - 1; ++i) {
            if (current[i] != NULL) {
                *(current[i]) += value;
            }
        }
        current = providedFunctions::convert(current[blockSize - 1]);
    }
}

float** loadFromFile(std::string csvFileName) {
    std::ifstream file(csvFileName.c_str());
    if (!file.is_open()) {
        return NULL;
    }

    float** block = NULL;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string valueStr;

        while (std::getline(ss, valueStr, ',')) {
            std::stringstream converter(valueStr);
            float value;
            if (converter >> value) {
                insert(block, value);
            }
        }
    }

    file.close();
    return block;
}

}
