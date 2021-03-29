//Implementation file for the priority queue ADT 

#include <iostream>
#include "pQueue1.h"

void pQueue::enqueue(Item entry)
{
	data[count] = entry;	//add the new entry to the current index of the array
	reheapUP(count);		//move it to the correct position (restore heap property)	
	++count;				//increment index 
}

//Private Function used by enqueue()
void pQueue::reheapUP(int child)
{
	int parent;					//tree term for head of a binary branch
	parent = (child - 1) / 2;	//equation to find the parent of a given(child) value 
	while (child > 0 && data[child] > data[parent]) //while there are still elements to compare and if the child > parent, then it needs to move up the tree
	{
		std::swap(data[child], data[parent]);
		child = parent;				//reset child to new value since it moved up the tree
		parent = (child - 1 / 2);	//find this values parent to compare again and see if it should move up further
	}
}
void pQueue::heapSort(pQueue q, int size)
{
	for (int i = (size - 2) / 2; i > 0; --i)
	{

	}
}


pQueue::Item pQueue::dequeue()
{
	Item temp;			//placeholder used to restore heap property
	temp = data[0];		//start at root; 
	--count;			//moves count to be pointed at the bottom right most leaf 
	data[0] = data[count];	//move the right-most leaf to the root 
	reheapDown(0);			//reheap down starting at the root 
	return temp;
}

//Private Function used by dequeue()

void pQueue::reheapDown(int parent)	//Swaps the element initially in data[parent] 
{									//DOWN until the heap property is restored	
	int maxChild;
	bool done;

	done = false;
	while (2 * parent + 1 < count && !done)   //find child equation is 2i+1  (i is element of parent, so 2*parent + 1) 
	{
		maxChild = 2 * parent + 1; //examine left child 
		if (maxChild + 1 < count && data[maxChild + 1] > data[maxChild])  //is there a right child? If so, if the value in right child is larger than left child, increment to the right child
			++maxChild;													 //this moves to the right child if it has the larger value 
		if (data[parent] < data[maxChild])
		{
			std::swap(data[parent], data[maxChild]);	//if parent is smaller we need to exchange values to restore heap property
			parent = maxChild; //advance parent to maxChild so we can repeat the loop and check again if we need to move a smaller value below a larger value 
		}
		else				//if we hit this the parent has a larger value than child and heap property is intact
			done = true;	//flip done to true so loop stops 

	}
}

void pQueue::exchange(Item &x, Item &y)
{
	Item temp;
	temp = data[x];
	data[x] = data[y];
	data[y] = temp;
}