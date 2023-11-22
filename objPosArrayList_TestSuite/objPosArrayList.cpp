#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;
    aList = new objPos[sizeArray];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeArray;
}

void objPosArrayList::insertHead(objPos thisPos)
{

}

void objPosArrayList::insertTail(objPos thisPos)
{

}

void objPosArrayList::removeHead()
{
    
}

void objPosArrayList::removeTail()
{

}

void objPosArrayList::getHeadElement(objPos &returnPos)
{

}

void objPosArrayList::getTailElement(objPos &returnPos)
{

}

void objPosArrayList::getElement(objPos &returnPos, int index)
{

}