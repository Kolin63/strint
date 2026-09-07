#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <strint.h>

#define str_to_check(num, bits, fmt, func) {\
  char str[128];\
  snprintf(str, sizeof(str), "%" fmt, num);\
  if (func (str, NULL) == num) printf("\e[0;92mpass: %s(\"%s\")\e[0m\n", #func, str);\
  else {\
    printf("\e[1;91mfail: %s(\"%s\") -> %i\n\e[0m", #func, str, func (str, NULL)); \
    error++;\
  }\
}

#define str_to_u8_check(num) str_to_check(num, 8, "hhu", str_to_u8)
#define str_to_i8_check(num) str_to_check(num, 8, "hhi", str_to_i8)
#define str_to_u16_check(num) str_to_check(num, 16, "hu", str_to_u16)
#define str_to_i16_check(num) str_to_check(num, 16, "hi", str_to_i16)
#define str_to_u32_check(num) str_to_check(num, 32, "u", str_to_u32)
#define str_to_i32_check(num) str_to_check(num, 32, "i", str_to_i32)
#define str_to_u64_check(num) str_to_check(num, 64, "lu", str_to_u64)
#define str_to_i64_check(num) str_to_check(num, 64, "li", str_to_i64)

#define str_to_check_many(amt, type, func) for (int i = 0; i < amt; i++) { int x = rand() - 0xdeadbeef; func((type)x); }

#define str_to_u8_check_many(amt) str_to_check_many(amt, uint8_t, str_to_u8_check)
#define str_to_i8_check_many(amt) str_to_check_many(amt, int8_t, str_to_i8_check)
#define str_to_u16_check_many(amt) str_to_check_many(amt, uint16_t, str_to_u16_check)
#define str_to_i16_check_many(amt) str_to_check_many(amt, int16_t, str_to_i16_check)
#define str_to_u32_check_many(amt) str_to_check_many(amt, uint32_t, str_to_u32_check)
#define str_to_i32_check_many(amt) str_to_check_many(amt, int32_t, str_to_i32_check)
#define str_to_u64_check_many(amt) str_to_check_many(amt, uint64_t, str_to_u64_check)
#define str_to_i64_check_many(amt) str_to_check_many(amt, int64_t, str_to_i64_check)

int
main() {
  int error = 0;
  const int checks_per_type = 1000000;

  str_to_u8_check_many(checks_per_type);
  str_to_i8_check_many(checks_per_type);
  str_to_u16_check_many(checks_per_type);
  str_to_i16_check_many(checks_per_type);
  str_to_u32_check_many(checks_per_type);
  str_to_i32_check_many(checks_per_type);
  str_to_u64_check_many(checks_per_type);
  str_to_i64_check_many(checks_per_type);

  str_to_u8_check(255);
  str_to_i8_check(127);
  str_to_i8_check(-128);
  str_to_u16_check(65535);
  str_to_i16_check(32767);
  str_to_i16_check(-32768);
  str_to_u32_check(4294967295);
  str_to_i32_check(2147483647);
  str_to_i32_check(-2147483648);
  str_to_u64_check(18446744073709551615ull);
  str_to_i64_check(9223372036854775807ll);
  str_to_i64_check(-9223372036854775808ull);

  return error;
}
