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
	void regular();//规范化，把数字前面的0都删掉
	bigint operator+(bigint& other);
	bigint operator-(bigint& other);
	bigint operator*(bigint& other);
	bigint mi(bigint& other);
};
#endif