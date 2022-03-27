#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
	//model betoltes xyz, 0=origo, 1=1, 2=-1
	//Elso tomb
    load_model(&(scene->cube110), "assets/models/cube.obj");
	load_model(&(scene->cube010), "assets/models/cube.obj");
	load_model(&(scene->cube210), "assets/models/cube.obj");
	
	load_model(&(scene->cube111), "assets/models/cube.obj");
	load_model(&(scene->cube011), "assets/models/cube.obj");
	load_model(&(scene->cube211), "assets/models/cube.obj");
	
	load_model(&(scene->cube112), "assets/models/cube.obj");
	load_model(&(scene->cube012), "assets/models/cube.obj");
	load_model(&(scene->cube212), "assets/models/cube.obj");
	
	//Kozepso tomb
	load_model(&(scene->cube100), "assets/models/cube.obj");
	//Gomb kozepso elem
	load_model(&(scene->cube200), "assets/models/cube.obj");
	
	load_model(&(scene->cube101), "assets/models/cube.obj");
	load_model(&(scene->cube001), "assets/models/cube.obj");
	load_model(&(scene->cube201), "assets/models/cube.obj");
	
	load_model(&(scene->cube102), "assets/models/cube.obj");
	load_model(&(scene->cube002), "assets/models/cube.obj");
	load_model(&(scene->cube202), "assets/models/cube.obj");
	
	//Hatso tomb
    load_model(&(scene->cube120), "assets/models/cube.obj");
	load_model(&(scene->cube020), "assets/models/cube.obj");
	load_model(&(scene->cube220), "assets/models/cube.obj");
	
	load_model(&(scene->cube121), "assets/models/cube.obj");
	load_model(&(scene->cube021), "assets/models/cube.obj");
	load_model(&(scene->cube221), "assets/models/cube.obj");
	
	load_model(&(scene->cube122), "assets/models/cube.obj");
	load_model(&(scene->cube022), "assets/models/cube.obj");
	load_model(&(scene->cube222), "assets/models/cube.obj");
	
	scene->texture_id = load_texture("assets/textures/cube.png");
	
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

void rotate_coub(Scene* scene, double val){
	
	glTranslatef(val, 1, 0);
	draw_model(&(scene->cube110));
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
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	
	
	glBindTexture(GL_TEXTURE_2D, scene->texture_id);
	//Model megjelenites xyz, 0=origo, 1=1, 2=-1
	//Elso tomb
	glTranslatef(1, 1, 0);
	draw_model(&(scene->cube110));
	
	glPopMatrix();
	glTranslatef(0, 1, 0);
	draw_model(&(scene->cube010));
	
	glPopMatrix();
	glTranslatef(-1, 1, 0);
	draw_model(&(scene->cube210));
	
	glPopMatrix();
	glTranslatef(1, 1, 1);
	draw_model(&(scene->cube111));
	
	glPopMatrix();
	glTranslatef(0, 1, 1);
	draw_model(&(scene->cube011));
	
	glPopMatrix();
	glTranslatef(-1, 1, 1);
	draw_model(&(scene->cube211));
	
	glPopMatrix();
	glTranslatef(1, 1, -1);
	draw_model(&(scene->cube112));
	
	glPopMatrix();
	glTranslatef(0, 1, -1);
	draw_model(&(scene->cube012));
	
	glPopMatrix();
	glTranslatef(-1, 1, -1);
	draw_model(&(scene->cube212));
	
	//Kozepso tomb
	glPopMatrix();
	glTranslatef(1, 0, 0);
	draw_model(&(scene->cube100));
	
	//Gomb kozepso elem
	
	glPopMatrix();
	glTranslatef(-1, 0, 0);
	draw_model(&(scene->cube200));
	
	glPopMatrix();
	glTranslatef(1, 0, 1);
	draw_model(&(scene->cube101));
	
	glPopMatrix();
	glTranslatef(0, 0, 1);
	draw_model(&(scene->cube001));
	
	glPopMatrix();
	glTranslatef(-1, 0, 1);
	draw_model(&(scene->cube201));
	
	glPopMatrix();
	glTranslatef(1, 0, -1);
	draw_model(&(scene->cube102));
	
	glPopMatrix();
	glTranslatef(0, 0, -1);
	draw_model(&(scene->cube002));
	
	glPopMatrix();
	glTranslatef(-1, 0, -1);
	draw_model(&(scene->cube202));
	
	//Hatso tomb
	glPopMatrix();
	glTranslatef(1, -1, 0);
	draw_model(&(scene->cube120));
	
	glPopMatrix();
	glTranslatef(0, -1, 0);
	draw_model(&(scene->cube020));
	
	glPopMatrix();
	glTranslatef(-1, -1, 0);
	draw_model(&(scene->cube220));
	
	glPopMatrix();
	glTranslatef(1, -1, 1);
	draw_model(&(scene->cube121));
	
	glPopMatrix();
	glTranslatef(0, -1, 1);
	draw_model(&(scene->cube021));
	
	glPopMatrix();
	glTranslatef(-1, -1, 1);
	draw_model(&(scene->cube221));
	
	glPopMatrix();
	glTranslatef(1, -1, -1);
	draw_model(&(scene->cube122));
	
	glPopMatrix();
	glTranslatef(0, -1, -1);
	draw_model(&(scene->cube022));
	
	glPopMatrix();
	glTranslatef(-1, -1, -1);
	draw_model(&(scene->cube222));
	
	
	
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
