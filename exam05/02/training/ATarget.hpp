#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>

#include "ASpell.hpp"

using namespace std;

class ASpell;

class ATarget
{
private:
	string type;
public:
	ATarget(string type): type(type)
	{}

	~ATarget()
	{}

	const string& getType() const
	{
		return type;
	}

	virtual ATarget *clone() = 0;

	void getHitBySpell(const ASpell& spell);
};

#endif
