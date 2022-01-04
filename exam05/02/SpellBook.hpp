/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:31:55 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/04 09:33:39 by hthomas          ###   ########.fr       */
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
			for (it = spells.begin(); it != spells.end() ; it++)
				delete(it->second);
		}

		void learnSpell(ASpell* spell)
		{
			spells.insert(pair<string, ASpell*>(spell->getName(), spell->clone()));
		}

		void forgetSpell(const string& spell_name)
		{
			spells.erase(spell_name);
		}

		ASpell* createSpell(const string& spell_name)
		{
			return (spells[spell_name]);
		}
};

#endif
