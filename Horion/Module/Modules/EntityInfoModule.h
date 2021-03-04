#pragma once

#include "Module.h"

class EntityInfoModule : public IModule {
public:

	std::map<int, std::string> entIdMap;
	std::map<int, std::string>::iterator entIdMapItor;

	int delay = 0;

	EntityInfoModule();
	~EntityInfoModule();
	
	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onPreRender(C_MinecraftUIRenderContext* renderCtx) override;
	void onLevelRender() override;
};