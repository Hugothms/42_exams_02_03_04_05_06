/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:19:13 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/29 15:01:42 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <iostream>

# include "ASpell.hpp"

class Polymorph: public ASpell
{
public:
	Polymorph():
	ASpell("Polymorph", "turned into a critter")
	{}

	Polymorph *clone() const
	{
		return new Polymorph();
	}
};

#endif
