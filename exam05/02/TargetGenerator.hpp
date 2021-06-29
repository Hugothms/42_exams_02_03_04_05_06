/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:59:18 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/29 17:13:55 by hthomas          ###   ########.fr       */
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
	map<string, ATarget*> targets;
	TargetGenerator(const TargetGenerator& copy);
	TargetGenerator& operator=(const TargetGenerator& copy);
public:
	TargetGenerator()
	{}

	~TargetGenerator()
	{}

	void learnTargetType(ATarget* target)
	{
		targets.insert(pair<string, ATarget*>(target->getType(), target));
	}

	void forgetTargetType(const string &target_type)
	{
		targets.erase(target_type);
	}

	ATarget* createTarget(const string &target_type)
	{
		return targets[target_type];
	}
};

#endif
