#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <math.h>
#include "minmax.h"

using std::cout;
using std::string;
using std::vector;
using std::stringstream;




int A[1000000];
int size = 0;


//for convenience
int minmax::getParent(int index)
{
    return((index-1)/2);
}
int minmax::getLeftChild(int index)
{
    return(2*index+1);
}
int minmax::getRightChild(int index)
{
    return(2*index+2);
}

bool minmax::onMinLevel(int index)
{
    if(int(log2(index+1))%2 == 1)
        return true;
}
bool minmax::onMaxLevel(int index)
{
    if(int(log2(index+1))%2 == 0)
        return true;
}

void minmax::trickleDown(int index)
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

void minmax::trickleDownMin(int index)
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


void minmax::trickleDownMax(int index)
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

void minmax::bubbleUp(int index)
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

void minmax::bubbleUpMin(int index)
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

void minmax::bubbleUpMax(int index)
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

int minmax::insert(int value)
{
    A[size] = value;
    bubbleUp(size);
    size++;
    return value;
}

string minmax::getMax()
{
    int max;
    if(size = 0)
        return "0";
    if(A[1] > A[2])
        max =  A[1];
    max = A[2];
    return "max = " + max;
}
string minmax::getMin()
{
    if(size = 0)
        return "0";
    return "min = " + A[0];
}

string minmax::deleteMin()
{
    int min = A[0];
    A[0] = A[size-1];
    A[size-1] = NULL;
    size--;
    trickleDown(0);
    return "deleted " + min;

}
string minmax::deleteMax()
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

void minmax::printHeap()
{
    cout << "heap = ";
    for(int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
}

int minmax::getInt(string command)
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


