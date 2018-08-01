//
// Created by gaoge on 2018/7/29.
//

#pragma once

#include <cstdlib>
#include <string>

// The lexer returns tokens [0-255] if it is an unknown character, otherwise
// one of these for known things.
enum class Token {
  tok_eof = -1,

  // Keywords
  tok_def = -2,
  tok_extern = -3,

  // Primary
  tok_identifer = -4,
  tok_number = -5,
};

// Filled in if tok_identifier
static std::string IdentifierStr;
// Filled in if tok_number
static double NumVal;

/// getTok - Return the next token from standard input.
static auto getTok() {
  static int LastChar = ' ';

  // Skip any whitespace.
  while (isspace(LastChar)) {
    LastChar = getchar();
  }

  return 0;
}
