#pragma once
#ifndef BIGDATA_H
#define BIGDATA_H

#include"list.h"
#include<string>

class bigint
{
private:
	list number;
public:
	bigint();
	bigint(int);
	void read();
	void print();
	void regular();//�淶����������ǰ���0��ɾ��
	bigint operator+(bigint& other);
	bigint operator-(bigint& other);
	bigint operator*(bigint& other);
	bigint mi(bigint& other);
};
#endif