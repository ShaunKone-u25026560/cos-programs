#include "Brainhurt.h"

Brainhurt::Brainhurt(int tapeSize) // Function 1
{
    tape = new Tape(tapeSize);
}

Brainhurt::~Brainhurt() // Function 2
{
    if (tape)
        delete tape;
}

void Brainhurt::operator()(std::string code, std::istream& in, std::ostream& out) // Function 3
{
    !(*tape);
    int codeLength = code.length(), nested = 0;
    bool skipLoop = false, reverseLoop = false;

    int loopNo = 0;
    for (int i = 0; i < codeLength; i++) // Loop through the passed in code (ALTERNATIVELY: use c pointers to loop)
    {
        char instruction = code[i];

        ///////////////////////////////////////////
        std::cout << "Instruction No: " << loopNo  << " Character: " << instruction << std::endl;
        loopNo++;
        //////////////////////////////////////////////

        if (!skipLoop && !reverseLoop)
        {
            try
            {
                switch (instruction)
                {
                    case '<' : (*tape)--;
                        break;
                    case '>' : (*tape)++;
                        break;
                    case '+' : ++(*tape);
                        break;
                    case '-' : --(*tape);
                        break;
                    case '.' : out << (*tape);
                        break;
                    case ',' : in >> (*tape);
                        break;
                    case '[' :  if ((*tape)[0])
                                    skipLoop = true;
                        break;
                    case ']' :  if (!((*tape)[0]))
                                    reverseLoop = true;
                        break;
                    default : throw "Illegal character in code\n";
                }
            }
            catch(const char* errMessage)
            {
                out << "Interpreter failed on instruction " << instruction << " with error: " << errMessage;
                return;
            }

        }else if (instruction == '[') // Code to skip over nested pairs of square brackets
        {
            if (skipLoop)
                nested++;
            else if (nested > 0)
                nested--;
            else
            {
                reverseLoop = false;
                nested = 0;
            }
        }else if (instruction == ']')
        {
            if (reverseLoop)
                nested++;
            else if (nested > 0)
            {
                nested--;
            }else
            {
                skipLoop = false;
                nested = 0;
            }
        }

        if (reverseLoop)
        {
            i -= 2;
            if (i < -1) // Means we couldn't find the matching brace
                throw "Invalid loop\n";
        }
    }

    if (skipLoop == true) // No matching brace was found
        throw "Invalid loop\n";
}
