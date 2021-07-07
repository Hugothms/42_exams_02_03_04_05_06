/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:31:55 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/29 17:13:39 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <map>

# include "ASpell.hpp"

using namespace std;

class SpellBook
{
private:
	map<string, ASpell*> spells;
	SpellBook(const SpellBook& copy);
	SpellBook& operator=(const SpellBook& copy);
public:
	SpellBook()
	{}

	~SpellBook()
	{}

	void learnSpell(ASpell* spell)
	{
		spells.insert(pair<string, ASpell*>(spell->getName(), spell));
	}

	void forgetSpell(const string& spell_name)
	{
		spells.erase(spell_name);
	}

	ASpell* createSpell(const string& spell_name)
	{
		ASpell* spell = spells[spell_name];
		if (spell)
			return spell;
		return NULL;
	}
};

#endif