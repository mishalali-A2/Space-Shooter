//MishalAli 22i-1291 K project'23


#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
#include "enemy.h"
#include "menu.h"
//#include "highscore.cpp"
const char title[] = "OOP-Project, Spring-2023_22i-1291_MishalAli";

using namespace sf;

class Game
{
public:
Sprite background; //Game background sprite
Texture bg_texture;
Player* p; //player 
//Player * damagp;
AlphaInv* ai;	//alpha invader
BetaInv* bi;
GammaInv* gi;
Monster* mon;
Dragon* dragon;
//Enemy* ai;
//Enemy* bi;
//Enemy* gi;
//float timeaddgap=0.0;


Menu *menu;	//menu 



Game()
{
p=new Player("img/player_ship.png");
ai= new AlphaInv();
bi= new BetaInv();
gi=new GammaInv();
mon=new Monster();
dragon=new Dragon();
menu=new Menu();

bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(2, 1.5);

//timeaddgap = static_cast<float>(rand() % 5000) / 1000.0;

 



}


void start_game()
{	menu->display_menu();   //display menu at the satrt of the game
    
    srand(time(0));
    RenderWindow window(VideoMode(780, 780), title);
    Clock clock;
    float timer=0;
    int score=0;
    int remainlives=5;
    bool deletespries=0;
	//Music
 Music music;
   music.openFromFile("img/music/shooter.wav");
   music.setVolume(50);
   music.setLoop(true);
   music.play(); 
 

    
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
       float delta_time=clock.restart().asSeconds(); 
        p->bulltimegap+=delta_time;
        ai->bombtime+=delta_time;
        //timeaddgap+=delta_time;
        clock.restart();
        timer += time;  
        //cout<<time<<endl; 
        
          
          
 	Event e;
        while (window.pollEvent(e))
        {   
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                
                    	    
        }
       
          
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
            
        if ((Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Right))) // If up and righy\t key is pressed
            p->move("ur");  //player will move diagonally   
       if ((Keyboard::isKeyPressed(Keyboard::Up)) && (Keyboard::isKeyPressed(Keyboard::Left))) // If up and righy\t key is pressed
            p->move("ul");  //player will move diagonally     
        if ((Keyboard::isKeyPressed(Keyboard::Down)) && (Keyboard::isKeyPressed(Keyboard::Left))) // If up and righy\t key is pressed
            p->move("dl");  //player will move diagonally
            
         if ((Keyboard::isKeyPressed(Keyboard::Down)) && (Keyboard::isKeyPressed(Keyboard::Right))) // If up and righy\t key is pressed
            p->move("dr");  //player will move diagonally
            
            if (Keyboard::isKeyPressed(Keyboard::P))
            {	menu->pause();
                
            }
            
            if (Keyboard::isKeyPressed(Keyboard::R))
        {
            // Restart the game

            // Reseting player position and lives
            p->setpos(340, 700);
            remainlives = 5;

            // Reseting score
            score = 0;

            // Reactivate enemy sprites and reset their positions
            ai->demolish = false;
            ai->setpos(340, 55);
            bi->demolish = false;
            bi->setpos(140, 25);
            gi->demolish = false;
            gi->setpos(540, 25);

            // Reset timer
            timer = 0;

        }
            
	////////////////////////////////////////////////
	/////  Call your functions here          
	//CALLING PLAYER AND ITS SUB
	for (int i=0; i<200 && p->bull[i].isactive==true; i++)	//show multiple bullets on screen
	{	p->bull[i].move();	
	}
	p->updateBull();
	p->fire1();
	p->power->move();
	p->lyf->move();
	p->dang->move();
	p->fire->move();
	//CALLING INVADERS AND ITS SUBS
	ai->bom->move();
	bi->bom->move();
	gi->bom->move();
	
	ai->updateBomb();
	bi->updateBomb();
	gi->updateBomb();
	
	ai->fire_bom();
	bi->fire_bom();
	gi->fire_bom();
	
	ai->updateBomb();
	bi->updateBomb();
	gi->updateBomb();
	
	ai->fire_bom();
	bi->fire_bom();
	gi->fire_bom();
	
	//CALLING MONSTER
	mon->move_enem();
	mon->update();
	
	//CALLING DRAGON
	dragon->update();
	
	
	
	
	
	//checking collision of bullets with the enmeies
	for (int i=0; i<200 ; i++)
	{	if (p->bull[i].isactive && ai->enemy.getGlobalBounds().intersects(p->bull[i].bullet.getGlobalBounds())) 
		{
			    ai->demolish = true; // set the demolish flag to true
			    p->bull[i].isactive = false; // deactivate the bullet
			    ai->setpos(-100,900);
			    score+=10;
    		}

	 }
	 
	 //checking collision of bullets with the enmeies
	for (int i=0; i<200 ; i++)
	{	if (p->bull[i].isactive && bi->enemy.getGlobalBounds().intersects(p->bull[i].bullet.getGlobalBounds())) 
		{
			    bi->demolish = true; // set the demolish flag to true
			    p->bull[i].isactive = false; // deactivate the bullet
			    bi->setpos(-100,900);
			    score+=20;
    		}

	 }
	 
	 //checking collision of bullets with the enmeies
	/*for (int i=0; i<200 ; i++)
	{	if (p->bull[i].isactive && mon->enemy.getGlobalBounds().intersects(p->bull[i].bullet.getGlobalBounds())) //&& p->bull[i+1].isactive && mon->enemy.getGlobalBounds().intersects(p->bull[i+1].bullet.getGlobalBounds()) && p->bull[i+2].isactive && mon->enemy.getGlobalBounds().intersects(p->bull[i+2].bullet.getGlobalBounds())) 
		{
			    mon->demolish = true; // set the demolish flag to true
			    p->bull[i].isactive = false; // deactivate the bullet
			    mon->setpos(-100,900);
			    score+=40;
    		}

	 }*/
	 
	 //checking collision of bullets with the enmeies
	for (int i=0; i<200 ; i++)
	{	if (p->bull[i].isactive && gi->enemy.getGlobalBounds().intersects(p->bull[i].bullet.getGlobalBounds())) 
		{	 cout<<"Enemy got you!"<<endl;
			    gi->demolish = true; // set the demolish flag to true
			    p->bull[i].isactive = false; // deactivate the bullet
			    gi->setpos(-100,900);
			    score+=+30;
    		}

	 }
	 
	 //checking collisiion of the player with the enemies
	 if ( ai->enemy.getGlobalBounds().intersects(p->sprite.getGlobalBounds())) 
		{	   remainlives--;	//health decreases n loses a life
			   p->setpos(340,700);
			    cout<<"Enemy got you!"<<endl;
			  
			    if (remainlives<=0)
			    {	music.stop();
			    	menu->end_game();
			    	window.close();
			    }
    		}
    		
    	//checking collisiion of the player with the enemies
	 if ( bi->enemy.getGlobalBounds().intersects(p->sprite.getGlobalBounds())) 
		{	   remainlives--;	//health decreases n loses a life
			   p->setpos(340,700);
			    cout<<"Enemy got you!"<<endl;
			  
			    if (remainlives<=0)
			    {	music.stop();
			    	menu->end_game();
			    	window.close();
			    }
    		}
    		
    	//checking collisiion of the player with the enemies
	 if ( gi->enemy.getGlobalBounds().intersects(p->sprite.getGlobalBounds())) 
		{	   remainlives--;	//health decreases n loses a life
			   p->setpos(340,700);
			    cout<<"Enemy got you!"<<endl;
			  
			    if (remainlives<=0)
			    {	music.stop();
			    	menu->end_game();
			    	window.close();
			    }
    		}
    		
    	//checking collisiion of the player with the enemies
	 if ( mon->enemy.getGlobalBounds().intersects(p->sprite.getGlobalBounds())) 
		{	   remainlives--;	//health decreases n loses a life
			   p->setpos(340,700);
			  cout<<"Enemy got you!"<<endl;
			    if (remainlives<=0)
			    {	music.stop();
			    	menu->end_game();
			    	window.close();
			    }
    		}
    		
    	//checking collisiion of the player with the lyf powerup
    	 if ( p->lyf->addon.getGlobalBounds().intersects(p->sprite.getGlobalBounds())) 
		{	p->lyf->isactive=0; 
			cout<<"You got an extra life"<<endl; 
			 remainlives+=1;
			 p->lyf->setpos(-100,-100);	//health increases n loses a life	  
    		}
    	
    	//checking collisiion of the player with the fire powerup	
    	if ( p->fire->addon.getGlobalBounds().intersects(p->sprite.getGlobalBounds())) 
		{	p->fire->isactive=0; 
			cout<<"Power addon acheived!"<<endl; 
			p->fire->setpos(-100,-100);	//health increases n loses a life	  
    		}
    		
    	//checking collisiion of the player with the danger powerup
    	 if ( p->dang->addon.getGlobalBounds().intersects(p->sprite.getGlobalBounds())) 
		{	
		
		
			p->dang->isactive=0;  
			p->dang->setpos(-100,-100);
			cout<<"Danger sign got you!"<<endl;
			music.stop();
			menu->end_game();
			window.close();
				  
    		}
    		
    		if (p->getposx() < p->dang->getposx() - 100 && p->getposx() > p->dang->getposx() + 100 && p->getposy() < p->dang->getposy() - 100 && p->getposy() > p->dang->getposy() + 100) 
    		{
    			score+=5;
    			break;
    		}
    	
    		/*
    		float dangmissx=abs(p->sprite.getPosition().x - p->dang->addon.getPosition().x);
			float dangmissy=abs(p->sprite.getPosition().y - p->dang->addon.getPosition().y);
    			float missthreshold = 50.0f;
    		
    		if (dangmissx < missthreshold && dangmissy < missthreshold ) {
    		 score+=5;
    		 return;
    	 	}
    	if(! p->dang->addon.getGlobalBounds().intersects(p->sprite.getGlobalBounds()))
    	{	//p->dang->isactive=0; 
    	  score+=5;
    	  
    	  	//for dodging the danger sign
    	}*/
    	
    	
    		
    	
    	//checking collisiion of the player with the boms
    	for (int i=0; i<100 ; i++)
	{	if (ai->bom[i].isactive && p->sprite.getGlobalBounds().intersects(ai->bom[i].bomb.getGlobalBounds())) 
		{           ai->bom[i].isactive=0;
			    ai->bom[i].setpos(-100,-100);	//bomb disappears from screen.
			    remainlives--;	//health decreases n loses a life
			    
			    if (remainlives<=0)
			    {	music.stop();
			    	menu->end_game();
			    	window.close();
			    }
			   
    		}

	 }
	 
	 //checking collisiion of the player with the boms
    	for (int i=0; i<100 ; i++)
	{	if (bi->bom[i].isactive && p->sprite.getGlobalBounds().intersects(bi->bom[i].bomb.getGlobalBounds())) 
		{           bi->bom[i].isactive=0;
			    bi->bom[i].setpos(-100,-100);	//bomb disappears from screen.
			    remainlives--;	//health decreases n loses a life
			    
			    if (remainlives<=0)
			    {	music.stop();
			    	menu->end_game();
			    	window.close();
			    }
			   
    		}

	 }
	 
	 //checking collisiion of the player with the boms
    	for (int i=0; i<100 ; i++)
	{	if (gi->bom[i].isactive && p->sprite.getGlobalBounds().intersects(gi->bom[i].bomb.getGlobalBounds())) 
		{           gi->bom[i].isactive=0;
			    gi->bom[i].setpos(-100,-100);	//bomb disappears from screen.
			    remainlives--;	//health decreases n loses a life
			    
			    if (remainlives<=0)
			    {	music.stop();
			    	menu->end_game();
			    	window.close();
			    }
			   
    		}

	 }
    		
    	
	
	
	
	
	
	
	  ////
	//////////////////////////////////////////////

	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	//DRAWING PLAYER AND ITS SUBS
	window.draw(p->sprite);   // setting player on screen
	if(!deletespries)
	{//DRAWING ADDOONS
	window.draw(p->power->addon);
	window.draw(p->lyf->addon);
	window.draw(p->dang->addon);
	window.draw(p->fire->addon);
	//DRAWING ENEMY AND ITS SUBS
	window.draw(ai->enemy);
	window.draw(ai->bom->bomb);
	window.draw(bi->enemy);
	window.draw(bi->bom->bomb);
	window.draw(gi->enemy);
	window.draw(gi->bom->bomb);}
if (timer>=6.0 && timer>=11.0)
{window.draw(mon->enemy);
deletespries=1;
 
 if (timer>8.0)
 {window.draw(mon->beam);}
	
	
	for (int i=0; i<200 ; i++)
	{	if (p->bull[i].isactive && mon->enemy.getGlobalBounds().intersects(p->bull[i].bullet.getGlobalBounds())) //&& p->bull[i+1].isactive && mon->enemy.getGlobalBounds().intersects(p->bull[i+1].bullet.getGlobalBounds()) && p->bull[i+2].isactive && mon->enemy.getGlobalBounds().intersects(p->bull[i+2].bullet.getGlobalBounds())) 
		{
			    mon->demolish = true; // set the demolish flag to true
			    p->bull[i].isactive = false; // deactivate the bullet
			    mon->setpos(-100,900);
			    score+=40;
    		}

	 }
	 
	  //collsion of player with fire of monster
	if (mon->firecheck && p->sprite.getGlobalBounds().intersects(mon->beam.getGlobalBounds())) 
	{          remainlives--;	//health decreases n loses a life
			    
			    if (remainlives<=0)
			    {	music.stop();
			    	menu->end_game();
			    	window.close();
			    }
			   
    	}
    	
}

if (timer>=13.0 && timer>=21.0)
{window.draw(dragon->enemy);
deletespries=1;
 if (timer>18.0)
{window.draw(dragon->beam);}
 
	
	
	for (int i=0; i<200 ; i++)
	{	if (p->bull[i].isactive && dragon->enemy.getGlobalBounds().intersects(p->bull[i].bullet.getGlobalBounds())) //&& p->bull[i+1].isactive && mon->enemy.getGlobalBounds().intersects(p->bull[i+1].bullet.getGlobalBounds()) && p->bull[i+2].isactive && mon->enemy.getGlobalBounds().intersects(p->bull[i+2].bullet.getGlobalBounds())) 
		{
			    dragon->demolish = true; // set the demolish flag to true
			    p->bull[i].isactive = false; // deactivate the bullet
			    dragon->setpos(-100,900);
			    score+=50;
    		}

	 }
	
    	//collsion of player with fire of dragon
	if (dragon->firecheck && p->sprite.getGlobalBounds().intersects(dragon->beam.getGlobalBounds())) 
	{          remainlives--;	//health decreases n loses a life
			    
			    if (remainlives<=0)
			    {	music.stop();
			    	menu->end_game();
			    	window.close();
			    }
			   
    	}
}

	for (int i=0; i<200 && p->bull[i].isactive==true; i++)	//draw multiple bullets on screen
	{	window.draw(p->bull[i].bullet);

	}
	/*
	for (int i=0; i<100 && p->bom[i].isactive==true; i++)	//draw multiple bullets on screen
	{	window.draw(ai->bom[i].bomb);

	}*/
//SCORE BOARD		
	Font fmenu1;
        fmenu1.loadFromFile("img/font/Regular.ttf");
	
	Text scoreboard,points;
	scoreboard.setFont(fmenu1);
	scoreboard.setString("Score:  ");
	scoreboard.setPosition(18,24);
	scoreboard.setFillColor(Color::Cyan);
	scoreboard.setCharacterSize(20);
	scoreboard.setStyle(Text::Bold);
	
	points.setFont(fmenu1);
	points.setString(to_string (score));
	points.setPosition(25,45);
	points.setFillColor(Color::Cyan);
	points.setCharacterSize(17);
	points.setStyle(Text::Bold);
	
//Lives board

	Text lifeboard,lives;
	lifeboard.setFont(fmenu1);
	lifeboard.setString("Lives:  ");
	lifeboard.setPosition(18,70);
	lifeboard.setFillColor(Color::Cyan);
	lifeboard.setCharacterSize(20);
	lifeboard.setStyle(Text::Bold);
	
	lives.setFont(fmenu1);
	lives.setString(to_string (remainlives));
	lives.setPosition(25,90);
	lives.setFillColor(Color::Cyan);
	lives.setCharacterSize(25);
	lives.setStyle(Text::Bold);

	
	
        
	window.draw(scoreboard);
	window.draw(points);
	window.draw(lifeboard);
	window.draw(lives);
	window.display();  //Displying all the sprites
    }


}


};

