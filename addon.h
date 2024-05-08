//MishalAli 22i-1291 K project'23


#include <SFML/Graphics.hpp>
#include<string.h>

using namespace sf;
using namespace std;



class Addon {

public:	
	Texture tadd;
	//Texture tom;
	Sprite addon;
	bool demolish=0;
	bool isactive=0;
	//int score;
float addonspeed=2.0;
	
	Addon(string png_path, int x, int y)
{	tadd.loadFromFile(png_path);
	addon.setTexture(tadd);
	addon.setPosition(x,y);
	addon.setScale(1.25,1.25);
}


void setpos(float x, float y)
{	addon.setPosition(x,y);
}

int getposx()
{	 int x;
	 x=addon.getPosition().x;
	 return x;
}

int getposy()
{ 	int y;
	y=addon.getPosition().y;
	return y;
}

virtual void draw(RenderWindow & wind ) 
{	if (isactive==1)
	wind.draw(addon);
}
void move()
{
    addon.move(0, addonspeed);
}


    //virtual void activate() = 0;
};

class Powerup : public Addon
{
public:
float timremain=5;

Powerup():Addon("img/powerup.png", 10, 10){}
  	
    void activate()// override 
    {	isactive=1;
    }
    
    void draw();
};

class Firee : public Addon
{
public:
float timremain=5;

Firee():Addon("img/fireaddon.png", 600, 10){}
  	
    void activate()// override 
    {	isactive=1;
    }
    
    void draw();
};

class Lifes : public Addon
{
public:


Lifes():Addon("img/pill_red.png", 250, 10){}
 
  	
    void activate()// override 
    {	isactive=1;	
    }
    
    void draw();
};

class Danger : public Addon
{
public:


Danger():Addon("img/dangeraddon.png", 450, 10){}
 
  	
    void activate()// override 
    {	isactive=1;	
    }
    
    void draw();
};


/*
class Addon: public Player
{  public:	
	Texture tadd;
	//Texture tom;
	Sprite addon;
	bool demolish=0;
	int score;
	float addonspeed=1.9;	
 	


Addon(string png_path, int x, int y)
{	tadd.loadFromFile(png_path);
	addon.setTexture(tadd);
	addon.setPosition(x,y);
	addon.setScale(1.85,1.85);
}

virtual void draw(RenderWindow & wind ) 
{	wind.draw(addon);
}

addon.move(0, addonspeed);

bool collisioncheck(Player& * p)
{	if (p->getPosition().x== addon.getPosition().x && p->getPosition().y== addon.getPosition().y)
  		{	return true;
  		}
}

virtual ~Addon()
{}
};

class Powerup: public Addon
{ private:
	float timeremain=0;
	
  public:
  
  	Powerup():Addon("img/powerup.png", 134, 2)
  	{	timeremain=5;
  	}
  	
  	addon.move(0,addonspeed);
  	
  	
  	
  	
  	


};*/
