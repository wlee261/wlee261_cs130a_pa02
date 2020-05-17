//minmax.h

#ifndef MINMAX_H
#define MINXMAX_H

#include <iostream>
#include <vector>

class minmax{
	
	public:
		int getParent();
		int getLeftChild();
		int getRightChild();
		bool onMinLevel();
		bool onMaxLevel();
		void trickleDown();
		void trickleDownMin();
		void trickleDownMax();
		void bubbleUp();
		void bubbleUpMax();
		void bubbleUpMin();
		int insert();
		string getMax();
		string getMin();
		string deleteMax();
		string deleteMin();
		void printHeap();
		int getInt();
};

#endif