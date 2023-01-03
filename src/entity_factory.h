
#pragma once
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h" 
#include "picojson.h"


 /**
  * @copyright holm0715 Jaron Holm
  *
  */

  /**
   * @brief entity_factory.h Entity Factory is a base class that has the create entitiy
   * method. Other entity factors are derived from it and have their own version of create
   * entity based on the info they need.
   */
class EntityFactory {
	/**
	 * @brief pure virtual method that is implmented by the derived classes.
	 * @param the enitity data recieved through a picojson object.
	 * @return Pointer to entity created by factory
	 */
	virtual Entity* CreateEntity(picojson::object& entityData) = 0;
};