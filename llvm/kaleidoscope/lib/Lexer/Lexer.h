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
/// Current Token
static int CurTok;

/// getTok - Return the next token from standard input.
static auto getTok() {
  static int LastChar = ' ';

  // Skip any whitespace.
  while (isspace(LastChar)) {
    LastChar = getchar();
  }

  if (isalpha(LastChar)) {
    IdentifierStr = LastChar;

    while (isalnum(LastChar = getchar())) {
      IdentifierStr += LastChar;
    }

    if (IdentifierStr == "def") {
      return Token::tok_def;
    }
    if (IdentifierStr == "extern") {
      return Token::tok_extern;
    }
    return Token::tok_identifer;
  }

  if (isdigit(LastChar) || LastChar == '.') {
    std::string NumStr;

    do {
      NumStr += LastChar;
      LastChar = getchar();
    } while (isdigit(LastChar) || LastChar == '.');

    NumVal = strtod(NumStr.c_str(), 0);
    return Token::tok_number;
  }

  if (LastChar == '#') {
    do {
      LastChar = getchar();
    } while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

    if (LastChar != EOF) {
      return getTok();
    }
  }

  if (LastChar == EOF) {
    return Token::tok_eof;
  }

  int ThisChar = LastChar;
  LastChar = getchar();
  /// Prevent clang warning
  return static_cast<Token>(ThisChar);
}

static auto getNextToken() {
  /// Prevent clang warning
  return CurTok = static_cast<int>(getTok());
}
