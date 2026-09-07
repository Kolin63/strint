#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <strint.h>

#define to_str_check(num, bits, fmt, func) {\
  char buf[STRINT_##bits ];\
  char correct[128];\
  snprintf(correct, sizeof(correct), "%" fmt, num);\
  if (strcmp( func (buf, num, NULL), correct) == 0) printf("\e[0;92mpass: %s(%s)\e[0m\n", #func, correct);\
  else {\
    printf("\e[1;91mfail: %s(%s) -> '%s'\n\e[0m", #func, num, buf); \
    error++;\
  }\
}

#define u8_to_str_check(num) to_str_check(num, 8, "hhu", u8_to_str)
#define i8_to_str_check(num) to_str_check(num, 8, "hhi", i8_to_str)
#define u16_to_str_check(num) to_str_check(num, 16, "hu", u16_to_str)
#define i16_to_str_check(num) to_str_check(num, 16, "hi", i16_to_str)
#define u32_to_str_check(num) to_str_check(num, 32, "u", u32_to_str)
#define i32_to_str_check(num) to_str_check(num, 32, "i", i32_to_str)
#define u64_to_str_check(num) to_str_check(num, 64, "lu", u64_to_str)
#define i64_to_str_check(num) to_str_check(num, 64, "li", i64_to_str)

#define to_str_check_many(amt, type, func) for (int i = 0; i < amt; i++) { int x = rand() - 0xdeadbeef; func((type)x); }

#define u8_to_str_check_many(amt) to_str_check_many(amt, uint8_t, u8_to_str_check)
#define i8_to_str_check_many(amt) to_str_check_many(amt, int8_t, i8_to_str_check)
#define u16_to_str_check_many(amt) to_str_check_many(amt, uint16_t, u16_to_str_check)
#define i16_to_str_check_many(amt) to_str_check_many(amt, int16_t, i16_to_str_check)
#define u32_to_str_check_many(amt) to_str_check_many(amt, uint32_t, u32_to_str_check)
#define i32_to_str_check_many(amt) to_str_check_many(amt, int32_t, i32_to_str_check)
#define u64_to_str_check_many(amt) to_str_check_many(amt, uint64_t, u64_to_str_check)
#define i64_to_str_check_many(amt) to_str_check_many(amt, int64_t, i64_to_str_check)

int
main() {
  int error = 0;
  const int checks_per_type = 1000000;

  u8_to_str_check_many(checks_per_type);
  i8_to_str_check_many(checks_per_type);
  u16_to_str_check_many(checks_per_type);
  i16_to_str_check_many(checks_per_type);
  u32_to_str_check_many(checks_per_type);
  i32_to_str_check_many(checks_per_type);
  u64_to_str_check_many(checks_per_type);
  i64_to_str_check_many(checks_per_type);

  u8_to_str_check(255);
  i8_to_str_check(127);
  i8_to_str_check(-128);
  u16_to_str_check(65535);
  i16_to_str_check(32767);
  i16_to_str_check(-32768);
  u32_to_str_check(4294967295);
  i32_to_str_check(2147483647);
  i32_to_str_check(-2147483648);
  u64_to_str_check(18446744073709551615ull);
  i64_to_str_check(9223372036854775807ll);
  i64_to_str_check(-9223372036854775808ull);

  return error;
}
