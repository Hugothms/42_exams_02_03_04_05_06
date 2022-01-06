/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:40:47 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/06 18:43:43 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"
#include "Fwoosh.hpp"
#include "BrickWall.hpp"
#include "TargetGenerator.hpp"

int main()
{
	Warlock richard("Richard", "foo");
	richard.setTitle("Hello, I'm Richard the Warlock!");


	Polymorph* polymorph = new Polymorph();
	richard.learnSpell(polymorph);

	Fwoosh* fwoosh = new Fwoosh();
	Fwoosh* hugo(fwoosh);
	richard.learnSpell(hugo);

	Fireball* fireball = new Fireball();
	richard.learnSpell(fireball);



	BrickWall model1;
	TargetGenerator tarGen;
	tarGen.learnTargetType(&model1);
	ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");
	SpellBook spellGen;
	richard.introduce();
	ASpell* qwerty = spellGen.createSpell("qwerty");
	richard.introduce();
	(void)qwerty;
	// richard.learnSpell(qwerty);
	richard.introduce();
	richard.launchSpell("qwerty", *wall);
	richard.introduce();

	richard.introduce();
	richard.launchSpell("Polymorph", *wall);
	richard.launchSpell("Fireball", *wall);
	richard.launchSpell("Fwoosh", *wall);
}
