//#ifndef INTEGER_SET_H
//#define INTEGER_SET_H
#include <string>
#include <iostream>
using std::string;	

class IntegerSet
{
public:
	IntegerSet(){emptySet();}
	IntegerSet(int);
	IntegerSet(int [], int);
	IntegerSet union2(const IntegerSet& );
	IntegerSet intersect2(const IntegerSet& );
	void emptySet();
	void enterSet();
	void insertElement(int);
	void removeElement(int);
	void print()const;
	bool isEqual(const IntegerSet &);
	bool isSubset(const IntegerSet &);

protected:
	int intSet[128];
	int validEntry(int x) const
	{
		return (x>=0 && x<=128);
	}
};

