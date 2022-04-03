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
	scene->ny_texture_id = load_texture("assets/textures/hare.jpg");
	
	scene->angle = 0;
	scene->rotate = 0;
	for(int i = 0; i < 26; i++){
		int x, y, z;
		if(i == 0){
			x = 1; y = 1; z = 0;
		}
				
		if(x != 0 || y != 0 || z != 0){
			scene->cubesdate[i][0] = (double)x;
			scene->cubesdate[i][1] = (double)y;
			scene->cubesdate[i][2] = (double)z;
			scene->cubesdate[i][3] = 0;
			scene->cubesdate[i][4] = 0;
			scene->cubesdate[i][5] = 0;
			scene->cubesdate[i][6] = 0;
		}else{
			i--;
		}
				
		if(x == 1){
			x = 0;
		}else if(x == 0){
			x = -1;
		}else if(x == -1){
			x = 1;
			if(z == 0){
				z = 1;
			}else if(z == 1){
				z = -1;
			}else if(z == -1){
				z = 0;
				if(y == 1){
					y = 0;
				}else if(y == 0){
					y = -1;
				}
			}
		}
	}
	
	scene->primary_light = 1.0f;
	scene->secondary_light = 0.75f;
	scene->tertiary_light = 0.5f;

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

void set_lighting(Scene* scene)
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { scene->primary_light, scene->primary_light, scene->primary_light, 1.0f }; //szin
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
	
	float ambient_light1[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light1[] = { scene->secondary_light, scene->secondary_light, scene->secondary_light, 1.0f };
    float specular_light1[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position1[] = { 10.0f, 0.0f, 0.0f, 1.0f };

    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient_light1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_light1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light1);
    glLightfv(GL_LIGHT1, GL_POSITION, position1);
	
	float ambient_light2[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light2[] = { scene->secondary_light, scene->secondary_light, scene->secondary_light, 1.0f };
    float specular_light2[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position2[] = { 0.0f, 10.0f, 0.0f, 1.0f };

    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient_light2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse_light2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular_light2);
    glLightfv(GL_LIGHT2, GL_POSITION, position2);
	
	float ambient_light3[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light3[] = { scene->tertiary_light, scene->tertiary_light, scene->tertiary_light, 1.0f };
    float specular_light3[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position3[] = { 0.0f, 0.0f, -10.0f, 1.0f };

    glLightfv(GL_LIGHT3, GL_AMBIENT, ambient_light3);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse_light3);
    glLightfv(GL_LIGHT3, GL_SPECULAR, specular_light3);
    glLightfv(GL_LIGHT3, GL_POSITION, position3);
	
	float ambient_light4[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light4[] = { scene->secondary_light, scene->secondary_light, scene->secondary_light, 1.0f };
    float specular_light4[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position4[] = { -10.0f, 0.0f, 0.0f, 1.0f };

    glLightfv(GL_LIGHT4, GL_AMBIENT, ambient_light4);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuse_light4);
    glLightfv(GL_LIGHT4, GL_SPECULAR, specular_light4);
    glLightfv(GL_LIGHT4, GL_POSITION, position4);
	
	float ambient_light5[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light5[] = { scene->secondary_light, scene->secondary_light, scene->secondary_light, 1.0f };
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
	scene->angle += scene->rotate*time;
}


void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting(scene);
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
	glPushMatrix();
	
	
	glBindTexture(GL_TEXTURE_2D, scene->texture_id);
	
	//Model megjelenites xyz, 0=origo, 1=1, 2=-1
	//Elso tomb
	glPopMatrix();
	glTranslatef(getCuX(scene, 0), getCuY(scene, 0), getCuZ(scene, 0));
	glRotatef(getAngle(scene, 0), getAnX(scene, 0), getAnY(scene, 0), getAnZ(scene, 0));
	draw_model(&(scene->cube110));
	
	glBindTexture(GL_TEXTURE_2D, scene->ny_texture_id);
	glPopMatrix();
	glTranslatef(getCuX(scene, 1), getCuY(scene, 1), getCuZ(scene, 1));
	glRotatef(getAngle(scene, 1), getAnX(scene, 1), getAnY(scene, 1), getAnZ(scene, 1));
	draw_model(&(scene->cube010));
	glBindTexture(GL_TEXTURE_2D, scene->texture_id);
	glPopMatrix();
	glTranslatef(getCuX(scene, 2), getCuY(scene, 2), getCuZ(scene, 2));
	glRotatef(getAngle(scene, 2), getAnX(scene, 2), getAnY(scene, 2), getAnZ(scene, 2));	
	draw_model(&(scene->cube210));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 3), getCuY(scene, 3), getCuZ(scene, 3));
	glRotatef(getAngle(scene, 3), getAnX(scene, 3), getAnY(scene, 3), getAnZ(scene, 3));
	draw_model(&(scene->cube111));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 4), getCuY(scene, 4), getCuZ(scene, 4));
	glRotatef(getAngle(scene, 4), getAnX(scene, 4), getAnY(scene, 4), getAnZ(scene, 4));
	draw_model(&(scene->cube011));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 5), getCuY(scene, 5), getCuZ(scene, 5));
	glRotatef(getAngle(scene, 5), getAnX(scene, 5), getAnY(scene, 5), getAnZ(scene, 5));
	draw_model(&(scene->cube211));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 6), getCuY(scene, 6), getCuZ(scene, 6));
	glRotatef(getAngle(scene, 6), getAnX(scene, 6), getAnY(scene, 6), getAnZ(scene, 6));
	draw_model(&(scene->cube112));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 7), getCuY(scene, 7), getCuZ(scene, 7));
	glRotatef(getAngle(scene, 7), getAnX(scene, 7), getAnY(scene, 7), getAnZ(scene, 7));
	draw_model(&(scene->cube012));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 8), getCuY(scene, 8), getCuZ(scene, 8));
	glRotatef(getAngle(scene, 8), getAnX(scene, 8), getAnY(scene, 8), getAnZ(scene, 8));
	draw_model(&(scene->cube212));
	
	//Kozepso tomb
	glPopMatrix();
	glTranslatef(getCuX(scene, 9), getCuY(scene, 9), getCuZ(scene, 9));
	glRotatef(getAngle(scene, 9), getAnX(scene, 9), getAnY(scene, 9), getAnZ(scene, 9));
	draw_model(&(scene->cube100));
	
	//Gomb kozepso elem
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 10), getCuY(scene, 10), getCuZ(scene, 10));
	glRotatef(getAngle(scene, 10), getAnX(scene, 10), getAnY(scene, 10), getAnZ(scene, 10));
	draw_model(&(scene->cube200));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 11), getCuY(scene, 11), getCuZ(scene, 11));
	glRotatef(getAngle(scene, 11), getAnX(scene, 11), getAnY(scene, 11), getAnZ(scene, 11));
	draw_model(&(scene->cube101));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 12), getCuY(scene, 12), getCuZ(scene, 12));
	glRotatef(getAngle(scene, 12), getAnX(scene, 12), getAnY(scene, 12), getAnZ(scene, 12));
	draw_model(&(scene->cube001));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 13), getCuY(scene, 13), getCuZ(scene, 13));
	glRotatef(getAngle(scene, 13), getAnX(scene, 13), getAnY(scene, 13), getAnZ(scene, 13));
	draw_model(&(scene->cube201));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 14), getCuY(scene, 14), getCuZ(scene, 14));
	glRotatef(getAngle(scene, 14), getAnX(scene, 14), getAnY(scene, 14), getAnZ(scene, 14));
	draw_model(&(scene->cube102));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 15), getCuY(scene, 15), getCuZ(scene, 15));
	glRotatef(getAngle(scene, 15), getAnX(scene, 15), getAnY(scene, 15), getAnZ(scene, 15));
	draw_model(&(scene->cube002));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 16), getCuY(scene, 16), getCuZ(scene, 16));
	glRotatef(getAngle(scene, 16), getAnX(scene, 16), getAnY(scene, 16), getAnZ(scene, 16));
	draw_model(&(scene->cube202));
	
	//Hatso tomb
	glPopMatrix();
	glTranslatef(getCuX(scene, 17), getCuY(scene, 17), getCuZ(scene, 17));
	glRotatef(getAngle(scene, 17), getAnX(scene, 17), getAnY(scene, 17), getAnZ(scene, 17));
	draw_model(&(scene->cube120));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 18), getCuY(scene, 18), getCuZ(scene, 18));
	glRotatef(getAngle(scene, 18), getAnX(scene, 18), getAnY(scene, 18), getAnZ(scene, 18));
	draw_model(&(scene->cube020));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 19), getCuY(scene, 19), getCuZ(scene, 19));
	glRotatef(getAngle(scene, 19), getAnX(scene, 19), getAnY(scene, 19), getAnZ(scene, 19));
	draw_model(&(scene->cube220));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 20), getCuY(scene, 20), getCuZ(scene, 20));
	glRotatef(getAngle(scene, 20), getAnX(scene, 20), getAnY(scene, 20), getAnZ(scene, 20));
	draw_model(&(scene->cube121));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 21), getCuY(scene, 21), getCuZ(scene, 21));
	glRotatef(getAngle(scene, 21), getAnX(scene, 21), getAnY(scene, 21), getAnZ(scene, 21));
	draw_model(&(scene->cube021));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 22), getCuY(scene, 22), getCuZ(scene, 22));
	glRotatef(getAngle(scene, 22), getAnX(scene, 22), getAnY(scene, 22), getAnZ(scene, 22));
	draw_model(&(scene->cube221));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 23), getCuY(scene, 23), getCuZ(scene, 23));
	glRotatef(getAngle(scene, 23), getAnX(scene, 23), getAnY(scene, 23), getAnZ(scene, 23));
	draw_model(&(scene->cube122));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 24), getCuY(scene, 24), getCuZ(scene, 24));
	glRotatef(getAngle(scene, 24), getAnX(scene, 24), getAnY(scene, 24), getAnZ(scene, 24));
	draw_model(&(scene->cube022));
	
	glPopMatrix();
	glTranslatef(getCuX(scene, 25), getCuY(scene, 25), getCuZ(scene, 25));
	glRotatef(getAngle(scene, 25), getAnX(scene, 25), getAnY(scene, 25), getAnZ(scene, 25));
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

double getCuX(Scene* scene, int sor){
	return scene->cubesdate[sor][0];
}

void setCuX(Scene* scene, int sor, double ertek){
	if(ertek == 0){
		scene->cubesdate[sor][0] = scene->cubesdate[sor][0]*-1;
	}else{
		scene->cubesdate[sor][0] = scene->cubesdate[sor][0]+ertek;
	}
}

double getCuY(Scene* scene, int sor){
	return scene->cubesdate[sor][1];
}

void setCuY(Scene* scene, int sor, double ertek){
	if(ertek == 0){
		scene->cubesdate[sor][1] = scene->cubesdate[sor][1]*-1;
	}else{
		scene->cubesdate[sor][1] = scene->cubesdate[sor][1]+ertek;
	}
}

double getCuZ(Scene* scene, int sor){
	return scene->cubesdate[sor][2];
}

void setCuZ(Scene* scene, int sor, double ertek){
	if(ertek == 0){
		scene->cubesdate[sor][2] = scene->cubesdate[sor][2]*-1;
	}else{
		scene->cubesdate[sor][2] = scene->cubesdate[sor][2]+ertek;
	}
}

double getAngle(Scene* scene, int sor){
	return scene->cubesdate[sor][3];
}

void setAngle(Scene* scene, int sor, double ertek){
	scene->cubesdate[sor][3] += ertek;
}

double getAnX(Scene* scene, int sor){
	return scene->cubesdate[sor][4];
}

void setAnX(Scene* scene, int sor, double ertek){
	scene->cubesdate[sor][4] = ertek;
}

double getAnY(Scene* scene, int sor){
	return scene->cubesdate[sor][5];
}

void setAnY(Scene* scene, int sor, double ertek){
	scene->cubesdate[sor][5] = ertek;
}

double getAnZ(Scene* scene, int sor){
	return scene->cubesdate[sor][6];
}

void setAnZ(Scene* scene, int sor, double ertek){
	scene->cubesdate[sor][6] = ertek;
}

void setDefault(Scene* scene){
	for(int i = 0; i < 26; i++){
		int x, y, z;
		if(i == 0){
			x = 1; y = 1; z = 0;
		}
				
		if(x != 0 || y != 0 || z != 0){
			scene->cubesdate[i][0] = (double)x;
			scene->cubesdate[i][1] = (double)y;
			scene->cubesdate[i][2] = (double)z;
			scene->cubesdate[i][3] = 0;
			scene->cubesdate[i][4] = 0;
			scene->cubesdate[i][5] = 0;
			scene->cubesdate[i][6] = 0;
		}else{
			i--;
		}
				
		if(x == 1){
			x = 0;
		}else if(x == 0){
			x = -1;
		}else if(x == -1){
			x = 1;
			if(z == 0){
				z = 1;
			}else if(z == 1){
				z = -1;
			}else if(z == -1){
				z = 0;
				if(y == 1){
					y = 0;
				}else if(y == 0){
					y = -1;
				}
			}
		}
	}
}
