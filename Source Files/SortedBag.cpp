#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>
using namespace std;

SortedBag::SortedBag(Relation r) {
    this->current_elements = 0;
    this->relation = r;
    this->elements = new TElem[this->capacity];
}

void SortedBag::add(TComp e) {
	if (this->current_elements == this->capacity){
	    throw exception();
	}
	int index=0;
	while(index<this->current_elements&&!this->relation(e, this->elements[index])) index++;
	this->current_elements++;
	for(int i = this->current_elements-1;i>index;i--)
	    this->elements[i] = this->elements[i-1];
	this->elements[index] = e;
}


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
	    return found;
	}
	else{
	    return found;
	}
}


bool SortedBag::search(TComp elem) const {
	int index = 0;
	bool found = false;
	while(index < this->current_elements && !found){
	    if (this->elements[index] == elem) found = true;
	    index++;
	}
	return found;
}


int SortedBag::nrOccurrences(TComp elem) const {
	int index=0,count=0;
	while(index<this->current_elements){
	    if (this->elements[index] == elem) count++;
	    index++;
	}
	return count;
}



int SortedBag::size() const {
	return this->current_elements;
}


bool SortedBag::isEmpty() const {
	if (this->current_elements == 0)
	    return true;
	else if (this->current_elements > 0)
	    return false;
	else
	    throw exception();
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	delete[] this->elements;
}
