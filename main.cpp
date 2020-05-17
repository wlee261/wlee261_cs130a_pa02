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
    minmax mm;
    std::string line;
    std::ifstream myfile ("PA2_dataset.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            mm.insert(std::stoi(line));
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
            mm.printHeap();
        else if(result[i].substr(0,5) == "getMi")
            mm.getMin();
        else if(result[i].substr(0,5) == "getMa")
            mm.getMax();
        else if(result[i].substr(0,5) == "inser")
        {
            mm.insert(getInt(result[i]));
        }
        else if(result[i].substr(0,8) == "deleteMa")
            mm.deleteMax();
        else if(result[i].substr(0,8) == "deleteMi")
            mm.deleteMin();

    }

}
