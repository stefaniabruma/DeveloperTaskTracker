#include "Validator.h"

void Validator::valideaza(const Task& tsk) const
{
	if (tsk.get_descriere().size() == 0)
		throw(std::exception("Invalid!\n"));

	if (tsk.get_stare() != "open" && tsk.get_stare() != "inprogress" && tsk.get_stare() != "closed")
		throw(std::exception("Invalid!\n"));
}