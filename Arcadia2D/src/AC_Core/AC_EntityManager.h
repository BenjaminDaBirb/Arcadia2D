#pragma once
#include "AC_GameObject.h"

enum EntityType {
	Environmental,
	Prop,
	Gameplay
};

enum NPCType {
	Hostile,
	Friendly
};

class AC_EntityManager
{
public:
	static AC_EntityManager* GetInstance() { return inst = (inst != nullptr) ? inst : new AC_EntityManager(); }
	void CreateEntity(std::string id, EntityType entityType, NPCType npcType);
	void DeleteEntity(std::string id);



private:
	AC_EntityManager() {}
	static AC_EntityManager* inst;
};

