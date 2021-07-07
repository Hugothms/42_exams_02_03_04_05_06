#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <list>

# include "ATarget.hpp"
# include "SpellBook.hpp"

class Warlock
{
private:
	std::string name;
	std::string title;
	SpellBook book;
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
		book.learnSpell(spell);
	}

	void forgetSpell(string spell_name)
	{
		book.forgetSpell(spell_name);
	}

	void launchSpell(string spell_name, ATarget& target)
	{
		book.launchSpell(spell_name, target);
	}
};

#endif
