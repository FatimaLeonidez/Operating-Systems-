#ifndef PAGE_H
#define PAGE_H


#include <iostream>
using namespace std;


class Page {
private:
	int pageNumber; // page number
	int frameNumber; // a frame number for the file, just in case
	bool valid; // secures the bit


public:
	Page(int pageNumber = -1);


	int getPageNumber() const;
	int getFrameNumber() const;
	bool isValid() const;


	void setFrameNumber(int frame);
	void setValid(bool v);


	void display() const;
};


#endif
