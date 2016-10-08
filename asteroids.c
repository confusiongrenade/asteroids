//
//  asteroids.c
//  
//
//  Created by Nicholas Carroll on 11/1/15.
//
//


//
//
//
//
//  Created by Nicholas Carroll on 11/1/15.
//
//
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "gfx.h"
#include <math.h>
#include <unistd.h>


int main()
{  // establish all of the variables
    srand(time(NULL));
    int r = rand();
    int ra = rand();
    int i;
    double pi = acos(-1);
    int n;
    double angle;
    int xsize = 500;
    int ysize = 500;
    int radius = 10;
    int x;
    int y;
    int dx;
    int dy;
    int dxlaser =0, dylaser=0, xlaser =0 ,ylaser=0;
    int inside =1;
    char c;
    
    // Open a new window for drawing.
    gfx_open(xsize, ysize, "Example Graphics Program");
    
    angle =0;
    
    // Set the current drawing color
    gfx_color(0,200,100);
    
    // set up the screen, and the initial position
    dx = 0;
    dy = 0;
    
    gfx_clear();
    
    x=100;
    y = 100;
    x+=dx;
    y+=dy;
    
    gfx_line(x+radius*cos(angle),y+radius*sin(angle),x+radius*cos(angle+(2*pi/3)),y+radius*sin(angle+(2*pi/3)));
    gfx_line(x+radius*cos(angle+(2*pi/3)),y+radius*sin(angle+(2*pi/3)),x+radius*cos(angle+(4*pi/3)),y+radius*sin(angle+(4*pi/3)));
    gfx_line(x+radius*cos(angle),y+radius*sin(angle),x+radius*cos(angle+(4*pi/3)),y+radius*sin(angle+(4*pi/3)));
    gfx_flush();
    
    
    // use the keys to control the screen
    while(1) {
        // Wait for the user to press a character.
        
        // if a key is pressed, it captures that key
        if (gfx_event_waiting)
        {
        c = gfx_wait();
        }
       
        
        
        //  case structures based on in the input
        switch (c){
                
            
            case 'Q':
            case 'a': // rotate left
                angle-=(2*pi/16);
                break;
            case 'S':
            case 'd': //rotate right
                angle+=(2*pi/16);
                break;
            case 'R':
            case 'w': // accelerate
                dx +=5*cos(angle);
                dy +=5*sin(angle);
                break;
            case 'p': // p shoots a laser at the same angle as the front of the spaceship
                dxlaser = 25*cos(angle);
                dylaser = 25*sin(angle);
                xlaser = x;
                ylaser = y;
                
                // typing 1,2,or 3 chanes the color of everything
            case '1':
                gfx_color(0,200,0);
                break;
            case '2':
                gfx_color(0,0,200);
                break;
            case '3':
                gfx_color(200,0,0);
                break;
            default:
                break;
                
                
        }
        
        
        while (inside){
            usleep(100000);
            
            
            
            
            gfx_clear();
            
            // animate laser
            
            if (xlaser != 0)
            {
                gfx_line(xlaser, ylaser,(xlaser+dxlaser),(ylaser+dylaser));
                xlaser+=dxlaser;
                ylaser+=dylaser;
            }
            
            // animate spaceship
            x+=dx;
            y+=dy;
            
            gfx_line(x+radius*cos(angle),y+radius*sin(angle),x+radius*cos(angle+(2*pi/3)),y+radius*sin(angle+(2*pi/3)));
            gfx_line(x+radius*cos(angle+(2*pi/3)),y+radius*sin(angle+(2*pi/3)),x+radius*cos(angle+(4*pi/3)),y+radius*sin(angle+(4*pi/3)));
            gfx_line(x+radius*cos(angle),y+radius*sin(angle),x+radius*cos(angle+(4*pi/3)),y+radius*sin(angle+(4*pi/3)));
            gfx_flush();
            // if the spaceship goes out of bounds, it goes to the other side of the screen
            if (x>xsize)
                x-=xsize;
            if (x<0)
                x+=xsize;
            if (y>ysize)
                y-=ysize;
            if (y<0)
                y+=ysize;
            
            // this will update the space animation
            if (gfx_event_waiting())
                break;
        }
        
        
        if(c=='q') break;
    }
}