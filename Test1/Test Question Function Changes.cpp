//How to adjust bool list::present   to stop searching if it encounters a value > target?   
//add an if branch within the while loop;  if data field of traveling node > target, target not in list and return false

bool LinkedList::present(Item target) const
{
	Node* trvlPtr = first;			//create a traveling pointer that starts at first
	while (trvlPtr != NULL && trvlPtr->data != target)	//check as long as there are more nodes (!= NULL) lazy eval adds next check if trvlPtr found desired (target) value
	{
		if (trvlPtr->data > target)
			return false;
		else
			trvlPtr = trvlPtr->next;	//if not found and more items advance travel pointer to the next node
	}
	return trvlPtr != NULL;




//How to adjust insert to avoid duplicates:

//add an if statement; it still requires lazy evaluation to make sure we've not fallen off list  
//prev->next->data  since we are at prev  need to check the data field of the next node  so prev->next->data
//if this field ==entry then we have a duplicate  and dont add the value 

void LinkedList::insert(Item entry)
{
	Node* prev; 	//traveling pointer to find the Node in the list that is directly before the spot (value of entry) the new node should be placed
	if (first == NULL || entry < first->data)  //check if the list is empty or if the new value (entry) is now the smallest value in the list and should be first
		first = GetNode(entry, first);	//call GetNode to create a new node at the first position by passing value of entry and location first
	else			//ASSERT: list is not empty and entry is > the first value in the list
	{
		prev = first;		// set our traveling pointer prev to the start of the list
		while (prev->next != NULL && prev->next->data < entry)		//until we are at the end of list (entry is new largest value) and the node after prev contains a value < entry
			prev = prev->next;		//advance prev to next node
		if (prev->next!=NULL && prev->next->data == entry)
		{
			std::cout << "Duplicate value found: NO value inserted" << '\n';
			return;
		}
		else
			prev->next = GetNode(entry, prev->next);  //create a new node with the value of entry and connect it to the list by linking it with the pointer from prev->next
	}
}


//How to adjust insert function in double linked list to account for three special cases
//1.) List is NULL; 2.) Entry is < First; 3.) Entry > Last
//Answers to special cases
//1.) --> We now need to break our if statement into two separate parts    if list == NULL and if entry < first->data  
//    --> if list == NULL   first = GetNode(item, first, NULL)  --> Call GetNode to make a new node and sicne it is first backwars is NULL
//2.)   If entry < first-data
//      --> first = GetNode(item, first, NULL)  //same as before  we also need to add a new line so that the back field of the previous first node points to the new first
//      --> first->next->back = first; 
//3.) Entry > Last  ; just like with the first two special cases we need to add an extra branch to our insertion 
//      --> if (prev->next == NULL) // check if we are at the last node
//      -->     prev->next = GetNode(entry, prev->next, prev) //call GetNode but since this is the last node we don't need the extra line 


void LinkedList::insert(Item entry)
{
	Node* prev; 	//traveling pointer to find the Node in the list that is directly before the spot (value of entry) the new node should be placed
	if (first == NULL )  //check if the list is empty or if the new value (entry) is now the smallest value in the list and should be first
	{
		first = GetNode(entry, first, NULL);	//call GetNode to create a new node at the first position by passing value of entry and location first
	}
	else if (entry < first->data)
	{
		first = GetNode(entry, first, NULL);	//call GetNode to create a new node at the first position by passing value of entry and location first
		first->next->back = first;
	}
	else			//ASSERT: list is not empty and entry is > the first value in the list
	{
		prev = first;		// set our traveling pointer prev to the start of the list
		while (prev->next != NULL && prev->next->data < entry)		//until we are at the end of list (entry is new largest value) and the node after prev contains a value < entry
			prev = prev->next;		//advance prev to next node
		if (prev->next != NULL && prev->next->data == entry)
		{
			std::cout << "Duplicate value found: NO value inserted" << '\n';
			return;
		}
		else if (prev->next == NULL)
			prev->next = GetNode(entry, prev->next, prev);
		else
		{
			prev->next = GetNode(entry, prev->next, prev);  //create a new node with the value of entry and connect it to the list by linking it with the pointer from prev->next
			prev->next->next->back = prev->next;
		}
	}
}
	
//overload istream
	
std::istream LinkedList::operator >>(std::istream&, istream& infile)
{
  Item entry;
  Node* last; 

  makeEmpty();  //clear the file in case something in it 

  infile >> entry; 
  first = GetNode(entry, NULL)
  last = first; 
  infile >> entry; 
  while(!infile.eof())
  {
    last->next=GetNode(entry,NULL);
    last=last->next;
    inifle >> entry; 
  }
  return infile; 
}
