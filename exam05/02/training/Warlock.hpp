#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <list>

# include "ATarget.hpp"

class Warlock
{
private:
	std::string name;
	std::string title;
	list<ASpell* > known_spells;
	Warlock();
	Warlock(const Warlock& copy);
	Warlock& operator=(const Warlock& copy);
public:
	Warlock(const std::string name, const std::string title): name(name), title(title)
	{
		std::cout << name << ": This looks like another boring day." << std::endl;
	}

	~Warlock()
	{
		std::cout << name << ": My job here is done!" << std::endl;
	}

	const std::string& getName(void) const
	{
		return name;
	}

	const std::string& getTitle(void) const
	{
		return title;
	}

	void listTitle(const std::string& title)
	{
		this->title = title;
	}

	void introduce() const
	{
		std::cout << name << ": I am " << name << ", " << title << " !" << std::endl;
	}

	void learnSpell(ASpell *spell)
	{
		list<ASpell*>::iterator it = known_spells.begin();
		while(it != known_spells.end())
		{
			if ((*it) == spell)
				return ;
			it++;
		}
		known_spells.push_back(spell);
	}

	void forgetSpell(string spell_name)
	{
		list<ASpell*>::iterator it = known_spells.begin();
		while(it != known_spells.end())
		{
			if ((*it)->getName() == spell_name)
				return known_spells.remove(*it);
			it++;
		}
	}

	void launchSpell(string spell_name, ATarget& target)
	{
		list<ASpell*>::iterator it = known_spells.begin();
		while(it != known_spells.end())
		{
			if ((*it)->getName() == spell_name)
				return (*it)->launch(target);
			it++;
		}
	}
};

#endif
