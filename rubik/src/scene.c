#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->cube), "assets/models/cube.obj");
	load_model(&(scene->ring), "assets/models/Ring.obj");
	
	scene->texture_id = load_texture("assets/textures/cube.png");
	scene->ring_texture_id = load_texture("assets/textures/ring.png");
	scene->ny_texture_id = load_texture("assets/textures/hare.jpg");
	scene->dashboard_texture_id = load_texture("assets/textures/rubik_dashboard.png");
	scene->dashboardX_texture_id = load_texture("assets/textures/rubik_dashboardX.jpg");
	scene->dashboardY_texture_id = load_texture("assets/textures/rubik_dashboardY.jpg");
	scene->help_texture_id[0] = load_texture("assets/textures/rubik_help_mozgas.jpg");
	scene->help_texture_id[1] = load_texture("assets/textures/rubik_help_billentyu.jpg");
	scene->help_texture_id[2] = load_texture("assets/textures/rubik_help_iranyitopult.jpg");
	
	scene->d_t_id = 0;
	scene->d_t_id_flag = 0;
	
	scene->help_flag = 0;
	scene->help_number = 0;
	
	scene->angle = 0;
	scene->rotate = 0;
	scene->translateMod = 0;
	
	scene->horizontal_ring = 0;
	scene->vertical_ring = 0;
	scene->tengelyY_X = 0;
	scene->ring_flag = 0;
	
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
    //draw_origin();
	glPushMatrix();
	glPushMatrix();
	
	for(int i=0; i<26; i++){
		glPushMatrix();
	}	
	
	
	
	for(int i=0; i<26; i++){
		if(i == 1){
			glBindTexture(GL_TEXTURE_2D, scene->ny_texture_id);
		}else{
			glBindTexture(GL_TEXTURE_2D, scene->texture_id);
		}
		
		glPopMatrix();
		if(scene->translateMod == 1){
			glRotatef(getAngle(scene, i), getAnX(scene, i), getAnY(scene, i), getAnZ(scene, i));
			glTranslatef(getCuX(scene, i), getCuY(scene, i), getCuZ(scene, i));
		}else if(scene->translateMod == 0){
			glTranslatef(getCuX(scene, i), getCuY(scene, i), getCuZ(scene, i));
		}
		draw_cube(&(scene->kocka[i]));
	}
	
	glBindTexture(GL_TEXTURE_2D, scene->ring_texture_id);
	glPopMatrix();
	if(scene->ring_flag == 0){
		glTranslatef(0, 0, scene->horizontal_ring);
		glRotatef(90, 1, 0, 0);
		glScalef(2.5, 2.5, 2.5);
		draw_model(&(scene->ring));
		
		if(scene->tengelyY_X == 0){
			glPopMatrix();
			glTranslatef(0, scene->vertical_ring, 0);
			glScalef(2.5, 2.5, 2.5);
			draw_model(&(scene->ring));
		}else if(scene->tengelyY_X == 1){
			glPopMatrix();
			glTranslatef(scene->vertical_ring, 0, 0);
			glRotatef(90, 0, 0, 1);
			glScalef(2.5, 2.5, 2.5);
			draw_model(&(scene->ring));
		}
	}
	
	if(scene->help_flag == 1){
		glBindTexture(GL_TEXTURE_2D, scene->help_texture_id[scene->help_number]);
		show_texture_preview_help();
	}
	
	
	if(scene->d_t_id_flag == 0){
		if(scene->d_t_id == 0){
			glBindTexture(GL_TEXTURE_2D, scene->dashboardX_texture_id);
		}else{
			glBindTexture(GL_TEXTURE_2D, scene->dashboardY_texture_id);
		}
		show_texture_preview();
	}else{
		glBindTexture(GL_TEXTURE_2D, scene->dashboard_texture_id);
		show_texture_preview_no_dashboard();
	}
	
	
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

void setAngleDefault(Scene* scene, int sor, double ertek){
	scene->cubesdate[sor][3] = ertek;
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
