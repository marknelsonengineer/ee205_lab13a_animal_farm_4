///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Every Animal has a Weight.
///
/// @file Weight.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   06_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <ostream>

/// Every Animal has a Weight.
///
/// C++ maintains Weight as a `float` (#t_weight), however, weights in the physical world
/// have certain constraints (i.e. you can't have a negative #weight -- and/or you
/// *may* have a maximum weight.)
///
/// By default, the weight is #UNKNOWN_WEIGHT.  Once it's known, it can never
/// be un-known.
///
/// If the Weight has a maximum weight, then #weight must be `<=` it.  Also,
/// the #weight can never be `<= 0`.  #maxWeight is set in a constructor
/// and can not be changed.
///
/// Weight can can be expressed in different units of measure (#UnitOfWeight).
/// The Weight's unit of measure is set in a constructor and can not be changed.  It
/// defaults to #POUND.  Other units of measure are the #KILO and #SLUG.
///
/// We are not implementing a complete numeric class, which would have
/// overrides for:  `*=  /=  %=  ++  --  +  -  *  /  >=  >  <=  !=` and `<=>`
///
/// @see https://en.wikipedia.org/wiki/Pound_(mass)
/// @see https://en.wikipedia.org/wiki/Kilogram
/// @see https://en.wikipedia.org/wiki/Slug_(unit)
///
class Weight {
public:  //////////////// Enumerations & Type Definitions //////////////////////

   /// A unit of measure for Weight
   enum UnitOfWeight { POUND  ///< @see https://en.wikipedia.org/wiki/Pound_(mass)
                      ,KILO   ///< @see https://en.wikipedia.org/wiki/Kilogram
                      ,SLUG   ///< @see https://en.wikipedia.org/wiki/Slug_(unit)
                     };

   /// The native datatype of the Weight class
   typedef float t_weight;

public:   //////////////////////// Constants ///////////////////////////////////
   static const t_weight UNKNOWN_WEIGHT ;    ///< When #weight is not known, return this.

   static const t_weight KILOS_IN_A_POUND ;  ///< The number of kilos in a #POUND
   static const t_weight SLUGS_IN_A_POUND ;  ///< The number of slugs in a #POUND

   static const std::string POUND_LABEL ;       ///< Unit of measure for the #POUND
   static const std::string KILO_LABEL ;        ///< Unit of measure for the #KILO
   static const std::string SLUG_LABEL ;        ///< Unit of measure for the #SLUG

private:  ////////////////////// Member Variables //////////////////////////////
   bool bIsKnown = false ;  ///< `true` if #weight is known.  Defaults to `false`.
   bool bHasMax = false ;   ///< `true` if Weight has a maximum weight defined.  Defaults to `false`.
   enum UnitOfWeight unitOfWeight = POUND ;  ///< How the #weight is held and displayed.  Defaults to #POUND.
                                             ///< #UnitOfWeight can only be set when Weight is constructed.

   t_weight weight{} ;      ///< The weight.  It must always be `> 0`.  If #maxWeight is set then it must also be `<=` #maxWeight
   t_weight maxWeight{} ;   ///< The maximum weight.  The maximum weight can only be set when Weight is constructed.

public:   //////////////////////// Constructors ////////////////////////////////
   Weight() noexcept;  ///< A default Weight (the #weight is #UNKNOWN_WEIGHT)
   Weight( t_weight newWeight );  ///< A Weight with a #weight
   Weight( UnitOfWeight newUnitOfWeight ) noexcept;  ///< A Weight with a #UnitOfWeight (the #weight is #UNKNOWN_WEIGHT)
   Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight );  ///< A Weight with a #weight and #UnitOfWeight
   Weight( t_weight newWeight, t_weight newMaxWeight );  ///< A Weight with a #weight and a #maxWeight
   Weight( UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );  ///< A Weight with a #UnitOfWeight and a #maxWeight (the #weight is #UNKNOWN_WEIGHT)
   Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );  ///< A fully-specified Weight with a #weight, #UnitOfWeight and #maxWeight

public:   /////////////////////////// Getters  /////////////////////////////////
   bool  isWeightKnown() const noexcept;   ///< `true` if #weight is known
   bool  hasMaxWeight() const noexcept;    ///< `true` if #maxWeight is set
   t_weight getWeight() const noexcept;    ///< Get the #weight in the Weight's units
   t_weight getWeight( UnitOfWeight weightUnits ) const noexcept;  ///< Get the #weight in the specified unit
   t_weight getMaxWeight() const noexcept; ///< Get #maxWeight
   UnitOfWeight getWeightUnit() const noexcept;  ///< Get the #UnitOfWeight for this Weight

public:   /////////////////////////// Setters  /////////////////////////////////
   void setWeight( t_weight newWeight );  ///< Set the #weight
   void setWeight( t_weight newWeight, UnitOfWeight weightUnits );  ///< Set the #weight in the specified unit

private:   ///////////////////// Private Methods ///////////////////////////////
   void setMaxWeight( t_weight newMaxWeight );  ///< Set #maxWeight

public:   /////////////////////// Static Methods ///////////////////////////////
   // Static methods are `const` by default
   static float fromKilogramToPound( t_weight kilogram ) noexcept;  ///< Convert #KILO to #POUND
   static float fromPoundToKilogram( t_weight pound ) noexcept;     ///< Convert #POUND to #KILO
   static float fromSlugToPound( t_weight slug ) noexcept;          ///< Convert #SLUG to #POUND
   static float fromPoundToSlug( t_weight pound ) noexcept;         ///< Convert #POUND to #SLUG

   /// Convert fromWeight in fromUnit to a weight in toUnit
   static float convertWeight( t_weight fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit ) noexcept;

public:   /////////////////////// Public Methods ///////////////////////////////
   bool isWeightValid( t_weight checkWeight ) const noexcept;  ///< Check the Weight
   bool validate() const noexcept;   ///< Check Weight to ensure it's healthy
   void dump() const noexcept;       ///< Print the Weight class

public:   ////////////////////// Public Overrides //////////////////////////////
   bool operator==( const Weight& rhs_Weight ) const;  ///< Weights are equal when their #weight s are equal
   bool operator<( const Weight& rhs_Weight ) const;   ///< Compare two Weights
   Weight& operator+=( t_weight rhs_addToWeight );     ///< Add to an existing Weight
   Weight& operator-=( t_weight rhs_subtractFromWeight );  ///< Subtract from an existing Weight
};


/// Output Weight as a formatted string
///
/// @param lhs_stream The output stream to write to (usually `cout`).  `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
/// @param rhs_Weight The Weight to output.  `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
/// @return `Unknown Pounds` or `3.14 out of 20 Kilos`
std::ostream& operator<<( std::ostream& lhs_stream, const Weight& rhs_Weight ) ;


/// Output the #Weight::UnitOfWeight as a formatted string
///
/// @param lhs_stream       The output stream to write to (usually `cout`).  `lhs` stands for Left Hand Side and means the left side of the `<<` operator.
/// @param rhs_UnitOfWeight The weight-unit to output.  `rhs` stands for Right Hand Side and means the right side of the `<<` operator.
/// @return `Pound`, `Kilo` or `Slug` as defined by #Weight::POUND_LABEL, #Weight::KILO_LABEL or #Weight::SLUG_LABEL
std::ostream& operator<<( std::ostream& lhs_stream, Weight::UnitOfWeight rhs_UnitOfWeight );
