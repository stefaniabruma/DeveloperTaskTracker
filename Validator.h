#pragma once
#include "Domain.h"

class Validator
{
public:

	Validator() = default;

	void valideaza(const Task& tsk) const;

	~Validator() = default;
};
