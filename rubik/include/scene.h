#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
	//Modellek xyz, 0=origo, 1=1, 2=-1
	//Elso tomb
    Model cube110;
	Model cube010;
	Model cube210;
	
	Model cube111;
	Model cube011;
	Model cube211;
	
	Model cube112;
	Model cube012;
	Model cube212;
	
	//Kozepso tomb
	Model cube100;
	//Gomb kozepso elem
	Model cube200;
	
	Model cube101;
	Model cube001;
	Model cube201;
	
	Model cube102;
	Model cube002;
	Model cube202;
	
	//Hatso tomb
	Model cube120;
	Model cube020;
	Model cube220;
	
	Model cube121;
	Model cube021;
	Model cube221;
	
	Model cube122;
	Model cube022;
	Model cube222;
	
    Material material;
    GLuint texture_id;
	
	GLuint ny_texture_id;
	
	double primary_light;
	double secondary_light;
	double tertiary_light;
	
	double angle;
	double rotate;
	double cubesdate[26][7];
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

double getAnX(Scene* scene, int sor);

void setAnX(Scene* scene, int sor, double ertek);

double getAnY(Scene* scene, int sor);

void setAnY(Scene* scene, int sor, double ertek);

double getAnZ(Scene* scene, int sor);

void setAnZ(Scene* scene, int sor, double ertek);

void setDefault(Scene* scene);

#endif /* SCENE_H */
