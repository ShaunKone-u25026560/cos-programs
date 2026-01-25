#ifndef ROBOTS_H
#define ROBOTS_H

#include <string>
#include <sstream>

/**
 * @brief Robot Obfuscation Bamboozlement Oscillation Translator Student
 * 
 */
namespace ROBOTS
{
    /**
     * @brief Validates the input.
     * 
     * @param input Input from external source
     * @return true if input is valid
     * @return false if input is invalid
     */
    bool task1(std::string input);

    /**
     * @brief Converts input to trinary.
     * 
     * @param input Valid input from external source
     * @return std::string converted input
     */
    std::string task2(std::string input);
    
    /**
     * @brief Translates input
     * 
     * @param convertedInput Converted input from external source
     * @return std::string translated input
     */
    std::string task3(std::string convertedInput);

    /**
     * @brief Expands input
     * 
     * @param translatedInput Input from external source
     * @return std::string expanded input
     */
    std::string task4(std::string translatedInput);

    /**
     * @brief Converts an int into a string
     * 
     * @param v input int
     * @return std::string string form of the passed in int.
     */
    std::string intToString(int v);
} // namespace ROBOTS


#endif /*ROBOTS_H*/