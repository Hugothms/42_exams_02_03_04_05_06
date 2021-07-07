#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>

#include "ASpell.hpp"

class Fireball: public ASpell
{
private:

public:
	Fireball(): ASpell("Fireball", "burnt to a crisp")
	{}

	~Fireball();

	ASpell *clone()
	{
		return new Fireball();
	}
};

#endif
