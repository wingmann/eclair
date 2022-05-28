#include "special/special_characters.h"

#include <iostream>

using namespace wingmann::eclair::special_chars;

std::string convertSpecialChar(std::uint32_t symbol, std::ofstream &outputFile)
{
    switch (symbol) {
    case a_lower_acute: return "á";
    case e_lower_acute: return "é";
    case i_lower_acute: return "í";
    case o_lower_acute: return "ó";
    case u_lower_acute: return "ú";

    case a_lower_grave: return "à";
    case e_lower_grave: return "è";
    case i_lower_grave: return "ì";
    case o_lower_grave: return "ò";
    case u_lower_grave: return "ù";

    case a_lower_circumflex: return "â";
    case e_lower_circumflex: return "ê";
    case i_lower_circumflex: return "î";
    case o_lower_circumflex: return "ô";
    case u_lower_circumflex: return "û";

    case a_upper_acute: return "Á";
    case e_upper_acute: return "É";
    case i_upper_acute: return "Í";
    case o_upper_acute: return "Ó";
    case u_upper_acute: return "Ú";

    case a_upper_grave: return "À";
    case e_upper_grave: return "È";
    case i_upper_grave: return "Ì";
    case o_upper_grave: return "Ò";
    case u_upper_grave: return "Ù";

    case a_upper_circumflex: return "Â";
    case e_upper_circumflex: return "Ê";
    case i_upper_circumflex: return "Î";
    case o_upper_circumflex: return "Ô";
    case u_upper_circumflex: return "Û";

    case n_lower_tilde: return "ñ";

    default:
        if (symbol < 128)
            return sf::String(symbol);

        outputFile.close();
        std::cerr << "\nERROR: Can't save character: " << c << std::endl;
        return "";
    }
}
