#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	this->current_element = 0;
}

TComp SortedBagIterator::getCurrent() {
	if (this->current_element >= this->bag.current_elements){
        throw exception();
	}
	return this->bag.elements[this->current_element];
}

bool SortedBagIterator::valid() {
    if (this->current_element < this->bag.current_elements){
        return true;
    }
	return false;
}

void SortedBagIterator::next() {
    if (this->current_element >= this->bag.current_elements){
        throw exception();
    }
    this->current_element++;
}

void SortedBagIterator::first() {
	this->current_element=0;
}

