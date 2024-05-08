//MishalAli 22i-1291 K project'23


#include <SFML/Graphics.hpp>
#include<string.h>
#include "bullet.h"
#include "addon.h"


using namespace sf;
using namespace std;


//PLAYER CLASS
class Player
{	
 public:
	Texture tex;
	Texture tex1;
	Texture tex2;
	Texture tex3;
	
	Sprite sprite;
	Sprite og;
	Sprite ul;
	Sprite ur;
	float speed=2.2;
	int x,y;
	Bullet * bull;
	float bulltimegap;
	Powerup* power;
	Lifes* lyf;
	Danger* dang;
	Firee* fire;
	//int timeremain=0;
	
	
	
	Player(string png_path)
	{	//bull=new Bullet("img/bullett.png");
		tex.loadFromFile(png_path);
		tex1.loadFromFile("img/1.png");
		tex2.loadFromFile("img/2.png");

		sprite.setTexture(tex);
		
		x=340;y=700;
		sprite.setPosition(x,y);
		sprite.setScale(0.75,0.75);
		
		bulltimegap=0.0;
		bull= new Bullet [200];	//bullet obj
		
		power=new Powerup();
		lyf=new Lifes();
		dang=new Danger();
		fire= new Firee();
	}
	
	
	

//firing w/ delay of 0.6 secs	
void fire1()
{	if( Keyboard::isKeyPressed(Keyboard::Space))
	{ 	
	for (int i=0; i<200; i++)
		{	if (!bull[i].isactive )
			{	
				bull[i].fire( sprite.getPosition().x+35,  sprite.getPosition().y);//setting the new bullets location to players cordinates
			bulltimegap=0.0;
			break;
			}
		}
		
		
		
	}
	
}
//displaying bullets on the screen
void drawBull(RenderWindow & window)
{	for (int i=0; i<200; i++)	
	{	if(bull[i].isactive)
		{	window.draw(bull[i].bullet);
		}
	}
}
//updating the bullets till 200 reache d
void updateBull()
{	for (int i=0; i<200; i++)
	{	bull[i+1].update();
	}
	


}


/*
void activatepowerup()
{	if(sprite.getGlobalBounds().intersects(power->addon.getGlobalBounds()))
	{	Texture fire;
		fire.loadFromFile("img/fire00.png");
		power->isactive=0;
	while ( power->timremain<0);
		bull->changetext(fire);
		fire1();
		power->timremain--;
	}

}
*/


void setpos(int x, int y)
{	sprite.setPosition(x,y);
}

int getposx()
{	 int x;
	 x=sprite.getPosition().x;
	 return x;
}

int getposy()
{ 	int y;
	y=sprite.getPosition().y;
	return y;
}

//bool collisioncheck(Enemy & enemy);	//checking the cordinates of player and bullet w/ enemy

//	MOVEMENT of the player ship
void move(string s)
{	float delta_x=0,delta_y=0;

	
if(s=="l")
	{delta_x=-1;
	sprite.setTexture(tex);
	
	}//move the player left
else if(s=="r")
	{delta_x=+1;
	sprite.setTexture(tex);;
	}//move the player right
else if(s=="u")
	{delta_y=-1;
	sprite.setTexture(tex);}//move the player up
else if(s=="d")
	{delta_y=1;
	sprite.setTexture(tex);}//move the player down
else if (s=="ur")
 	sprite.setTexture(tex1);//move the player diagonally	
else if(s=="ul")
	sprite.setTexture(tex2);//move the player diagonally
else if (s=="dr")
 	sprite.setTexture(tex);//move the player diagonally	
 	
else if(s=="dl")
	sprite.setTexture(tex);//move the player diagonally
	
	


delta_x*=speed;
delta_y*=speed;
sprite.move(delta_x, delta_y);


//	WRAP AROUND
	//wrap around x-axis
 if (sprite.getPosition().x < 0) //wrap around from left
    {	sprite.setPosition(sprite.getPosition().x + 800, sprite.getPosition().y);
    } 
    else if (sprite.getPosition().x > 800) //wrap around from right
    {	sprite.setPosition(sprite.getPosition().x - 800, sprite.getPosition().y);
    }
   	//wrap around y-axis 
    if (sprite.getPosition().y < 0) //wrap around from top
    {	sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 750);
    } 
    else if (sprite.getPosition().y > 750)//wrap around from bottom 
    {	sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 750);
    }
}

};

