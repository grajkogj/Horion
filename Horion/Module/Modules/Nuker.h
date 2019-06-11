#pragma once
#include "Module.h"


class Nuker :
	public IModule
{
private:
	int nukerRadius = 4;
public:
	Nuker();
	~Nuker();

	inline int getNukerRadius() { return nukerRadius; };
	// Inherited via IModule
	virtual const char* getModuleName() override;
};

