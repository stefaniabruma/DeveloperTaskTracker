#include "Repository.h"

void Repository::readFromFile()
{
	std::ifstream fin(filename);

	if (!fin.is_open())
		throw(std::exception("open()"));

	while (!fin.eof())
	{
		int id;
		fin >> id;

		if (fin.eof())
			break;

		std::string desc;
		fin >> desc;

		std::vector<std::string> programatori;
		std::string programator;

		fin >> programator;
		while (programator != "open" && programator != "inprogress" && programator != "closed")
		{
			programatori.push_back(programator);
			fin >> programator;
		}

		std::string stare = programator;

		Task tsk{ id, desc, programatori, stare };
		taskuri.push_back(tsk);

		sort(taskuri.begin(), taskuri.end(), [](const Task& tsk1, const Task& tsk2) {return tsk1.get_stare() > tsk2.get_stare(); });
	}

	fin.close();
}

void Repository::writeToFIle()
{
	std::ofstream fout(filename);

	if (!fout.is_open())
		throw(std::exception("open()"));

	for (const Task& tsk : taskuri)
	{
		fout << tsk.get_id() << '\n';
		fout << tsk.get_descriere() << '\n';

		for (const std::string& prg : tsk.get_programator())
			fout << prg << '\n';

		fout << tsk.get_stare() << '\n' << '\n';
	}

	fout.close();
}

const std::vector<Task>& Repository::get_all_repo()
{
	return taskuri;
}

void Repository::adauga_repo(const Task& tsk)
{
	taskuri.push_back(tsk);

	sort(taskuri.begin(), taskuri.end(), [](const Task& tsk1, const Task& tsk2) {return tsk1.get_stare() > tsk2.get_stare(); });

	writeToFIle();
}

void Repository::modifica_stare_repo(int id, const std::string& stare)
{
	for(Task& tsk : taskuri)
		if(tsk.get_id() == id)
		{
			tsk.set_stare(stare);
			break;
		}

	sort(taskuri.begin(), taskuri.end(), [](const Task& tsk1, const Task& tsk2) {return tsk1.get_stare() > tsk2.get_stare(); });

	writeToFIle();

}
