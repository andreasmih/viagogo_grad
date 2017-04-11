#ifndef COMPARE_H
#define COMPARE_H

#include "information.h"

class Compare
{
public:
    bool operator()(Information x,Information y) {
        return x.id>y.id;
    }
};

#endif // COMPARE_H
