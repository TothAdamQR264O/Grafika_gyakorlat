#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"

#include <stdbool.h>

/**
 * Camera, as a moving point with direction
 */
typedef struct Camera
{
    vec3 position;
    vec3 rotation;
    vec3 speed;
    bool is_preview_visible;
} Camera;

/**
 * Initialize the camera to the start position.
 */
void init_camera(Camera* camera);

/**
 * Update the position of the camera.
 */
void update_camera(Camera* camera, double time);

/**
 * Apply the camera settings to the view transformation.
 */
void set_view(const Camera* camera);

/**
 * Set the horizontal and vertical rotation of the view angle.
 */
void rotate_camera(Camera* camera, double horizontal, double vertical);
/**
 *Kamera mozgatas billentyuvel z tengej
 */
void set_camera_rotate_horizontal(Camera* camera, double rotate);
/**
 *Kamera mozgatas billentyuvel x tengej
 */
void set_camera_rotate_vertical(Camera* camera, double rotate);
/**
 * Set the speed of forward and backward motion.
 */
void set_camera_speed(Camera* camera, double speed);

/**
 * Set the speed of left and right side steps.
 */
void set_camera_side_speed(Camera* camera, double speed);
/**
 *Magassag bealitas
 */
void set_camera_height_speed(Camera* camera, double speed);
/**
 *Alaphejzetbe alitja a kamerat
 */
void set_camera_default_view(Camera* camera);

#endif /* CAMERA_H */
