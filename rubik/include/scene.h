#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "cube.h"

#include <obj/model.h>

typedef struct Scene
{
	Model ring;
	
    Material material;
	GLuint ring_texture_id;
	GLuint win_texture_id;
	GLuint dashboard_texture_id;
	GLuint dashboardX_texture_id;
	GLuint dashboardY_texture_id;
	GLuint help_texture_id[3];
	
	Cube kocka[26];
	
	int d_t_id;
	int d_t_id_flag;
	
	int help_flag;
	int help_number;
	
	double primary_light;
	double secondary_light;
	double tertiary_light;
	
	double angle;
	double rotate;
	double cubesdate[26][7];
	int translateMod;
	
	int horizontal_ring;
	int vertical_ring;
	int tengelyY_X;
	int ring_flag;
	
	int gyoz;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(Scene* scene);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene, double time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/**
 *Mátriksz get, set metódusai
 */
double getCuX(Scene* scene, int sor);

void setCuX(Scene* scene, int sor, double ertek);

double getCuY(Scene* scene, int sor);

void setCuY(Scene* scene, int sor, double ertek);

double getCuZ(Scene* scene, int sor);

void setCuZ(Scene* scene, int sor, double ertek);

double getAngle(Scene* scene, int sor);

void setAngle(Scene* scene, int sor, double ertek);

void setAngleDefault(Scene* scene, int sor, double ertek);

double getAnX(Scene* scene, int sor);

void setAnX(Scene* scene, int sor, double ertek);

double getAnY(Scene* scene, int sor);

void setAnY(Scene* scene, int sor, double ertek);

double getAnZ(Scene* scene, int sor);

void setAnZ(Scene* scene, int sor, double ertek);

void setDefault(Scene* scene);

#endif /* SCENE_H */
