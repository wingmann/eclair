#include "cursor/cursor.h"

using namespace wingmann::eclair;

Cursor::Cursor() : Cursor{0, 0}
{
}

Cursor::Cursor(int lineN, int charN) : maxCharNReached{}
{
    updatePos(lineN, charN);
}

void Cursor::setPosition(int lineN, int charN, bool updateMaxChar)
{
    updatePos(lineN, charN);

    if (updateMaxChar)
        setMaxCharNReached(this->charN);
}

int Cursor::getLineN()
{
    return lineN;
}

int Cursor::getCharN()
{
    return charN;
}

void Cursor::setMaxCharNReached(int charN)
{
    maxCharNReached = charN;
}

int Cursor::getMaxCharNReached()
{
    return maxCharNReached;
}

void Cursor::moveUp()
{
    updatePos(lineN - 1, charN);
}

void Cursor::moveDown()
{
    updatePos(lineN + 1, charN);
}

void Cursor::moveUpToMaxCharN()
{
    updatePos(lineN - 1, maxCharNReached);
}

void Cursor::moveDownToMaxCharN()
{
    updatePos(lineN + 1, maxCharNReached);
}

void Cursor::moveLeft(bool updateMaxChar)
{
    if (updateMaxChar)
        setMaxCharNReached(charN - 1);

    updatePos(lineN, charN - 1);
}

void Cursor::moveRight(bool updateMaxChar)
{
    if (updateMaxChar)
        setMaxCharNReached(charN + 1);

    updatePos(lineN, charN + 1);
}

void Cursor::moveToEnd(int charsInLine, bool updateMaxChar)
{
    if (updateMaxChar)
        setMaxCharNReached(charsInLine);

    updatePos(lineN, charsInLine);
}

void Cursor::moveToStart(bool updateMaxChar)
{
    if (updateMaxChar)
        setMaxCharNReached(0);

    updatePos(lineN, 0);
}

void Cursor::nextLine()
{
    charN = 0;
    moveDown();
}

void Cursor::updatePos(int l, int c)
{
    lineN = l;
    charN = c;
}
