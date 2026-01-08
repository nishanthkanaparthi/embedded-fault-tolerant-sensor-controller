#include <stdio.h>
#include "sensor_controller.h"

// Set initial values
void controller_init(SensorController *ctrl,
                     float warning_threshold,
                     float error_threshold) {
    ctrl->state = STATE_OK;
    ctrl->warning_threshold = warning_threshold;
    ctrl->error_threshold = error_threshold;
    ctrl->error_count = 0;
}

// Turn enum values into readable text
const char *controller_state_to_string(SensorState state) {
    switch (state) {
        case STATE_OK:      return "OK";
        case STATE_WARNING: return "WARNING";
        case STATE_ERROR:   return "ERROR";
        case STATE_RESET:   return "RESET";
        default:            return "UNKNOWN";
    }
}

// Decide the next state based on the sensor value
void controller_update(SensorController *ctrl, float sensor_value) {
    // Decide state based on thresholds and current state
    switch (ctrl->state) {
        case STATE_OK:
        case STATE_WARNING:
            if (sensor_value >= ctrl->error_threshold) {
                ctrl->state = STATE_ERROR;
                ctrl->error_count++;
            } else if (sensor_value >= ctrl->warning_threshold) {
                ctrl->state = STATE_WARNING;
            } else {
                ctrl->state = STATE_OK;
            }
            break;

        case STATE_ERROR:
            // After seeing an error once, go to RESET on the next reading
            ctrl->state = STATE_RESET;
            break;

        case STATE_RESET:
            // From RESET, go back toward normal if values improve
            if (sensor_value < ctrl->warning_threshold) {
                ctrl->state = STATE_OK;
            } else if (sensor_value < ctrl->error_threshold) {
                ctrl->state = STATE_WARNING;
            } else {
                // still too high -> count another error
                ctrl->state = STATE_ERROR;
                ctrl->error_count++;
            }
            break;
    }

    // Print what happened
    printf("Reading: %.1f -> %s\n",
           sensor_value,
           controller_state_to_string(ctrl->state));
}
