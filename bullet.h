//MishalAli 22i-1291 K project'23


#include <SFML/Graphics.hpp>
#include<string.h>


using namespace sf;
using namespace std;


//BULLET CLASS
class Bullet
{   public:	
	Texture tex2;
	Sprite bullet;
	float bullspeed=1.5;
	int x,y;
	bool isactive=0;	//to see fire

	//constructor setting its image
	Bullet()
	{	tex2.loadFromFile("img/bullett1.png");
		bullet.setTexture(tex2);
		x=375; y=690;
		bullet.setPosition(x,y);
		bullet.setScale(0.65,0.65);
	}
	
void changetext(Texture t)
{	bullet.setTexture(t);
}

// moving the bullet up	w/o changing x cordinate
void move()
{
    bullet.move(0, -bullspeed);
}
//updating its positiion
void update()
{	if (isactive)
	{ bullet.move(0, -bullspeed);
		/*if (bullet.getPosition().y<-10)
		{	isactive=0;
		}*/
		
	}
}
//setting bullets position as per players
void setpos(float x, float y)
{	bullet.setPosition(x,y);
}
//firing the bullet
void fire( int x, int y)
{	setpos(x,y);
	isactive=1;
}

int getposx()
{	 int x;
	 x=bullet.getPosition().x;
	 return x;
}

int getposy()
{ 	int y;
	y=bullet.getPosition().y;
	return y;
}
	
};

