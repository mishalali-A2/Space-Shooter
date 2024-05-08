//MishalAli 22i-1291 K project'23


#include <SFML/Graphics.hpp>
#include<string.h>



using namespace sf;
using namespace std;

//BOMB CLASS
class Bomb
{ public:	
	Texture tex2;
	Sprite bomb;
	float bombspeed=1.8;
	int x,y;
	bool isactive=0;	//to see fire

	//constructor setting its image
	Bomb()
	{	tex2.loadFromFile("img/bomb1.png");
		bomb.setTexture(tex2);
		//bomb.setPosition(x,y);
		bomb.setScale(0.75,0.75);
	}

void setText(string png_path)
{ Texture t;
t.loadFromFile(png_path);	
bomb.setTexture(t);
	bomb.setScale(2,2);
}

// moving the bomb up	w/o changing x cordinate
void move()
{
    bomb.move(0, bombspeed);
}
//updating its positiion
void update()
{	if (isactive)
	{ bomb.move(0, bombspeed);
		if (bomb.getPosition().y>700)
			isactive=0;
	}
}
//setting bomb position as per enemies
void setpos(float x, float y)
{	bomb.setPosition(x,y);
}
//firing the bomb
void fire( int x, int y)
{	setpos(x,y);
	isactive=1;
}

int getposx()
{	 int x;
	 x=bomb.getPosition().x;
	 return x;
}

int getposy()
{ 	int y;
	y=bomb.getPosition().y;
	return y;
}


	
};



