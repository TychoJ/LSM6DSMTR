/*  LSM6DSMTR
 *  ^^^^^^^^^
 *  Author  	: TychoJ
 *
 *  File	: LSM6DSMTR.c
 *  Contains	: The configurations for make.avr.mk *
 *  MIT License
 *
 *  Copyright (c) 20223 TychoJ
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#include "LSM6DSMTR.h"



/*
 * Register addres defines
 */

#define WHO_AM_I_REG 	0x0F
#define WHO_AM_I	0x6A

// Enable embedded functions register
#define FUNC_CFG_ACCESS 0x01

// Sensor sync time frame register
#define SENSOR_SYNC_TIME_FRAME 0x04

// Sensor sync resolution ratio
#define SENSOR_SYNC_RES_RATIO  0x05

// FiFo control registers
#define FIFO_CTRL1 0x06
#define FIFO_CTRL2 0x07
#define FIFO_CTRL3 0x08
#define FIFO_CTRL4 0x09
#define FIFO_CTRL5 0x0A

// Data ready config register
#define DRDY_PULSE_CFG 0x0B

// INT 1/2 controll registers
#define INT1_CTRL 0x0D
#define INT2_CTRL 0x0E

#define CTRL1_XL 0x10
#define CTRL2_G  0x11
#define CTRL3_C  0x12
#define CTRL4_C  0x13
#define CTRL5_C  0x14
#define CTRL6_C  0x15
#define CTRL7_G  0x16
#define CTRL8_XL 0x17
#define CTRL9_XL 0x18
#define CTRL10_C 0x19

#define MASTER_CONFIG 0x1A

#define WAKE_UP_SRC   0x1B
#define TAP_SRC       0x1C
#define D6D_SRC       0x1D

#define STATUS_REG    0x1E
#define STATUS_SPIAux 0x1E

#define OUT_TEMP_L      0x20
#define OUT_TEMP_H      0x21
#define OUTX_L_G        0x22
#define OUTX_H_G        0x23
#define OUTY_L_G        0x24
#define OUTY_H_G        0x25
#define OUTZ_L_G        0x26
#define OUTZ_H_G        0x27
#define OUTX_L_XL       0x28
#define OUTX_H_XL       0x29
#define OUTY_L_XL       0x2A
#define OUTY_H_XL       0x2B
#define OUTZ_L_XL       0x2C
#define OUTZ_H_XL       0x2D

// Sensor hub defines
#define SENSORHUB1_REG  0x2E
#define SENSORHUB2_REG  0x2F
#define SENSORHUB3_REG  0x30
#define SENSORHUB4_REG  0x31
#define SENSORHUB5_REG  0x32
#define SENSORHUB6_REG  0x33
#define SENSORHUB7_REG  0x34
#define SENSORHUB8_REG  0x35
#define SENSORHUB9_REG  0x36
#define SENSORHUB10_REG 0x37
#define SENSORHUB11_REG 0x38
#define SENSORHUB12_REG 0x39

// Fifo status registers
#define FIFO_STATUS1 0x3A
#define FIFO_STATUS2 0x3B
#define FIFO_STATUS3 0x3C
#define FIFO_STATUS4 0x3D

// FIFO data out registers
#define FIFO_DATA_OUT_L 0x3E
#define FIFO_DATA_OUT_H 0x3F

// Time stamp registers
#define TIMESTAMP0_REG 0x40
#define TIMESTAMP1_REG 0x41
#define TIMESTAMP2_REG 0x42

// Step Time stamp registers
#define STEP_TIMESTAMP_L 0x49
#define STEP_TIMESTAMP_H 0x4A

// Step counter registers
#define STEP_COUNTER_L 0x4B
#define STEP_COUNTER_H 0x4C

// Sensor hub registers 13 - 18
#define SENSORHUB13_REG 0x4D
#define SENSORHUB14_REG 0x4E
#define SENSORHUB15_REG 0x4F
#define SENSORHUB16_REG 0x50
#define SENSORHUB17_REG 0x51
#define SENSORHUB18_REG 0x52

// Significant (motion) interupt registers
#define FUNC_SRC1 0x53
#define FUNC_SRC2 0x54

// Wrist tilt event detection register
#define WRIST_TILT_IA 0x55

// Enable interupts
#define TAP_CFG 0x58

// Register to set sensitivity of embedded functions
#define TAP_THS_6D  0x59
#define INT_DUR2    0x5A
#define WAKE_UP_THS 0x5B
#define WAKE_UP_DUR 0x5C
#define FREE_FALL   0x5D

// Route int 1 and 2 register
#define MD1_CFG 0x5E
#define MD2_CFG 0x5F

// Registers for stuff
#define MASTER_CMD_CODE          0x60
#define SENS_SYNC_SPI_ERROR_CODE 0x61
#define OUT_MAG_RAW_X_L          0x66
#define OUT_MAG_RAW_X_H          0x67
#define OUT_MAG_RAW_Y_L          0x68
#define OUT_MAG_RAW_Y_H          0x69
#define OUT_MAG_RAW_Z_L          0x6A
#define OUT_MAG_RAW_Z_H          0x6B
#define INT_OIS                  0x6F
#define CTRL1_OIS                0x70
#define CTRL2_OIS                0x71
#define CTRL3_OIS                0x72

// User settable accel offset registers
#define X_OFS_USR 0x73
#define Y_OFS_USR 0x74
#define Z_OFS_USR 0x75

/*
 * Bit precision of settings in register defines
 */

// FUNC_CFG_ACCESS
#define FUNC_CFG_EN_bp   7
#define FUNC_CFG_EN_B_bp 5

// SENSOR_SYNC_TIME_FRAME
#define SEN_SYNC_TIME_FRAME_bp 0

// SENSOR_SYNC_RES_RATIO
#define SEN_SYNC_RES_RATIO_bp 0

// FIFO_CTRL2
#define TIMER_PEDO_FIFO_EN_bp   7
#define TIMER_PEDO_FIFO_DRDY_bp 6
#define FIFO_TEMP_EN_bp         3
#define FTH_bp                  0

// FIFO_CTRL3
#define DEC_FIFO_GYRO_bp 3
#define DEC_FIFO_XL_bp   0

// FIFO_CTRL4
#define STOP_ON_FTH_bp      7
#define ONLY_HIGH_DATA_bp   6
#define DEC_DS4_FIFO_bp     3
#define DEC_DS3_FIFO_bp     0

// FIFO_CTRL5
#define ODR_FIFO_bp     3
#define FIFO_MODE_bp    0

// DRDY_PULSE_CFG
#define DRDY_PULSED_bp      7
#define INT2_WRIST_TILT_bp  0

// INT1_CTRL
#define INT1_STEP_DETECTOR_bp   7
#define INT1_SIGN_MOT_bp        6
#define INT1_FULL_FLAG_bp       5
#define INT1_FIFO_OVR_bp        4
#define INT1_FTH_bp             3
#define INT1_BOOT_bp            2
#define INT1_DRDY_G_bp          1
#define INT1_DRDY_XL_bp         0

// INT2_CTRL
#define INT2_STEP_DELTA_bp      7
#define INT2_STEP_COUNT_OV_bp   6
#define INT2_FULL_FLAG_bp       5
#define INT2_FIFO_OVR_bp        4
#define INT2_FTH_bp             3
#define INT2_DRDY_TEMP_bp       2
#define INT2_DRDY_G_bp          1
#define INT2_DRDY_XL_bp         0

// CTRL1_XL
#define ODR_XL_bp       4
#define FS_XL_bp        2
#define LPF1_BW_SEL_bp  1
#define BW0_XL_bp       0

// CTRL2_G
#define ODR_G_bp    4
#define FS_G_bp     2
#define FS_125_bp   1

// CTRL3_C
#define BOOT_bp         7
#define BDU_bp          6
#define H_LACTIVE_bp    5
#define PP_OD_bp        4
#define SIM_bp          3
#define IF_INC_bp       2
#define BLE_bp          1
#define SW_RESET_bp     0

// CTRL4_C
#define DEN_XL_EN_bp        7
#define SLEEP_G_bp          6
#define INT2_on_INT1_bp     5
#define DEN_DRDY_INT1_bp    4
#define DRDY_MASK_bp        3
#define I2C_disable_bp      2
#define LPF1_SEL_G_bp       1

// CTRL5_C
#define ROUNDING_bp     5
#define DEN_LH_bp       4
#define ST_G_bp         2
#define ST_XL_bp        0

// CTRL6_C
#define TRIG_EN_bp      7
#define LVL1_EN_bp      6
#define LVL2_EN_bp      5
#define XL_HM_MODE_bp   4
#define USR_OFF_W_bp    3
#define FTYPE_bp        0

// CTRL7_G
#define G_HM_MODE_bp    	7
#define HP_EN_G_bp      	6
#define HPM_G_bp        	4
#define ROUNDING_STATUS_bp 	2

// CTRL8_XL
#define LPF2_XL_EN_bp       7
#define HPCF_XL_bp          5
#define HP_REF_MODE_bp      4
#define INPUT_COMPOSITE_bp  3
#define HP_SLOPE_XL_EN_bp   2
#define LOW_PASS_ON_6D_bp   0

// CTRL9_XL
#define DEN_X_bp    7
#define DEN_Y_bp    6
#define DEN_Z_bp    5
#define DEN_XL_G_bp 4
#define SOFT_EN_bp  2

// CTRL10_C
#define WRIST_TILT_EN_bp    7
#define TIMER_EN_bp         5
#define PEDO_EN_bp          4
#define TILT_EN_bp          3
#define FUNC_EN_bp          2
#define PEDO_RST_STEP_bp    1
#define SIGN_MOTION_EN_bp   0

// MASTER_CONFIG
#define DRDY_ON_INT1_bp         7
#define DATA_VALID_SEL_FIFO_bp  6
#define START_CONFIG_bp         4
#define PULL_UP_EN_bp           3
#define PASS_THROUGH_MODE_bp    2
#define IRON_EN_bp              1
#define MASTER_ON_bp            0

// WAKE_UP_SRC
#define FF_IA_bp            5
#define SLEEP_STATE_IA_bp   4
#define WU_IA_bp            3
#define X_WU_bp             2
#define Y_WU_bp             1
#define Z_WU_bp             0

// TAP_SRC
#define TAP_IA_bp       6
#define SINGLE_TAP_bp   5
#define DOUBLE_TAP_bp   4
#define TAP_SIGN_bp     3
#define X_TAP_bp        2
#define Y_TAP_bp        1
#define Z_TAP_bp        0

// D6D_SRC
#define DEN_DRDY_bp     7
#define D6D_IA_bp       6
#define ZH_bp           5
#define ZL_bp           4
#define YH_bp           3
#define YL_bp           2
#define XH_bp           1
#define XL_bp           0

// STATUS_REG
#define TDA_bp  2
#define GDA_bp  1
#define XLDA_bp 0


/*
 * Group control defines
 */

// FIFO_CTRL3 "DEC_FIFO_GYRO"
#define GYRO_NOT_IN_FIFO_gc             0x00
#define GYRO_NO_DECIMATION_FIFO_gc      0x01
#define GYRO_2X_DECIMATION_FIFO_gc      0x02
#define GYRO_3X_DECIMATION_FIFO_gc      0x03
#define GYRO_4X_DECIMATION_FIFO_gc      0x04
#define GYRO_8X_DECIMATION_FIFO_gc      0x05
#define GYRO_16X_DECIMATION_FIFO_gc     0x06
#define GYRO_32X_DECIMATION_FIFO_gc     0x07

// FIFO_CTRL3 "DEC_FIFO_XL"
#define XL_NOT_IN_FIFO_gc               0x00
#define XL_NO_DECIMATION_FIFO_gc        0x01
#define XL_2X_DECIMATION_FIFO_gc        0x02
#define XL_3X_DECIMATION_FIFO_gc        0x03
#define XL_4X_DECIMATION_FIFO_gc        0x04
#define XL_8X_DECIMATION_FIFO_gc        0x05
#define XL_16X_DECIMATION_FIFO_gc       0x06
#define XL_32X_DECIMATION_FIFO_gc       0x07

// FIFO_CTRL4 "DEC_DS4_FIFO"
#define DS4_NOT_IN_FIFO_gc              0x00
#define DS4_NO_DECIMATION_FIFO_gc       0x01
#define DS4_2X_DECIMATION_FIFO_gc       0x02
#define DS4_3X_DECIMATION_FIFO_gc       0x03
#define DS4_4X_DECIMATION_FIFO_gc       0x04
#define DS4_8X_DECIMATION_FIFO_gc       0x05
#define DS4_16X_DECIMATION_FIFO_gc      0x06
#define DS4_32X_DECIMATION_FIFO_gc      0x07

// FIFO_CTRL4 "DEC_DS3_FIFO"
#define DS3_NOT_IN_FIFO_gc              0x00
#define DS3_NO_DECIMATION_FIFO_gc       0x01
#define DS3_2X_DECIMATION_FIFO_gc       0x02
#define DS3_3X_DECIMATION_FIFO_gc       0x03
#define DS3_4X_DECIMATION_FIFO_gc       0x04
#define DS3_8X_DECIMATION_FIFO_gc       0x05
#define DS3_16X_DECIMATION_FIFO_gc      0x06
#define DS3_32X_DECIMATION_FIFO_gc      0x07

// FIFO_CTRL5 "ODR_FIFO"
#define FIFO_DISABLE_gc     0x00
#define FIFO_ODR_12_5Hz_gc  0x01
#define FIFO_ODR_26Hz_gc    0x02
#define FIFO_ODR_52Hz_gc    0x03
#define FIFO_ODR_104Hz_gc   0x04
#define FIFO_ODR_208Hz_gc   0x05
#define FIFO_ODR_416Hz_gc   0x06
#define FIFO_ODR_833Hz_gc   0x07
#define FIFO_ODR_1K66Hz_gc  0x08
#define FIFO_ODR_3K33Hz_gc  0x09
#define FIFO_ODR_6K66Hz_gc  0x0A

// FIFO_CTRL5 "FIFO_MODE"
#define FIFO_DISABLED_gc                            0x00
#define FIFO_STOP_WHEN_OVERFLOWING_gc               0x01
#define FIFO_CONTINUES_UNTIL_TRIGGER_THEN_FIFO_gc   0x03
#define FIFO_BYPASS_UNTIL_TRIGGER_THEN_CONTINUES_gc 0x04
#define FIFO_CONTINUES_WHEN_OVERFLOW_OVERWRITE_gc   0x06

// CTRL5_C "ROUNDING"
#define NO_ROUNDING_gc  0x00
#define XL_ONLY_gc      0x01
#define G_ONLY_gc       0x02
#define XL_AND_G_gc     0x03

// CTRL5_C "ST_G"
#define G_SELF_TEST_NORMAL_gc           0x00
#define G_POSITIVE_SIGN_SELF_TEST_gc    0x01
#define G_NEGATIVE_SIGN_SELF_TEST_gc    0x03

// CTRL5_C "ST_XL"
#define XL_SELF_TEST_NORMAL_gc          0x00
#define XL_POSITIVE_SIGN_SELF_TEST_gc   0x01
#define XL_NEGATIVE_SIGN_SELF_TEST_gc   0x02

// CTRL6_C "Trigger mode"
#define TRIGGER_MODE_EDGE_SENSITIVE_gc                  0x04
#define TRIGGER_MODE_LEVEL_SENSITIVE_gc                 0x02
#define TRIGGER_MODE_LEVEL_SENSITIVE_LATCHED_gc         0x03
#define TRIGGER_MODE_LEVEL_SENSITIVE_FIFO_ENABLED_gc    0x06

// CTRL6_C "FILTER_TYPES"
#define G_FILTER_TYPE_0_gc              0x00
#define G_FILTER_TYPE_1_gc              0x01
#define G_FILTER_TYPE_2_gc              0x02
#define G_FILTER_TYPE_3_gc              0x03

// CTRL1_OIS "DEN MODE"
#define DEN_TRIGGER_MODE_gc             0x02
#define DEN_LATCHED_MODE_gc             0x03

// CTRL2_OIS "G OIS CHAIN BANDWIDTH"
#define G_BANDWIDTH_TYPE_0_gc           0x00
#define G_BANDWIDTH_TYPE_1_gc           0x01
#define G_BANDWIDTH_TYPE_2_gc           0x02
#define G_BANDWIDTH_TYPE_3_gc           0x03

// CTRL3_OIS "XL OIS CHANNEL BANDWIDTH"
#define XL_BANDWIDTH_TYPE_0_gc          0x00
#define XL_BANDWIDTH_TYPE_1_gc          0x01
#define XL_BANDWIDTH_TYPE_2_gc          0x02
#define XL_BANDWIDTH_TYPE_3_gc          0x03

/*
*   BIT MASKS
*/ 

// FUNC_CFG_ACCESS MASK
#define MSK_FUNC_CFG_EN                 0b10000000
#define MSK_FUNC_CFG_EN_B               0b00100000

// SENSOR_SYNC_TIME_FRAME MASK
#define MSK_SENSOR_SYNC_TIME_FRAME      0b00001111

// SENSOR_SYNC_RES_RATIO MASK
#define MSK_SENSOR_SYNC_RES_RATIO       0b00000011

// FIFO_CTRL1 MASK
#define MSK_FIFO_CTRL1_FTH              0b11111111

// FIFO_CTRL2 MASK
#define MSK_TIMER_PEDO_FIFO_EN          0b10000000
#define MSK_TIMER_PEDO_FIFO_DRDY        0b01000000
#define MSK_FIFO_TEMP_EN                0b00001000
#define MSK_FIFO_CTRL2_FTH              0b00000111

// FIFO_CTRL3 MASK
#define MSK_DEC_FIFO_GYRO               0b00111000
#define MSK_DEC_FIFO_XL                 0b00000111

// FIFO_CTRL4 MASK
#define MSK_STOP_ON_FTH                 0b10000000
#define MSK_ONLY_HIGH_DATA              0b01000000
#define MSK_DEC_DS4_FIFO                0b00111000
#define MSK_DEC_DS3_FIFO                0b00000111

// FIFO_CTRL5 MASK
#define MSK_ODR_FIFO                    0b01111000
#define MSK_FIFO_MODE                   0b00000111

// DRDY_PULSE_CFG MASK
#define MSK_DRDY_PULSE_CFG              0b10000000
#define MSK_INT2_WRIST_TILT             0b00000001

// INT1_CTRL MASK
#define MSK_INT1_STEP_DETECTOR          0b10000000
#define MSK_INT1_SIGN_MOT               0b01000000
#define MSK_INT1_FULL_FLAG              0b00100000
#define MSK_INT1_FIFO_OVR               0b00010000
#define MSK_INT1_FTH                    0b00001000
#define MSK_INT1_BOOT                   0b00000100
#define INT1_DRDY_G                     0b00000010
#define INT1_DRDY_XL                    0b00000001

// INT2_CTRL MASK
#define MSK_INT2_STEP_DELTA             0b10000000
#define MSK_INT2_STEP_COUNT_OV          0b01000000
#define MSK_INT2_FULL_FLAG              0b00100000
#define MSK_INT2_FIFO_OVR               0b00010000
#define MSK_INT2_FTH                    0b00001000
#define MSK_INT2_DRDY_TEMP              0b00000100
#define MSK_INT2_DRDY_G                 0b00000010
#define MSK_INT2_DRDY_XL                0b00000001

// CTRL1_XL MASK
#define MSK_ODR_XL                      0b11110000
#define MSK_FS_XL                       0b00001100
#define MSK_LPF1_BW_SEL                 0b00000010
#define MSK_BW0_XL                      0b00000001

// CTRL2_G MASK
#define MSK_ODR_G                       0b11110000
#define MSK_FS_G                        0b00001100
#define MSK_FS_125                      0b00000010

// CTRL3_C MASK
#define MSK_BOOT                        0b10000000
#define MSK_BDU                         0b01000000
#define MSK_H_LACTIVE                   0b00100000
#define MSK_PP_OD                       0b00010000
#define MSK_SIM                         0b00001000
#define MSK_IF_INC                      0b00000100
#define MSK_BLE                         0b00000010
#define MSK_SW_RESET                    0b00000001

// CTRL4_C MASK
#define MSK_DEN_XL_EN                   0b10000000
#define MSK_SLEEP                       0b01000000
#define MSK_INT2_on_INT1                0b00100000
#define MSK_DEN_DRDY_INT1               0b00010000
#define MSK_DRDY_MASK                   0b00001000
#define MSK_I2C_disable                 0b00000100
#define MSK_LPF1_SEL_G                  0b00000010

// CTRL5_C MASK
#define MSK_ROUNDING                    0b11100000
#define MSK_DEN_LH                      0b00010000
#define MSK_ST_G                        0b00001100
#define MSK_ST_XL                       0b00000011

// CTRL6_C MASK
#define MSK_TRIG_EN                     0b10000000
#define MSK_LVL1_EN                     0b01000000
#define MSK_LVL2_EN                     0b00100000
#define MSK_XL_HM_MODE                  0b00010000
#define MSK_USR_OFF_W                   0b00001000
#define MSK_FTYPE                       0b00000011

// CTRL7_G MASK
#define MSK_G_HM_MODE                   0b10000000
#define MSK_HP_EN_G                     0b01000000
#define MSK_HPM_G                       0b00110000
#define MSK_ROUNDING_STATUS             0b00000100

// CTRL8_XL MASK
#define MSK_LPF2_XL_EN                  0b10000000
#define MSK_HPCF_XL                     0b01100000
#define MSK_HP_REF_MODE                 0b00010000
#define MSK_INPUT_COMPOSITE             0b00001000
#define MSK_HP_SLOPE_XL_EN              0b00000100
#define MSK_LOW_PASS_ON_6D              0b00000001

// CTRL9_XL MASK
#define MSK_DEN_X                       0b10000000
#define MSK_DEN_Y                       0b01000000
#define MSK_DEN_Z                       0b00100000
#define MSK_DEN_XL_G                    0b00010000
#define MSK_SOFT_EN                     0b00000100

// CTRL10_C MASK
#define MSK_WRIST_TILT_EN               0b10000000
#define MSK_TIMER_EN                    0b00100000
#define MSK_PEDO_EN                     0b00010000
#define MSK_TILT_EN                     0b00001000
#define MSK_FUNC_EN                     0b00000100
#define MSK_PEDO_RST_STEP               0b00000010
#define MSK_SIGN_MOTION_EN              0b00000001

// MASTER_CONFIG MASK
#define MSK_DRDY_ON_INT1                0b10000000
#define MSK_DATA_VALID_SEL_FIFO         0b01000000
#define MSK_START_CONFIG                0b00010000
#define MSK_PULL_UP_EN                  0b00001000
#define MSK_PASS_THROUGH_MODE           0b00000100
#define MSK_IRON_EN                     0b00000010
#define MSK_MASTER_ON                   0b00000001


uint8_t whoAmI(LSM6DSMTR_t device) {
    uint8_t ret;
    uint8_t value;

    ret = device.readFromRegister(device.twi, device.addr, &value, WHO_AM_I_REG);

    if (value == WHO_AM_I && ret == 5) ret = 0;
    else ret = 1;

    return ret;
}
