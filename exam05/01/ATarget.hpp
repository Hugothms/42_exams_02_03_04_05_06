/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:14:21 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/28 17:32:53 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>

# include "ASpell.hpp"

class ASpell;

class ATarget
{
private:
	std::string type;
	ATarget();
	ATarget& operator=(const ATarget& copy);
public:
	ATarget(std::string type):
	type(type)
	{}

	~ATarget();

	ATarget(const ATarget& copy)
	{
		type = copy.getType();
	}

	std::string const &getType() const
	{
		return type;
	}

	virtual ATarget *clone() const = 0;

	void getHitBySpell(const ASpell &spell) const
	{
		std::cout << type <<" has been " << spell.getEffects() << "!" << std::endl;
	}
};

#endif
