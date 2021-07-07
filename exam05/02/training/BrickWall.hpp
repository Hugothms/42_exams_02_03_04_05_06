#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include <iostream>

#include "ATarget.hpp"

class BrickWall: public ATarget
{
private:

public:
	BrickWall(): ATarget("Inconspicuous Red-brick Wall")
	{}

	~BrickWall()
	{}

	ATarget *clone()
	{
		return new BrickWall();
	}
};

#endif
