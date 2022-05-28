#ifndef WINGMANN_ECLAIR_INCLUDE_DOCUMENT_TEXT_DOCUMENT_H
#define WINGMANN_ECLAIR_INCLUDE_DOCUMENT_TEXT_DOCUMENT_H

#include <SFML/System/String.hpp>

#include <string>
#include <vector>
#include <cstdint>

namespace wingmann::eclair {

/**
 *
 */
class TextDocument {
    sf::String buffer_;
    std::vector<int> lineBuffer_;
    std::size_t length_;
    bool documentHasChanged_;

public:
    /**
     *
     * @param filename
     * @return
     */
    bool init(std::string& filename);

    /**
     *
     * @param filename
     * @return
     */
    bool saveFile(std::string& filename);

    /**
     *
     * @return
     */
    [[nodiscard]] bool hasChanged() const;

    /**
     *
     * @param lineNumber
     * @return
     */
    sf::String getLine(int lineNumber);

    /**
     *
     * @param line
     * @return
     */
    [[nodiscard]] int charsInLine(int line) const;

    /**
     *
     * @return
     */
    [[nodiscard]] int getLineCount() const;

    /**
     *
     * @param text
     * @param line
     * @param charNumber
     */
    void addTextToPos(sf::String text, int line, int charNumber);

    /**
     *
     * @param amount
     * @param line
     * @param charNumber
     */
    void removeTextFromPos(int amount, int line, int charNumber);

    /**
     *
     * @param amount
     * @param line
     * @param charNumber
     * @return
     */
    sf::String getTextFromPos(int amount, int line, int charNumber);

    /**
     *
     * @param lineA
     * @param lineB
     */
    void swapLines(int lineA, int lineB);

    /**
     *
     * @param startLineNumber
     * @param startCharNumber
     * @param endLineNumber
     * @param endCharNumber
     * @return
     */
    int charAmountContained(
        int startLineNumber,
        int startCharNumber,
        int endLineNumber,
        int endCharNumber);

private:
    //
    bool initLineBuffer();

    //
    int getBufferPos(int line, int charN);

    //
    void swapWithNextLine(int line);

    //
    static sf::String toUtf32(const std::string &inString);
};

} // namespace wingmann::eclair

#endif // WINGMANN_ECLAIR_INCLUDE_DOCUMENT_TEXT_DOCUMENT_H
