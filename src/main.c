#include <stdio.h>
#include "sensor_controller.h"

int main(void) {
    SensorController controller;
    controller_init(&controller, 50.0f, 100.0f); // warning at 50, error at 100

    // Example "sensor readings"
    float readings[] = {20.0f, 45.0f, 65.0f, 80.0f, 120.0f, 90.0f, 40.0f};
    int num_readings = sizeof(readings) / sizeof(readings[0]);

    for (int i = 0; i < num_readings; i++) {
        controller_update(&controller, readings[i]);
    }

    printf("Total error events: %d\n", controller.error_count);
    return 0;
}
