/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:25:19 by hthomas           #+#    #+#             */
/*   Updated: 2021/07/09 09:08:32 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include <iostream>

# include "ATarget.hpp"

class BrickWall: public ATarget
{
public:
	BrickWall():
	ATarget("Inconspicuous Red-brick Wall")
	{}

	ATarget *clone() const
	{
		return new BrickWall();
	}
};

#endif