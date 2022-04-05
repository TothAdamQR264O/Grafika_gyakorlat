#include "app.h"

#include <SDL2/SDL_image.h>

void init_app(App* app, int width, int height)
{
    int error_code;
    int inited_loaders;

    app->is_running = false;

    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0) {
        printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
        return;
    }

    app->window = SDL_CreateWindow(
        "Cube!",
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
	app->tengelyY_X = 0;
}

void init_opengl()
{
    glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glClearColor(0.1, 0.1, 0.1, 1.0);

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
	int forseb = 15;
	int vizkoc = 1;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                app->is_running = false;
                break;
            case SDL_SCANCODE_W:
                set_camera_speed(&(app->camera), sebes);
                break;
            case SDL_SCANCODE_S:
                set_camera_speed(&(app->camera), -sebes);
                break;
            case SDL_SCANCODE_A:
                set_camera_side_speed(&(app->camera), sebes);
                break;
            case SDL_SCANCODE_D:
                set_camera_side_speed(&(app->camera), -sebes);
                break;
			case SDL_SCANCODE_X:
                set_camera_height_speed(&(app->camera),  sebes);
                break;
            case SDL_SCANCODE_Z:
                set_camera_height_speed(&(app->camera),  -sebes);
                break;
			case SDL_SCANCODE_Q:
				set_camera_rotate_horizontal(&(app->camera),  sebes);
                break;
			case SDL_SCANCODE_E:
                set_camera_rotate_horizontal(&(app->camera),  -sebes);
                break;
			case SDL_SCANCODE_R:
				set_camera_rotate_vertical(&(app->camera),  sebes);
                break;
			case SDL_SCANCODE_F:
                set_camera_rotate_vertical(&(app->camera),  -sebes);
                break;
			case SDL_SCANCODE_C:
                set_camera_default_view(&(app->camera));
                break;
			case SDL_SCANCODE_KP_PLUS:
				if(app->scene.primary_light < 1.0f){
					app->scene.primary_light += 0.25f;
				}
                if(app->scene.secondary_light < 0.75f){
					app->scene.secondary_light += 0.25f;
				}
				if(app->scene.tertiary_light < 0.5f){
					app->scene.tertiary_light += 0.25f;
				}
                break;
			case SDL_SCANCODE_KP_MINUS:
                if(app->scene.primary_light > 0.5f){
					app->scene.primary_light -= 0.25f;
				}
                if(app->scene.secondary_light > 0.25f){
					app->scene.secondary_light -= 0.25f;
				}
				if(app->scene.tertiary_light > 0.15f){
					app->scene.tertiary_light -= 0.25f;
				}
                break;
			case SDL_SCANCODE_KP_MULTIPLY:
                app->scene.primary_light = 1.0f;
				app->scene.secondary_light = 0.75f;
				app->scene.tertiary_light = 0.5f;
                break;
			case SDL_SCANCODE_RIGHT:
				app->scene.translateMod = 1;
				for(int i = 0; i < 26; i++){
					if(getCuZ(&(app->scene), i) == app->vizTengely){
						setAnZ(&(app->scene), i, 1);
						setAngle(&(app->scene), i, forseb);
					}
				}
				//app->scene.rotate = forseb;
                break;
			case SDL_SCANCODE_LEFT:
				app->scene.translateMod = 1;
				for(int i = 0; i < 26; i++){
					if(getCuZ(&(app->scene), i) == app->vizTengely){						
						setAnZ(&(app->scene), i, 1);
						setAngle(&(app->scene), i, -forseb);
					}
				}
				//app->scene.rotate = -forseb;
                break;
			case SDL_SCANCODE_UP:
				app->scene.translateMod = 1;
				for(int i = 0; i < 26; i++){
					if(app->tengelyY_X == 0){
						if(getCuY(&(app->scene), i) == app->fugTengely){						
							setAnY(&(app->scene), i, 1);
							setAngle(&(app->scene), i, forseb);
						}
					}else if(app->tengelyY_X == 1){
						if(getCuX(&(app->scene), i) == app->fugTengely){						
							setAnX(&(app->scene), i, 1);
							setAngle(&(app->scene), i, forseb);
						}
					}
				}
                break;
			case SDL_SCANCODE_DOWN:
				app->scene.translateMod = 1;
				for(int i = 0; i < 26; i++){
					if(app->tengelyY_X == 0){
						if(getCuY(&(app->scene), i) == app->fugTengely){						
							setAnY(&(app->scene), i, 1);
							setAngle(&(app->scene), i, -forseb);
						}
					}else if(app->tengelyY_X == 1){
						if(getCuX(&(app->scene), i) == app->fugTengely){						
							setAnX(&(app->scene), i, 1);
							setAngle(&(app->scene), i, -forseb);
						}
					}
				}
                break;
			case SDL_SCANCODE_G:
				
                break;
			case SDL_SCANCODE_T:
				setDefault(&(app->scene));
                break;
			case SDL_SCANCODE_KP_1:
				app->vizTengely = -1;
                break;
			case SDL_SCANCODE_KP_2:
				app->vizTengely = 0;
                break;
			case SDL_SCANCODE_KP_3:
				app->vizTengely = 1;
                break;
			case SDL_SCANCODE_KP_4:
				app->fugTengely = -1;
                break;
			case SDL_SCANCODE_KP_5:
				app->fugTengely = 0;
                break;
			case SDL_SCANCODE_KP_6:
				app->fugTengely = 1;
                break;
			case SDL_SCANCODE_KP_7:
				if(app->tengelyY_X == 0){
					app->tengelyY_X = 1;
				}else if(app->tengelyY_X == 1){
					app->tengelyY_X = 0;
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
			case SDL_SCANCODE_LEFT:
			case SDL_SCANCODE_UP:
			case SDL_SCANCODE_DOWN:
				app->scene.translateMod = 0;
				for(int i = 0; i < 26; i++){
					setAnZ(&(app->scene), i, 0);
					setAnX(&(app->scene), i, 0);
					setAnY(&(app->scene), i, 0);
					setAngleDefault(&(app->scene), i, 0);
				}				
				app->scene.rotate = 0;
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            is_mouse_down = true;
            break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x, &y);
            if (is_mouse_down) {
                rotate_camera(&(app->camera), mouse_x - x, mouse_y - y);
            }
            mouse_x = x;
            mouse_y = y;
            break;
        case SDL_MOUSEBUTTONUP:
            is_mouse_down = false;
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

    current_time = (double)SDL_GetTicks() / 1000;
    elapsed_time = current_time - app->uptime;
    app->uptime = current_time;

    update_camera(&(app->camera), elapsed_time);
    update_scene(&(app->scene), elapsed_time);
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
