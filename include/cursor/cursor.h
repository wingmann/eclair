#ifndef WINGMANN_ECLAIR_CURSOR_CURSOR_H
#define WINGMANN_ECLAIR_CURSOR_CURSOR_H

namespace wingmann::eclair {

/**
 *
 */
class Cursor {
    int lineN;
    int charN;
    int maxCharNReached;

public:
    /**
     *
     */
    Cursor();

    /**
     *
     * @param lineN
     * @param charN
     */
    Cursor(int lineN, int charN);

    virtual ~Cursor() = default;

public:
    /**
     *
     */
    void moveUp();

    /**
     *
     */
    void moveDown();

    /**
     *
     * @param updateMaxChar
     */
    void moveLeft(bool updateMaxChar = false);

    /**
     *
     * @param updateMaxChar
     */
    void moveRight(bool updateMaxChar = false);

    /**
     *
     * @param charsInLine
     * @param updateMaxChar
     */
    void moveToEnd(int charsInLine, bool updateMaxChar = false);

    /**
     *
     * @param updateMaxChar
     */
    void moveToStart(bool updateMaxChar = false);

    /**
     *
     */
    void nextLine();

    /**
     *
     * @return
     */
    int getLineN();

    /**
     *
     * @return
     */
    int getCharN();

    /**
     *
     * @param lineN
     * @param charN
     * @param updateMaxChar
     */
    void setPosition(int lineN, int charN, bool updateMaxChar = false);

    /**
     *
     */
    void moveDownToMaxCharN();

    /**
     *
     */
    void moveUpToMaxCharN();

    /**
     *
     * @param charN
     */
    void setMaxCharNReached(int charN);

    /**
     *
     * @return
     */
    int getMaxCharNReached();

private:
    /**
     *
     * @param posY
     * @param posX
     */
    void updatePos(int posY, int posX);
};

} // namespace wingmann::eclair

#endif // WINGMANN_ECLAIR_CURSOR_CURSOR_H
