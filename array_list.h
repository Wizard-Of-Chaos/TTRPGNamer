#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "list.h"
#include <string>

const int MAXSIZE = 500;

class ArrayList : public List
{
	protected:
	string* m_data;
	int m_size;

	public:
	ArrayList();
	~ArrayList();
	int size() const;
	void print() const;
	bool find(const string num) const;
	void insert(const string num);
	bool remove(const string num);
	string &operator[](int i);
};

#endif //ARRAYLIST_H
