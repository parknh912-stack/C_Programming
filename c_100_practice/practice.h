#pragma once

// 실행할 파트와 문제 번호를 선택하세요.
#define PART 1
#define PROBLEM 5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#if PART < 1 || PART > 5
#error Invalid PART: choose 1 to 5.
#endif
#if PROBLEM < 1 || (PART == 1 && PROBLEM > 25) || (PART == 2 && PROBLEM > 24) || (PART == 3 && PROBLEM > 20) || (PART == 4 && PROBLEM > 18) || (PART == 5 && PROBLEM > 13)
#error Invalid PROBLEM for the selected PART.
#endif
