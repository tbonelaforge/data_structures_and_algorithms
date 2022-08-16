#include <iostream>
#include <fstream>
#include <string>

#include <cstdio>

#include "SortedList.h"

using namespace std;



void fileError(string filename) {
    cout << "File " << filename << " could not be opened." << endl;
    exit(1);
}

void trim(istream& in) {
    char c;
    while ((c = in.get())) {
        if (c == 0x0a || c == 0x07) {

            // Skip linefeeds or carriage returns
            continue;
        }
        in.putback(c);
        break;
    }
}


void printSortedList(SortedList &sl, std::ostream& out) {
    ItemType x;

    sl.reset();
    out << "[";
    while (sl.hasNext()) {
        x = sl.getNext();
        x.Print(out);
        if (sl.hasNext()) {
            out << ", ";
        }
    }
    out << "]" << endl;
}

void processCommands(ifstream& infile, ofstream& outfile, string title) {
    string command;
    int itemValue, i = 0;
    SortedList sl(5);
    ItemType item;
    bool found;
    bool done = false;
    outfile << title << endl;
    while (!done && (infile >> command)) {
        if (command == "putItem") {
            infile >> itemValue;
            item.Initialize(itemValue);
            sl.putItem(item);
            item.Print(outfile);
            outfile << " is in list " << endl;
        } else if (command == "getItem") {
            infile >> itemValue;
            item.Initialize(itemValue);
            sl.getItem(item, found);
            item.Print(outfile);
            if (found) {
                outfile << " found in list" << endl;
            } else {
                outfile << " not in list" << endl;
            }
        } else if (command == "printSortedList") {
            printSortedList(sl, outfile);
        } else if (command == "getLength") {
            outfile << "Length is: " << sl.getLength() << endl;
        } else if (command == "deleteItem") {
            infile >> itemValue;
            item.Initialize(itemValue);
            sl.deleteItem(item);
            item.Print(outfile);
            outfile << " is deleted" << endl;
        } else if (command == "makeEmpty") {
            sl.makeEmpty();
            outfile << "Made Empty" << endl;
        } else if (command == "isFull") {
            if (sl.isFull()) {
                outfile << "List is full." << endl;
            } else {
                outfile << "List is not full." << endl;
            }
        } else if (command == "quit") {
            done = true;
        } else {
            cout << command << " is not a valid command." << endl;
            continue;
        }
        i += 1;
        cout << "Command number " << i << " completed." << endl;
    }
}

int main() {
    string filename, title;
    ifstream infile;
    ofstream outfile;
    cout << "Enter input filename to test:" << endl;
    cin >> filename;
    infile.open(filename);
    if (!infile) fileError(filename);
    cout << "Enter output filename to write test results to:" << endl;
    cin  >> filename;
    outfile.open(filename);
    if (!outfile) fileError(filename);
    cout << "Enter a title for this test run:" << endl;
    trim(cin);
    getline(cin, title, '\n');
    processCommands(infile, outfile, title);
    infile.close();
    outfile.close();
};
