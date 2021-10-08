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
	}//���ҵ�βԪ�ص�ָ��
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
	}//���ҵ�����λ�õ�ָ���ǰһ��ָ��
	node* temp = tracer->next;
	tracer->next = tracer->next->next;
	delete temp;
	--size;
}
bool list::isEmpty()
{
	return header->next == NULL;
}