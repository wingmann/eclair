#include "cursor/cursor.h"

using namespace wingmann::eclair;

Cursor::Cursor() : Cursor{0, 0}
{
}

Cursor::Cursor(int lineNumber, int charNumber) : maxCharNumberReached_{}
{
    updatePos(lineNumber, charNumber);
}

void Cursor::setPosition(int lineNumber, int charNumber, bool updateMaxChar)
{
    updatePos(lineNumber, charNumber);

    if (updateMaxChar)
        setMaxCharNReached(charNumber_);
}

int Cursor::getLineN() const
{
    return lineNumber_;
}

int Cursor::getCharN() const
{
    return charNumber_;
}

void Cursor::setMaxCharNReached(int charNumber)
{
    maxCharNumberReached_ = charNumber;
}

int Cursor::getMaxCharNReached() const
{
    return maxCharNumberReached_;
}

void Cursor::moveUp()
{
    updatePos(lineNumber_ - 1, charNumber_);
}

void Cursor::moveDown()
{
    updatePos(lineNumber_ + 1, charNumber_);
}

void Cursor::moveUpToMaxCharN()
{
    updatePos(lineNumber_ - 1, maxCharNumberReached_);
}

void Cursor::moveDownToMaxCharN()
{
    updatePos(lineNumber_ + 1, maxCharNumberReached_);
}

void Cursor::moveLeft(bool updateMaxChar)
{
    if (updateMaxChar)
        setMaxCharNReached(charNumber_ - 1);

    updatePos(lineNumber_, charNumber_ - 1);
}

void Cursor::moveRight(bool updateMaxChar)
{
    if (updateMaxChar)
        setMaxCharNReached(charNumber_ + 1);

    updatePos(lineNumber_, charNumber_ + 1);
}

void Cursor::moveToEnd(int charsInLine, bool updateMaxChar)
{
    if (updateMaxChar)
        setMaxCharNReached(charsInLine);

    updatePos(lineNumber_, charsInLine);
}

void Cursor::moveToStart(bool updateMaxChar)
{
    if (updateMaxChar)
        setMaxCharNReached(0);

    updatePos(lineNumber_, 0);
}

void Cursor::nextLine()
{
    charNumber_ = 0;
    moveDown();
}

void Cursor::updatePos(int y, int x)
{
    lineNumber_ = y;
    charNumber_ = x;
}
