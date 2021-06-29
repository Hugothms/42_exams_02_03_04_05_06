/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:59:18 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/29 16:02:21 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>

# include "ATarget.hpp"

using namespace std;

class TargetGenerator
{
private:
	/* data */
	TargetGenerator(const TargetGenerator& copy);
	TargetGenerator& operator=(const TargetGenerator& copy);
public:
	TargetGenerator();
	~TargetGenerator();
	// teaches a target to the generator
	void learnTargetType(ATarget*)
	{

	}
	// that makes the generator forget a target type if its known
	void forgetTargetType(string const &)
	{

	}
	// that creates a target of the specified type
	ATarget* createTarget(string const &)
	{
		return ;
	}
};

#endif
