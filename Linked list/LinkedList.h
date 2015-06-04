#pragma once

#include "Node.h"
#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
#include <string>
using namespace std;
template <class T>
class List
{

private:
	Node<T>* first;
	bool circle;
public:
	Node<T>* getFirst()
	{
		return first;
	}
	T getItem()
	{
		if(first == NULL)
			cout << "no items to retrieve" << endl;
		else
			return first->NodeItem;
	}
	T getNextItem()
	{
		if (first == NULL || first->next == NULL)
			cout << "no Items to retrieve" << endl;
		else
			return first->next->NodeItem;
	}
	List()
	{
		first = NULL;
		circle = false;
	}
	List(T firstItem, bool circ)//class constructor 
	{
		if(!circ)
		{
			first = new Node<T>(firstItem);
			circle = false;
		}
		else
		{
			first = new Node<T>(firstItem);
			first->next = first;
			circle = true;
		}
	}
	T BiggestItem()
	{
		if (first == NULL)
		{
			return 0;
		}
		T* biggest;
		Node<T>* iter = first;
		Node<T>* stopper = first;
		biggest = &first->NodeItem;
		while(stopper->next != NULL)
		{
			if(*biggest < iter->NodeItem)
			{
				biggest = &iter->NodeItem;
			}
			stopper = iter;
			iter = iter->next;
		}
		cout << "biggest is " << *biggest << endl; // test to make sure biggest works
		return *biggest;
	}
	
	void AddToBack(T newItem)//this function adds to the back of the list
	{
		if (first == NULL)
		{
			first = new Node<T>(newItem);
		}
		else 
		{
			Node<T>* iter = first;
			while(iter->next != NULL)
			{
				iter = iter->next;
			}		
			iter->next = new Node<T>(newItem);
		}
	}
	void PushInBack(T newItem) //for a circular list
	{
		if (first == NULL)
		{
			first = new Node<T>(newItem);
			first->next=first;
		}
		else 
		{
			Node<T>* iter = first;
			while(iter->next != first)
			{
				iter = iter->next;
			}		
			iter->next = new Node<T>(newItem);
			iter->next->next = first;
		}
	}
	bool isEmpty()
	{
		return (first == NULL);
	}
	int Count()
	{
		int count = 0;
		Node *iter = first;
		while (iter)
		{
			count++;
			iter = iter->next;
		}
		return count;
	}
	void AddToFront(T newItem)// this function adds to the front of the list
	{
		if (first == NULL)
		{
			first = new Node<T>(newItem);
		}
		else
		{
			Node<T>* iter = first;
			first = new Node<T>(newItem);
			first->next = iter;
		}
	}
	T DeleteFront() // this function deletes at the front of the list
	{
		if (first == NULL)
			throw "Could not delete from empty list!";
		Node<T>* iter = first;
		first = first->next;
		T returnVal = iter->NodeItem;
		delete iter;
		return returnVal;
	}

	T Pop() 
	{
		if (first == NULL)
			throw "Could not delete from empty list!";
		Node<T>* tmp = first;
		first = first->next;
		T val = tmp->NodeItem;
		delete tmp;
		return val;
	}

	T PopFront() // for a circular list
	{
		if (first == NULL)
			throw "Could not delete from empty list!";
		Node<T>* iter = first;
		first = first->next;
		Node<T>* back = first;
		while(back->next != iter)
		{
			back=back->next;
		}
		back->next=first;
		T returnVal = iter->NodeItem;
		delete iter;
		return returnVal;
	}
	T DeleteBack()// this function deletes from the back
	{
		if (first == NULL)
			throw "Could not delete from empty list!";
		Node<T>* iter = first;
		Node<T>* prev = first;
		while(iter->next != NULL)
		{
			prev = iter;
			iter = iter->next;
			
		}
		prev->next = NULL;
		T returnVal = iter->NodeItem;
		delete iter;
		return returnVal;
	}
	void DisplayList()// this function displays the list
	{
		if(circle)
			throw "wrong function call";
		else
		{
			Node<T>* iter = first;
			while(iter != NULL)
			{
				cout << iter->getNodeItem() << endl;
				iter=iter->next;
			}
		}
	}

	void DisplayCircularList()
	{
		if (!circle)
			throw "wrong fucntion call";
		else
		{
			Node<T>* iter = first;
			while(iter->next !=first)
			{
				cout << iter->getNodeItem() << endl;
				iter=iter->next;
			}
		}
	}
	~List()//class destuctor 
	{	
		if (first == NULL)
			return;
		if (!circle) 
		{
			while(first->next != NULL)
			{
				Node<T> *iter = first;
				first = first->next;
				delete iter;
			}
			delete first;
		}
		else
		{
			while(first->next != first)
			{
				Node<T> *iter = first;
				
				first = first->next;
				Node<T>* back = first;
				while(back->next!=iter)
				{
					back=back->next;
				}
				back->next = first;
				delete iter;
			}
			delete first;
		}
	}
};