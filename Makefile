game:main.o  backgroundfunc.o Menufunctions.o menu1.o AffichageObj.o playermov.o  InitObjet.o collisionbb.o rot.o scrolling.o jump.o ennemi.o ia.o collision.o enigf.o
	gcc main.o backgroundfunc.o jump.o menu1.o AffichageObj.o enigf.o collisionbb.o rot.o playermov.o ennemi.o collision.o scrolling.o InitObjet.o Menufunctions.o ia.o -o game -lSDL  -lSDL_ttf -lSDL_image -lSDL_mixer -lSDL_gfx -g
menu1.o:menu1.c
	gcc -c menu1.c -lSDL -lSDL_image -lSDL_mixer -g
Menufunctions.o:Menufunctions.c
	gcc -c Menufunctions.c -lSDL -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_gfx -g
backgroundfunc.o:backgroundfunc.c
	gcc -c backgroundfunc.c -lSDL -lSDL_image -lSDL_mixer -lSDL_gfx -g
jump.o:jump.c
	gcc -c jump.c -lSDL -lSDL_image -lSDL_mixer -lSDL_gfx -g
playermov.o:playermov.c
	gcc -c playermov.c -lSDL -lSDL_image -lSDL_gfx -g
scrolling.o:scrolling.c
	gcc -c scrolling.c -lSDL -lSDL_image -lSDL_gfx -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -lSDL -lSDL_image -lSDL_gfx -g
collision.o:collision.c
	gcc -c collision.c -lSDL -lSDL_image -g
AffichageObj.o:AffichageObj.c
	gcc -c AffichageObj.c -lSDL -lSDL_image -g
InitObjet.o:InitObjet.c
	gcc -c InitObjet.c -lSDL -lSDL_image -g 
collisionbb.o:collisionbb.c
	gcc -c collisionbb.c -lSDL -lSDL_image -g 
enigf.o:enigf.c
	gcc -c enigf.c -lSDL -lSDL_image -g 
rot.o:rot.c
	gcc -c rot.c -lSDL -lSDL_image -lSDL_gfx -g  
ia.o:ia.c
	gcc -c ia.c -lSDL_image -g
