#include "BaseEntity.h"

BaseEntity::BaseEntity() 
	:id(0){ }

int BaseEntity::getId() const { return id; }

void BaseEntity::setId(int id) { this->id = id; }