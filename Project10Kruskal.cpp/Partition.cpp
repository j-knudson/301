//Implementation file for the partition class
//See Partition.h for documentation 

#include "Partition.h"

//Default Constructor
Partition::Partition() //intitialize a partition to all singletons
{
	for (int i = 0; i < VERTICES; ++i)
		partArr[i] = -1;	//Magic Number: roots start as -1
}

//Member Functions
int Partition::uf_find(int x)
{
	int t, root; 
	int temp = x; 
	while (partArr[temp] >= 0) //while the value is not a root 
		temp = partArr[temp];	//move up the partition tree to find the root 
	root = temp;				//save the root of the partition 
	
	temp = x;					//reset temp to the bottom of the branch
	while (partArr[temp] >= 0)	//move up the branch until we reach the root
	{
		t = temp;				//save the child
		temp = partArr[temp];	//move up to the parent 
		partArr[t] = root;		//move the child to be directly under the root 
	}

	return root;				//don't forget to return the value 
}




void Partition::uf_union(int x, int y) //a weighted uf_union 
{
	int xset = uf_find(x);	//find the root of x
	int yset = uf_find(y);	//find the root of y 

	if (partArr[xset] < partArr[yset]) //if the xset is a larger (size determined by negative) partition than the yset 
	{
		partArr[xset] += partArr[yset]; //adjust size of x partition tree to include y partition 
		partArr[yset] = xset;			//convert y into a child of x 
	}
	else								//the yset is larger than xset 
	{
		partArr[yset] += partArr[xset];	//add size of x to include size of y 
		partArr[xset] = yset;			//make x a child of y 
	}
}

//uf_union without weighted combination 
/*void Partition::uf_union(int x, int y)
{
	int root, newChild;		//placeholders to turn the root of partition y into a child of x
	root = uf_find(x);		//find the root of partition x
	newChild = uf_find(y);	//find the root of partition y
	partArr[newChild] = root;		//assign y to be a part of partition x
}*/