#include <iostream>
#include <vector>
#include <queue>
#include "page.h"

using namespace std;

int main()
{
    vector<int> references = {1, 0, 1, 3, 2, 0, 3, 2}; // placeholder references

    cout << "Loaded " << references.size() << " memory references." << endl;

    vector<Page> pageTable;
    for (int i = 0; i < 8; i++) { // creates an eight page page table 
        pageTable.push_back(Page(i));
    }

    int numFrames = 3; // test of 3 memory frames

    queue<int> fifo; // simulates replacement algorithm: FIFO replacement algorithm to handle page faults
    vector<int> frameTable(numFrames, -1); // initialize frame table with invalid markers

    int numFreeFrames = 0;

    cout << "Initial Page Table:" << endl;
    for (auto& p : pageTable) p.display(); // displays the first page table


    cout << "\nSimulating accesses:" << endl;

    for (int r : references) {
        cout << "Accessing page " << r << "... ";

        // use references to modify the actual table entries
        Page& page = pageTable[r];

        if (page.isValid()) { // if there is a page hit
            cout << "[PAGE HIT] Frame: " << page.getFrameNumber() << endl; // displays frame number of frame
        }
        else { // if there is a page fault
            cout << "[PAGE FAULT] "; 

			if (numFreeFrames < numFrames) { // if there are free frames available
                cout << "Loading into free frame: " << numFreeFrames << endl;

                page.setFrameNumber(numFreeFrames); 
                page.setValid(true);

                frameTable[numFreeFrames] = r;
                fifo.push(r);

                numFreeFrames++;
            }
			else { // if there are no free frames available, FIFO replacement algorithm is used
                int replacedPageNum = fifo.front();
                fifo.pop();

                Page& replacedPage = pageTable[replacedPageNum];

                cout << "Replacing page: [" << replacedPageNum << "] from frame: " << replacedPage.getFrameNumber() << endl;

                int frameToUse = replacedPage.getFrameNumber();

				replacedPage.setValid(false); // invalidates the replaced page
                replacedPage.setFrameNumber(-1);

				page.setFrameNumber(frameToUse); // loads the new page into the freed frame
                page.setValid(true);

                frameTable[frameToUse] = r;
                fifo.push(r);

            }
        }

    }

    cout << "\nFinal Page Table:" << endl; 
	for (auto& p : pageTable) p.display(); // displays the final page table

    return 0;
}
