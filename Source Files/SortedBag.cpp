#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>
#include <typeinfo>
#include <string>
using namespace std;

SortedBag::SortedBag(Relation r) {
    if (strcmp(typeid(r).name(), "bool") !=0){
        throw exception();
    }
    this->current_elements = 0;
    this->relation = r;
    this->elements = new TElem[this->capacity];
}

void SortedBag::add(TComp e) {
	if (this->current_elements == this->capacity){
	    throw exception();
	}
	this->elements[this->current_elements] = e;
	this->current_elements++;
	qsort(this->elements, this->current_elements, sizeof(int),
          reinterpret_cast<_CoreCrtNonSecureSearchSortCompareFunction>(this->relation));
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
	//TODO - Implementation
	return 0;
}



int SortedBag::size() const {
	//TODO - Implementation
	return 0;
}


bool SortedBag::isEmpty() const {
	//TODO - Implementation
	return false;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	delete[] this->elements;
}
