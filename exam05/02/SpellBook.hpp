/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:31:55 by hthomas           #+#    #+#             */
/*   Updated: 2022/02/16 16:12:04 by hthomas          ###   ########.fr       */
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

		SpellBook(SpellBook const &other);
		SpellBook &operator=(SpellBook const &other);

	public:
		SpellBook()
		{}

		~SpellBook()
		{
			std::map<string, ASpell*>::iterator it;
			for (it = spells.begin(); it != spells.end(); it++)
				delete it->second;
		}

		void learnSpell(ASpell* spell)
		{
			if (spell)
				spells.insert(pair<string, ASpell*>(spell->getName(), spell->clone()));
		}

		void forgetSpell(const string& spell_name)
		{
			std::map<std::string, ASpell *>::iterator it = spells.find(spell_name);
			if (it != spells.end())
				delete it->second;
			spells.erase(spell_name);
		}

		ASpell* createSpell(const string& spell_name)
		{
			map<string, ASpell*>::iterator it = spells.find(spell_name);
			if (it != spells.end())
				return spells[spell_name];
			return NULL;
		}
};

#endif
