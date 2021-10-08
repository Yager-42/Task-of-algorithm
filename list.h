#pragma once
#ifndef LIST_H
#define LIST_H
#include<iostream>
using namespace std;


struct node
{
	int data;
	node* next;
	node()
	{
		data = 0;
		next = NULL;
	}
	node(int d, node* n)
	{
		data = d;
		next = n;
	}
};
class list
{
	friend class bigint;
protected:
	node* header;
	int size;
public:
	list();
	void insert(int element);
	void remove(int index);
	bool isEmpty();
	int getSize()
	{
		return size;
	}

};
#endif