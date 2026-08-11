#pragma once

#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct range_nfd {
    uint32_t first;
    uint32_t last;
    uint32_t nfd;
};

// 一个字节     00xx                            U+0000 ~ U+007F
// 二个字节     110xxxxx 10xxxxxx               U+0080 ~ U+07FF
// 三个字节     1110xxxx 10xxxxxx 10xxxxxx      U+0800 ~ U+FFFF
// 四个字节     11110xxx 10xxxxxx 10xxxxxx      U+10000 ~ U+10FFFF
// code point 当前上界为 0x110000
static const uint32_t MAX_CODEPOINTS = 0x110000;

extern const std::initializer_list<std::pair<uint32_t, uint16_t>> unicode_ranges_flags;
extern const std::unordered_set<uint32_t> unicode_set_whitespace;
extern const std::initializer_list<std::pair<uint32_t, uint32_t>> unicode_map_lowercase;
extern const std::initializer_list<std::pair<uint32_t, uint32_t>> unicode_map_uppercase;
extern const std::initializer_list<range_nfd> unicode_ranges_nfd;
