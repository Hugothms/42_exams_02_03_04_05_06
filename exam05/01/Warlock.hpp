/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:10:33 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/28 17:33:04 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>
# include <list>

# include "ASpell.hpp"

class Warlock
{
private:
	std::string name;
	std::string title;
	std::list<ASpell> know_spells;
	Warlock();
	Warlock(const Warlock& copy);
	Warlock& operator=(const Warlock& copy);
public:

	Warlock(std::string const name, std::string const title): name(name), title(title)
	{
		std::cout << name << ": This looks like another boring day." << std::endl;
	}

	~Warlock()
	{
		std::cout << name << ": My job here is done!" << std::endl;
	}

	std::string const &getName() const
	{
		return name;
	}

	std::string const &getTitle() const
	{
		return title;
	}

	void setTitle(std::string const &title)
	{
		this->title = title;
	}

	void introduce() const
	{
		std::cout << name << ": I am " << name << ", " << title << " !" << std::endl;
	}

	void learnSpell(ASpell* spell)
	{
		know_spells.push_back(*spell);
	}

	void forgetSpell(std::string spell_name)
	{
		std::list<ASpell>::iterator it;
		for (it = know_spells.begin(); it != know_spells.end(); it++)
		{
			if (it->getName() == spell_name)
				know_spells.remove(*it);
		}
	}

	void launchSpell(std::string spell_name, ATarget& target)
	{
		std::list<ASpell>::iterator it;
		for (it = know_spells.begin(); it != know_spells.end(); it++)
		{
			if (it->getName() == spell_name)
				it->launch(target);
		}
	}
};

#endif
