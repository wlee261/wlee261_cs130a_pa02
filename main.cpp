#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <math.h>
#include "PA2_dataset.txt"
#include "minmax.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    string line;
    ifstream myfile ("PA2_dataset.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            insert(stoi(line));
        }
        myfile.close();
    }

    else cout << "Unable to open file"; 
    string commands = argv[1];
    vector<string> result;
    stringstream s_stream(commands);
    while(s_stream.good())
    {
    string substr;
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