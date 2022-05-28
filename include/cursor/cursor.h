#ifndef WINGMANN_ECLAIR_CURSOR_CURSOR_H
#define WINGMANN_ECLAIR_CURSOR_CURSOR_H

namespace wingmann::eclair {

/**
 *
 */
class Cursor {
    int lineNumber_{};
    int charNumber_{};
    int maxCharNumberReached_;

public:
    /**
     *
     */
    Cursor();

    /**
     *
     * @param lineNumber
     * @param charNumber
     */
    Cursor(int lineNumber, int charNumber);

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
    [[nodiscard]] int getLineN() const;

    /**
     *
     * @return
     */
    [[nodiscard]] int getCharN() const;

    /**
     *
     * @param lineNumber
     * @param charNumber
     * @param updateMaxChar
     */
    void setPosition(int lineNumber, int charNumber, bool updateMaxChar = false);

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
     * @param charNumber
     */
    void setMaxCharNReached(int charNumber);

    /**
     *
     * @return
     */
    [[nodiscard]] int getMaxCharNReached() const;

private:
    //
    void updatePos(int y, int x);
};

} // namespace wingmann::eclair

#endif // WINGMANN_ECLAIR_CURSOR_CURSOR_H
