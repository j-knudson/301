//File Partition.h
//This is the header file for a Partition class which will be used to make a minimum spanning tree with Kruskal's algorithm


#ifndef PARTITION
#define PARTITION

class Partition
{
	public: 
		//Member Constant 
		static const int VERTICES = 42+8; //this can be any number; it is the possible number of vertices in the spanning tree
		
	
		//Default Constructor
		Partition(); //intitialize a partition to all singletons
	
		//Member Functions
		int uf_find(int x); 
		//Postcondition: The root of element x is returned; x is made a direct child to its root  
		void uf_union(int x, int y); 
		//Postcondition: Subtrees x and y are compared and the smaller of the two is made a subtree to the larger
	private: 
		//Data Member --> The array of partitions 
		int partArr[VERTICES]; 
};

#endif 