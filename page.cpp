#include "page.h"
#include <iostream>
using namespace std;


Page::Page(int pageNumber)
: pageNumber(pageNumber), frameNumber(-1), valid(false) {}

int Page::getPageNumber() const {
return pageNumber;
}

int Page::getFrameNumber() const {
return frameNumber;
}

bool Page::isValid() const {
return valid;
}

void Page::setFrameNumber(int frame) {
frameNumber = frame;
}

void Page::setValid(bool v) {
valid = v;
}

void Page::display() const {
cout << "Page " << pageNumber
<< " | Frame: " << frameNumber
<< " | Valid: "  << valid << endl;
