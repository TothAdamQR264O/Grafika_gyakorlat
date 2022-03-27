#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->cube), "assets/models/cube.obj");
	load_model(&(scene->cat), "assets/models/cat.obj");
	load_model(&(scene->hare), "assets/models/hare.obj");
	load_model(&(scene->deer), "assets/models/deer.obj");
	load_model(&(scene->duck), "assets/models/duck.obj");
	load_model(&(scene->gun), "assets/models/gun.obj");
	load_model(&(scene->house), "assets/models/house.obj");
	load_model(&(scene->porsche), "assets/models/porsche.obj");
	load_model(&(scene->raptor), "assets/models/raptor.obj");
	scene->texture_id = load_texture("assets/textures/cube.png");
    scene->hare_texture_id = load_texture("assets/textures/hare.jpg");
	scene->duck_texture_id = load_texture("assets/textures/duck.jpg");
	scene->raptor_texture_id = load_texture("assets/textures/raptor.png");
	
	scene->angle = 0;

    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    scene->material.ambient.red = 0.0;
    scene->material.ambient.green = 0.0;
    scene->material.ambient.blue = 0.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 100.0;
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //szin
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
	
	float ambient_light1[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light1[] = { 0.15f, 0.15f, 0.15f, 1.0f };
    float specular_light1[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position1[] = { 10.0f, 0.0f, 0.0f, 1.0f };

    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient_light1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_light1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light1);
    glLightfv(GL_LIGHT1, GL_POSITION, position1);
	
	float ambient_light2[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light2[] = { 0.15f, 0.15f, 0.15f, 1.0f };
    float specular_light2[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position2[] = { 0.0f, 10.0f, 0.0f, 1.0f };

    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient_light2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse_light2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular_light2);
    glLightfv(GL_LIGHT2, GL_POSITION, position2);
	
	float ambient_light3[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light3[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    float specular_light3[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position3[] = { 0.0f, 0.0f, -10.0f, 1.0f };

    glLightfv(GL_LIGHT3, GL_AMBIENT, ambient_light3);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse_light3);
    glLightfv(GL_LIGHT3, GL_SPECULAR, specular_light3);
    glLightfv(GL_LIGHT3, GL_POSITION, position3);
	
	float ambient_light4[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light4[] = { 0.15f, 0.15f, 0.15f, 1.0f };
    float specular_light4[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position4[] = { -10.0f, 0.0f, 0.0f, 1.0f };

    glLightfv(GL_LIGHT4, GL_AMBIENT, ambient_light4);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuse_light4);
    glLightfv(GL_LIGHT4, GL_SPECULAR, specular_light4);
    glLightfv(GL_LIGHT4, GL_POSITION, position4);
	
	float ambient_light5[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light5[] = { 0.15f, 0.15f, 0.15f, 1.0f };
    float specular_light5[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position5[] = { 0.0f, -10.0f, 0.0f, 1.0f };

    glLightfv(GL_LIGHT5, GL_AMBIENT, ambient_light5);
    glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuse_light5);
    glLightfv(GL_LIGHT5, GL_SPECULAR, specular_light5);
    glLightfv(GL_LIGHT5, GL_POSITION, position5);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene, double time)
{
	scene->angle += 15*time;
}

void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    draw_origin();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	
	glRotatef(scene->angle, 1, 0, 0); //forgatsa
	glBindTexture(GL_TEXTURE_2D, scene->texture_id);
	draw_model(&(scene->cube));
	
	glPopMatrix();
	glRotatef(scene->angle, 0, 0, 1);
	glTranslatef(0, 1, 0);
	glRotatef(scene->angle, 0, 1, 0);
	draw_model(&(scene->cat));
	
	glPopMatrix();
	glTranslatef(3, 3, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(0.01, 0.01, 0.01);
	draw_model(&(scene->house));
	
	glPopMatrix();
	glTranslatef(0, -3, 0);
	draw_model(&(scene->gun));
	
	glPopMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-3, 0, 0);
	glScalef(0.1, 0.1, 0.1);
	draw_model(&(scene->deer));
	
	glPopMatrix();
	glTranslatef(-5, -3, 0);
	glRotatef(90, 1, 0, 0);
	draw_model(&(scene->porsche));
	
	glPopMatrix();
	glTranslatef(-3,-2, 0);
	glScalef(0.1, 0.1, 0.1);
	glBindTexture(GL_TEXTURE_2D, scene->duck_texture_id);
	draw_model(&(scene->duck));
	
	glPopMatrix();
	glTranslatef(2,-3, 0);
	glBindTexture(GL_TEXTURE_2D, scene->raptor_texture_id);
	draw_model(&(scene->raptor));
	
	
	glPopMatrix();
	glTranslatef(0, 0, 1);
	glScalef(0.05, 0.05, 0.05);
	glBindTexture(GL_TEXTURE_2D, scene->hare_texture_id);
	draw_model(&(scene->hare));	
	
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
