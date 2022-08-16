
#include <iostream>

#include "Maze.h"
#include "List.h"
#include "OrderedPair.h"

using namespace std;

Maze::Maze(int n, int m): n(n), m(m) {
    data = new char*[n];
    for (int i = 0; i < n; i++) {
        data[i] = new char[m];
        for (int j = 0; j < m; j++) {
            data[i][j] = 'a' + m * i + j;
        }
    }
}

Maze::~Maze() {
    for (int i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;
}


Maze::Maze(const Maze& other) {
    n = other.n;
    m = other.m;
    data = new char*[n];
    for (int i = 0; i < n; i++) {
        data[i] = new char[m];
        for (int j = 0; j < m; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

void Maze::print(std::ostream& out) const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out << data[i][j];
        }
        out << endl;
    }
}

void Maze::set(int i, int j, char c) {
    data[i][j] = c;
}

int Maze::getNumRows() const {
    return n;
}

int Maze::getNumColumns() const {
    return m;
}

bool Maze::find_exit(int i, int j) const {
    Maze workspace(*this);
    bool result = workspace.find_exit_recursive(i, j);
    return result;
}

bool Maze::find_exit_recursive(int i, int j) {
    if (!isWithinBounds(i, j)) {
        return false;
    }
    if (isExit(i, j)) {
        return true;
    }
    if (isBlocked(i, j) || isMarked(i, j)) {
        return false;
    }
    mark(i, j);
    return find_exit_recursive(i, j + 1)
        || find_exit_recursive(i - 1, j)
        || find_exit_recursive(i, j - 1)
        || find_exit_recursive(i + 1, j);
}

bool Maze::isBlocked(int i, int j) const {
    assertWithinBounds(i, j);
    return data[i][j] == BLOCKED;
}

bool Maze::isMarked(int i, int j) const {
    assertWithinBounds(i, j);
    return data[i][j] == MARKED;
}

bool Maze::isWithinBounds(int i, int j) const {
    return (i < 0 || i >= n || j < 0 || j >= m) ? false : true;
}

void Maze::assertWithinBounds(int i, int j) const {
    if (!isWithinBounds(i, j)) {
        throw OutOfBounds();
    }
}

bool Maze::isExit(int i, int j) const {
    assertWithinBounds(i, j);
    return data[i][j] == EXIT;
}

void Maze::mark(int i, int j) {
    set(i, j, MARKED);
}

bool Maze::find_exit_path(int i, int j, List<OrderedPair>& path) const {
    Maze workspace(*this);
    bool result = workspace.find_exit_path_recursive(i, j, path);
    return result;
}

bool Maze::find_exit_path_recursive(int i, int j, List<OrderedPair>& path) {
    if (!isWithinBounds(i, j) || isBlocked(i, j) || isMarked(i, j)) {
        return false;
    }
    path.push(OrderedPair(i, j));
    if (isExit(i, j)) {
        return true;
    }
    mark(i, j);
    bool found = find_exit_path_recursive(i, j + 1, path)
        || find_exit_path_recursive(i - 1, j, path)
        || find_exit_path_recursive(i, j - 1, path)
        || find_exit_path_recursive(i + 1, j, path);
    if (!found) {
        OrderedPair popped = path.pop();
    }
    return found;
}

int Maze::count_exit_paths(int i, int j) const {
    Maze workspace(*this);
    int result = workspace.count_exit_paths_recursive(i, j);
    return result;
}

int Maze::count_exit_paths_recursive(int i, int j) {
    /*
      Count number of ways of extending the current call stack,
      with a non-crossing path from (i, j) to the exit.
     */
    if (!isWithinBounds(i, j) || isBlocked(i, j) || isMarked(i, j)) {
        return 0;
    }
    if (isExit(i, j)) {
        print(cout);
        cout << endl;
        return 1;
    }
    char c = data[i][j];
    mark(i, j);
    int count = count_exit_paths_recursive(i, j + 1)
        + count_exit_paths_recursive(i - 1, j)
        + count_exit_paths_recursive(i, j - 1)
        + count_exit_paths_recursive(i + 1, j);
    set(i, j, c);
    return count;
}

bool Maze::find_all_exit_paths(int i, int j, List< List<OrderedPair> >& paths) const {
    Maze workspace(*this);
    return workspace.find_all_exit_paths_recursive(i, j, paths);
}

bool Maze::find_all_exit_paths_recursive(int i, int j, List< List<OrderedPair> >& paths) {
    /*
      Accumulate all ways of extending the current call stack (represented by currentPath),
      with a non-crossing path from (i, j) to the exit
     */
    if (!isWithinBounds(i, j) || isBlocked(i, j) || isMarked(i, j)) {
        return false;
    }
    currentPath.push(OrderedPair(i, j));
    char c = data[i][j];
    mark(i, j);
    bool returnValue;
    if (c == EXIT) {
        paths.push(currentPath);
        returnValue = true;
    } else {
        bool result1 = find_all_exit_paths_recursive(i, j + 1, paths);
        bool result2 = find_all_exit_paths_recursive(i - 1, j, paths);
        bool result3 = find_all_exit_paths_recursive(i, j - 1, paths);
        bool result4 = find_all_exit_paths_recursive(i + 1, j, paths);
        returnValue = result1 || result2 || result3 || result4;
    }
    set(i, j, c); // unmark
    currentPath.pop();
    return returnValue;
}
