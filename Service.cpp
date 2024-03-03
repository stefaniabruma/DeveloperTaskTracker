#include "Service.h"

const std::vector<Task>& Service::get_all_serv()
{
	return repo.get_all_repo();
}

int Service::nr_prgrm(const Task& tsk)
{
	return tsk.get_programator().size();
}

void Service::adauga_serv(int id, const std::string& desc, const std::vector<std::string>& prg, const std::string& stare)
{
	if (find_if(repo.get_all_repo().begin(), repo.get_all_repo().end(), [id](const Task& tsk) {return tsk.get_id() == id; }) != repo.get_all_repo().end())
		throw(std::exception("Existent~\n"));

	Task tsk{ id, desc, prg, stare };
	Validator vld;
	vld.valideaza(tsk);

	repo.adauga_repo(tsk);
}

std::vector<Task> Service::filtreaza_programator(const std::string& prg)
{
	std::vector<Task> tsks;

	for (const Task& tsk : repo.get_all_repo())
	{
		for(const std::string& p : tsk.get_programator())
			if (p == prg)
			{
				tsks.push_back(tsk);
				break;
			}
	}

	return tsks;
}

std::vector<Task> Service::filtreaza_stare(const std::string& stare)
{
	std::vector<Task> tsks;

	for (const Task& tsk : repo.get_all_repo())
		if (tsk.get_stare() == stare)
			tsks.push_back(tsk);

	return tsks;
}

void Service::modifica_stare(int id, const std::string& stare)
{
	repo.modifica_stare_repo(id, stare);
}
