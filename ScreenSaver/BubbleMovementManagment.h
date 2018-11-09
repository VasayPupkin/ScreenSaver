#ifndef BUBBLEMOVEMENTMANAGMENT_H
#define BUBBLEMOVEMENTMANAGMENT_H

#include <list>
#include <memory>
#include <boost/asio/>

#include "BubbleShape.h"

using BubblePtr = std::unique_ptr<BubbleShape>;
using BubblePtrList = std::list<BubblePtr>;

class BubbleMovementManagment
{
public:
    BubbleMovementManagment();

private:
    BubblePtrList _bubble_ptr_list;
};

#endif // BUBBLEMOVEMENTMANAGMENT_H
