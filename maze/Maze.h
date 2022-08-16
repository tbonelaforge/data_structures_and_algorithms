#ifndef _MAZE_H_
#define _MAZE_H_

#include <iostream>

#include "List.hpp"
#include "OrderedPair.h"


class Maze {
public:
    static const char EXIT = 'E'; // Exit
    static const char BLOCKED = '+'; // Blocked
    static const char MARKED = '*'; // Marked

    Maze(int n, int m);
    ~Maze();
    Maze(const Maze& other);
    bool find_exit(int i, int j) const;
    bool find_exit_path(int i, int j, List<OrderedPair>& path) const;
    int count_exit_paths(int i, int j) const;
    bool find_all_exit_paths(int i, int j, List< List<OrderedPair> >& paths) const;
    void set(int i, int j, char c);
    void print(std::ostream& out) const;
    int getNumRows() const;
    int getNumColumns() const;
    bool isBlocked(int i, int j) const;
    bool isExit(int i, int j) const;
    void mark(int i, int j);
    bool isMarked(int i, int j) const;
private:
    bool find_exit_recursive(int i, int j);
    bool find_exit_path_recursive(int i, int j, List<OrderedPair>& path);
    int count_exit_paths_recursive(int i, int j);
    bool find_all_exit_paths_recursive(int i, int j, List< List<OrderedPair> >& paths);
    bool isWithinBounds(int i, int j) const;
    void assertWithinBounds(int i, int j) const;
    int n;
    int m;
    char ** data;
    List<OrderedPair> currentPath;
    
};

class OutOfBounds {};

#endif
