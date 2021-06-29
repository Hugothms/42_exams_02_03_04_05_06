/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:10:33 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/29 14:49:14 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>
# include <map>

# include "ASpell.hpp"

class Warlock
{
private:
	std::string name;
	std::string title;
	std::map<std::string, ASpell*> known_spells;
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
		known_spells.insert(std::pair<std::string, ASpell*>(spell->getName(),spell));
	}

	void forgetSpell(std::string spell_name)
	{
		known_spells.erase(spell_name);
	}

	void launchSpell(std::string spell_name, ATarget& target)
	{
		ASpell* spell = known_spells.operator[](spell_name);
		if (spell)
			spell->launch(target);
	}
};

#endif
