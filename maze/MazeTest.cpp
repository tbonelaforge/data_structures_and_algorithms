#include <iostream>

#include "Maze.h"
#include "List.h"
#include "OrderedPair.h"

using namespace std;

const int MAX_TEST_COLS = 10;

void set_maze(Maze& m, char values[][MAX_TEST_COLS]) {
    for (int i = 0; i < m.getNumRows(); i++) {
        for (int j = 0; j < m.getNumColumns(); j++) {
            m.set(i, j, values[i][j]);
        }
    }
}

int main() {
    cout << "Inside main function, about to construct a new maze with 4 rows and 3 columns..." << endl;
    Maze maze1(4, 3);
    cout << "Constructed the new maze object, about to print..." << endl;
    maze1.print(cout);
    cout << endl << "About to set cell (2,2) to 'z', in maze1..." << endl;
    maze1.set(2, 2, 'z');
    cout << "Now maze1 looks like: " << endl;
    maze1.print(cout);
    cout << endl << "About to make a new maze2, which is a copy of maze1..." << endl;
    Maze maze2 = maze1;
    cout << "The maze2 looks like:" << endl;
    maze2.print(cout);
    cout << endl << "About to change the copied maze2,..." << endl;
    maze2.set(2, 2, 'q');
    cout << "Now maze2 looks like:" << endl;
    maze2.print(cout);
    cout << "While maze1 still looks like:" << endl;
    maze1.print(cout);
    cout << endl;

    char test_cells[][MAX_TEST_COLS] = {
        { 'O', 'O', 'O', 'O' },
        { 'E', 'O', '+', 'O' },
        { 'O', '+', 'O', 'O' },
        { 'O', '+', 'O', '+' }
    };
    cout << "about to construct maze3, and then set the test values..." << endl;
    Maze maze3(4, 4);
    cout << "Before setting the test values, we have the maze looking like:" << endl;
    maze3.print(cout);
    set_maze(maze3, test_cells);
    cout << endl << "Now the maze looks like:" << endl;
    maze3.print(cout);
    cout << "About to try and find an exit, starting from 0, 1" << endl;
    bool result = maze3.find_exit(0, 1);
    cout << "The result is: " << result << endl;
    cout << "After finding the exit, maze3 still looks like: " << endl;
    maze3.print(cout);
    cout << "ABout to try and find the exit path, starting from 0, 1" << endl;
    List<OrderedPair> lop;
    result = maze3.find_exit_path(3, 2, lop);
    cout << "The result of find_exit_path is:" << result << endl;
    cout << "The resulting path is:" << endl;
    lop.print(cout);
    cout << endl << "And that is all..." << endl;
    cout << "About to count the number of exit paths, starting from 0, 1:" << endl;
    int num_paths = maze3.count_exit_paths(0, 1);
    cout << "Got " << num_paths << " exit paths" << endl;

    char test_cells2[][MAX_TEST_COLS] = {
        { 'O', 'O', 'O', 'O' },
        { 'E', 'O', '+', 'O' },
        { 'O', 'O', 'O', 'O' },
        { 'O', '+', 'O', '+' }
    };
    Maze maze4(4, 4);
    set_maze(maze4, test_cells2);
    cout << "Now trying a more 'open' maze:" << endl;
    maze4.print(cout);
    cout << endl;
    cout << "About to count the number of exit paths, starting from 0, 1:" << endl;
    num_paths = maze4.count_exit_paths(0, 1);
    cout << "Got " << num_paths << " exit paths" << endl;


    char test_cells3[][MAX_TEST_COLS] = {
        { 'O', 'O', 'O', 'O' },
        { 'E', 'O', '+', 'O' },
        { 'O', 'O', 'O', 'O' },
        { 'O', '+', 'O', 'O' }
    };
    Maze maze5(4, 4);
    set_maze(maze5, test_cells3);
    cout << "Now trying an even more 'open' maze:" << endl;
    maze5.print(cout);
    cout << endl;
    cout << "About to count the number of exit paths, starting from 0, 1:" << endl;
    num_paths = maze5.count_exit_paths(0, 1);
    cout << "Got " << num_paths << " exit paths" << endl;

    cout << "About to find all paths in maze3 (see printout below), starting from 0, 1:\n" << endl;
    maze3.print(cout);
    cout << endl;
    List< List<OrderedPair> > allPaths;
    result = maze3.find_all_exit_paths(0, 1, allPaths);
    cout << "The result is:" << result << endl;
    cout << "All paths are:" << endl;
    allPaths.print(cout);
    cout << endl;

    char test_cells4[][MAX_TEST_COLS] = {
        { 'O', 'O', 'O', 'O' },
        { 'E', 'O', '+', 'O' },
        { 'O', 'O', 'O', 'O' },
        { 'O', '+', 'O', 'O' }
    };

}
