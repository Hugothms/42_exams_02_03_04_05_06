/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:23:18 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/29 14:35:54 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ATarget.hpp"

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << type <<" has been " << spell.getEffects() << "!" << std::endl;
}
