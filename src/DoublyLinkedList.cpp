///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A generic DoublyLinkedList collection class.
///
/// @file DoublyLinkedList.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   26_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>

#include "config.h"
#include "DoublyLinkedList.h"

using namespace std;

/// @return `true` if the list is empty.  `false` if the list has Nodes in it.
bool DoublyLinkedList::empty() const noexcept {
   return (head == nullptr) ;
}

/// @return The number of Nodes in the list
unsigned int DoublyLinkedList::size() const noexcept {
   return count ;
}


/// @param newNode The node to add to the list
void DoublyLinkedList::push_front(Node *newNode) noexcept {
   if( newNode == nullptr )
      return;  /// If newNode is `nullptr`, then quietly return

   assert( validate() );

   // GENERAL CASE:  The list is not empty
   if( head != nullptr ) {
      newNode->next = head;
      newNode->prev = nullptr;
      head->prev = newNode;
      head = newNode;
   } else {	 // SPECIAL CASE:  The list is empty.
      newNode->next = nullptr;
      newNode->prev = nullptr;
      head = newNode;
      tail = newNode;
   }

   count++;
   assert( validate() );
} // push_front


/// @param newNode The node to add to the list
void DoublyLinkedList::push_back(Node *newNode) noexcept {
   if( newNode == nullptr )
      return;  /// If newNode is `nullptr`, then quietly return

   assert( validate() );

   // GENERAL CASE:  The list is not empty
   if( tail != nullptr ) {
      newNode->next = nullptr;
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
   } else {	 // SPECIAL CASE:  The list is empty.
      newNode->next = nullptr;
      newNode->prev = nullptr;
      head = newNode;
      tail = newNode;
   }

   count++;
   assert( validate() );
} // push_back


/// @return The first Node in the list or `nullptr` if the list is empty
Node *DoublyLinkedList::pop_front() noexcept {
   if( head == nullptr )  // SPECIAL CASE:  The list is empty
      return nullptr;

   assert( validate() );

   Node* returnValue = head;

   // GENERAL CASE:  Not the last node
   if( head != tail ) {
      head->next->prev = nullptr;
      head = head->next;
   } else {  // SPECIAL CASE:  This is the last node
      head = nullptr;
      tail = nullptr;
   }

   returnValue->next = nullptr;    // Unlink the next pointer
   returnValue->prev = nullptr;    // Unlink the prev pointer

   count--;
   assert( validate() );

   return returnValue;
} // pop_front


/// @return The last Node in the list or `nullptr` if the list is empty
Node *DoublyLinkedList::pop_back() noexcept {
   if( tail == nullptr )  // SPECIAL CASE:  The list is empty
      return nullptr;

   assert( validate() );

   Node* returnValue = tail;

   // GENERAL CASE:  Not the last node
   if( head != tail ) {
      tail->prev->next = nullptr;
      tail = tail->prev;
   } else {  // SPECIAL CASE:  This is the last node
      head = nullptr;
      tail = nullptr;
   }

   returnValue->next = nullptr;
   returnValue->prev = nullptr;

   count--;
   assert( validate() );

   return returnValue;
} // pop_back


/// @param currentNode Insert `newNode` after this node.  If it's `nullptr` and
///                    the list is empty, call `push_front( newNode )`
/// @param newNode The node to add to the list.  This can not be `nullptr`
void DoublyLinkedList::insert_after(Node *currentNode, Node *newNode) {
   // SPECIAL CASE:  The list is empty
   if( currentNode == nullptr && head == nullptr ) {
      push_front( newNode );   // We already know how to do this...
      return;
   }

   /// @throws invalid_argument If `currentNode` is not null and the list is empty
   if( currentNode != nullptr && head == nullptr) {
      throw( invalid_argument( PROGRAM_NAME ": Can't have a currentNode if the list is empty!" ));
   }

   /// @throws invalid_argument If `currentNode` is `nullptr` and the list is not empty
   if( currentNode == nullptr && head != nullptr ) {
      throw( invalid_argument( PROGRAM_NAME ": Need to supply a currentNode for a non-empty list" ));
   }

   // At this point, currentNode != null && head != null
   assert( currentNode != nullptr && head != nullptr );

   // Now, make sure that currentNode is in the list
   assert( isIn( currentNode ));

   // Make sure newNode is not null
   assert( newNode != nullptr );

   // And make sure that newNode is not in the list
   assert( !isIn( newNode ));

   assert( validate() );

   // GENERAL CASE:  Not inserting at the end of the list
   if( tail != currentNode ) {
      newNode->next = currentNode->next;
      currentNode->next = newNode;
      newNode->prev = currentNode;
      newNode->next->prev = newNode;
   } else {	 // SPECIAL CASE:  Inserting at the end of the list... we already know how to do that!
      push_back( newNode );
   }

   assert( validate() );
} // insert_after


/// @param currentNode Insert `newNode` before this node.  If it's `nullptr` and
///                    the list is empty, call `push_front( newNode )`
/// @param newNode The node to add to the list.  This can not be `nullptr`
void DoublyLinkedList::insert_before(Node *currentNode, Node *newNode) {
   // SPECIAL CASE:  The list is empty
   if( currentNode == nullptr && head == nullptr ) {
      push_front( newNode );  // We already know how to do this...
      return;
   }

   /// @throws invalid_argument If `currentNode` is not null and the list is empty
   if( currentNode != nullptr && head == nullptr) {
      throw( invalid_argument( PROGRAM_NAME ": Can't have a currentNode if the list is empty!" ));
   }

   /// @throws invalid_argument If `currentNode` is `nullptr` and the list is not empty
   if( currentNode == nullptr && head != nullptr ) {
      throw( invalid_argument( PROGRAM_NAME ": Need to supply a currentNode for a non-empty list" ));
   }

   // At this point, currentNode != null && head != null
   assert( currentNode != nullptr && head != nullptr );

   // Now, make sure that currentNode is in the list
   assert( isIn( currentNode ));

   // Make sure newNode is not null
   assert( newNode != nullptr );

   // And make sure that newNode is not in the list
   assert( !isIn( newNode ));

   assert( validate() );

   // GENERAL CASE:  Not inserting at the beginning of the list
   if( head != currentNode ) {
      newNode->prev = currentNode->prev;
      currentNode->prev = newNode;
      newNode->next = currentNode;
      newNode->prev->next = newNode;
   } else {	 // SPECIAL CASE:  Inserting at the end of the list... we already know how to do that!
      push_front( newNode );
   }

   assert( validate() );
} // insert_before


/// @param aNode Check this node to see if it's in the list
/// @return `true` if `aNode` is in the list.  `false` if it's not.
bool DoublyLinkedList::isIn(Node *aNode) const noexcept {
   Node* currentNode = head;

   while( currentNode != nullptr ) {
      if( aNode == currentNode )
         return true;
      currentNode = currentNode->next;
   }

   return false;  // Never found aNode in the list
}


/// This method depends on Node's > operator.
/// @return `true` if the list is sorted.  `false` if it's not.
bool DoublyLinkedList::isSorted() const noexcept {
   if( count <= 1 ) // SPECIAL CASE:  The list is empty or only has one item...
      return true;

   for( Node* i = head ; i->next != nullptr ; i = i->next ) {
      if( *i > *i->next )  // If the previous is greater than the next
         return false;     // ...then the list is *not* sorted
   }

   return true;  // Everything looks kosher
}


/// @param node1 Must not be `nullptr` and must be in the list
/// @param node2 Must not be `nullptr` and must be in the list
void DoublyLinkedList::swap( Node *node1, Node *node2 ) noexcept {
   assert( !empty() );

   assert( node1 != nullptr );
   assert( node2 != nullptr );

   assert( isIn( node1 ));
   assert( isIn( node2 ));

   assert( validate() );

   if( node1 == node2 ) { /// If `node1` and `node2` are the same, do nothing
      return;
   }

   /// @todo In the list, we need to make sure that node1 is to the left of node2.
   ///       If they aren't, we may be in for some unpredictable behavior.

   /// @internal We will divide this into 4 separate operations... each with a general & special case.
   Node* node1_left  = node1->prev;
   Node* node1_right = node1->next;
   Node* node2_left  = node2->prev;
   Node* node2_right = node2->next;

   bool isAdjoining = (node1_right == node2);

   // Fixup node1_left
   if( !isAdjoining )  // GENERAL CASE: The nodes are not adjoining
      node1->prev = node2->prev;
   else                // SPECIAL CASE: The two nodes are next to each other
      node1->prev = node2;

   if( node1 != head ) {  // GENERAL CASE: node1 is not the first in the list
      node1_left->next = node2;
      node2->prev = node1_left;
   } else {               // SPECIAL CASE: node1 is the first in the list
      head = node2;
      node2->prev = nullptr;
   }

   // Fixup node2_right
   if( !isAdjoining )  // GENERAL CASE:  The nodes are not adjoining
      node2->next = node1_right;
   else                // SPECIAL CASE:  The two nodes are next to each other
      node2->next = node1;

   if( node2 != tail ) { // GENERAL CASE: node2 is not the last in the list
      node2_right->prev = node1;
      node1->next = node2_right;
   } else {              // SPECIAL CASE: node2 is the last in the list
      tail = node1;
      node1->next = nullptr;
   }

   // Fixup inside connectors
   if( !isAdjoining ) {
      node1_right->prev = node2;
      node2_left->next = node1;
   }

   assert( validate() );
} // swap


/// @see https://en.wikipedia.org/wiki/Insertion_sort
///
/// @post `isSorted()` is `true`
///
/// This method depends on Node's > operator.
///
void DoublyLinkedList::insertionSort() noexcept {
   assert( validate() );

   if( count <= 1 ) // SPECIAL CASE:  The list is empty or only has one item...
      return;

   // dump();

   for( Node* i = head ; i->next != nullptr ; i = i->next ) {  // Outer loop
      Node* minNode = i;

      for( Node* j = i->next ; j != nullptr ; j = j->next ) {  // Inner loop
         if( *minNode > *j )
            minNode = j;
      }
      // The minimum node is...
      // cout << "minNode = [" << minNode << "]" << endl;

      swap( i, minNode );
      i = minNode;  // This fixes up i so i->next will work
      // dump();
   }

   assert( isSorted() ) ;

   assert( validate() );
}


/// @return The first node in the list.  If the list is empty, return `nullptr`.
Node *DoublyLinkedList::get_first() const noexcept {
   return head;
}

/// @return The last node in the list.  If the list is empty, return `nullptr`.
Node *DoublyLinkedList::get_last() const noexcept {
   return tail;
}


/// @param currentNode Start here
/// @return Return the Node that follows `currentNode` in the list
Node *DoublyLinkedList::get_next(const Node *currentNode) noexcept {
   assert( currentNode != nullptr ) ;
   return currentNode->next;
}


/// @param currentNode Start here
/// @return Return the Node that's before `currentNode` in the list
Node *DoublyLinkedList::get_prev(const Node *currentNode) noexcept {
   assert( currentNode != nullptr ) ;
   return currentNode->prev;
}


void DoublyLinkedList::dump() const noexcept {
   cout << "DoubleLinkedList:  head=[" << head << "]   tail=[" << tail << "]" << endl;
   for( Node* currentNode = head ; currentNode != nullptr ; currentNode = currentNode->next ) {
      cout << "  ";
      currentNode->dump();
   }
}


/// This method checks the list.  If something is not right, it will
/// dump out a message and stop the validation.  It will not throw an
/// exception.
///
/// @note This method does not call validate() on its Nodes.
///
/// @return `true` if the list is healthy.  `false` if otherwise.
bool DoublyLinkedList::validate() const noexcept {
   if( head == nullptr ) {
      assert( tail == nullptr );
      assert( count == 0 );
      assert( empty() );
   } else {
      assert( tail != nullptr );
      assert( count != 0 );
      assert( !empty() );
   }

   if( tail == nullptr ) {
      assert( head == nullptr );
      assert( count == 0 );
      assert( empty() );
   } else {
      assert( head != nullptr );
      assert( count != 0 );
      assert( !empty() );
   }

   if( head != nullptr && tail == head ) {
      assert( count == 1 );
   }

   unsigned int forwardCount = 0;
   Node* currentNode = head;
   // Count forward through the list
   while( currentNode != nullptr ) {
      forwardCount++;
      if( currentNode->next != nullptr ) {
         assert( currentNode->next->prev == currentNode );
      }
      currentNode = currentNode->next;
   }
   assert( count == forwardCount );

   // Count backward through the list
   unsigned int backwardCount = 0;
   currentNode = tail;
   while( currentNode != nullptr ) {
      backwardCount ++;
      if( currentNode->prev != nullptr ) {
         assert( currentNode->prev->next == currentNode );
      }
      currentNode = currentNode->prev;
   }
   assert( count == backwardCount );

   // cout << PROGRAM_NAME ": List is valid" << endl;

   return true;
} // validate()