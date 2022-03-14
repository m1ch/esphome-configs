#ifndef helpers_h
#define helpers_h

#include "esphome.h"

#define PAGEMAIN     0
#define PAGESWITCHES 1
#define PAGEALARMS   2
#define PAGECLOCK    3
#define PAGELAST     4

#define INPUTSMAINTEMPERATURE   0
#define INPUTSMAINHUMIDITY      1
#define INPUTSMAINLAST          2

#define INPUTSSWITCHES0         0
#define INPUTSSWITCHES1         1
#define INPUTSSWITCHES2         2
#define INPUTSSWITCHES3         3
#define INPUTSSWITCHES4         4
#define INPUTSSWITCHES5         5
#define INPUTSSWITCHES6         6
#define INPUTSSWITCHES7         7
#define INPUTSSWITCHES8         8
#define INPUTSSWITCHESLAST      9


// enum PAGES {PAGEmain, PAGEswitches, PAGEalarms, PAGEclock, PAGELAST}; // eink42_page = PAGEmain;
// inline PAGES& operator++(PAGES& x, int) {
//     const int i = static_cast<int>(x)+1;
//     const PAGES last = PAGELAST;
//     x = static_cast<PAGES>((i) % static_cast<int>(last));
//     return x;
// }

// enum INPUTSMAIN {INPUTSMAINtemperature, INPUTSMAINhumidity, INPUTSMAINLAST} input_select_main = INPUTSMAINtemperature;
// inline INPUTSMAIN& operator++(INPUTSMAIN& x, int) {
//     const int i = static_cast<int>(x)+1;
//     const INPUTSMAIN last = INPUTSMAINLAST;
//     x = static_cast<INPUTSMAIN>((i) % static_cast<int>(last));
//     return x;
// }

// enum INPUTSSWITCHES {INPUTSSWITCHES0, INPUTSSWITCHES1, INPUTSSWITCHES2, 
//                      INPUTSSWITCHES3, INPUTSSWITCHES4, INPUTSSWITCHES5, 
//                      INPUTSSWITCHES6, INPUTSSWITCHES7, INPUTSSWITCHES8, 
//                      INPUTSSWITCHESLAST} input_select_switches = INPUTSSWITCHES0;
// inline INPUTSSWITCHES& operator++(INPUTSSWITCHES& x, int) {
//     const int i = static_cast<int>(x)+1;
//     const INPUTSSWITCHES last = INPUTSSWITCHESLAST;
//     x = static_cast<INPUTSSWITCHES>((i) % static_cast<int>(last));
//     return x;
// }

// enum STATE {STATE_1, STATE_2, STATE_3, STATE_4, STATE_5, STATE_6, LAST};
// inline STATE& operator++(STATE& state, int) {
//     const int i = static_cast<int>(state)+1;
//     const STATE x = LAST;
//     state = static_cast<STATE>((i) % static_cast<int>(x));
//     return state;
// }

// enum mode77_t:uint8_t{
//     SETTEMP,
//     SETHUM,
//     LAST77
// } mode77;
// inline mode77_t& operator++(mode77_t& state, int) {
//     const int i = static_cast<int>(state)+1;
//     const mode77_t x = LAST77;
//     state = static_cast<mode77_t>((i) % static_cast<int>(x));
//     return state;
// }

// void test23(){
//     STATE xxx = STATE_1;
//     xxx++;
// }

#endif //helpers_h
