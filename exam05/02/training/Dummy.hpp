#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <iostream>

#include "ATarget.hpp"

class Dummy: public ATarget
{
private:

public:
	Dummy(): ATarget("Target Practice Dummy")
	{}

	~Dummy()
	{}

	ATarget *clone()
	{
		return new Dummy();
	}
};

#endif
