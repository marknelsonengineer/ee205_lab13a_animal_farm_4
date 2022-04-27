///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab14a_animal_farm_4 - EE 205 - Spr 2022
///
/// A generic collection class.
///
/// @file Container.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"


/// A very generic collection class.
///
class Container {
protected:  ////////////////////// Protected Members ///////////////////////////
   unsigned int count = 0 ;   ///< Maintain a count of the number of Nodes in this Container

public:  /////////////////////////// Public Methods ////////////////////////////
   virtual bool         empty()    const noexcept ;  ///< `true` if the Container is empty
   virtual unsigned int size()     const noexcept ;  ///< Return the number of Nodes in the Container

   virtual void         dump()     const noexcept ;  ///< Output the member variables in this object
   virtual bool         validate() const noexcept ;  ///< Check to see if the container is valid
};