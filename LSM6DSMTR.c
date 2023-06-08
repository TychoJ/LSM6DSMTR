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
#include "../Xmega-TWI/twi.h"

#define WHO_AM_I_REG 0x0F

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




uint8_t whoAmI(LSM6DSMTR_t device) {
    uint8_t ret;
    uint8_t value;

    ret = read_8bit_register_TWI(device.twi, device.addr, &value, WHO_AM_I_REG)

    if (value == WHO_AM_I && ret == 5) ret = 0;
    else ret = 1;

    return ret;
}