#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>

#include "ATarget.hpp"

using namespace std;

class ATarget;

class ASpell
{
private:
	string name;
	string effects;
public:
	ASpell(string name, string effects):
	name(name), effects(effects)
	{}

	~ASpell()
	{}

	string getName() const
	{
		return name;
	}

	string getEffects() const
	{
		return effects;
	}

	virtual ASpell *clone() = 0;

	void launch(ATarget &target);
};

#endif
