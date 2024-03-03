#pragma once
#include "Domain.h"
#include  <fstream>
#include <algorithm>

class Repository
{
private:
	std::vector<Task> taskuri;
	std::string filename;

	void readFromFile();
	void writeToFIle();
public:

	Repository(std::string filename) : filename{ filename } { readFromFile(); }

	~Repository() = default;

	const std::vector<Task>& get_all_repo();

	void adauga_repo(const Task& tsk);

	void modifica_stare_repo(int id, const std::string& stare);
};