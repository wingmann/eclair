#ifndef WINGMANN_ECLAIR_SPECIAL_SPECIAL_CHARACTERS_H
#define WINGMANN_ECLAIR_SPECIAL_SPECIAL_CHARACTERS_H

#include <SFML/System.hpp>

#include <string>
#include <cstdint>
#include <fstream>

namespace wingmann::eclair::special_chars {

const auto a_lower_grave      = 224;
const auto a_lower_acute      = 225;
const auto a_lower_circumflex = 226;

const auto e_lower_grave      = 232;
const auto e_lower_acute      = 233;
const auto e_lower_circumflex = 234;

const auto i_lower_grave      = 236;
const auto i_lower_acute      = 237;
const auto i_lower_circumflex = 238;

const auto n_lower_tilde      = 241;

const auto o_lower_grave      = 242;
const auto o_lower_acute      = 243;
const auto o_lower_circumflex = 244;

const auto u_lower_grave      = 249;
const auto u_lower_acute      = 250;
const auto u_lower_circumflex = 251;

const auto a_upper_grave      = 192;
const auto a_upper_acute      = 193;
const auto a_upper_circumflex = 194;

const auto e_upper_grave      = 200;
const auto e_upper_acute      = 201;
const auto e_upper_circumflex = 202;

const auto i_upper_grave      = 204;
const auto i_upper_acute      = 205;
const auto i_upper_circumflex = 206;

const auto o_upper_grave      = 210;
const auto o_upper_acute      = 211;
const auto o_upper_circumflex = 212;

const auto u_upper_grave      = 217;
const auto u_upper_acute      = 218;
const auto u_upper_circumflex = 219;

std::string convertSpecialChar(std::uint32_t symbol, std::ofstream &outputFile);

} // namespace wingmann::eclair::special_chars

#endif // WINGMANN_ECLAIR_SPECIAL_SPECIAL_CHARACTERS_H
