#pragma once
#include "Repository.h"
#include <algorithm>
#include "Validator.h"

class Service 
{
private:
	Repository& repo;

public:

	Service(Repository& repo) : repo{ repo } {}

	~Service() = default;

	const std::vector<Task>& get_all_serv();

	int nr_prgrm(const Task& tsk);

	void adauga_serv(int id, const std::string& desc, const std::vector<std::string>& prg, const std::string& stare);

	std::vector<Task> filtreaza_programator(const std::string& prg);

	std::vector<Task> filtreaza_stare(const std::string& stare);

	void modifica_stare(int id, const std::string& stare);
};