#include <SDL2/SDL.h>
#include "line.h"
#include "color.h"
#include "square.h"
#include <stdbool.h>
#include <stdio.h>

/**
 * Vonalakat rajzolo példa
 */
int main(int argc, char* argv[])
{
  int error_code;
  SDL_Window* window;
  bool need_run;
  SDL_Event event;
  SDL_Renderer* renderer;
  int i;
  Line line;
  set_line_data(&line, 0, 0, 25, 0);
  Color color;
  set_color_data(&color, 255, 255, 255);
  Square square;
  set_square_data(&square, 0, 0, 25, 0);
  int max_line = 0;
  int max_square = 0;

  error_code = SDL_Init(SDL_INIT_EVERYTHING);
  if (error_code != 0) {
    printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
    return error_code;
  }

  window = SDL_CreateWindow(
    "Hello SDL!",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    800, 600, 0);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  void kepernyo(){
	  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	  SDL_RenderClear(renderer);
	  int palet_color_r = 255;
	  int palet_color_g = 0;
	  int palet_color_b = 30;
	  int leptetes = 0;
	  for (i = 0; i < 300; ++i) {
		  SDL_SetRenderDrawColor(renderer, palet_color_r, palet_color_g, palet_color_b, SDL_ALPHA_OPAQUE);
		  SDL_RenderDrawLine(renderer, 0, i * 2, 25, i * 2);
		  leptetes++;
		  if(leptetes == 15){
			  palet_color_r = palet_color_r +100;
			  palet_color_g = palet_color_g +10;
			  palet_color_b = palet_color_b +50;
			  leptetes = 0;
		  }
	   }
	   SDL_RenderPresent(renderer);
 }
  kepernyo();
  
  void negyzet_rajzolas(double sx1, double sy1, double sx2, double sy2){
	  double x1, y1, x2, y2;
	  int magassag;
	  if(sx1 <= sx2){
		  x1 = sx1;
		  x2 = sx2;
	  }else if(sx1 > sx2){
		  x1 = sx2;
		  x2 = sx1;
	  }
	  if(sy1 <= sy2){
		  y1 = sy1;
		  y2 = sy2;
	  }else if(sy1 > sy2){
		  y1 = sy2;
		  y2 = sy1;
	  }
	  for(int s = y1; s <= y2; s++){
		  SDL_RenderDrawLine(renderer, x1, s, x2, s);
		  SDL_RenderPresent(renderer);
	  }
  }
	

  need_run = true;
  while (need_run) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_KEYDOWN:
        case SDL_SCANCODE_Q:
        need_run = false;
        break;
      case SDL_QUIT:
        need_run = false;
        break;
      }
	  if(event.type == SDL_MOUSEBUTTONDOWN){
		  if(event.button.x > 25){
			  if(event.button.button == SDL_BUTTON_LEFT){
				  if(max_line > 4){
					  max_line = 0;
					  max_square = 0;
					  kepernyo();
				  }
				  max_line++;
				  set_line_data(&line, get_x2(&line), get_y2(&line), event.button.x, event.button.y);
				  SDL_SetRenderDrawColor(renderer, get_red(&color), get_green(&color), get_blue(&color), SDL_ALPHA_OPAQUE);
				  SDL_RenderDrawLine(renderer, get_x1(&line), get_y1(&line), get_x2(&line), get_y2(&line));
				  SDL_RenderPresent(renderer);
				}
				if(event.button.button == SDL_BUTTON_RIGHT){
					if(max_square > 1){
					  max_square = 0;
					  max_line = 0;
					  kepernyo();
					}
					max_square++;
					set_square_data(&square, get_Sx2(&square), get_Sy2(&square), event.button.x, event.button.y);
					SDL_SetRenderDrawColor(renderer, get_red(&color), get_green(&color), get_blue(&color), SDL_ALPHA_OPAQUE);
					negyzet_rajzolas(get_Sx1(&square), get_Sy1(&square), get_Sx2(&square), get_Sy2(&square));
				}
		  }else if(event.button.x < 26){
			  int j;
			  for(j = 0; j < 300; j++){
				  if(event.button.y > j*30 && event.button.y < 31+(j*30)){
					  if(event.button.button == SDL_BUTTON_LEFT){
						  set_color_data(&color, 255+(j*100), 0+(j*10), 30+(j*50));
					  }
				  }
			  }
		  }
		}
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}