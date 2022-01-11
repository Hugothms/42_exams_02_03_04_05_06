/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:58:48 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/11 11:15:41 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>

# include "ATarget.hpp"

using namespace std;

class ATarget;

class ASpell
{
private:
	string name;
	string effects;
public:
	ASpell(string name, string effects): name(name), effects(effects)
	{}

	virtual ~ASpell()
	{}

	string const &getName() const
	{
		return name;
	}

	string const &getEffects() const
	{
		return effects;
	}

	virtual ASpell *clone() const = 0;

	void launch(ATarget const& target);
};

#endif
