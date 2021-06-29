/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:23:06 by hthomas           #+#    #+#             */
/*   Updated: 2021/06/29 14:36:29 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ASpell.hpp"

void ASpell::launch(ATarget const& target)
{
	target.getHitBySpell(*this);
}
