/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:58:48 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/04 09:33:34 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>

# include "ATarget.hpp"

class ATarget;

using namespace std;

class ASpell
{
	private:
		string name;
		string effects;

	public:
		ASpell()
		{}

		ASpell(const ASpell &other)
		{
			*this = other;
		}

		ASpell &operator=(const ASpell &other)
		{
			this->name = other.name;
			this->effects = other.effects;
			return *this;
		}

		ASpell(string name, string effects): name(name), effects(effects)
		{}

		virtual ~ASpell()
		{}

		// ASpell &operator=(const ASpell &other)
		// {
		// 	this->name = other.name;
		// }

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
