/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:14:21 by hthomas           #+#    #+#             */
/*   Updated: 2021/11/16 16:51:01 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>

# include "ASpell.hpp"

using namespace std;

class ASpell;

class ATarget
{
private:
	string type;

public:
	ATarget()
	{}

	ATarget(const ATarget &other)
	{
		*this = other;
	}

	ATarget &operator=(const ATarget &other)
	{
		this->type = other.type;
		return *this;
	}

	ATarget(string type): type(type)
	{}

	~ATarget()
	{}

	string getType() const
	{
		return type;
	}

	virtual ATarget *clone() const = 0;

	void getHitBySpell(const ASpell &spell) const;
};

#endif
