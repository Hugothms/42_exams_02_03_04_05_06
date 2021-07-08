#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <map>

# include "ASpell.hpp"
# include "ATarget.hpp"

using namespace std;

class TargetGenerator
{
private:
	map<string, ATarget*> targets;
public:
	TargetGenerator()
	{}

	~TargetGenerator()
	{}

	void learnTargetType(ATarget* target)
	{
		targets.insert(pair<string, ATarget*>(target->getType(), target));
	}

	void forgetTargetType(string const &target_name)
	{
		targets.erase(target_name);
	}

	ATarget* createTarget(string const &target_name)
	{
		if (targets[target_name])
			return targets[target_name];
		return NULL;
	}

};

#endif
