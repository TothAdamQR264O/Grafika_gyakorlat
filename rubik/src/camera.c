#include "camera.h"

#include <GL/gl.h>

#include <math.h>

void init_camera(Camera* camera)
{
    camera->position.x = -3.0;
    camera->position.y = 3.0;
    camera->position.z = 2.5;
    camera->rotation.x = -35.0;
    camera->rotation.y = 0.0;
    camera->rotation.z = -45.0;
    camera->speed.x = 0.0;
    camera->speed.y = 0.0;
    camera->speed.z = 0.0;

    camera->is_preview_visible = false;
}

void update_camera(Camera* camera, double time)
{
    double angle;
    double side_angle;

    angle = degree_to_radian(camera->rotation.z);
    side_angle = degree_to_radian(camera->rotation.z + 90.0);

    camera->position.x += cos(angle) * camera->speed.y * time;
    camera->position.y += sin(angle) * camera->speed.y * time;
    camera->position.x += cos(side_angle) * camera->speed.x * time;
    camera->position.y += sin(side_angle) * camera->speed.x * time;
	camera->position.z += camera->speed.z * time;

}

void set_view(const Camera* camera)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->rotation.z - 90), 0, 0, 1.0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
}

void rotate_camera(Camera* camera, double horizontal, double vertical)
{
    camera->rotation.z += horizontal;
    camera->rotation.x += vertical;

    if (camera->rotation.z < 0) {
        camera->rotation.z += 360.0;
    }

    if (camera->rotation.z > 360.0) {
        camera->rotation.z -= 360.0;
    }

    if (camera->rotation.x < 0) {
        camera->rotation.x += 360.0;
    }

    if (camera->rotation.x > 360.0) {
        camera->rotation.x -= 360.0;
    }
}

void set_camera_rotate_horizontal(Camera* camera, double rotate){
		camera->rotation.z += rotate;
}

void set_camera_rotate_vertical(Camera* camera, double rotate){
		camera->rotation.x += rotate;
}

void set_camera_speed(Camera* camera, double speed)
{
    camera->speed.y = speed;
}

void set_camera_side_speed(Camera* camera, double speed)
{
    camera->speed.x = speed;
}

void set_camera_height_speed(Camera* camera, double speed)
{
    camera->speed.z = speed;
}

void set_camera_default_view(Camera* camera)
{
    camera->rotation.z = -45;
	camera->rotation.x = -35;
	camera->position.x = -3;
	camera->position.y = 3;
	camera->position.z = 2.5;
}

void show_texture_preview()
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-1.2, -0.5, -1.5);
    glTexCoord2f(1, 0);
    glVertex3f(1.2, -0.5, -1.5);
    glTexCoord2f(1, 1);
    glVertex3f(1.2, -0.9, -1.5);
    glTexCoord2f(0, 1);
    glVertex3f(-1.2, -0.9, -1.5);
    glEnd();
	
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void show_texture_preview_no_dashboard()
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-1.2, -0.85, -1.5);
    glTexCoord2f(1, 0);
    glVertex3f(-1.15, -0.85, -1.5);
    glTexCoord2f(1, 1);
    glVertex3f(-1.15, -0.9, -1.5);
    glTexCoord2f(0, 1);
    glVertex3f(-1.2, -0.9, -1.5);
    glEnd();
	
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

void show_texture_preview_help()
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
    glVertex3f(-1, 1.5, -2.5);
    glTexCoord2f(1, 0);
    glVertex3f(1, 1.5, -2.5);
    glTexCoord2f(1, 1);
    glVertex3f(1, -0.8, -2.5);
    glTexCoord2f(0, 1);
    glVertex3f(-1, -0.8, -2.5);
    glEnd();
	
    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}
