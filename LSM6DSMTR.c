/*  LSM6DSMTR
 *  ^^^^^^^^^
 *  Author  	: TychoJ
 * 
 *  File		: LSM6DSMTR.c
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

#define WHO_AM_I_REG 0x0F
#define WHO_AM_I 0x6A

// Enable embedded functions register
#define FUNC_CFG_ACCESS 0x01

// Sensor sync time frame register
#define SENSOR_SYNC_TIME_FRAME 0x04

// Sensor sync resolution ratio
#define SENSOR_SYNC_RES_RATIO 0x05

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
#define INT1_ STEP_DETECTOR_bp  7
#define INT1_SIGN_MOT_bp        6
#define INT1_FULL_FLAG_bp       5
#define INT1_FIFO_OVR_bp        4
#define INT1_FTH_bp             3
#define INT1_ BOOT_bp           2
#define INT1_DRDY_G_bp          1
#define INT1_DRDY_XL            0

// INT2_CTRL
#define INT2_STEP_DELTA_bp      7
#define INT2_STEP_COUNT_OV_bp   6
#define INT2_ FULL_FLAG_bp      5
#define INT2_FIFO_OVR_bp        4
#define INT2_FTH_bp             3
#define INT2_DRDY_TEMP_bp       2
#define INT2_DRDY_G_bp          1
#define INT2_DRDY_XL            0

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
#define G_HM_MODE_bp    7
#define HP_EN_G_bp      6
#define HPM_G_bp        4
#define ROUNDING_STATUS 2

// CTRL8_XL
#define LPF2_XL_EN_bp       7
#define HPCF_XL_bp          5
#define HP_REF_MODE_bp      4
#define INPUT_COMPOSITE_bp  3
#define HP_SLOPE_XL_EN_bp   2
#define LOW_PASS_ON_6D      0

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

uint8_t whoAmI(LSM6DSMTR_t device) {
    uint8_t ret;
    uint8_t value;

    ret = device.readFromRegister(device.twi, device.addr, &value, WHO_AM_I_REG);

    if (value == WHO_AM_I && ret == 5) ret = 0;
    else ret = 1;

    return ret;
}