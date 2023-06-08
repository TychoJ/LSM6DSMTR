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

uint8_t whoAmI(LSM6DSMTR_t device) {
    uint8_t ret;
    uint8_t value;

    ret = read_8bit_register_TWI(device.twi, device.addr, &value, WHO_AM_I_REG)

    if (value == WHO_AM_I && ret == 5) ret = 0;
    else ret = 1;

    return ret;
}