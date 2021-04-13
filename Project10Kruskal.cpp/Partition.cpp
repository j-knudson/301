//Implementation file for the partition class
//See Partition.h for documentation 

#include "Partition.h"

//Default Constructor
Partition::Partition() //intitialize a partition to all singletons
{
	for (int i = 0; i < VERTICES; ++i)
		partArr[i] = -1;	//Magic Number: roots are -1 
}

//Member Functions
int Partition::uf_find(int x)
{
	int temp = x; 
	while (partArr[temp] >= 0) //while the value is not a root 
		temp = partArr[temp];	//move up the partition tree to find the root 
	return temp;				//return the root of the partition 
}
void Partition::uf_union(int x, int y)
{
	int root, newChild;		//placeholders to turn the root of partition y into a child of x
	root = uf_find(x);		//find the root of partition x
	newChild = uf_find(y);	//find the root of partition y
	partArr[newChild] = root;		//assign y to be a part of partition x  
}