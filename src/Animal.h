///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// Where the wild things roam
///
/// @file Animal.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

#include "config.h"
#include "Gender.h"
#include "Weight.h"


/// A class that encompasses all Animals on the farm.
///
/// This class should be the parent class of all of the Animals on the farm.
/// It contains 1 abstract method `speak()` that each Animal must implement
/// before it can be instantiated.
///
/// Animals understand things I don't know -- and they know languages which are not made of words.”
///
/// @see https://en.wikipedia.org/wiki/Animal
/// @see https://en.wikipedia.org/wiki/Taxonomy_(biology)
class Animal {
public:   //////////////////////// Constants ///////////////////////////////////
   static const std::string KINGDOM_NAME;  ///< The scientific name of the Animal Kingdom.

private:  ///////////////////// Member Variables //////////////////////////////
   std::string species;                     ///< The Animal's biological species
   std::string classification;              ///< The Animal's biological classification
   Gender gender = Gender::UNKNOWN_GENDER;  ///< The Animal's gender
   Weight weight;                           ///< The weight of the Animal

public:   /////////////////////// Constructors ////////////////////////////////
   /// Create an Animal with the *minimum* required fields
   Animal( const Weight::t_weight newMaxWeight
          ,const std::string&     newClassification
          ,const std::string&     newSpecies
          );

   /// Create an Animal, populating *all* of the member variables
   Animal( const Gender           newGender
          ,const Weight::t_weight newWeight
          ,const Weight::t_weight newMaxWeight
          ,const std::string&     newClassification
          ,const std::string&     newSpecies
          );

public:   ///////////////////// Getters & Setters /////////////////////////////
   std::string getKingdom() const noexcept;         ///< Get the kingdom, which is `Animalia`
   std::string getClassification() const noexcept;  ///< Get the classification
   std::string getSpecies() const noexcept;         ///< Get the species

   Gender getGender() const noexcept;  ///< Get the Animal's Gender

   Weight::t_weight getWeight() const noexcept;         ///< Get the Animal's Weight
   void setWeight( const Weight::t_weight newWeight );  ///< Set the Animal's Weight

protected:  ////////////////////// Protected Methods ///////////////////////////
   void setGender( const Gender newGender);   ///< Set the Animal's Gender

public:  /////////////////////// Static Public Methods /////////////////////////
   static bool validateClassification( const std::string& checkClassification ) noexcept;  ///< Verify the biological classification is valid
   static bool validateSpecies( const std::string& checkSpecies ) noexcept;                ///< Verify the biological species is valid

public:   ////////////////////////// Methods //////////////////////////////////
   virtual std::string speak() const noexcept = 0;  ///< Ask the Animal to say something.  This method is virtual and abstract.
   void dump() const noexcept;       ///< Output the contents of this object
   bool validate() const noexcept;   ///< Check to see if the Animal object is valid
};