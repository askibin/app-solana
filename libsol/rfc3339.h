#pragma once

#include <stdint.h>

int rfc3339_format(char *dst, size_t len, uint64_t seconds);
