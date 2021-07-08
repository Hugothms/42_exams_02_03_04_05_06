#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <map>

# include "ASpell.hpp"

using namespace std;

class SpellBook
{
private:
	map<string, ASpell*> known_spells;
public:
	SpellBook()
	{}

	~SpellBook()
	{}

	void learnSpell(ASpell* spell)
	{
		known_spells.insert(pair<string, ASpell*>(spell->getName(), spell->clone()));
	}

	void forgetSpell(string spell_name)
	{
		known_spells.erase(spell_name);
	}

	void launchSpell(string spell_name, ATarget& target)
	{
		ASpell* spell = known_spells[spell_name];
		if (spell)
			spell->launch(target);
	}
};

#endif
