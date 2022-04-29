///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab15a_animal_farm_4 - EE 205 - Spr 2022
///
/// A generic Binary Search Tree
///
/// @file Tree.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   25_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"
#include "List.h"

/// Holds Node classes in a Binary Search Tree
class Tree : public Container {
protected:  ////////////////////// Protected Members ///////////////////////////
   Node* rootNode = nullptr;  ///< The root for the binary search tree

public:
   void insert( Node* newNode );    ///< Add a Node to the Tree

private:
   bool isIn( Node* aNode ) const override ;  ///< `true` if `aNode` is in the Tree

   void insert( Node* atNode, Node* newNode );  ///< Add a Node starting at atNode

// void dfsInorderReverse( Node* atCat, int depth ) const;  ///< Depth First Search - Inorder reverse search
// void dfsInorder( Node* atCat ) const;                    ///< Depth First Search - Inorder search
// void catTail( Node* atCat, Tree* tailList ) const;
// void dfsPreorder( Node* atCat ) const;
};
