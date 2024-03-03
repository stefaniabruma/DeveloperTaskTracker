#pragma once
#include <string>
#include <vector>

class Task
{
private:
	int id;
	std::string descriere;
	std::vector<std::string> programatori;
	std::string stare;

public:
	Task(int id, const std::string& descriere, const std::vector<std::string>& programatori, const std::string& stare) : id{ id }, descriere{ descriere }, programatori{ programatori }, stare{ stare } {}

	~Task() = default;

	bool operator==(const Task& tsk) const;

	int get_id() const;

	const std::string& get_descriere() const;

	const std::vector<std::string>& get_programator() const;

	const std::string& get_stare() const;

	void set_stare(const std::string& st);
};