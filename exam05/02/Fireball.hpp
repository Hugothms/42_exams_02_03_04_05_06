/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:19:13 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/29 14:59:45 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>

# include "ASpell.hpp"

class Fireball: public ASpell
{
public:
	Fireball(): ASpell("Fireball", "burnt to a crisp")
	{}

	Fireball *clone() const
	{
		return new Fireball();
	}
};

#endif
