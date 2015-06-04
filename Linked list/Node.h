#pragma once

#ifndef NULL
#define NULL 0
#endif
template <class T>
class Node//getters and setters were not used correctly so are unnecessary in the current version of the code, but will be implemented in the future.
{
public:
	Node() //node constructor no arguments
	{
		next = NULL;
	}

	Node(T newItem)//node constructor with setting of int
	{
		NodeItem = newItem;
		next = NULL;
	}

	T getNodeItem()//get of int nodenum
	{
		return NodeItem;
	}
	T setNodeItem(T SetValue)//setting of int nodenum
	{
		NodeItem = SetValue;
	}
	Node* getNext()//getting of pointer next
	{
		return next;
	}
	Node* setNext(Node *NextNode)//setting of pointer next
	{
		next = NextNode;
	}

//private:
	T NodeItem;
	Node *next; 
};