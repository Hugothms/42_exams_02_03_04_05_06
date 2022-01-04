/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:19:13 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/04 09:34:17 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>

# include "ASpell.hpp"

class Fwoosh: public ASpell
{
	public:
		Fwoosh(): ASpell("Fwoosh", "fwooshed")
		{}

		Fwoosh *clone() const
		{
			return new Fwoosh();
		}
};

#endif
