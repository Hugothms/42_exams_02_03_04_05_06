#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <iostream>

#include "ASpell.hpp"

class Polymorph: public ASpell
{
private:

public:
	Polymorph(): ASpell("Polymorph", "turned into a critter")
	{}

	~Polymorph();

	ASpell *clone()
	{
		return new Polymorph();
	}
};

#endif
