/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:59:18 by hthomas           #+#    #+#             */
/*   Updated: 2022/02/16 16:12:56 by hthomas          ###   ########.fr       */
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
		{
		std::map<string, ATarget*>::iterator it;
		for (it = targets.begin(); it != targets.end(); it++)
			delete it->second;
		}

		void learnTargetType(ATarget* target)
		{
			targets.insert(pair<string, ATarget*>(target->getType(), target->clone()));
		}

		void forgetTargetType(const string &target_type)
		{
			std::map<std::string, ATarget *>::iterator it = targets.find(target_type);
			if (it != targets.end())
				delete it->second;
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
