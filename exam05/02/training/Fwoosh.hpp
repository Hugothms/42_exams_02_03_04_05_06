#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>

#include "ASpell.hpp"

class Fwoosh: public ASpell
{
private:

public:
	Fwoosh(): ASpell("Fwoosh", "fwooshed")
	{}

	~Fwoosh()
	{}

	ASpell *clone()
	{
		return new Fwoosh();
	}
};

#endif
