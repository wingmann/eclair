#include "document/text_document.h"
#include "special/special_characters.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace wingmann::eclair;

bool TextDocument::init(std::string &filename)
{
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    std::stringstream inputStringStream;
    inputStringStream << inputFile.rdbuf();

    buffer_ = toUtf32(inputStringStream.str());
    length_ = buffer_.getSize();

    inputFile.close();
    initLineBuffer();
    return true;
}

bool TextDocument::saveFile(std::string &filename)
{
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    std::stringstream toBeSaved;

    for (std::uint32_t ch : buffer_)
        toBeSaved << special_chars::convertSpecialChar(ch, outputFile);

    outputFile << toBeSaved.str();
    outputFile.close();

    documentHasChanged_ = false;
    return true;
}

bool TextDocument::hasChanged() const
{
    return documentHasChanged_;
}

bool TextDocument::initLineBuffer()
{
    int lineStart = 0;
    lineBuffer_.clear();
    lineBuffer_.push_back(lineStart);

    auto bufferSize = buffer_.getSize();

    for (int i = 0; i < bufferSize; i++) {
        if (buffer_[i] == '\n' || buffer_[i] == 13) {
            lineStart = i + 1;
            lineBuffer_.push_back(lineStart);
        }
    }
    return true;
}

sf::String TextDocument::getLine(int lineNumber)
{
    auto lastLine = lineBuffer_.size() - 1;

    if (lineNumber < 0 || lineNumber > lastLine) {
        std::cerr << "lineNumber " << lineNumber << " is not a valid number line. "
                  << "Max is: " << lineBuffer_.size() - 1 << std::endl;
        return "";
    }

    if (lineNumber == lastLine) {
        return buffer_.substring(lineBuffer_[lineNumber]);
    }
    else {
        auto bufferStart = lineBuffer_[lineNumber];
        auto nextBufferStart = lineBuffer_[lineNumber + 1];
        auto candidate = nextBufferStart - bufferStart - 1;

        return buffer_.substring(bufferStart, candidate);
    }
}

sf::String TextDocument::toUtf32(const std::string &inString)
{
    sf::String outString = "";
    auto iterEnd = inString.cend();

    for (auto iter = inString.cbegin(); iter != iterEnd;) {
        std::uint32_t out;
        iter = sf::Utf8::decode(iter, iterEnd, out);
        outString += out;
    }
    return outString;
}

void TextDocument::addTextToPos(sf::String text, int line, int charNumber)
{
    documentHasChanged_ = true;

    auto textSize = text.getSize();
    auto bufferInsertPos = getBufferPos(line, charNumber);

    buffer_.insert(bufferInsertPos, text);

    auto lineAmount = lineBuffer_.size();

    for (int l = line + 1; l < lineAmount; l++)
        lineBuffer_[l] += static_cast<int>(textSize);

    for (int i = 0; i < (int)text.getSize(); i++) {
        if (text[i] == '\n' || text[i] == 13) {
            int newLineStart = bufferInsertPos + i + 1;

            lineBuffer_.insert(
                std::lower_bound(lineBuffer_.begin(), lineBuffer_.end(), newLineStart),
                newLineStart);
        }
    }
}

void TextDocument::removeTextFromPos(int amount, int lineN, int charNumber)
{
    documentHasChanged_ = true;

    int bufferStartPos = getBufferPos(lineN, charNumber);
    buffer_.erase(bufferStartPos, amount);

    initLineBuffer();
}

sf::String TextDocument::getTextFromPos(int amount, int line, int charNumber)
{
    int bufferPos = getBufferPos(line, charNumber);
    return buffer_.substring(bufferPos, amount);
}

int TextDocument::charAmountContained(int startLineNumber, int startCharNumber, int endLineNumber, int endCharNumber)
{
    return getBufferPos(endLineNumber, endCharNumber) - getBufferPos(startLineNumber, startCharNumber) + 1;
}

void TextDocument::swapLines(int lineA, int lineB)
{
    if (lineA == lineB) return;

    documentHasChanged_ = true;

    auto minLine = std::min(lineA, lineB);
    auto maxLine = std::max(lineA, lineB);
    auto lastLine = getLineCount() - 1;

    if (minLine < 0)
        std::cerr << "SwapLines: Line " << minLine << " does not exist\n";

    if (maxLine > lastLine)
        std::cerr << "SwapLines: Line " << lastLine << " does not exist\n";

    if (minLine == maxLine - 1)
        swapWithNextLine(minLine);
    else
        std::cerr << "Cant swap non-contiguous lines\n";
}

void TextDocument::swapWithNextLine(int line)
{
    if (line < 0 || line + 1 == getLineCount())
        std::cerr << "Cant swap with nonexisting line: " << line << "\n";

    auto a = getLine(line);
    auto b = getLine(line + 1);

    auto lenA = a.getSize();
    auto lenB = b.getSize();

    sf::String z = "";
    z += b;
    z += '\n';
    z += a;

    auto lineAStart = lineBuffer_[line];
    auto totalLen = lenA + 1 + lenB;

    for (int i = 0; i < totalLen; i++)
        buffer_[i + lineAStart] = z[i];

    lineBuffer_[line + 1] = static_cast<int>(lineBuffer_[line] + lenB + 1);
}

int TextDocument::getBufferPos(int line, int charN)
{
    if (line >= (int)lineBuffer_.size()) {
        std::cerr << "\nCan't get buffer pos of: " << line << "\n";
        std::cerr << "Buffer last line is: " << lineBuffer_.size() - 1 << "\n\n";
    }
    return lineBuffer_[line] + charN;
}

int TextDocument::charsInLine(int line) const
{
    if (line == lineBuffer_.size() - 1)
        return static_cast<int>(buffer_.getSize() - lineBuffer_[lineBuffer_.size() - 1]);

    return lineBuffer_[line + 1] - lineBuffer_[line] - 1;
}

int TextDocument::getLineCount() const
{
    return static_cast<int>(lineBuffer_.size());
}
