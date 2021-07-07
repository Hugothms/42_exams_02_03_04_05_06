#include "ASpell.hpp"

void ASpell::launch(ATarget &target)
{
	target.getHitBySpell(*this);
}
