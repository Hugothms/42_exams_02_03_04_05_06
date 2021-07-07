#include "ATarget.hpp"

void ATarget::getHitBySpell(const ASpell& spell)
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
