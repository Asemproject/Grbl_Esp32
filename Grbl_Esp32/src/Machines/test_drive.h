#pragma once
// clang-format off

/*
4axis_external_driver.h
Adapted for Wemos D1 R32 (ESP32) to match CNC Shield V3 physical pinout
(Arduino D2..D13, A0..A5) mapping for Wemos D1 R32.

Notes:
 - D2..D7 mapped to X/Y/Z step & dir
 - D8 mapped to steppers enable (GPIO12) — WARNING: GPIO12 is a boot-strap pin.
   Remove R1 (pull-up on EN) on the CNC Shield or move STEPPERS_DISABLE_PIN if you
   experience boot issues.
 - 4th axis (A) mapped to D9/D10 to avoid conflict with D11 (spindle) where possible.
 - Limit pins use ESP32 ADC pins (A2..A5) where appropriate (input-only pins).
*/

$ifdef CPU_MAP_ESP32DUINO32_CNCSHIELD
// This is the CPU Map for the ESP32 CNC SHIELD Controller

// It is OK to comment out any step and direction pins. This
// won’t affect operation except that there will be no output
// form the pins. Grbl will virtually move the axis. This could
// be handy if you are using a servo, etc. for another axis.
#define X_STEP_PIN GPIO_NUM_26
#define Y_STEP_PIN GPIO_NUM_25
#define Z_STEP_PIN GPIO_NUM_17

#define X_DIRECTION_PIN GPIO_NUM_16
#define Y_DIRECTION_PIN GPIO_NUM_27
#define Z_DIRECTION_PIN GPIO_NUM_14

// OK to comment out to use pin for other features
#define STEPPERS_DISABLE_PIN GPIO_NUM_12

// *** the flood coolant feature code is activated by defining this pins
// *** Comment it out to use the pin for other features
//#define COOLANT_FLOOD_PIN GPIO_NUM_34
//#define COOLANT_MIST_PIN GPIO_NUM_21

// If SPINDLE_PWM_PIN is commented out, this frees up the pin, but Grbl will still
// use a virtual spindle. Do not comment out the other parameters for the spindle.
#define SPINDLE_PWM_PIN GPIO_NUM_19
#define SPINDLE_PWM_CHANNEL 0
// PWM Generator is based on 80,000,000 Hz counter
// Therefor the freq determines the resolution
// 80,000,000 / freq = max resolution
// For 5000 that is 80,000,000 / 5000 = 16000
// round down to nearest bit count for SPINDLE_PWM_MAX_VALUE = 13bits (8192)
#define SPINDLE_PWM_BASE_FREQ 5000 // Hz
#define SPINDLE_PWM_BIT_PRECISION 8 // be sure to match this with SPINDLE_PWM_MAX_VALUE
#define SPINDLE_PWM_OFF_VALUE 0
#define SPINDLE_PWM_MAX_VALUE 255 // (2^SPINDLE_PWM_BIT_PRECISION)

Advertisement

#ifndef SPINDLE_PWM_MIN_VALUE
#define SPINDLE_PWM_MIN_VALUE 1 // Must be greater than zero.
#endif

#define SPINDLE_PWM_RANGE (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)

// if these spindle function pins are defined, they will be activated in the code
// comment them out to use the pins for other functions
//#define SPINDLE_ENABLE_PIN GPIO_NUM_16
//#define SPINDLE_DIR_PIN GPIO_NUM_16

#define X_LIMIT_PIN GPIO_NUM_13
#define Y_LIMIT_PIN GPIO_NUM_5
#define Z_LIMIT_PIN GPIO_NUM_23
#define LIMIT_MASK B111

#define PROBE_PIN GPIO_NUM_36

//#define CONTROL_SAFETY_DOOR_PIN GPIO_NUM_39 // needs external pullup
#define CONTROL_RESET_PIN GPIO_NUM_2 // needs external pullup
#define CONTROL_FEED_HOLD_PIN GPIO_NUM_4 // needs external pullup
#define CONTROL_CYCLE_START_PIN GPIO_NUM_35 // needs external pullup

#endif
