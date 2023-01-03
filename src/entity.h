#ifndef ENTITY_H_
#define ENTITY_H_

//done by tran0607 - Ethan M Tran
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "picojson.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A base entity class for inheritance.
 */
class Entity{
public:
    /**
    * @brief A virtual deconstructor.
    */
    virtual ~Entity() {
        printf("Entity Deconstructor");
    }
    /**
    * @brief A getter for the entity's name.
    * Returns a string.
    */
    std::string GetName();
    /**
    * @brief A getter for the entity's ID.
    * Returns a double.
    */
    double GetID();
    /**
    * @brief A setter for the entity's name.
    * Takes a string.
    */
    void SetName(std::string name);
    /**
    * @brief A virtual update method.
    */
    virtual void Update(double dt) {};
    /**
    * @brief A virtual method for returning a PicoJSON object.
    */
    virtual picojson::object ReturnAsPicoJSON() {};
    /**
    * @brief Gets the data of the entity as a string for data collection.
    */
    virtual std::string GetData() {};
protected:
    /**
    * @brief A string for the entity's name.
    */
    std::string name;
    /**
    * @brief A double for the entity's ID.
    */
    double id;
};


#endif
