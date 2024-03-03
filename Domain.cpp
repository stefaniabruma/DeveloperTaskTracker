#include "Domain.h"

bool Task::operator==(const Task& tsk) const
{
	return id == tsk.id;
}

int Task::get_id() const
{
	return id;
}

const std::string& Task::get_descriere() const
{
	return descriere;
}

const std::vector<std::string>& Task::get_programator() const
{
	return programatori;
}

const std::string& Task::get_stare() const
{
	return stare;
}

void Task::set_stare(const std::string& st)
{
	stare = st;
}
