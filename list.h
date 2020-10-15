#ifndef LIST_H
#define LIST_H
#include <string>

using namespace std;

class List
{
	public:
	//Accessors
	virtual int size() const = 0;
	virtual void print() const = 0;
	virtual bool find(const string num) const = 0;
	//Mutators
	virtual void insert(const string num) = 0;
	virtual bool remove(const string num) = 0;
};

#endif //LIST_H
