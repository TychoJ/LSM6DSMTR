/*  LSM6DSMTR
 *  ^^^^^^^^^
 *  Author  	: TychoJ
 * 
 *  File		: LSM6DSMTR.h
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


#ifndef LSM6DSMTR_H
#define LSM6DSMTR_H

#include <stdint.h>
#include <avr/io.h>

typedef struct {
    TWI_t *twi;
    uint8_t addr;
}LSM6DSMTR_t;

// Get accelerometer data
int16_t accelGetX(LSM6DSMTR_t device);
int16_t accelGetY(LSM6DSMTR_t device);
int16_t accelGetZ(LSM6DSMTR_t device);

// Get gyroscope data
int16_t gyroGetX(LSM6DSMTR_t device);
int16_t gyroGetY(LSM6DSMTR_t device);
int16_t gyroGetZ(LSM6DSMTR_t device);

// Enable accelerometer axis
int16_t enableAccelX(LSM6DSMTR_t device);
int16_t enableAccelY(LSM6DSMTR_t device);
int16_t enableAccelZ(LSM6DSMTR_t device);

// Enable gyroscope axis
int16_t enableGyroX(LSM6DSMTR_t device);
int16_t enableGyroY(LSM6DSMTR_t device);
int16_t enableGyroZ(LSM6DSMTR_t device);

#endif //LSM6DSMTR_H