//MishalAli 22i-1291 K project'23


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<string.h>
#include <iostream>


using namespace sf;
using namespace std;



class Menu{
public:

//add menu attributes here
Menu()
{}

void display_menu()

{	//RenderWindow window(VideoMode(780, 780),"oop-project23");

	Font fmenu;
	fmenu.loadFromFile("img/font/Regular.ttf");
	//Mian menu
	Text title, subopt, credits;
	title.setFont(fmenu);
	title.setString("Space Shooter Game\n");
	title.setPosition(40,140);
	title.setFillColor(Color::Cyan);
	title.setCharacterSize(26);
	title.setStyle(Text::Bold);
	
	subopt.setFont(fmenu);
	subopt.setString("New Game: Press Space\nHelp: Press H \nQuit: Press Escape");
	subopt.setPosition(30,250);
	subopt.setFillColor(Color::Cyan);
	subopt.setCharacterSize(22);
	
	credits.setFont(fmenu);
	credits.setString("By: Mishal Ali     Rollno: 22i-1291     Sec:K");
	credits.setPosition(50,350);
	credits.setFillColor(Color::Cyan);
	credits.setCharacterSize(10);
	
	Texture backg;
	backg.loadFromFile ("img/background2.jpg");
	
	
	Sprite menubg(backg);
	menubg.setScale(1.75,1.75);
	RenderWindow window_menu(VideoMode(320, 480), "Space Shooter-Menu");
	
	 Event e;
		while (window_menu.isOpen())
    {
        //---Event Listening Part---//
       
        while (window_menu.pollEvent(e))
        {   if (e.type == Event::Closed)                  
            {window_menu.close(); 
            return ;
            }
                                         
            if (e.type == Event::KeyPressed) 
           {        if (e.key.code == Keyboard::Space)    
                   { window_menu.close();
                    //start_game();
                    return;
                    }
                    
                    else if(e.key.code == Keyboard::Escape) 
                     { window_menu.close(); 
                     	
            			break; }
            			                
                    else if (e.key.code == Keyboard::H)    
                     {	display_instruct();}
                     
           }
        

      window_menu.draw(menubg);
      window_menu.draw(title);
      window_menu.draw(subopt);
      window_menu.draw(credits);
      
      window_menu.display();
    	}	
   }
   return;
}

void display_instruct()
{	//RenderWindow window_inst(VideoMode(320, 480), "Menu-Instructions")

	Font fmenu1;
	fmenu1.loadFromFile("img/font/Regular.ttf");
	
	Text instruction, subinst;
	instruction.setFont(fmenu1);
	instruction.setString("INSTRUCTIONS\n");
	instruction.setPosition(15,50);
	instruction.setFillColor(Color::Cyan);
	instruction.setCharacterSize(35);
	instruction.setStyle(Text::Bold);
	
	subinst.setFont(fmenu1);
	subinst.setString("1. Use the keys to move the ship\n2. Avoid getting hit by the enemy bombs.\n3. Kill all your enemies and WIN\n 4. Press R anytime in the game to restart\n5.BEST OF LUCK! \n\n\n Press Enter to continue");
	subinst.setPosition(10,200);
	subinst.setFillColor(Color::Cyan);
	subinst.setCharacterSize(15);
	
	 //Sprite instbg(backg);
	Texture backg;
	backg.loadFromFile ("img/background2.jpg");
	
	
	Sprite instbg(backg);
	instbg.setScale(1.75,1.75);
	RenderWindow window_inst(VideoMode(320, 480), "Menu-Instructions");
	
	while (window_inst.isOpen())
   	{	Event e;
       							 while (window_inst.pollEvent(e))
       							 {   if (e.type == Event::Closed)                  
        						    {window_inst.close(); 
           						 return ;
}
                                         
 else if (e.type == Event::KeyPressed) 
{        if (e.key.code == Keyboard::Enter)    
               				    					   	{	 window_inst.close();  }
} 
             window_inst.draw(instbg);
             window_inst.draw(instruction);
             window_inst.draw(subinst);
             window_inst.display();                     
            }
        }
}

void pause()
{	Font fmenu2;
	fmenu2.loadFromFile("img/font/Minecraft.ttf");
	
	Font fmenu1;
	fmenu1.loadFromFile("img/font/Regular.ttf");

	Text pause, subpause;
	pause.setFont(fmenu2);
	pause.setString("Game    Paused\n");
	pause.setPosition(17,50);
	pause.setFillColor(Color::Cyan);
	pause.setCharacterSize(30);
	pause.setStyle(Text::Bold);
	
	subpause.setFont(fmenu1);
	subpause.setString("1.Press H to go to the instructions \nwindow.\n\n 2.Press Enter to Resume the game. :) \n3. R to restart game");
	subpause.setPosition(10,160);
	subpause.setFillColor(Color::Cyan);
	subpause.setCharacterSize(17);
	
	Texture backg;
	backg.loadFromFile ("img/background2.jpg");
	
	
	Sprite instbg(backg);
	instbg.setScale(1.75,1.75);
	RenderWindow window_pause(VideoMode(320, 480), "Pause Menu");
	
	while (window_pause.isOpen())
   						 {
     						   //---Event Listening Part---//
      						  Event e;
       							 while (window_pause.pollEvent(e))
       							 {   if (e.type == Event::Closed)                  
        						    {window_pause.close(); 
           						 return ;
           						 }
                                         
         					  else if (e.type == Event::KeyPressed) 
          			 {        if (e.key.code == Keyboard::H)    
               				    { window_pause.close();
               				    	display_instruct();
               				     }
               				      if (e.key.code == Keyboard::Enter) 
               				      { window_pause.close();
               				      return;
               				      }
                     } 
                     window_pause.draw(instbg);
                     window_pause.draw(pause);
                     window_pause.draw(subpause);
                     
                     window_pause.display ();                     
            }
        }
}

void end_game()
{	Font fmenu2;
	fmenu2.loadFromFile("img/font/Minecraft.ttf");
	

	Text dead;
	dead.setFont(fmenu2);
	dead.setString("x GAME x \nx OVER x\n\n  x___x");
	dead.setPosition(30,100);
	dead.setFillColor(Color::Cyan);
	dead.setCharacterSize(50);
	dead.setStyle(Text::Bold);
	
	Music gameup;
	gameup.openFromFile("img/music/gameover.ogg");
   	gameup.setVolume(100);
   	gameup.setLoop(true);
	
	Texture backg;
	backg.loadFromFile ("img/background2.jpg");
	
	
	Sprite instbg(backg);
	instbg.setScale(1.75,1.75);
       		
       		RenderWindow windowdead(VideoMode(320, 480), "Play Again");
	
						while (windowdead.isOpen())
   						 {
     						   //---Event Listening Part---//
      						  Event e;
       							 while (windowdead.pollEvent(e))
       							 {   if (e.type == Event::Closed)                  
        						    {windowdead.close(); 
           						 return ;
           						 }
                                         
         					  else if (e.type == Event::KeyPressed) 
          			 {        if (e.key.code == Keyboard::Enter)    
               				     windowdead.close();
               				     
                     } 
                     windowdead.draw(instbg);
                     windowdead.draw(dead);
                     windowdead.display();
                     gameup.play();
                    }
    }
 		 gameup.stop() ;  
       	 //windowdead.draw(dead);
       	 }



};
