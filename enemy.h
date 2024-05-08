//MishalAli 22i-1291 K project'23


#include <SFML/Graphics.hpp>
#include<string.h>
#include "bomb.h"


using namespace sf;
using namespace std;


//ENEMY CLASS
class Enemy
{  public:
	Texture ten;
	Texture tom;
	Sprite enemy;
	Bomb * bom;
	bool demolish=0;
	float bombtime;
	
	
	
Enemy(string png_path, int x, int y)
{	ten.loadFromFile(png_path);
	enemy.setTexture(ten);
	enemy.setPosition(x,y);
	enemy.setScale(0.55,0.55);
	
	bombtime=0.0;
	bom = new Bomb[100];
	bom->setpos(enemy.getPosition().x, enemy.getPosition().y);
	
}


//virtual void fire_bom()
//{}
virtual void fire_bom()
{	if(bombtime>=2.0)
	{	for (int i=0; i<100; i++)
		{	if (!bom[i].isactive)
			{	bom[i].fire( enemy.getPosition().x+32,  enemy.getPosition().y+30);	//setting the new boomb location to enemy cordinates
			break;
			}
		}
		bombtime=0.0;	//reseting the gap time
	}
}

  
//displaying bomb on the screen
 virtual void drawbomb(RenderWindow & window)
{	for (int i=0; i<100; i++)	
	{ //bom[i].setpos(enemy.getPosition().x+40,  enemy.getPosition().y+30);	
		if(bom[i].isactive)
		{	window.draw(bom[i].bomb);
		}
	}
}
//updating the bomb till 100 reached
 void updateBomb()
{	for (int i=0; i<100; i++)
	{	bom[i].update();
	}
}


virtual void draw(RenderWindow & wind ) 
{	if (!demolish)
	wind.draw(enemy);
}

virtual	int getposx()
{	 int x;
	 x=enemy.getPosition().x;
	 return x;
}

 virtual int getposy()
{ 	int y;
	y=enemy.getPosition().y;
	return y;
}

virtual void setpos(int x, int y)
	{	enemy.setPosition(x,y);
	}

void move_enem()
{	


}

};

class Invader: public Enemy
{  public:
	float bombintertime;
	float bomtimer;
	
	Invader (string png_path, int x, int y, float bomtime):	Enemy (png_path, x,y), bombintertime(bomtime)
{
//	bombintertime=bomtime;
	bomtimer=rand()% static_cast<int>(bombintertime*1000);
}

 
};

class AlphaInv: public Invader
{  public:
	AlphaInv():
	Invader("img/enemy_1.png", 340, 55,5.0)
	{}
	
	
	
	

};

class BetaInv: public Invader
{  public:
	BetaInv():
	Invader("img/enemy_2.png", 140, 25,3.0)
	{}
	
	
		
};

class GammaInv: public Invader
{  public:
	GammaInv():
	Invader("img/enemy_3.png", 540, 25,2.0)
	{}
	
	
};
/*
class Monster : public Enemy 
{  public:
    float beam_timer;
    float beam_inter;
    bool beamOn;
    Sprite beam;
    Texture tbeam;
    float beamspeed=0.9;
    

    Monster() :
            Enemy("img/monster1.png",- 10, 35), beam_timer(0), beamOn(false) 
            {	//bom->setText("img/fire08.png");
            tbeam.loadFromFile("img/fire00.png");
	beam.setTexture(tbeam);
beam.setTexture(ten);
        beam.setScale(2, 3);
       // beam.setColor(Color(255, 255, 255, 150));
    }

    void update()  {
        beam_timer += 2.0;
        if (beam_timer >= beam_inter) {
            beam_timer = 0;
            beamOn = !beamOn;
        }

        if (beamOn) {
        
            
                beam.setPosition(getposx() + 75, getposy() + 120);
               
            }
        } 
  

    void draw(RenderWindow& wind) override {
        wind.draw(enemy);
        wind.draw(beam);
    }
  /* void moveLeft() {
        enemy.move(-4 *2, 0);
        if(enemy.getPosition().x<50)
        return;
    }

    void moveRight() {
       // if(enemy.getPosition().x<50)
        enemy.move(0.3 * 1, 0);
        
    }
    void movebeam()
    { //beam.move(0, beamspeed);
    }

  /*  int getposx() 
     {
        int x;
        x = enemy.getPosition().x;
        return x + 70; // adjust for monster sprite size
    }

    int getposy() 
     {
        int y;
        y = enemy.getPosition().y;
        return y + 120; // adjust for monster sprite size
    }
};
*/
class Monster : public Enemy
{  public:
    bool firecheck;
    float beam_inter;
    float beam_timer;
    float beamspeed=1.5;
   Sprite beam;
   Texture bt;

     Monster() :
            Enemy("img/monster1.png",-300, 35)
    {	bt.loadFromFile("img/fire00.png");
	beam.setTexture(bt);
	beam.setScale(3.75,14.75);
	beam.setPosition(enemy.getPosition().x+130, enemy.getPosition().y +250);
        // Set the demolish status to false initially
        demolish = false;

        // Set the initial firing state and interval
        firecheck = 1;
        beam_inter = 2.0;
        beam_timer = 0.0;

        // Set the position of the beam relative to the monster
      
    }

    void move_enem()
    { 
    	enemy.move(0.3 * 2, 0);
    	
    }

    void update() {
        if(beam_timer> 2.0)
        {	firecheck=0;
        	beam_timer=0.0;
        }
        else 
        {firecheck=1;
        	 beam.setPosition(enemy.getPosition().x + 130, enemy.getPosition().y + 250);}

      
    }
    void draw(RenderWindow& wind) {
        if (!demolish) {
            wind.draw(enemy);
            
        }
    }
};


class Dragon : public Enemy
{  public:
    bool firecheck;
    float beam_inter;
    float beam_timer;
    float beamspeed=1.7;
   Sprite beam;
   Texture bt;

     Dragon() :
            Enemy("img/dragon1.png",300, 15)
    {	enemy.setScale(1.3,1.2);	
    bt.loadFromFile("img/fire14.png");
	beam.setTexture(bt);
	beam.setScale(5.75,18.75);
	beam.setPosition(enemy.getPosition().x+130, enemy.getPosition().y +270);
        // Set the demolish status to false initially
        demolish = false;

        // Set the initial firing state and interval
        firecheck = false;
        beam_inter = 2.0;
        beam_timer = 0.0;

        // Set the position of the beam relative to the monster
      
    }

 

  void update() {
        if(beam_timer> 2.0)
        {	firecheck=0;
        	beam_timer=0.0;
        }
        else 
        {firecheck=1;
        	 beam.setPosition(enemy.getPosition().x + 100, enemy.getPosition().y + 150);}

      
    }
    void draw(RenderWindow& wind) {
        if (!demolish) {
            wind.draw(enemy);
            
        }
    }
};

