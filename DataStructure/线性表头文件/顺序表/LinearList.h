#include<iostream>
#include<fstream>
using namespace std;
template<class T>
class linearlist
{
public:
	linearlist(int llmaxsize);
	~linearlist();
	linearlist<T>&insert(int k, const T&x);
	bool isempty()const;
	int getlength()const;
	bool getdata(int k, T&x);
	bool modifydata(int k, const T&x);
	int find(const T&x);
	linearlist<T>& deletebyindex(int k, T&x);
	linearlist<T>& deletebykey(const T&x, T&y);
	void output(ostream&out)const;
private:
	int length;
	int maxsize;
	T *element;
};
template<class T>
linearlist<T>::linearlist(int llmaxsize)
{
	maxsize = llmaxsize;
	element = new T[llmaxsize];
	length = 0;
}
template<class T>
linearlist<T>::~linearlist()
{
	delete[]element;
}
template<class T>
linearlist<T>&linearlist<T>::insert(int k, const T&x)
{
	if (k<1 || k>length + 1)
		cout << "元素下标越界，添加元素失败";
	else
	if (length == maxsize)
		cout << "此表已满，无法添加新元素";
	else
	{
		for (int i = length; i>k - 1; i--)
			element[i] = element[i - 1];
		element[k - 1] = x;
		length++;
	}
	return *this;
}
template<class T>
bool linearlist<T>::isempty()const
{
	return length == 0;
}
template<class T>
int linearlist<T>::getlength()const
{
	return length;
}
template<class T>
bool linearlist<T>::getdata(int k, T&x)
{
	if (k<1 || k>length)
		return false;
	else
	{
		x = element[k - 1];
		return true;
	}
}
template<class T>
bool linearlist<T>::modifydata(int k, const T&x)
{
	if (k<1 || k>length)
		return false;
	else
	{
		element[k - 1] = x;
		return true;
	}
}
template<class T>
int linearlist<T>::find(const T&x)
{
	for (int i = 0; i<length; i++)
	if (element[i] == x)
		return i + 1;
	return 0;
}
template<class T>
linearlist<T>&linearlist<T>::deletebyindex(int k, T&x)
{
	if (getdata(k, x))
	{
		for (int i = k - 1;
			i<length - 1; i++)
			element[i] = element[i + 1];
		length--;
	}
	else
		cout << "元素下标越界，删除失败";
	return *this;
}
template<class T>
linearlist<T>&linearlist<T>::deletebykey(const T&x, T&y)
{
	int index = find(x);
	if (index != 0)
		return deletebyindex(index, y);
	else
	{
		cout << "没有此元素，删除失败";
		return*this;
	}
}
template<class T>
void linearlist<T>::output(ostream&out)const
{
	for (int i = 0; i<length; i++)
		out << element[i] << endl;
}
template<class T>
ostream& operator<<(ostream&out, const linearlist<T>&x)
{
	x.output(out);
	return out;
}
#ifndef NODE
#define NODE
#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
	Node(char *name, int grade);
	Node(){};
	Node&getnode();
	void setname(char *name);
	void setgrade(int grade);
	string getname();
	int getgrade();
	void Outputnode(ostream&out)const;
private:
	string stdname;
	int score;
};
Node::Node(char *name, int grade)
{
	stdname = name;
	score = grade;
}
Node&Node::getnode()
{
	return *this;
}
void Node::setname(char *b)
{
	stdname = b;
};
string Node::getname(){ return stdname; }
void Node::setgrade(int c)
{
	score = c;
};
int Node::getgrade()
{
	return score;
};
void Node::Outputnode(ostream&out)const
{
	out << stdname << endl; out << "成绩：" << score;
}
ostream&operator<<(ostream&out, const Node&x)
{
	x.Outputnode(out);
	return out;
}
#endif