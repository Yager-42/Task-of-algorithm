#include"list.h"

list::list()
{
	header = new node;
	header->next = NULL;
	header->data = 0;
	size = 0;
}
void list::insert(int element)
{
	node* temp = new node;
	node* tracer = header;
	for (int i = 0; i < size; ++i)
	{
		tracer = tracer->next;
	}//查找到尾元素的指针
	temp->data = element;
	tracer->next = temp;
	++size;
}
void list::remove(int index)
{
	node* tracer = header;
	for (int i = 0; i < index-1; ++i)
	{
		tracer = tracer->next;
	}//查找到定向位置的指针的前一个指针
	node* temp = tracer->next;
	tracer->next = tracer->next->next;
	delete temp;
	--size;
}
bool list::isEmpty()
{
	return header->next == NULL;
}