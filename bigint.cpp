#include"bigint.h"

bigint::bigint()
{
	
}
bigint::bigint(int element)
{
	number.insert(element);
}
void bigint::read()//把数字先存在字符串中然后再将字符串反向读取，低位到高位的顺序塞进链表
{
	string get;
	cout << "输入数字" << endl;
	cin >> get;
	if (get[0] == '-')
	{
		number.header->data = 1;
		for (int i = get.length() - 1; i >= 1; --i)
		{
			number.insert((int)(get[i] - 48));
		}
	}
	else
	{
		for (int i = get.length() - 1; i >= 0; --i)
		{
			number.insert((int)(get[i] - 48));
		}
	}
	
}
void bigint::print()//将链表中的数据倒过来放进整数数组，判断头指针中的data，1负0正
{
	node* tra = this->number.header->next;
	int* out = new int[this->number.getSize()];
	for (int i = this->number.getSize()-1; i >= 0; --i)
	{
		out[i] = tra->data;
		tra = tra->next;
	}
	if (this->number.header->data == 1)
	{
		cout << '-';
	}
	for (int i = 0; i < this->number.getSize(); ++i)
	{
		cout << out[i];
	}
	cout << endl;
}
void bigint::regular()
{
	node* tra = number.header;
	for (int i = 0; i < number.getSize(); ++i)
	{
		tra = tra->next;
	}
	if (tra->data == 0)
	{
		number.remove(number.getSize());
	}
}
bigint bigint::operator+(bigint& other)
{
	bigint sum;
	int counter = 0;
	int big = 0;
	int tempsum = 0;
	int carry = 0;
	int num = 0;
	node* bigTra;
	node* thisTra = this->number.header->next;
	node* otherTra = other.number.header->next;
	if (this->number.getSize() > other.number.getSize())
	{
		counter = other.number.getSize();
		big = this->number.getSize();
		bigTra = this->number.header->next;
	}
	else
	{
		counter = this->number.getSize();
		big = other.number.getSize();
		bigTra = other.number.header->next;
	}//先把数位较小的加起来
	for (int i = 0;i < counter; ++i)
	{
		tempsum = thisTra->data + otherTra->data+carry;
		if (tempsum > 9)
		{
			tempsum = tempsum - 10;
			carry = 1;
		}//进位
		else
		{
			carry = 0;
		}
		sum.number.insert(tempsum);
		thisTra = thisTra->next;
		otherTra = otherTra->next;
		bigTra = bigTra->next;//到下一个位数
	}
	if (thisTra == NULL && otherTra == NULL&&carry==1)
	{
		sum.number.insert(carry);
	}//两个数一样长，处理进位
	else
	{
		if (bigTra == NULL)
		{
			if (carry == 1)
			{
				sum.number.insert(carry);
			}
		}
		else
		{
			num = bigTra->data + carry;
			if (num > 9)
			{
				num -= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			sum.number.insert(num);
			bigTra = bigTra->next;
			for (int i = counter + 1; i < big; ++i)
			{
				num = bigTra->data + carry;
				if (num > 9)
				{
					num -= 10;
					carry = 1;
				}
				else
				{
					carry = 0;
				}
				sum.number.insert(num);
				bigTra = bigTra->next;
			}
			if (carry == 1)
			{
				sum.number.insert(carry);
			}//最后一位的处理
		}
	}
	return sum;
}
bigint bigint::operator-(bigint& other)
{
	bigint sub;
	int big=0;
	int small = 0;
	int tempsub = 0;
	int borrow = 0;
	int thisL = this->number.getSize();
	int otherL = other.number.getSize();
	node* thisTra = this->number.header->next;
	node* otherTra = other.number.header->next;
	if (thisL > otherL)
	{
		big = thisL;
		small = otherL;
	}
	else
	{
		big = otherL;
		small = thisL;
	}
	for (int i = 0; i < small; ++i)
	{
		tempsub = thisTra->data - otherTra->data - borrow;
		if (tempsub < 0)
		{
			tempsub += 10;
			borrow = 1;
		}//借位
		else
		{
			borrow = 0;
		}
		sub.number.insert(tempsub);
		thisTra = thisTra->next;
		otherTra = otherTra->next;
	}
	if(thisTra==NULL&&otherTra==NULL&&borrow==1)
	{
		sub=other - (*this);
		sub.number.header->data = 1;
		return sub;
	}//前面的数不够减后面的，数值等于后面的减前面的，加个负号
	else if (thisTra == NULL && otherTra == NULL && borrow == 0)
	{
		return sub;
	}
	else if (thisTra == NULL && otherTra != NULL)
	{
		sub=other - (*this);
		sub.number.header->data = 1;
		return sub;
	}//小数位减大数位
	else if (thisTra != NULL)
	{
		for (int i = small; i < big; ++i)
		{
			tempsub = thisTra->data - borrow;
			if (tempsub < 0)
			{
				tempsub += 10;
				borrow = 1;
			}
			else
			{
				borrow = 0;
			}
			sub.number.insert(tempsub);
			thisTra = thisTra->next;
		}//处理借位
		sub.regular();
		return sub;
	}

}
bigint bigint::operator*(bigint& other)//连加，判断两个数的符号得到结果符号
{
	bigint sum(0);
	bigint temp;
	bigint one(1);
	node* tra = other.number.header->next;
	for (int i = 0; i < other.number.getSize();++i)
	{
		temp.number.insert(tra->data);
		tra = tra->next;
	}
	while (temp.number.header->next!=NULL)
	{
		temp = temp - one;
		temp.regular();
		sum = sum + (*this);
	}
	if (this->number.header->data == 1 && other.number.header->data == 0)
	{
		sum.number.header->data = 1;
	}
	if (this->number.header->data == 0 && other.number.header->data == 1)
	{
		sum.number.header->data = 1;
	}
	return sum;
}
bigint bigint::mi(bigint& other)//连乘
{
	bigint sum(1);
	bigint one(1);
	bigint temp;
	node* tra = other.number.header->next;
	for (int i = 0; i < other.number.getSize(); ++i)
	{
		temp.number.insert(tra->data);
		tra = tra->next;
	}
	while (temp.number.header->next!=NULL)
	{
		temp = temp - one;
		temp.regular();
		sum = sum * (*this);
	}
	return sum;
}