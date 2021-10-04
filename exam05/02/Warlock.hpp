/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:10:33 by hthomas           #+#    #+#             */
/*   Updated: 2021/10/04 13:35:02 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>

# include "ASpell.hpp"
# include "SpellBook.hpp"

using namespace std;

class Warlock
{
private:
	string name;
	string title;
	SpellBook spell_book;
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
		cout << name << ": I am " << name << ", " << title << "!" << endl;
	}

	void learnSpell(ASpell* spell)
	{
		spell_book.learnSpell(spell);
	}

	void forgetSpell(string spell_name)
	{
		spell_book.forgetSpell(spell_name);
	}

	void launchSpell(string spell_name, ATarget& target)
	{
		ASpell* spell = spell_book.createSpell(spell_name);
		if (spell)
			spell->launch(target);
	}
};

#endif
