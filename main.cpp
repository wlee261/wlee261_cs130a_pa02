#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <math.h>
#include "PA2_dataset.txt"
#include "minmax.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::string line;
    std::ifstream myfile ("PA2_dataset.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            insert(std::stoi(line));
        }
        myfile.close();
    }

    else std::cout << "Unable to open file"; 
    std::string commands = argv[1];
    std::vector<std::string> result;
    std::stringstream s_stream(commands);
    while(s_stream.good())
    {
    std::string substr;
        getline(s_stream, substr, ',');
        result.push_back(substr);
    }

    for(int i = result.size(); i > 0; i--)
    {
        if(result[i].substr(0,5) == "printH")
            printHeap();
        else if(result[i].substr(0,5) == "getMi")
            getMin();
        else if(result[i].substr(0,5) == "getMa")
            getMax();
        else if(result[i].substr(0,5) == "inser")
        {
            insert(getInt(result[i]));
        }
        else if(result[i].substr(0,8) == "deleteMa")
            deleteMax();
        else if(result[i].substr(0,8) == "deleteMi")
            deleteMin();

    }

}