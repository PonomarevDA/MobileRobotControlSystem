/**
* @file robot_control.h
* @brief Declaration of robot control system
*/

#ifndef ROBOT_CONTROL_H
#define	ROBOT_CONTROL_H

#include "encoder.h"
#include "hard.h"
#include "motor_control.h"
#include "rangefinder.h"
#include "timer.h"
#include "uart.h"

typedef enum 
{
    ROBOT_INITIALIZED = 1,
    ROBOT_IN_PROGRESS = 2,
    ROBOT_FINISHED = 3,
    ROBOT_CANT_MOVE = 4,
} Robot_status;

typedef struct 
{
    Robot_status status;
    uint8_t currentSpeed;
    int8_t speedRegulator;
    int16_t x;
    int16_t y;
    int16_t angle;
    uint16_t range;
    
    uint8_t minSpeed;
    uint8_t maxSpeed;
} Robot_data;


void measure();
void turn_around_by(int16_t angle);     /// Поворот на указанный угол
void turn_around_to(int16_t angle);     /// Поворот к указанному углу
void move_to(int16_t x, int16_t y);     /// Движение к указанной координате
void move_forward(uint16_t distance);   /// Движение вперед на указанное расстояние
void move_with_obstacle_avoidance(int16_t x, int16_t y);
void init_periphery();                  /// Инициализация всей переферии
void log_transmit();

#endif	/* ROBOT_CONTROL_H */

