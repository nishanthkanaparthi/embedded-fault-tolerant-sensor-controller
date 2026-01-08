#ifndef SENSOR_CONTROLLER_H
#define SENSOR_CONTROLLER_H

// Possible controller states
typedef enum {
    STATE_OK,
    STATE_WARNING,
    STATE_ERROR,
    STATE_RESET
} SensorState;

// Controller data
typedef struct {
    SensorState state;
    float warning_threshold;
    float error_threshold;
    int error_count;       // <-- how many times we've seen an error
} SensorController;

// Initialize the controller
void controller_init(SensorController *ctrl,
                     float warning_threshold,
                     float error_threshold);

// Update the controller with a new sensor value
void controller_update(SensorController *ctrl, float sensor_value);

// Helper to print state as text
const char *controller_state_to_string(SensorState state);

#endif
