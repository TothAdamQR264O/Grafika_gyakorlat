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
	double angle;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

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

void rotate_coub(Scene* scene, double val);

#endif /* SCENE_H */
