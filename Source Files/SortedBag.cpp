#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>
using namespace std;

SortedBag::SortedBag(Relation r) {
    this->current_elements = 0;
    this->relation = r;
    this->elements = new TElem[this->capacity];
}
//Theta(1)

void SortedBag::resize() {
    if (this->current_elements == this->capacity){
        this->capacity *= 2;
        this->elements = (TElem*)realloc(this->elements, this->capacity*sizeof(TElem));
    }
    else if (this->current_elements*4 == this->capacity){
        this->capacity /= 2;
        this->elements = (TElem*)realloc(this->elements, this->capacity*sizeof(TElem));
    }
}
//Theta(1)

void SortedBag::add(TComp e) {
	if (this->current_elements == this->capacity || 4*this->current_elements+1 == this->capacity){
	    resize();
	}
	int index=0;
	while(index<this->current_elements&&!this->relation(e, this->elements[index])) index++;
	this->current_elements++;
	for(int i = this->current_elements-1;i>index;i--)
	    this->elements[i] = this->elements[i-1];
	this->elements[index] = e;
}
// Best case : Theta(1) ; Worst case: Theta(n) => Total complexity: O(n)


bool SortedBag::remove(TComp e) {
	int index=0, found_at_index=0;
    bool found=false;
    while(index < this->current_elements && !found){
        if (this->elements[index] == e){
            found = true;
            found_at_index = index;
        }
        index++;
    }
	if (found){
	    for (index=found_at_index;index<this->current_elements-1;index++)
	        this->elements[index] = this->elements[index+1];
	    this->current_elements--;
        if (4*this->current_elements == this->capacity){
            resize();
        }
	    return found;
	}
	else{
	    return found;
	}
}
/*
 *  Theta(n), because:
 *      - if the element removed is the last one, obviously it takes a long time to search for it, but we don't have
 *        to move the other elements
 *      - if the element removed is the first one, it takes very little to search for it, but it takes a long time
 *        to move the other elements
 *      - and because Theta(2*n) is actually Theta(n)
 */


bool SortedBag::search(TComp elem) const {
	int index = 0;
	bool found = false;
	while(index < this->current_elements && !found){
	    if (this->elements[index] == elem) found = true;
	    index++;
	}
	return found;
}
// Best case: Theta(1), Worst case: Theta(n) => Total complexity: O(n)


int SortedBag::nrOccurrences(TComp elem) const {
	int index=0,count=0;
	while(index<this->current_elements){
	    if (this->elements[index] == elem) count++;
	    index++;
	}
	return count;
}
// Theta(n)


int SortedBag::size() const {
	return this->current_elements;
}
// Theta(1)

bool SortedBag::isEmpty() const {
	if (this->current_elements == 0)
	    return true;
	else if (this->current_elements > 0)
	    return false;
	else
	    throw exception();
}
// Theta(1)


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}
// Theta(1)


SortedBag::~SortedBag() {
	delete[] this->elements;
}
// I don't know the exact procedure of freeing an array in C++, but it is probably Theta(1)
