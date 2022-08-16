#ifndef _ORDERED_PAIR_H_
#define _ORDERED_PAIR_H_

class OrderedPair {
public:
    OrderedPair(): i(-1), j(-1) {};
    OrderedPair(int i, int j) : i(i), j(j) {};
    void print(ostream& out) {
        out << "(" << i << ", " << j << ")";
    }
private:
    int i;
    int j;
};

#endif
