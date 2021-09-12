#ifndef KB_H
#define KB_H

#include "quantum.h"

#define LAYOUT(                                                                       \
	      K001, K002, K003,       K005,       K007, K008,       K010,       K012,       K014,       \
	      K101, K102, K103, K104, K105, K106, K107, K108, K109,                   K113, K114, K115, \
	      K201, K202, K203, K204, K205, K206, K207, K208,                                           \
	      K301, K302, K303, K304, K305, K306, K307, K308,             K311, K312, K313, K314, K315, \
	      K401, K402, K403, K404, K405, K406, K407, K408,                   K412,       K414, K415, \
	K500, K501, K502, K503, K504, K505, K506,       K508, K509,                         K514, K515, \
	            K602,             K605,       K607,             K610, K611, K612, K613, K614, K615, \
	K700, K701, K702, K703, K704, K705, K706, K707, K708,             K711,             K714  \
) { \
	{ KC_NO, K001,  K002,  K003,  KC_NO, K005,  KC_NO, K007,  K008,  KC_NO, K010,  KC_NO, K012,  KC_NO, K014,  KC_NO }, \
	{ KC_NO, K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  KC_NO, KC_NO, KC_NO, K113,  K114,  K115 }, \
	{ KC_NO, K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
	{ KC_NO, K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  KC_NO, KC_NO, K311,  K312,  K313,  K314,  K315 }, \
	{ KC_NO, K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  KC_NO, KC_NO, KC_NO, K412,  KC_NO, K414,  K415 }, \
	{ K500,  K501,  K502,  K503,  K504,  K505,  K506,  KC_NO, K508,  K509,  KC_NO, KC_NO, KC_NO, KC_NO, K514,  K515 }, \
	{ KC_NO, KC_NO, K602,  KC_NO, KC_NO, K605,  KC_NO, K607,  KC_NO, KC_NO, K610,  K611,  K612,  K613,  K614,  K615 }, \
	{ K700,  K701,  K702,  K703,  K704,  K705,  K706,  K707,  K708,  KC_NO, KC_NO, K711,  KC_NO, KC_NO, K714,  KC_NO }  \
}

#endif
