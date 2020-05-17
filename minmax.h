//minmax.h

#ifndef MINMAX_H
#define MINXMAX_H

#include <iostream>
#include <vector>


class minmax{
	
	public:
		int getParent(int index);
		int getLeftChild(int index);
		int getRightChild(int index);
		bool onMinLevel(int index);
		bool onMaxLevel(int index);
		void trickleDown(int index);
		void trickleDownMin(int index);
		void trickleDownMax(int index);
		void bubbleUp(int index);
		void bubbleUpMax(int index);
		void bubbleUpMin(int index);
		int insert(int value);
		std::string getMax();
		std::string getMin();
		std::string deleteMax();
		std::string deleteMin();
		void printHeap();
		int getInt(std::string command);
};

#endif
