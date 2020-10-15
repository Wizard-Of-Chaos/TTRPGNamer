#include "array_list.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

ArrayList::ArrayList()
{
	m_data = new string[MAXSIZE];
	m_size = 0;
}

ArrayList::~ArrayList()
{
	delete[] m_data;
}

int ArrayList::size() const
{
	return m_size;
}

void ArrayList::print() const
{
	ostringstream ACK;
	ACK.str("");
	for (int i = 0; i < m_size; ++i) {
		ACK << m_data[i] << " ";
	}
	cout <<  ACK.str() << endl;
}

bool ArrayList::find(const string num) const
{
	for (int i = 0; i < m_size; ++i) {
		if (m_data[i] == num) {
			return true;
		}
	}
	return false;
}

void ArrayList::insert(const string num)
{
	if (m_size < MAXSIZE) {
		m_data[m_size] = num;
		++m_size;
	}
}

bool ArrayList::remove(const string num)
{
	for (int i = 0; i < m_size; ++i) {
		if (m_data[i] == num) {
			m_data[i] = m_data[m_size];
			--m_size;
			return true;
		}
	}
	return false;
}

string & ArrayList::operator[](int i)
{
	return m_data[i];
}
