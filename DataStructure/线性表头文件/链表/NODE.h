#ifndef NODE
#define NODE
#include<iostream>
using namespace std;
#include<string>
	class Node
	{
	public:
		Node(char *name,int grade);
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
Node::Node(char *name,int grade)
{stdname=name;
score=grade;}
Node&Node::getnode()
{
	return *this;
}
void Node::setname(char *b)
{stdname=b;};
string Node::getname(){return stdname;}
void Node::setgrade(int c)
{score=c;};
int Node::getgrade()
{return score;};
void Node::Outputnode(ostream&out)const
{out<<stdname<<endl;out<<"³É¼¨£º"<<score;}
ostream&operator<<(ostream&out,const Node&x)
{
	x.Outputnode(out);
	return out;
}
#endif