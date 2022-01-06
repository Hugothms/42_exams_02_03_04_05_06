/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:59:18 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/06 18:41:21 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <map>

# include "ATarget.hpp"

using namespace std;

class TargetGenerator
{
	private:
		map<string, ATarget*> targets;

		TargetGenerator(TargetGenerator const &other);
		TargetGenerator &operator=(TargetGenerator const &other);

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
			map<string, ATarget*>::iterator it = targets.find(target_type);
			if (it != targets.end())
				return targets[target_type];
			return NULL;
		}
};

#endif
