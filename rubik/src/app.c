#include "app.h"

#include <SDL2/SDL_image.h>
#include <time.h>

void init_app(App* app, int width, int height)
{
    int error_code;
    int inited_loaders;
	app->eger_esemeny = 0;

    app->is_running = false;

    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0) {
        printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
        return;
    }

    app->window = SDL_CreateWindow(
        "Rubic!",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_OPENGL);
    if (app->window == NULL) {
        printf("[ERROR] Unable to create the application window!\n");
        return;
    }

    inited_loaders = IMG_Init(IMG_INIT_PNG);
    if (inited_loaders == 0) {
        printf("[ERROR] IMG initialization error: %s\n", IMG_GetError());
        return;
    }

    app->gl_context = SDL_GL_CreateContext(app->window);
    if (app->gl_context == NULL) {
        printf("[ERROR] Unable to create the OpenGL context!\n");
        return;
    }

    init_opengl();
    reshape(width, height);

    init_camera(&(app->camera));
    init_scene(&(app->scene));

    app->is_running = true;
	
	app->vizTengely = 0;
	app->fugTengely = 0;
}

void init_opengl()
{
    glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glClearColor(0.3, 0.3, 0.3, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glClearDepth(1.0);

    glEnable(GL_TEXTURE_2D);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
}

void reshape(GLsizei width, GLsizei height)
{
    int x, y, w, h;
    double ratio;

    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double)height * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)width / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(
        -.08, .08,
        -.06, .06,
        .1, 10
    );
}

void handle_app_events(App* app)
{
    SDL_Event event;
    static bool is_mouse_down = false;
    static int mouse_x = 0;
    static int mouse_y = 0;
    int x;
    int y;
	int sebes = 3;
	int forseb = 5;
	int vizkoc = 1;
	
	
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                app->is_running = false;
                break;
            case SDL_SCANCODE_W:
				if(app->scene.help_flag == 0){
					set_camera_speed(&(app->camera), sebes);
				}
                break;
            case SDL_SCANCODE_S:
				if(app->scene.help_flag == 0){
					set_camera_speed(&(app->camera), -sebes);
				}
                break;
            case SDL_SCANCODE_A:
				if(app->scene.help_flag == 0){
					set_camera_side_speed(&(app->camera), sebes);
				}
                break;
            case SDL_SCANCODE_D:
                if(app->scene.help_flag == 0){
					set_camera_side_speed(&(app->camera), -sebes);
				}
                break;
			case SDL_SCANCODE_X:
				if(app->scene.help_flag == 0){
					set_camera_height_speed(&(app->camera),  sebes);
				}
                break;
            case SDL_SCANCODE_Z:
                if(app->scene.help_flag == 0){
					set_camera_height_speed(&(app->camera),  -sebes);
				}
                break;
			case SDL_SCANCODE_Q:
				if(app->scene.help_flag == 0){
					set_camera_rotate_horizontal(&(app->camera),  sebes);
				}
                break;
			case SDL_SCANCODE_E:
                if(app->scene.help_flag == 0){
					set_camera_rotate_horizontal(&(app->camera),  -sebes);
				}
                break;
			case SDL_SCANCODE_R:
				if(app->scene.help_flag == 0){
					set_camera_rotate_vertical(&(app->camera),  sebes);
				}
                break;
			case SDL_SCANCODE_F:
				if(app->scene.help_flag == 0){
					set_camera_rotate_vertical(&(app->camera),  -sebes);
				}
                break;
			case SDL_SCANCODE_C:
				if(app->scene.help_flag == 0){
					set_camera_default_view(&(app->camera));
				}
                break;
			case SDL_SCANCODE_H:
                if(app->scene.help_flag == 0){
					app->scene.help_flag = 1;
				}else{
					app->scene.help_flag = 0;
				}
                break;
			case SDL_SCANCODE_KP_PLUS:
				if(app->scene.help_flag == 0){
					fegy_fel(app, 0.01f);
				}
                break;
			case SDL_SCANCODE_KP_MINUS:
				if(app->scene.help_flag == 0){
					fegy_le(app, 0.01f);
				}
                break;
			case SDL_SCANCODE_KP_MULTIPLY:
				if(app->scene.help_flag == 0){
					app->scene.primary_light = 1.0f;
					app->scene.secondary_light = 0.75f;
					app->scene.tertiary_light = 0.5f;
				}
                break;
			case SDL_SCANCODE_RIGHT:
				if(app->scene.help_flag == 0 && app->scene.gyoz != 1){
					forgatas_jobbra(app, forseb);
				}
                break;
			case SDL_SCANCODE_LEFT:
				if(app->scene.help_flag == 0 && app->scene.gyoz != 1){
					forgatas_balra(app, forseb);
				}
                break;
			case SDL_SCANCODE_UP:
				if(app->scene.help_flag == 0 && app->scene.gyoz != 1){
					forgatas_fel(app, forseb);
				}
                break;
			case SDL_SCANCODE_DOWN:
				if(app->scene.help_flag == 0 && app->scene.gyoz != 1){
					forgatas_le(app, forseb);
				}
                break;
			case SDL_SCANCODE_G:
				if(app->scene.help_flag == 0){
					set_random_color(app);
				}
				//printf("X: %d, Y: %d\n", mouse_x, mouse_y);
				break;
			case SDL_SCANCODE_U:
				if(app->scene.help_flag == 0){
					if(app->scene.d_t_id_flag == 0){
						app->scene.d_t_id_flag = 1;
					}else{
						app->scene.d_t_id_flag = 0;
					}
				}
                break;
			case SDL_SCANCODE_J:
				if(app->scene.help_flag == 0){
					if(app->scene.ring_flag == 0){
						app->scene.ring_flag = 1;
					}else{
						app->scene.ring_flag = 0;
					}
				}
				break;
			case SDL_SCANCODE_T:
				if(app->scene.help_flag == 0){
					for(int i = 0; i < 26; i++){
						set_default_color(&(app->scene.kocka[i]));
					}
					app->scene.gyoz = 0;
				}
                break;
			case SDL_SCANCODE_B:
				test_szin(app);
				app->scene.gyoz = 2;
                break;
			case SDL_SCANCODE_KP_1:
				if(app->scene.help_flag == 0){
					app->vizTengely = -1;
					app->scene.horizontal_ring = -1;
				}
                break;
			case SDL_SCANCODE_KP_2:
				if(app->scene.help_flag == 0){
					app->vizTengely = 0;
					app->scene.horizontal_ring = 0;
				}
                break;
			case SDL_SCANCODE_KP_3:
				if(app->scene.help_flag == 0){
					app->vizTengely = 1;
					app->scene.horizontal_ring = 1;
				}
                break;
			case SDL_SCANCODE_KP_4:
				if(app->scene.help_flag == 0){
					app->fugTengely = -1;
					app->scene.vertical_ring = -1;
				}
                break;
			case SDL_SCANCODE_KP_5:
				if(app->scene.help_flag == 0){
					app->fugTengely = 0;
					app->scene.vertical_ring = 0;
				}
                break;
			case SDL_SCANCODE_KP_6:
				if(app->scene.help_flag == 0){
					app->fugTengely = 1;
					app->scene.vertical_ring = 1;
				}
                break;
			case SDL_SCANCODE_KP_7:
				if(app->scene.help_flag == 0){
					if(app->scene.tengelyY_X == 0){
						app->scene.tengelyY_X = 1;
						app->scene.d_t_id = 1;
					}else if(app->scene.tengelyY_X == 1){
						app->scene.tengelyY_X = 0;
						app->scene.d_t_id = 0;
					}
				}
                break;
            default:
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_S:
                set_camera_speed(&(app->camera), 0);
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_D:
                set_camera_side_speed(&(app->camera), 0);
                break;
			case SDL_SCANCODE_X:
            case SDL_SCANCODE_Z:
                set_camera_height_speed(&(app->camera), 0);
                break;
			case SDL_SCANCODE_Q:
            case SDL_SCANCODE_E:
                set_camera_rotate_horizontal(&(app->camera), 0);
                break;
			case SDL_SCANCODE_R:
            case SDL_SCANCODE_F:
                set_camera_rotate_vertical(&(app->camera), 0);
                break;
			case SDL_SCANCODE_RIGHT:
				if(app->scene.help_flag == 0){
					forgatas_szin_viszszintes(app, 1);
					forgatas_sehova(app);
				}
                break;
			case SDL_SCANCODE_LEFT:
				if(app->scene.help_flag == 0){
					forgatas_szin_viszszintes(app, 2);
					forgatas_sehova(app);
				}
                break;
			case SDL_SCANCODE_UP:
				if(app->scene.help_flag == 0){
					forgatas_szin_fugolegesen(app, 1);
					forgatas_sehova(app);
				}
                break;
			case SDL_SCANCODE_DOWN:
				if(app->scene.help_flag == 0){
					forgatas_szin_fugolegesen(app, 2);
					forgatas_sehova(app);
				}
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            is_mouse_down = true;
			switch (event.button.button) {
				case SDL_BUTTON_LEFT:
					if(app->scene.help_flag == 1){
						if(mouse_x > 208 && mouse_x < 318 && mouse_y > 8 && mouse_y < 23){
							app->scene.help_number = 0;
						}
						if(mouse_x > 321 && mouse_x < 474 && mouse_y > 8 && mouse_y < 23){
							app->scene.help_number = 1;
						}
						if(mouse_x > 476 && mouse_x < 588 && mouse_y > 8 && mouse_y < 23){
							app->scene.help_number = 2;
						}
						if(mouse_x > 536 && mouse_x < 590 && mouse_y > 427 && mouse_y < 451){
							if(app->scene.language == 0){
								app->scene.language = 1;
							}else if(app->scene.language == 1){
								app->scene.language = 0;
							}
						}
					}else{
						if(app->scene.d_t_id_flag == 0){
							if(mouse_x > 25 && mouse_x < 144 && mouse_y > 560 && mouse_y < 580){
								app->eger_esemeny = 1;
							}
							if(mouse_x > 149 && mouse_x < 268 && mouse_y > 560 && mouse_y < 580){
								app->eger_esemeny = 2;
							}
							if(mouse_x > 130 && mouse_x < 162 && mouse_y > 476 && mouse_y < 517){
								app->eger_esemeny = 3;
							}
							if(mouse_x > 130 && mouse_x < 162 && mouse_y > 520 && mouse_y < 557){
								app->eger_esemeny = 4;
							}
							if(mouse_x > 285 && mouse_x < 405 && mouse_y > 476 && mouse_y < 498){
								app->vizTengely = 1;
								app->scene.horizontal_ring = 1;
							}
							if(mouse_x > 285 && mouse_x < 405 && mouse_y > 515 && mouse_y < 538){
								app->vizTengely = 0;
								app->scene.horizontal_ring = 0;
							}
							if(mouse_x > 285 && mouse_x < 405 && mouse_y > 560 && mouse_y < 583){
								app->vizTengely = -1;
								app->scene.horizontal_ring = -1;
							}
							if(mouse_x > 421 && mouse_x < 453 && mouse_y > 476 && mouse_y < 584){
								app->fugTengely = 1;
								app->scene.vertical_ring = 1;
							}
							if(mouse_x > 473 && mouse_x < 503 && mouse_y > 476 && mouse_y < 584){
								app->fugTengely = 0;
								app->scene.vertical_ring = 0;
							}
							if(mouse_x > 521 && mouse_x < 553 && mouse_y > 476 && mouse_y < 584){
								app->fugTengely = -1;
								app->scene.vertical_ring = -1;
							}
							if(mouse_x > 565 && mouse_x < 600 && mouse_y > 476 && mouse_y < 497){
								if(app->scene.tengelyY_X == 0){
									app->scene.tengelyY_X = 1;
									app->scene.d_t_id = 1;
								}else if(app->scene.tengelyY_X == 1){
									app->scene.tengelyY_X = 0;
									app->scene.d_t_id = 0;
								}
							}
							if(mouse_x > 712 && mouse_x < 747 && mouse_y > 476 && mouse_y < 493){
								app->eger_esemeny = 5;
							}
							if(mouse_x > 712 && mouse_x < 747 && mouse_y > 521 && mouse_y < 538){
								app->eger_esemeny = 6;
							}
							if(mouse_x > 629 && mouse_x < 662 && mouse_y > 476 && mouse_y < 498){
								if(app->scene.ring_flag == 0){
									app->scene.ring_flag = 1;
								}else{
									app->scene.ring_flag = 0;
								}
							}
							if(mouse_x > 566 && mouse_x < 684 && mouse_y > 531 && mouse_y < 552){
								for(int i = 0; i < 26; i++){
									set_default_color(&(app->scene.kocka[i]));
								}
								app->scene.gyoz = 0;
							}
							if(mouse_x > 566 && mouse_x < 684 && mouse_y > 560 && mouse_y < 583){
								set_random_color(app);
							}
						}
						if(mouse_x < 18 && mouse_y > 585){
							if(app->scene.d_t_id_flag == 0){
								app->scene.d_t_id_flag = 1;
							}else{
								app->scene.d_t_id_flag = 0;
							}
						}
					}
					break;
			}
			
            break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x, &y);
            if (is_mouse_down) {
				if(app->scene.help_flag == 0){
					if(app->scene.d_t_id_flag == 0){
					if(mouse_y < 467){
							rotate_camera(&(app->camera), mouse_x - x, mouse_y - y);
						}
					}else{
						rotate_camera(&(app->camera), mouse_x - x, mouse_y - y);
					}
				}
            }
            mouse_x = x;
            mouse_y = y;
            break;
        case SDL_MOUSEBUTTONUP:
			app->eger_esemeny = 0;
            is_mouse_down = false;
			if(app->scene.d_t_id_flag == 0 && app->scene.help_flag != 1){
				if(mouse_x > 25 && mouse_x < 144 && mouse_y > 560 && mouse_y < 580){
					forgatas_szin_viszszintes(app, 2);
				}
				if(mouse_x > 149 && mouse_x < 268 && mouse_y > 560 && mouse_y < 580){
					forgatas_szin_viszszintes(app, 1);
				}
				if(mouse_x > 130 && mouse_x < 162 && mouse_y > 476 && mouse_y < 517){
					forgatas_szin_fugolegesen(app, 1);
				}
				if(mouse_x > 130 && mouse_x < 162 && mouse_y > 520 && mouse_y < 557){
					forgatas_szin_fugolegesen(app, 2);
				}
			}
			forgatas_sehova(app);
            break;
        case SDL_QUIT:
            app->is_running = false;
            break;
        default:
            break;
        }
    }
}

void update_app(App* app)
{
    double current_time;
    double elapsed_time;
	double forseb = 1;

    current_time = (double)SDL_GetTicks() / 1000;
    elapsed_time = current_time - app->uptime;
    app->uptime = current_time;

    update_camera(&(app->camera), elapsed_time);
    update_scene(&(app->scene), elapsed_time);
	
	kocka_szin_feny(app);
	
	if(app->scene.gyoz != 1){
		if(app->eger_esemeny == 1){
			forgatas_balra(app, forseb);
		}
		if(app->eger_esemeny == 2){
			forgatas_jobbra(app, forseb);
		}
		if(app->eger_esemeny == 3){
			forgatas_fel(app, forseb);
		}
		if(app->eger_esemeny == 4){
			forgatas_le(app, forseb);
		}
		if(app->eger_esemeny == 5){
			fegy_fel(app, 0.001f);
		}
		if(app->eger_esemeny == 6){
			fegy_le(app, 0.001f);
		}
	}
	
	
	if(app->scene.gyoz == 2){
		ellenorzo(app);
	}
}

void render_app(App* app)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    set_view(&(app->camera));
    render_scene(&(app->scene));
    glPopMatrix();

    if (app->camera.is_preview_visible) {
        show_texture_preview();
    }

    SDL_GL_SwapWindow(app->window);
}

void destroy_app(App* app)
{
    if (app->gl_context != NULL) {
        SDL_GL_DeleteContext(app->gl_context);
    }

    if (app->window != NULL) {
        SDL_DestroyWindow(app->window);
    }

    SDL_Quit();
}

void forgatas_jobbra(App* app, int ertek){
	app->scene.translateMod = 1;
	for(int i = 0; i < 26; i++){
		if(getCuZ(&(app->scene), i) == app->vizTengely){
			setAnZ(&(app->scene), i, 1);
			setAngle(&(app->scene), i, ertek);
		}
	}
}

void forgatas_balra(App* app, int ertek){
	app->scene.translateMod = 1;
	for(int i = 0; i < 26; i++){
		if(getCuZ(&(app->scene), i) == app->vizTengely){						
			setAnZ(&(app->scene), i, 1);
			setAngle(&(app->scene), i, -ertek);
		}
	}
}

void forgatas_szin_viszszintes(App* app, int irany){
	double face_colors_temp[8][4][3];
	double face_colors_UP[8][3];
	double face_colors_Down[8][3];
	int real_cube[8];
	int temp_cube[8];
	int elfor_oldal = 0;
	int elfor_kocka = 0;
	int eltolas_oldal = 0;
	int eltolas_kocka = 0;
	double szog = 0;
	int side_number[4];
	
	if(irany == 1){
		side_number[0] = 1;
		side_number[1] = 4;
		side_number[2] = 2;
		side_number[3] = 5;
		if(app->vizTengely == 0){
			real_cube[0] = 0;
			real_cube[1] = 1;
			real_cube[2] = 2;
			real_cube[3] = 10;
			real_cube[4] = 19;
			real_cube[5] = 18;
			real_cube[6] = 17;
			real_cube[7] = 9;
		}else if(app->vizTengely == 1){
			real_cube[0] = 3;
			real_cube[1] = 4;
			real_cube[2] = 5;
			real_cube[3] = 13;
			real_cube[4] = 22;
			real_cube[5] = 21;
			real_cube[6] = 20;
			real_cube[7] = 11;
		}else if(app->vizTengely == -1){
			real_cube[0] = 6;
			real_cube[1] = 7;
			real_cube[2] = 8;
			real_cube[3] = 16;
			real_cube[4] = 25;
			real_cube[5] = 24;
			real_cube[6] = 23;
			real_cube[7] = 14;
		}
	}else if(irany == 2){
		side_number[0] = 1;
		side_number[1] = 5;
		side_number[2] = 2;
		side_number[3] = 4;
		if(app->vizTengely == 0){
			real_cube[0] = 0;
			real_cube[1] = 9;
			real_cube[2] = 17;
			real_cube[3] = 18;
			real_cube[4] = 19;
			real_cube[5] = 10;
			real_cube[6] = 2;
			real_cube[7] = 1;
		}else if(app->vizTengely == 1){
			real_cube[0] = 3;
			real_cube[1] = 11;
			real_cube[2] = 20;
			real_cube[3] = 21;
			real_cube[4] = 22;
			real_cube[5] = 13;
			real_cube[6] = 5;
			real_cube[7] = 4;
		}else if(app->vizTengely == -1){
			real_cube[0] = 6;
			real_cube[1] = 14;
			real_cube[2] = 23;
			real_cube[3] = 24;
			real_cube[4] = 25;
			real_cube[5] = 16;
			real_cube[6] = 8;
			real_cube[7] = 7;
		}
	}
	
	int kocka = 0;
	while(getAngle(&(app->scene), kocka) == 0){
		kocka++;
	}
	
	if(irany == 1){
		szog = getAngle(&(app->scene), kocka);
	}else if(irany == 2){
		szog = getAngle(&(app->scene), kocka) * -1;
	}
	while(szog > 360){
		szog -= 360;
	}
	if(szog > 45 && szog <= 135){
		elfor_oldal = 1;
		elfor_kocka = 2;
	}else if(szog > 135 && szog <= 225){
		elfor_oldal = 2;
		elfor_kocka = 4;
	}else if(szog > 225 && szog <= 315){
		elfor_oldal = 3;
		elfor_kocka = 6;
	}
	
	for(int i = 0; i < 8; i++){
		eltolas_kocka = i - elfor_kocka;
		if(eltolas_kocka == -1){
			eltolas_kocka = 7;
		}
		if(eltolas_kocka == -2){
			eltolas_kocka = 6;
		}
		if(eltolas_kocka == -3){
			eltolas_kocka = 5;
		}
		if(eltolas_kocka == -4){
			eltolas_kocka = 4;
		}
		if(eltolas_kocka == -5){
			eltolas_kocka = 3;
		}
		if(eltolas_kocka == -6){
			eltolas_kocka = 2;
		}
		temp_cube[i] = real_cube[eltolas_kocka];
	}
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 4; j++){
			eltolas_oldal = j -elfor_oldal;
			if(eltolas_oldal == -1){
				eltolas_oldal = 3;
			}
			if(eltolas_oldal == -2){
				eltolas_oldal = 2;
			}
			if(eltolas_oldal == -3){
				eltolas_oldal = 1;
			}
			face_colors_temp[i][j][0] = get_cube_color_R(&(app->scene.kocka[temp_cube[i]]), side_number[eltolas_oldal]);
			face_colors_temp[i][j][1] = get_cube_color_G(&(app->scene.kocka[temp_cube[i]]), side_number[eltolas_oldal]);
			face_colors_temp[i][j][2] = get_cube_color_B(&(app->scene.kocka[temp_cube[i]]), side_number[eltolas_oldal]);
		}
	}
	
	for(int i = 0; i < 8; i++){
		face_colors_UP[i][0] = get_cube_color_R(&(app->scene.kocka[temp_cube[i]]), 0);
		face_colors_UP[i][1] = get_cube_color_G(&(app->scene.kocka[temp_cube[i]]), 0);
		face_colors_UP[i][2] = get_cube_color_B(&(app->scene.kocka[temp_cube[i]]), 0);
		face_colors_Down[i][0] = get_cube_color_R(&(app->scene.kocka[temp_cube[i]]), 3);
		face_colors_Down[i][1] = get_cube_color_G(&(app->scene.kocka[temp_cube[i]]), 3);
		face_colors_Down[i][2] = get_cube_color_B(&(app->scene.kocka[temp_cube[i]]), 3);
	}
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 4; j++){
			set_cube_color(&(app->scene.kocka[real_cube[i]]), face_colors_temp[i][j][0], face_colors_temp[i][j][1], face_colors_temp[i][j][2], side_number[j]);
		}
		set_cube_color(&(app->scene.kocka[real_cube[i]]), face_colors_UP[i][0], face_colors_UP[i][1], face_colors_UP[i][2], 0);
		set_cube_color(&(app->scene.kocka[real_cube[i]]), face_colors_Down[i][0], face_colors_Down[i][1], face_colors_Down[i][2], 3);
	}
}

void forgatas_fel(App* app, int ertek){
	app->scene.translateMod = 1;
	for(int i = 0; i < 26; i++){
		if(app->scene.tengelyY_X == 0){
			if(getCuY(&(app->scene), i) == app->fugTengely){						
				setAnY(&(app->scene), i, 1);
				setAngle(&(app->scene), i, ertek);
			}
		}else if(app->scene.tengelyY_X == 1){
			if(getCuX(&(app->scene), i) == app->fugTengely){						
				setAnX(&(app->scene), i, 1);
				setAngle(&(app->scene), i, ertek);
			}
		}
	}
}

void forgatas_le(App* app, int ertek){
	app->scene.translateMod = 1;
	for(int i = 0; i < 26; i++){
		if(app->scene.tengelyY_X == 0){
			if(getCuY(&(app->scene), i) == app->fugTengely){						
				setAnY(&(app->scene), i, 1);
				setAngle(&(app->scene), i, -ertek);
			}
		}else if(app->scene.tengelyY_X == 1){
			if(getCuX(&(app->scene), i) == app->fugTengely){						
				setAnX(&(app->scene), i, 1);
				setAngle(&(app->scene), i, -ertek);
			}
		}
	}
}

void forgatas_szin_fugolegesen(App* app, int irany){
	double face_colors_temp[8][4][3];
	double face_colors_UP[8][3];
	double face_colors_Down[8][3];
	int real_cube[8];
	int temp_cube[8];
	int elfor_oldal = 0;
	int elfor_kocka = 0;
	int eltolas_oldal = 0;
	int eltolas_kocka = 0;
	double szog = 0;
	int side_number[4];
	
	if(app->scene.tengelyY_X == 0){
		if(irany == 1){
			side_number[0] = 0;
			side_number[1] = 2;
			side_number[2] = 3;
			side_number[3] = 1;
			if(app->fugTengely == 0){
				real_cube[0] = 11;
				real_cube[1] = 9;
				real_cube[2] = 14;
				real_cube[3] = 15;
				real_cube[4] = 16;
				real_cube[5] = 10;
				real_cube[6] = 13;
				real_cube[7] = 12;
			}else if(app->fugTengely == -1){
				real_cube[0] = 20;
				real_cube[1] = 17;
				real_cube[2] = 23;
				real_cube[3] = 24;
				real_cube[4] = 25;
				real_cube[5] = 19;
				real_cube[6] = 22;
				real_cube[7] = 21;
			}else if(app->fugTengely == 1){
				real_cube[0] = 3;
				real_cube[1] = 0;
				real_cube[2] = 6;
				real_cube[3] = 7;
				real_cube[4] = 8;
				real_cube[5] = 2;
				real_cube[6] = 5;
				real_cube[7] = 4;
			}
		}else if(irany == 2){
			side_number[0] = 0;
			side_number[1] = 1;
			side_number[2] = 3;
			side_number[3] = 2;
			if(app->fugTengely == 0){
				real_cube[0] = 11;
				real_cube[1] = 12;
				real_cube[2] = 13;
				real_cube[3] = 10;
				real_cube[4] = 16;
				real_cube[5] = 15;
				real_cube[6] = 14;
				real_cube[7] = 9;
			}else if(app->fugTengely == -1){
				real_cube[0] = 20;
				real_cube[1] = 21;
				real_cube[2] = 22;
				real_cube[3] = 19;
				real_cube[4] = 25;
				real_cube[5] = 24;
				real_cube[6] = 23;
				real_cube[7] = 17;
			}else if(app->fugTengely == 1){
				real_cube[0] = 3;
				real_cube[1] = 4;
				real_cube[2] = 5;
				real_cube[3] = 2;
				real_cube[4] = 8;
				real_cube[5] = 7;
				real_cube[6] = 6;
				real_cube[7] = 0;
			}
		}
	}else if(app->scene.tengelyY_X == 1){
		if(irany == 1){
			side_number[0] = 0;
			side_number[1] = 4;
			side_number[2] = 3;
			side_number[3] = 5;
			if(app->fugTengely == 0){
				real_cube[0] = 4;
				real_cube[1] = 12;
				real_cube[2] = 21;
				real_cube[3] = 18;
				real_cube[4] = 24;
				real_cube[5] = 15;
				real_cube[6] = 7;
				real_cube[7] = 1;
			}else if(app->fugTengely == -1){
				real_cube[0] = 5;
				real_cube[1] = 13;
				real_cube[2] = 22;
				real_cube[3] = 19;
				real_cube[4] = 25;
				real_cube[5] = 16;
				real_cube[6] = 8;
				real_cube[7] = 2;
			}else if(app->fugTengely == 1){
				real_cube[0] = 3;
				real_cube[1] = 11;
				real_cube[2] = 20;
				real_cube[3] = 17;
				real_cube[4] = 23;
				real_cube[5] = 14;
				real_cube[6] = 6;
				real_cube[7] = 0;
			}
		}else if(irany == 2){
			side_number[0] = 0;
			side_number[1] = 5;
			side_number[2] = 3;
			side_number[3] = 4;
			if(app->fugTengely == 0){
				real_cube[0] = 4;
				real_cube[1] = 1;
				real_cube[2] = 7;
				real_cube[3] = 15;
				real_cube[4] = 24;
				real_cube[5] = 18;
				real_cube[6] = 21;
				real_cube[7] = 12;
			}else if(app->fugTengely == -1){
				real_cube[0] = 5;
				real_cube[1] = 2;
				real_cube[2] = 8;
				real_cube[3] = 16;
				real_cube[4] = 25;
				real_cube[5] = 19;
				real_cube[6] = 22;
				real_cube[7] = 13;
			}else if(app->fugTengely == 1){
				real_cube[0] = 3;
				real_cube[1] = 0;
				real_cube[2] = 6;
				real_cube[3] = 14;
				real_cube[4] = 23;
				real_cube[5] = 17;
				real_cube[6] = 20;
				real_cube[7] = 11;
			}
		}
	}
	
	int kocka = 0;
	while(getAngle(&(app->scene), kocka) == 0){
		kocka++;
	}
	
	if(irany == 1){
		szog = getAngle(&(app->scene), kocka);
	}else if(irany == 2){
		szog = getAngle(&(app->scene), kocka) * -1;
	}
	while(szog > 360){
		szog -= 360;
	}
	if(szog > 45 && szog <= 135){
		elfor_oldal = 1;
		elfor_kocka = 2;
	}else if(szog > 135 && szog <= 225){
		elfor_oldal = 2;
		elfor_kocka = 4;
	}else if(szog > 225 && szog <= 315){
		elfor_oldal = 3;
		elfor_kocka = 6;
	}
	
	for(int i = 0; i < 8; i++){
		eltolas_kocka = i - elfor_kocka;
		if(eltolas_kocka == -1){
			eltolas_kocka = 7;
		}
		if(eltolas_kocka == -2){
			eltolas_kocka = 6;
		}
		if(eltolas_kocka == -3){
			eltolas_kocka = 5;
		}
		if(eltolas_kocka == -4){
			eltolas_kocka = 4;
		}
		if(eltolas_kocka == -5){
			eltolas_kocka = 3;
		}
		if(eltolas_kocka == -6){
			eltolas_kocka = 2;
		}
		temp_cube[i] = real_cube[eltolas_kocka];
	}
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 4; j++){
			eltolas_oldal = j -elfor_oldal;
			if(eltolas_oldal == -1){
				eltolas_oldal = 3;
			}
			if(eltolas_oldal == -2){
				eltolas_oldal = 2;
			}
			if(eltolas_oldal == -3){
				eltolas_oldal = 1;
			}
			face_colors_temp[i][j][0] = get_cube_color_R(&(app->scene.kocka[temp_cube[i]]), side_number[eltolas_oldal]);
			face_colors_temp[i][j][1] = get_cube_color_G(&(app->scene.kocka[temp_cube[i]]), side_number[eltolas_oldal]);
			face_colors_temp[i][j][2] = get_cube_color_B(&(app->scene.kocka[temp_cube[i]]), side_number[eltolas_oldal]);
		}
	}
	
	for(int i = 0; i < 8; i++){
		if(app->scene.tengelyY_X == 0){
			face_colors_UP[i][0] = get_cube_color_R(&(app->scene.kocka[temp_cube[i]]), 4);
			face_colors_UP[i][1] = get_cube_color_G(&(app->scene.kocka[temp_cube[i]]), 4);
			face_colors_UP[i][2] = get_cube_color_B(&(app->scene.kocka[temp_cube[i]]), 4);
			face_colors_Down[i][0] = get_cube_color_R(&(app->scene.kocka[temp_cube[i]]), 5);
			face_colors_Down[i][1] = get_cube_color_G(&(app->scene.kocka[temp_cube[i]]), 5);
			face_colors_Down[i][2] = get_cube_color_B(&(app->scene.kocka[temp_cube[i]]), 5);
		}else if(app->scene.tengelyY_X == 1){
			face_colors_UP[i][0] = get_cube_color_R(&(app->scene.kocka[temp_cube[i]]), 2);
			face_colors_UP[i][1] = get_cube_color_G(&(app->scene.kocka[temp_cube[i]]), 2);
			face_colors_UP[i][2] = get_cube_color_B(&(app->scene.kocka[temp_cube[i]]), 2);
			face_colors_Down[i][0] = get_cube_color_R(&(app->scene.kocka[temp_cube[i]]), 1);
			face_colors_Down[i][1] = get_cube_color_G(&(app->scene.kocka[temp_cube[i]]), 1);
			face_colors_Down[i][2] = get_cube_color_B(&(app->scene.kocka[temp_cube[i]]), 1);
		}
	}
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 4; j++){
			set_cube_color(&(app->scene.kocka[real_cube[i]]), face_colors_temp[i][j][0], face_colors_temp[i][j][1], face_colors_temp[i][j][2], side_number[j]);
		}
		if(app->scene.tengelyY_X == 0){
			set_cube_color(&(app->scene.kocka[real_cube[i]]), face_colors_UP[i][0], face_colors_UP[i][1], face_colors_UP[i][2], 4);
			set_cube_color(&(app->scene.kocka[real_cube[i]]), face_colors_Down[i][0], face_colors_Down[i][1], face_colors_Down[i][2], 5);
		}else if(app->scene.tengelyY_X == 1){
			set_cube_color(&(app->scene.kocka[real_cube[i]]), face_colors_UP[i][0], face_colors_UP[i][1], face_colors_UP[i][2], 2);
			set_cube_color(&(app->scene.kocka[real_cube[i]]), face_colors_Down[i][0], face_colors_Down[i][1], face_colors_Down[i][2], 1);
		}
	}
}


void forgatas_sehova(App* app){
	app->scene.translateMod = 0;
	for(int i = 0; i < 26; i++){
		setAnZ(&(app->scene), i, 0);
		setAnX(&(app->scene), i, 0);
		setAnY(&(app->scene), i, 0);
		setAngleDefault(&(app->scene), i, 0);
	}				
	app->scene.rotate = 0;
}

void fegy_fel(App* app, double ertek){
	if(app->scene.primary_light < 1.0f){
		app->scene.primary_light += ertek;
	}
    if(app->scene.secondary_light < 0.75f){
		app->scene.secondary_light += ertek;
	}
	if(app->scene.tertiary_light < 0.5f){
		app->scene.tertiary_light += ertek;
	}
}

void fegy_le(App* app, double ertek){
	if(app->scene.primary_light > 0.5f){
		app->scene.primary_light -= ertek;		
	}
	if(app->scene.secondary_light > 0.25f){
		app->scene.secondary_light -= ertek;		
	}
	if(app->scene.tertiary_light > 0.15f){
		app->scene.tertiary_light -= ertek;
	}
}

void kocka_szin_feny(App* app){
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 6; j++){
			double red = get_cube_color_R(&(app->scene.kocka[i]), j);
			double green = get_cube_color_G(&(app->scene.kocka[i]), j);
			double blue = get_cube_color_B(&(app->scene.kocka[i]), j);
			if(j == 0){
				if(red > 0.12){
				red = app->scene.primary_light;
				}
				if(green > 0.12){
					green = app->scene.primary_light;
				}
				if(blue > 0.12){
					blue = app->scene.primary_light;
				}
			}
			if(j == 3){
				if(red > 0.12){
				red = app->scene.tertiary_light;
				}
				if(green > 0.12){
					green = app->scene.tertiary_light;
				}
				if(blue > 0.12){
					blue = app->scene.tertiary_light;
				}
			}
			if(j > 0 && j != 3){
				if(red > 0.12){
				red = app->scene.secondary_light;
				}
				if(green > 0.12){
					green = app->scene.secondary_light;
				}
				if(blue > 0.12){
					blue = app->scene.secondary_light;
				}
			}
			set_cube_color(&(app->scene.kocka[i]), red, green, blue, j);
		}
	}
}

void set_random_color(App* app){
	for(int i = 0; i < 26; i++){
		set_default_color(&(app->scene.kocka[i]));
	}
	app->scene.gyoz = 2;
	srand(time(0));
	
	int rand_cik = rand()%(20-5+1)+5;
	
	for(int i = 0; i < rand_cik; i++){
		int szog = rand()%(270-90+1)+90;
		int cselekves = rand()%(15-1+1)+1;
		app->vizTengely = rand()%(1-(-1)+1)+(-1);
		app->fugTengely = rand()%(1-(-1)+1)+(-1);
		app->scene.tengelyY_X = rand()%(1-0+1)+0;
		if(cselekves <= 5){
			
			setAngle(&(app->scene), 0, szog);
			forgatas_szin_fugolegesen(app, 1);
			setAngleDefault(&(app->scene), 0, 0);
		}else if(cselekves > 5 && cselekves <= 10){
			
			setAngle(&(app->scene), 0, szog);
			forgatas_szin_viszszintes(app, 1);
			setAngleDefault(&(app->scene), 0, 0);
		}
	}
	
	app->vizTengely = 0;
	app->fugTengely = 0;
	app->scene.tengelyY_X = 0;
}

void test_szin(App* app){
	for(int i = 0; i < 26; i++){
		set_default_color(&(app->scene.kocka[i]));
	}
	
	setAngle(&(app->scene), 0, 90);
	forgatas_szin_fugolegesen(app, 1);
	setAngleDefault(&(app->scene), 0, 0);
	
	setAngle(&(app->scene), 0, 90);
	forgatas_szin_viszszintes(app, 1);
	setAngleDefault(&(app->scene), 0, 0);
	
	setAngle(&(app->scene), 0, 90);
	forgatas_szin_fugolegesen(app, 1);
	setAngleDefault(&(app->scene), 0, 0);
}

void ellenorzo(App* app){
	
	int szin_oldal[6][6];
	int egyezo_hat_oldal = 0;
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			szin_oldal[i][j] = 0;
		}
	}
	
	for(int i = 0; i < 26; i++){
		if(app->scene.cubesdate[i][1] == 1){
			if(get_cube_color_R(&(app->scene.kocka[i]), 5) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 5) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 5) == app->scene.secondary_light){
				szin_oldal[5][0] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 5) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 5) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 5) == app->scene.secondary_light){
				szin_oldal[5][1] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 5) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 5) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 5) == 0){
				szin_oldal[5][2] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 5) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 5) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 5) == 0){
				szin_oldal[5][3] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 5) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 5) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 5) == app->scene.secondary_light){
				szin_oldal[5][4] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 5) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 5) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 5) == 0){
				szin_oldal[5][5] += 1;
			}
		}
		if(app->scene.cubesdate[i][1] == -1){
			if(get_cube_color_R(&(app->scene.kocka[i]), 4) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 4) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 4) == app->scene.secondary_light){
				szin_oldal[4][0] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 4) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 4) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 4) == app->scene.secondary_light){
				szin_oldal[4][1] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 4) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 4) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 4) == 0){
				szin_oldal[4][2] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 4) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 4) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 4) == 0){
				szin_oldal[4][3] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 4) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 4) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 4) == app->scene.secondary_light){
				szin_oldal[4][4] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 4) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 4) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 4) == 0){
				szin_oldal[4][5] += 1;
			}
		}
		if(app->scene.cubesdate[i][0] == 1){
			if(get_cube_color_R(&(app->scene.kocka[i]), 2) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 2) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 2) == app->scene.secondary_light){
				szin_oldal[2][0] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 2) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 2) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 2) == app->scene.secondary_light){
				szin_oldal[2][1] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 2) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 2) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 2) == 0){
				szin_oldal[2][2] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 2) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 2) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 2) == 0){
				szin_oldal[2][3] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 2) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 2) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 2) == app->scene.secondary_light){
				szin_oldal[2][4] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 2) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 2) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 2) == 0){
				szin_oldal[2][5] += 1;
			}
		}
		if(app->scene.cubesdate[i][0] == -1){
			if(get_cube_color_R(&(app->scene.kocka[i]), 1) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 1) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 1) == app->scene.secondary_light){
				szin_oldal[1][0] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 1) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 1) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 1) == app->scene.secondary_light){
				szin_oldal[1][1] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 1) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 1) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 1) == 0){
				szin_oldal[1][2] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 1) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 1) == app->scene.secondary_light && get_cube_color_B(&(app->scene.kocka[i]), 1) == 0){
				szin_oldal[1][3] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 1) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 1) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 1) == app->scene.secondary_light){
				szin_oldal[1][4] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 1) == app->scene.secondary_light && get_cube_color_G(&(app->scene.kocka[i]), 1) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 1) == 0){
				szin_oldal[1][5] += 1;
			}
		}
		if(app->scene.cubesdate[i][2] == 1){
			if(get_cube_color_R(&(app->scene.kocka[i]), 0) == app->scene.primary_light && get_cube_color_G(&(app->scene.kocka[i]), 0) == app->scene.primary_light && get_cube_color_B(&(app->scene.kocka[i]), 0) == app->scene.primary_light){
				szin_oldal[0][0] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 0) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 0) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 0) == app->scene.primary_light){
				szin_oldal[0][1] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 0) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 0) == app->scene.primary_light && get_cube_color_B(&(app->scene.kocka[i]), 0) == 0){
				szin_oldal[0][2] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 0) == app->scene.primary_light && get_cube_color_G(&(app->scene.kocka[i]), 0) == app->scene.primary_light && get_cube_color_B(&(app->scene.kocka[i]), 0) == 0){
				szin_oldal[0][3] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 0) == app->scene.primary_light && get_cube_color_G(&(app->scene.kocka[i]), 0) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 0) == app->scene.primary_light){
				szin_oldal[0][4] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 0) == app->scene.primary_light && get_cube_color_G(&(app->scene.kocka[i]), 0) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 0) == 0){
				szin_oldal[0][5] += 1;
			}
		}
		if(app->scene.cubesdate[i][2] == -1){
			if(get_cube_color_R(&(app->scene.kocka[i]), 3) == app->scene.tertiary_light && get_cube_color_G(&(app->scene.kocka[i]), 3) == app->scene.tertiary_light && get_cube_color_B(&(app->scene.kocka[i]), 3) == app->scene.tertiary_light){
				szin_oldal[3][0] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 3) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 3) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 3) == app->scene.tertiary_light){
				szin_oldal[3][1] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 3) == 0 && get_cube_color_G(&(app->scene.kocka[i]), 3) == app->scene.tertiary_light && get_cube_color_B(&(app->scene.kocka[i]), 3) == 0){
				szin_oldal[3][2] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 3) == app->scene.tertiary_light && get_cube_color_G(&(app->scene.kocka[i]), 3) == app->scene.tertiary_light && get_cube_color_B(&(app->scene.kocka[i]), 3) == 0){
				szin_oldal[3][3] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 3) == app->scene.tertiary_light && get_cube_color_G(&(app->scene.kocka[i]), 3) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 3) == app->scene.tertiary_light){
				szin_oldal[3][4] += 1;
			}
			if(get_cube_color_R(&(app->scene.kocka[i]), 3) == app->scene.tertiary_light && get_cube_color_G(&(app->scene.kocka[i]), 3) == 0 && get_cube_color_B(&(app->scene.kocka[i]), 3) == 0){
				szin_oldal[3][5] += 1;
			}
		}
	}
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if(szin_oldal[i][j] == 9){
				egyezo_hat_oldal += 1;
				break;
			}
		}
	}
	
	if(egyezo_hat_oldal == 6){
		app->scene.gyoz = 1;
	}
}