/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:10:33 by hthomas           #+#    #+#             */
/*   Updated: 2021/07/08 22:20:08 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>
# include <map>

# include "ASpell.hpp"

using namespace std;

class Warlock
{
private:
	string name;
	string title;
	map<string, ASpell*> known_spells;
public:
	Warlock(string const name, string const title): name(name), title(title)
	{
		cout << name << ": This looks like another boring day." << endl;
	}

	~Warlock()
	{
		cout << name << ": My job here is done!" << endl;
	}

	string const &getName() const
	{
		return name;
	}

	string const &getTitle() const
	{
		return title;
	}

	void setTitle(string const &title)
	{
		this->title = title;
	}

	void introduce() const
	{
		cout << name << ": I am " << name << ", " << title << " !" << endl;
	}

	void learnSpell(ASpell* spell)
	{
		known_spells.insert(pair<string, ASpell*>(spell->getName(), spell));
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
