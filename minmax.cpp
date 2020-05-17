#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <math.h>
#include "PA2_dataset.txt"

using namespace std;

int A[1000000];
int size = 0;


//for convenience
int getParent(int index)
{
    return((index-1)/2);
}
int getLeftChild(int index)
{
    return(2*index+1);
}
int getRightChild(int index)
{
    return(2*index+2);
}

bool onMinLevel(int index)
{
    if(int(log2(index+1))%2 == 1)
        return true;
}
bool onMaxLevel(int index)
{
    if(int(log2(index+1))%2 == 0)
        return true;
}

void trickleDown(int index)
{
    if(index == 0)
        return;

    if(getParent(index) == 0)
        return;

    if(onMinLevel(index))
        trickleDownMin(index);
    else 
        trickleDownMax(index);

}

void trickleDownMin(int index)
{
    int m;
    int descendants[6];
    bool isGrandChild;
    if (A[getLeftChild(index)])
    {
        descendants[0] = A[getLeftChild(index)];
    
        if(A[getRightChild(index)])
        {
            descendants[1] = A[getRightChild(index)];

            //grandchildren can only exist if there are two children for the passed index
            if(A[getLeftChild(getLeftChild(index))])
            {
                descendants[2] = A[getLeftChild(getLeftChild(index))];
            }
            if(A[getRightChild(getLeftChild(index))])
            {
                descendants[3] = A[getRightChild(getLeftChild(index))];
            }
            if(A[getLeftChild(getRightChild(index))])
            {
                descendants[4] = A[getLeftChild(getRightChild(index))];
            }
            if(A[getRightChild(getRightChild(index))])
            {
                descendants[5] = A[getRightChild(getRightChild(index))];
            }
        }
        for(int i = 0; i++; i < 6){ //get minimum from children and grandchildren, stored in an array
            m = 0;
            if(descendants[i])
            {
                if(descendants[i] < descendants[m])
                {
                    m = i;
                    if(m > 2)
                        isGrandChild = true;
                    else
                        isGrandChild = false;
                }
            }
        }
        if(isGrandChild){
            if(A[m] < A[index])
            {
                int temp = A[m];
                A[m] = A[index];
                A[index] = temp;
                if(A[m] > A[getParent(m)])
                {
                    int temp = A[m];
                    A[m] = A[getParent(m)];
                    A[getParent(m)] = A[m];
                }
                trickleDownMin(m);
            }

        }
        else
            if(A[m] < A[index]){ //swap A[m] and A[i]
                int temp = A[m];
                A[m] = A[index];
                A[index] = temp;
            }
    }

}


void trickleDownMax(int index)
{
    int m;
    int descendants[6];
    bool isGrandChild;
    if (A[getLeftChild(index)])
    {
        descendants[0] = A[getLeftChild(index)];
    
        if(A[getRightChild(index)])
        {
            descendants[1] = A[getRightChild(index)];

            //grandchildren can only exist if there are two children for the passed index
            if(A[getLeftChild(getLeftChild(index))])
            {
                descendants[2] = A[getLeftChild(getLeftChild(index))];
            }
            if(A[getRightChild(getLeftChild(index))])
            {
                descendants[3] = A[getRightChild(getLeftChild(index))];
            }
            if(A[getLeftChild(getRightChild(index))])
            {
                descendants[4] = A[getLeftChild(getRightChild(index))];
            }
            if(A[getRightChild(getRightChild(index))])
            {
                descendants[5] = A[getRightChild(getRightChild(index))];
            }
        }
        for(int i = 0; i++; i < 6){ //get minimum from children and grandchildren, stored in an array
            m = 0;
            if(descendants[i])
            {
                if(descendants[i] < descendants[m])
                {
                    m = i;
                    if(m > 2)
                        isGrandChild = true;
                    else
                        isGrandChild = false;
                }
            }
        }
        if(isGrandChild){
            if(A[m] > A[index])
            {
                int temp = A[m];
                A[m] = A[index];
                A[index] = temp;
                if(A[m] < A[getParent(m)])
                {
                    int temp = A[m];
                    A[m] = A[getParent(m)];
                    A[getParent(m)] = A[m];
                }
                trickleDownMax(m);
            }

        }
        else
            if(A[m] > A[index]){ //swap A[m] and A[i]
                int temp = A[m];
                A[m] = A[index];
                A[index] = temp;
            }
    }

}

void bubbleUp(int index)
{
    if(onMinLevel(index))
    {
        if(A[getParent(index)] && (A[index] > A[getParent(index)]))
        {
            int temp = A[index];
            A[index] = A[getParent(index)];
            A[getParent(index)] = temp;
            bubbleUpMax(getParent(index));
        }
        else
            bubbleUpMin(index);
    }
    else if(A[getParent(index)] && (A[index] < A[getParent(index)]))
    {
        int temp = A[index];
        A[index] = A[getParent(index)];
        A[getParent(index)] = temp;
        bubbleUpMin(getParent(index));
    }
    else
        bubbleUpMax(index);
}

void bubbleUpMin(int index)
{
    if(A[getParent(getParent(index))])
    {
        if(A[index] < A[getParent(getParent(index))])
        {
            int temp = A[index];
            A[index] = A[getParent(getParent(index))];
            A[getParent(getParent(index))] = temp;
            bubbleUpMin(getParent(getParent(index)));
        }
    }
}

void bubbleUpMax(int index)
{
    if(A[getParent(getParent(index))])
    {
        if(A[index] > A[getParent(getParent(index))])
        {
            int temp = A[index];
            A[index] = A[getParent(getParent(index))];
            A[getParent(getParent(index))] = temp;
            bubbleUpMax(getParent(getParent(index)));
        }
    }
}

int insert(int value)
{
    A[size] = value;
    bubbleUp(size);
    size++;
    return value;
}

string getMax()
{
    int max;
    if(size = 0)
        return "0";
    if(A[1] > A[2])
        max =  A[1];
    max = A[2];
    return "max = " + max;
}
string getMin()
{
    if(size = 0)
        return "0";
    return "min = " + A[0];
}

string deleteMin()
{
    int min = A[0];
    A[0] = A[size-1];
    A[size-1] = NULL;
    size--;
    trickleDown(0);
    return "deleted " + min;

}
string deleteMax()
{
    int maxIndex;
    int max;
    if(size = 0)
        return "0";
    if(A[1] > A[2])
        maxIndex =  1;
    maxIndex = 2;
    max = A[maxIndex];
    A[maxIndex] = A[size-1];
    A[size-1] = NULL;
    size--;
    trickleDown(maxIndex);
    return "deleted " + max;
}

void printHeap()
{
    cout << "heap = ";
    for(int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}

int getInt(string command)
{
    stringstream ss;
    ss << command;

    string temp;
    int found;
    int value; 

    while(!ss.eof())
    {
        ss >> command;
        if(stringstream(temp) >> found)
            value = found;
    }
    return value;
}


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