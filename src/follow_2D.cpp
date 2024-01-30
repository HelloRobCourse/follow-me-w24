/**
 * File: 2D_control_nearest.cpp
 *
 * Controls the robot to maintain a given distance to the nearest wall.
 *
 * This code finds the distance to the nearest wall in the Lidar scan. It
 * applies a control to the robot in the direction of the wall using the angle
 * to the scan.
 */

#include <iostream>
#include <cmath>

#include <signal.h>

#include <follow_me/common/utils.h>
#include <mbot_bridge/robot.h>

bool ctrl_c_pressed;
void ctrlc(int)
{
    ctrl_c_pressed = true;
}


/**
 * @brief findMinDist takes an vector of ranges, and returns the
 *        index of the smallest range in the vector
 *
 * @param ranges
 * @return int
 */
int findMinDist(const std::vector<float>& ranges)
{
    // *** Task 2: Implement findMinDist logic *** //
    // TODO: Add logic so that findMinDist returns the correct index.
    // HINT: Remember to ignore any ranges that are zero!

    return -1;

    // *** End Student Code *** //
}


int main(int argc, const char *argv[])
{
    signal(SIGINT, ctrlc);
    signal(SIGTERM, ctrlc);

    // Initialize the robot.
    mbot_bridge::MBot robot;
    // We will store the Lidar scan data in these vectors.
    std::vector<float> ranges;
    std::vector<float> thetas;

    // *** Task 1: Adjust these values appropriately ***

    float setpoint = 0;  // The goal distance from the wall in meters

    // *** End student code *** //

    while (true) {
        // This function gets the Lidar scan data.
        robot.readLidarScan(ranges, thetas);

        // Get the distance to the wall.
        float min_idx = findMinDist(ranges);
        float dist_to_wall = ranges[min_idx];
        float angle_to_wall = thetas[min_idx];

        // *** Task 3: Implement the 2D Follow Me controller ***
        // Hint: Look at your code from follow_1D
        // Hint: When you compute the velocity command, you might find the functions
        // sin(value) and cos(value) helpful!

        // *** End Student Code ***

        if (ctrl_c_pressed) break;
    }

    // Stop the robot.
    robot.stop();
    return 0;
}
