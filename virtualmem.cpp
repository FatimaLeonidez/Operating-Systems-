#include <iostream>

cout << "Loaded " << references.size() << " memory references." << endl;

vector<Page> pageTable;
for (int i = 0; i < 8; i++) {
pageTable.push_back(Page(i));
}


cout << "Initial Page Table:" << endl;
for (auto &p : pageTable) p.display();

cout << "\nSimulating accesses:" << endl;

for (int r : references) {
cout << "Accessing page " << r << "... ";

cout << "\nFinal Page Table:" << endl;
for (auto &p : pageTable) p.display();


return 0;
}
