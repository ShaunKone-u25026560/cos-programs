#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    char c;
	ifstream file("data.txt", ios::in);

	for (int i = 0; i < 5; i++)
    {
        file.seekg(i, ios::beg);
        if (file.get(c))
        {
            cout << c;
        }else{
            cout << "0";
            file.clear();
        }
    }

    file.close();


	return 0;
}
