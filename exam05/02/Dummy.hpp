/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:25:19 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/06 18:48:47 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <iostream>

# include "ATarget.hpp"

class Dummy: public ATarget
{
	public:
		Dummy(): ATarget("Target Practice Dummy")
		{}

		~Dummy()
		{}

		ATarget *clone() const
		{
			return new Dummy();
		}
};

#endif