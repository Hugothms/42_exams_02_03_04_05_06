/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:31:55 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/29 15:44:18 by hthomas          ###   ########.fr       */
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
	SpellBook(){}
	~SpellBook(){}

	void learnSpell(ASpell* spell)
	{
		spells.insert(pair<string, ASpell*>(spell->getName(), spell));
	}

	void forgetSpell(string& const spell_name)
	{
		spells.erase(spell_name);
	}

	ASpell* createSpell(string& const spell_name)
	{
		if ()
	}
		that receives a string corresponding to the name of a spell, creates it, and returns it.

};

#endif
