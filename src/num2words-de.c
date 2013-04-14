#include "num2words-de.h"
#include "string.h"

static const char* const ONES[] = {
  "null",
  "eins",
  "zwei",
  "drei",
  "vier",
  "fünf",
  "sechs",
  "sieben",
  "acht",
  "neun"
};

static const char* const TEENS[] ={
  "",
  "elf",
  "zwölf",
  "dreizehn",
  "vierzehn",
  "fünfzehn",
  "sechzehn",
  "siebzehn",
  "achtzehn",
  "neunzehn"
};

static const char* const TENS[] = {
  "",
  "zehn",
  "zwanzig",
  "dreissig",
  "vierzig",
  "fünfzig",
  "sechzig",
  "siebzig",
  "achzig",
  "neunzig"
};

static const char* UND = "und";

static size_t append_number(char* words, int num) {
  int tens_val = num / 10 % 10;
  int ones_val = num % 10;

  size_t len = 0;

  if (tens_val == 1 && num != 10) {
    strcat(words, TEENS[ones_val]);
    return strlen(TEENS[ones_val]);
  }

  if (ones_val > 0 || num == 0) {
    strcat(words, ONES[ones_val]);
    len += strlen(ONES[ones_val]);
  }

  if (tens_val > 0) {
    if (ones_val > 0) {
      strcat(words, UND);
      len += strlen(UND);
    }
    strcat(words, TENS[tens_val]);
    len += strlen(TENS[tens_val]);
  }

  return len;
}

static size_t append_string(char* buffer, const size_t length, const char* str) {
  strncat(buffer, str, length);

  size_t written = strlen(str);
  return (length > written) ? written : length;
}


void time_to_words(int hours, int minutes, char* words, size_t length) {

  size_t remaining = length;
  memset(words, 0, length);

  remaining -= append_number(words, hours % 12);
  remaining -= append_string(words, remaining, " ");
  remaining -= append_number(words, minutes);

}
void time_to_2words(int hours, int minutes, char* words, size_t length, char* words2, size_t length2) {

  size_t remaining = length;
  memset(words, 0, length);
  remaining -= append_number(words, hours % 12);

  size_t remaining2 = length2;
  memset(words2, 0, length2);
  remaining2 -= append_number(words2, minutes);

}

void fuzzy_time_to_words(int hours, int minutes, char* words, size_t length) {
}
