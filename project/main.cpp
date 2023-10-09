#include "SBDL.h"
#include <ctime>
#include <fstream>
using namespace std;

SDL_Rect foregroundr ={0,0,500,500};
SDL_Rect backgroundr1 ={0,0,500,500};
SDL_Rect backgroundr2 ={0,-500,500,500};
SDL_Rect runright = {430,270,20,40};
SDL_Rect runleft = {50,270,20,40};
SDL_Rect jump = {50,270,50,40};
SDL_Rect houser={0,501,80,70};
SDL_Rect housel={420,700,80,70};
SDL_Rect squirrelr[3];
SDL_Rect roper[3];
SDL_Rect boostanimation={250,250,50,50};
SDL_Rect throwerr={425,800,30,30};
SDL_Rect throwerl={42,800,30,30};
SDL_Rect bladerr={425,600,15,15};
SDL_Rect bladerl={42,600,15,15};
SDL_Rect bladerr2={425,600,15,15};
SDL_Rect bladerl2={42,600,15,15};
SDL_Rect  birdrr = {0,20,50,50};
SDL_Rect  birdrl = {430,20,50,50};
SDL_Rect  spikesrr = {45,800,20,80};
SDL_Rect  spikesrl = {430,800,20,80};
SDL_Rect fallinglr={50,270,40,40};
SDL_Rect fallingrr={430,270,40,40};
SDL_Rect shieldr = {250,700,40,40};
SDL_Rect shieldalarm={0,450,50,50};
SDL_Rect boost[3];
SDL_Rect scorer = {0,250,60,60};
SDL_Rect menuback = {0,0,500,500};
SDL_Rect menuplay = {50,350,100,100};
SDL_Rect menusound = {200,350,100,100};
SDL_Rect menuexit = {350,350,100,100};
SDL_Rect pausemenur ={0,0,500,500};
SDL_Rect continuepause = {200,100,100,100};
SDL_Rect playagainpause={200,200,100,100};
SDL_Rect firstmenupause={200,300,100,100};
SDL_Rect gameoverback={0,0,500,500};
SDL_Rect playagaingo = {100,300,100,100};
SDL_Rect firstmenugo ={300,300,100,100};
SDL_Rect offslashr={200,350,100,100};
int score=0;
int highscore=0;
int counter1=0;
int counter2=0;
int counter3=0;
int counter4=0;
int angelr=0;
int angell=0;
int speed=1;
int counter5l=0;
int counter5r=0;
int counter6=0;
int counter62=0;
int counter6r=0;
int counter6l=0;
int counter7=0;
int counter8=0;
int second;
int shieldcount=0;
int birdcounter=0;
int bladecounter=0;
int squirrelcounter=0;
bool isbirdboost=0;
bool issquirrelboost;
bool isbladeboost;
bool isfallingr;
bool isfallingl;
bool doubr ;
bool doubl;
bool birdr1;
bool birdl1;
bool shieldb;
bool leftp=true;
bool rightp=false;
bool jumpaction=false;
bool game=false;
bool firstmenu=true;
bool pausemenub= false;
bool gameover=false;
bool musicon=true;
bool newrecord;
void fallright() {
    if (SBDL::hasIntersectionRect(birdrr, runright)) {
        if (shieldb == false)
            isfallingr = true;
        else {
            shieldb = false;
            birdrr.y = 800;
        }
    } else if (SBDL::hasIntersectionRect(spikesrl, runright)) {
        if (shieldb == false)
            isfallingr = true;
        else {
            shieldb = false;
            spikesrl.y = 900;
        }
    } else if (SBDL::hasIntersectionRect(housel, runright)) {
        if (shieldb == false)
            isfallingr = true;
        else {
            shieldb = false;
            housel.y = 720;

        }
    } else if (SBDL::hasIntersectionRect(throwerr, runright)) {
        if (shieldb == false)
            isfallingr = true;
        else {
            shieldb = false;
            throwerr.y = 900;
        }
    } else if (SBDL::hasIntersectionRect(runright, bladerl)) {
        if (shieldb == false)
            isfallingr = true;
        else {
            shieldb = false;
            bladerl.y = 1000;
        }
    } else if (SBDL::hasIntersectionRect(runright, bladerl2)) {
        if (shieldb == false)
            isfallingr = true;
        else {
            shieldb = false;
            bladerl2.y = 9003;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (SBDL::hasIntersectionRect(squirrelr[i], runright)) {
            if (shieldb == false)
                isfallingr = true;
            else {
                shieldb = false;
                squirrelr[i].y = 4440;
            }
        }
    }
}
void fallleft(){
    if(SBDL::hasIntersectionRect(birdrl,runleft)){
        if(shieldb==false)
        isfallingl = true;
        else {
            shieldb = false;
            birdrl.y = 900;
        }
    }
    else if(SBDL::hasIntersectionRect(spikesrr,runleft)) {
        if(shieldb==false)
        isfallingl = true;
        else {
            shieldb = false;
            spikesrr.y = 600;
        }

    } else if(SBDL::hasIntersectionRect(houser,runleft))
    {
        if(shieldb==false)
        isfallingl = true;
        else {
            shieldb = false;
            houser.y = 505;
        }
    }
    else if(SBDL::hasIntersectionRect(throwerl,runleft)){
        if(shieldb==false)
        isfallingl = true;
        else {
            shieldb = false;
            throwerl.y=750;
        }
    }
    else if (SBDL::hasIntersectionRect(runleft,bladerr)) {
        if(shieldb==false)
        isfallingl = true;
        else {
            shieldb = false;
            bladerr.y=950;
        }
    }
    else if( SBDL::hasIntersectionRect(runleft,bladerr2)) {
        if(shieldb==false)
        isfallingl = true;
        else {
            shieldb = false;
            bladerr2.y=4200;
        }
    }
    for (int i = 0; i <3 ; ++i) {

        if (SBDL::hasIntersectionRect(squirrelr[i], runleft)) {
            if (shieldb == false)
                isfallingl = true;
            else {
                shieldb = false;
                squirrelr[i].y = 9000;
            }

        }
    }

}
void fallinganimation(Texture falling1,Texture falling2,Texture falling3){

    if(isfallingr){
        counter7++;
        if(counter7<7)
            SBDL::showTexture(falling1,0,fallingrr,SDL_FLIP_HORIZONTAL);
        else if(counter7<14)
            SBDL::showTexture(falling2,0,fallingrr,SDL_FLIP_HORIZONTAL);
        else if(counter7<21){
            SBDL::showTexture(falling3,0,fallingrr,SDL_FLIP_HORIZONTAL);
            if(counter7==20)
                counter7=0;
        }
        fallingrr.y+=2;
        fallingrr.x-=2;
        if(fallingrr.y>450){
            game=false;
            gameover=true;
        }
    }
    else if(isfallingl) {
        counter7++;
        if (counter7 < 7)
            SBDL::showTexture(falling1, 0, fallinglr);
        else if (counter7 < 14)
            SBDL::showTexture(falling2, 0, fallinglr);
        else if (counter7 < 21) {
            SBDL::showTexture(falling3, 0, fallinglr);
            if (counter7 == 20)
                counter7 = 0;
        }
        fallinglr.x += 2;
        fallinglr.y += 2;
        if(fallinglr.y>450){
            game=false;
            gameover=true;
        }
    }

}
void initializegamebackground(Texture background){
    SBDL::showTexture(background,backgroundr1);
    backgroundr1.y+=speed;
    if(backgroundr1.y>=500)
        backgroundr1.y=-500;
    SBDL::showTexture(background,backgroundr2);
    backgroundr2.y+=1;
    if(backgroundr2.y>=500)
        backgroundr2.y=-500;

};
void initializeforeground(Texture foreground){

    SBDL::showTexture(foreground,foregroundr);
    foregroundr.y+=speed;


}
void runanimationright(Texture runright1,Texture runright2,Texture runright3,Texture shieldrunright1,Texture shieldrunright2,Texture shieldrunright3){
        counter1++;
        if (counter1 < 10) {
            if(shieldb)
                SBDL::showTexture(shieldrunright1,runright);
            else
            SBDL::showTexture(runright1, runright);
        } else if (counter1 < 20) {
            if(shieldb)
                SBDL::showTexture(shieldrunright3,runright);
            else
            SBDL::showTexture(runright2, runright);
        } else if (counter1 < 30) {
            if(shieldb)
                SBDL::showTexture(shieldrunright3,runright);
            else
            SBDL::showTexture(runright3, runright);
            if (counter1 == 29)
                counter1 = 0;

    }

}
void runanimationleft(Texture runleft1,Texture runleft2,Texture runleft3,Texture shieldrunleft1,Texture shieldrunleft2,Texture shieldrunleft3){

        counter2++;
        if (counter2 < 10) {
            if(shieldb)
                SBDL::showTexture(shieldrunleft1, runleft);
            else
            SBDL::showTexture(runleft1, runleft);
        } else if (counter2 < 20) {
            if(shieldb)
                SBDL::showTexture(shieldrunleft2, runleft);
            else
            SBDL::showTexture(runleft2, runleft);
        } else if (counter2 < 30) {
            if(shieldb)
                SBDL::showTexture(shieldrunleft3, runleft);
            else
            SBDL::showTexture(runleft3, runleft);
            if (counter2 == 29)
                counter2 = 0;

    }
}
void jumpfunc(Texture jump1,Texture jump2,Texture jump3,Texture jump4,bool &rightp,Texture shieldjump1,Texture shieldjump2,Texture shieldjump3){

        counter3++;
        if(counter3<3){
            if(shieldb)
                SBDL::showTexture(shieldjump3, jump);

                else
            SBDL::showTexture(jump4,0,jump);
            if(rightp)
            jump.x-=6;
            else
                jump.x+=6;

        }
         else if(counter3<6){
            if(shieldb)
                SBDL::showTexture(shieldjump2,jump);
            else
            SBDL::showTexture(jump3,0,jump);
            if(rightp)
                jump.x-=6;
            else
                jump.x+=6;

        }
         else if(counter3<9){
            if(shieldb)
                SBDL::showTexture(shieldjump1,jump);
            else
             SBDL::showTexture(jump2,0,jump);
            if(rightp)
                jump.x-=6;
            else
                jump.x+=6;
        }
         else if(counter3<12){
            if(shieldb)
                SBDL::showTexture(shieldjump3,jump);
            else
                SBDL::showTexture(jump1,0,jump);
            if(rightp)
                jump.x-=6;
            else
                jump.x+=6;
            if(counter3==11)
            counter3=0;}
        if(jump.x>=430) {
            jumpaction = false;
            jump.x=430;
            rightp=true;
        }
    if(jump.x<=50) {
        jumpaction = false;
        jump.x=50;
        rightp= false;
    }
}
void ropefunc(Texture rope){
    for (int i = 0; i <3 ; ++i) {
        SBDL::showTexture(rope,roper[i]);
        srand(time(NULL));
        if(roper[i].y>=500) {


            roper[i].y =-200+ ((-100) * (rand() % 20));
            if((rand()%10)<4)
            squirrelr[i].y=roper[i].y-20;
        } else {
            roper[i].y += speed;
            squirrelr[i].y+=speed;
        }
    }



}
void squirrelfunc(Texture squirrel1,Texture squirrel2,Texture squirrel3,Texture squirrel4) {
    for (int i = 0; i < 3; ++i) {
        counter4++;
        if(squirrelr[i].x>430){
            leftp= false;
            squirrelr[i].x=430;
        }
        if(squirrelr[i].x<45){
            leftp=true;
            squirrelr[i].x=48;
        }
        if (counter4 < 10) {

            if(leftp) {
                SBDL::showTexture(squirrel1,0, squirrelr[i]);
                squirrelr[i].x += 2;
            }
            else{
            SBDL::showTexture(squirrel1,0, squirrelr[i],SDL_FLIP_HORIZONTAL);
                squirrelr[i].x -= 2;
        } }else if (counter4 < 20) {
            if(leftp) {
                SBDL::showTexture(squirrel2,0, squirrelr[i]);
                squirrelr[i].x += 2;
            }
            else{
                SBDL::showTexture(squirrel2,0, squirrelr[i],SDL_FLIP_HORIZONTAL);
                squirrelr[i].x -= 2;
            } } else if (counter4 < 30) {
            SBDL::showTexture(squirrel3, squirrelr[i]);
            if(leftp) {
                SBDL::showTexture(squirrel3,0, squirrelr[i]);
                squirrelr[i].x += 2;
            }
            else{
                SBDL::showTexture(squirrel3,0, squirrelr[i],SDL_FLIP_HORIZONTAL);
                squirrelr[i].x -= 2;
            } } else if (counter4 < 40) {
            if(leftp) {
                SBDL::showTexture(squirrel4,0, squirrelr[i]);
                squirrelr[i].x += 2;
                if(counter4==39)
                counter4 = 0;
            }
            else{
                SBDL::showTexture(squirrel4,0, squirrelr[i],SDL_FLIP_HORIZONTAL);
                squirrelr[i].x -= 2;
                if(counter4==39)
                counter4 = 0;
            } }

        }
    }
    void houseinitialize(Texture house1,Texture house2) {
        SBDL::showTexture(house2, houser);
        SBDL::showTexture(house2,0, housel,SDL_FLIP_HORIZONTAL);
        if (houser.y > 500)
            houser.y = -500 + ((rand() % 20) * -100);
        else
            houser.y += speed;
        if (housel.y > 500){
            srand(time(NULL));
            housel.y = -700 + ((rand() %10) * -200);}
        else
            housel.y += speed;



}
void throwerfunc(Texture thrower){
    SBDL::showTexture(thrower, throwerl);
    SBDL::showTexture(thrower,0, throwerr,SDL_FLIP_HORIZONTAL);
    if (throwerr.y > 500) {
        throwerr.y = -450 + ((rand() % 20) * -100);
        bladerr.y=throwerr.y;
        bladerr.x=throwerr.x;
        bladerr2.y=throwerr.y;
        bladerr2.x=throwerr.x;
    }
    else {
        throwerr.y += speed;
        bladerr.y+=speed;
        bladerr2.y+=speed;
    }
    if (throwerl.y > 500){
        srand(time(NULL));
        throwerl.y = -850 + ((rand() % 10) * -200);
        bladerl.y=throwerl.y;
        bladerl.x=throwerl.x;
        bladerl2.y=throwerl.y;
        bladerl2.x=throwerl.x;}
    else{
        throwerl.y += speed;
        bladerl.y+=speed;
        bladerl2.y+=speed;
    }




}
void throwblade(Texture blade1){
    if(counter5r==0) {
        if ((rand() % 100) < 10)
            doubr = true;
    }
        if ((rand() % 10) < 2){
            doubl = true;
    }
    counter5r++;
        counter5l++;
    if(bladerr.x==425){}
    else {
        if(doubr)
            SBDL::showTexture(blade1, angelr, bladerr2);
            SBDL::showTexture(blade1, angelr, bladerr);
            angelr += 10;

    }
    if(bladerl.x==42){}
    else {
        if(doubl)
            SBDL::showTexture(blade1, angell, bladerl2);
        SBDL::showTexture(blade1, angell, bladerl);
        angell+=10;
    }
    if(bladerr2.x<40) {
        counter5r = 0;
        doubr = false;
    }
    if(bladerl2.x>430) {
        counter5l=0;
        doubl = false;
    }

    if(bladerr.y>140){
        bladerr.x-=5;
        bladerr.y+=1;
        bladerr2.x-=5;
        bladerr2.y-=1;}
    if(bladerl.y>140){
        bladerl.x+=5;
        bladerl.y+=1;
        bladerl2.x+=5;
        bladerl2.y-=1;
    }


}
void birdright(Texture bird1,Texture bird2,Texture bird3){
    if(counter6r==0){
        if((rand()%100)<10 && birdl1==false)
            birdr1 = true;
        }
    if(birdr1) {
        counter6++;
        if (counter6 > 120) {
            birdrr.x += 5;
            birdrr.y += 3;
            if (counter6 < 125)
                SBDL::showTexture(bird1, birdrr);
            else if (counter6 < 130)
                SBDL::showTexture(bird2, birdrr);
            else if (counter6 < 135) {
                SBDL::showTexture(bird3, birdrr);
                if (counter6 == 134)
                    counter6 = 121;
            }
            if (birdrr.y > 500) {
                counter6 = 0;
                birdrr.y = 0;
                birdrr.x = 0;
                birdr1 = false;
            }
        } else
            SBDL::showTexture(bird1, birdrr);
    }
}
void birdleft(Texture bird1,Texture bird2,Texture bird3){
    if(counter6l==0){
        if((rand()%100)<10 && birdr1==false)
            birdl1 = true;
    }
    if(birdl1) {
        counter62++;
        if (counter62 > 120) {
            birdrl.x -= 5;
            birdrl.y += 3;
            if (counter62 < 125)
                SBDL::showTexture(bird1,0 ,birdrl,SDL_FLIP_HORIZONTAL);
            else if (counter62 < 130)
                SBDL::showTexture(bird2,0 ,birdrl,SDL_FLIP_HORIZONTAL);
            else if (counter62 < 135) {
                SBDL::showTexture(bird3,0 ,birdrl,SDL_FLIP_HORIZONTAL);
                if (counter62 == 134)
                    counter62 = 121;
            }
            if (birdrl.y > 500) {
                counter62 = 0;
                birdrl.y = 20;
                birdrl.x = 430;
                birdl1 = false;
            }
        } else
            SBDL::showTexture(bird1,0, birdrl,SDL_FLIP_HORIZONTAL);
    }
}
void spikefunc(Texture spike){
    SBDL::showTexture(spike,spikesrr);
    SBDL::showTexture(spike,0,spikesrl,SDL_FLIP_HORIZONTAL);
    if(spikesrr.y>500)
  spikesrr.y = -500 + ((rand()%20)*-100);
    else
        spikesrr.y+=1;
    if(spikesrl.y>500)
    spikesrl.y = -650 + ((rand()%10)*-200);
    else
        spikesrl.y+=1;

}
void fire(){
    for (int i = 0; i <3; ++i) {
        if(SBDL::hasIntersectionRect(jump,squirrelr[i])) {
            squirrelcounter++;
            squirrelr[i].y = 666;
            birdcounter=0;
            bladecounter=0;
        }
    }
    if(SBDL::hasIntersectionRect(jump,shieldr)) {
        shieldcount++;
        shieldr.y = 900;
    }
    if(SBDL::hasIntersectionRect(jump,bladerr)) {
        birdcounter=0;
        squirrelcounter=0;
        bladecounter++;
        bladerr.y = 800;
    }
    if(SBDL::hasIntersectionRect(jump,bladerr2)) {
        birdcounter=0;
        squirrelcounter=0;
        bladecounter++;
        bladerr2.y = 900;
    }
    if(SBDL::hasIntersectionRect(jump,bladerl)) {
        birdcounter=0;
        squirrelcounter=0;
        bladecounter++;
        bladerl.y = 1000;
    }
    if(SBDL::hasIntersectionRect(jump,bladerl2)) {
        birdcounter=0;
        squirrelcounter=0;
        bladecounter++;
        bladerl2.y = 1100;
    }
    if(SBDL::hasIntersectionRect(jump,birdrl)) {
        bladecounter=0;
        squirrelcounter=0;
      birdcounter++;
        birdrl.y = 555;
    }
    if(SBDL::hasIntersectionRect(jump,birdrr)) {
        birdcounter++;
        bladecounter=0;
        squirrelcounter=0;
        birdrr.y = 900;
    }
}
void checkfunc(){
    if(SBDL::hasIntersectionRect(housel,spikesrl))
        housel.y=7000;
    if(SBDL::hasIntersectionRect(houser,spikesrr))
        spikesrr.y=4000;
    if(SBDL::hasIntersectionRect(throwerl,houser))
        housel.y=6000;
    if(SBDL::hasIntersectionRect(throwerr,housel))
        throwerr.y=4000;
    if(SBDL::hasIntersectionRect(throwerl,spikesrr))
        spikesrl.y=2300;
    if(SBDL::hasIntersectionRect(throwerr,spikesrl))
        throwerr.y=4002;
    for (int i = 0; i < 3; ++i) {
        if(SBDL::hasIntersectionRect(houser,roper[i]))
            houser.y=20003;
        if(SBDL::hasIntersectionRect(housel,roper[i]))
            housel.y=54000;
        if(SBDL::hasIntersectionRect(throwerr,roper[i]))
            throwerr.y=4000;
        if(SBDL::hasIntersectionRect(throwerl,roper[i]))
            throwerl.y=7000;
        if(SBDL::hasIntersectionRect(spikesrr,roper[i]))
            spikesrr.y=540;
        if(SBDL::hasIntersectionRect(spikesrl,roper[i]))
            spikesrl.y=4000;




    }

}
void shieldfunc(Texture shield){
    SBDL::showTexture(shield,shieldr);
    if(shieldr.y>500) {
        shieldr.y = -500;
    } else
        shieldr.y+=speed;

}
void boostanimationfunc(Texture boostblade1,Texture boostblade2,Texture boostbird1,Texture boostbird2,Texture boostsquirrel){
        if(isbirdboost){
            counter7++;
            if(counter7<5)
                SBDL::showTexture(boostbird1,boostanimation);
            else if(counter7<10){
                SBDL::showTexture(boostbird2,boostanimation);
                if(counter7==9)
                    counter7=0;

            }
            second++;
            speed=1;
            if(second>=2000){
                isbirdboost= false;
                speed=1;
                second=0;
            }
        }
    else if(isbladeboost){
        counter7++;
        if(counter7<2000)
            SBDL::showTexture(boostblade1,boostanimation);
        else if(counter7<10){
            SBDL::showTexture(boostblade2,boostanimation);
            if(counter7==9)
                counter7=0;

        }
        second++;
        speed=1;
        if(second>=2000){
            isbladeboost= false;
            speed=1;
            second=0;
        }
    }
    else if(issquirrelboost){
        counter7++;
        if(counter7<5)
            SBDL::showTexture(boostsquirrel,boostanimation);
        else if(counter7<10){
            SBDL::showTexture(boostsquirrel,boostanimation);
            if(counter7==9)
                counter7=0;

        }
        second++;
        speed=1;
        if(second>=2000){
            issquirrelboost= false;
            speed=1;
            second=0;
        }
    }

}
void restartgame(Texture foreground){
     foregroundr ={0,0,500,500};
     backgroundr1 ={0,0,500,500};
     backgroundr2 ={0,-500,500,500};
    runright = {430,270,20,40};
   runleft = {50,270,20,40};
     jump = {50,270,50,40};
    houser={0,501,80,70};
     housel={420,700,80,70};
     squirrelr[3];
    roper[3];
    boostanimation={250,250,50,50};
     throwerr={425,800,30,30};
     throwerl={42,800,30,30};
     bladerr={425,600,15,15};
     bladerl={42,600,15,15};
     bladerr2={425,600,15,15};
     bladerl2={42,600,15,15};
     birdrr = {0,20,50,50};
     birdrl = {430,20,50,50};
     spikesrr = {45,800,20,80};
     spikesrl = {430,800,20,80};
    fallinglr={50,270,40,40};
     fallingrr={430,270,40,40};
     shieldr = {250,500,40,40};
     shieldalarm={0,450,50,50};
    boost[3];
     scorer = {0,250,60,60};
     score=0;
     counter1=0;
    counter2=0;
     counter3=0;
    counter4=0;
     angelr=0;
    angell=0;
     speed=1;
     counter5l=0;
   counter5r=0;
    counter6=0;
     counter62=0;
     counter6r=0;
     counter6l=0;
     counter7=0;
     counter8=0;
     second=0;
     shieldcount=0;
     birdcounter=0;
     bladecounter=0;
     squirrelcounter=0;
     isbirdboost=false;
    issquirrelboost=false;
     isbladeboost=false;
    isfallingr=false;
     isfallingl=false;
    doubr =false;
     doubl=false;
     birdr1=false;
     birdl1=false;
     shieldb=false;
    leftp=true;
     rightp=false;
    jumpaction=false;
    for (int i = 0; i <3 ; ++i) {
        roper[i] ={48,-200,400,50};
        squirrelr[i] ={48,-2000000,30,30};
        roper[i].y=-200+((rand()%10)*-100);
        if((rand()%10)<4)
            squirrelr[i].y=roper[i].y-20;
    }
    boost[0]={200,30,30,30};
    boost[1]={230,30,30,30};
    boost[2]={260,30,30,30};
    initializeforeground(foreground);

}





int main(int argc, char *argv[])
{
    fstream f1("highscore.txt", ios::in);
    f1 >> highscore;
    f1.close();
    const int window_width = 500;
    const int window_height = 500;
    SBDL::InitEngine("SBDL Test", window_width, window_height);

    int FPS = 60; //frame per second
    int delay = 1000 / FPS; //delay we need at each frame
    Texture foreground = SBDL::loadTexture("assets/background/foreground.png");
    Texture background = SBDL::loadTexture("assets/background/back1.png");
    Texture rope = SBDL::loadTexture("assets/obstacles/rope/rope.png");
    Texture runright1 = SBDL::loadTexture("assets/run/1.png");
    Texture runright2 = SBDL::loadTexture("assets/run/2.png");
    Texture runright3 = SBDL::loadTexture("assets/run/3.png");
    Texture runleft1 = SBDL::loadTexture("assets/run/4.png");
    Texture runleft2 = SBDL::loadTexture("assets/run/5.png");
    Texture runleft3 = SBDL::loadTexture("assets/run/6.png");
    Texture jump1 = SBDL::loadTexture("assets/run/7.png");
    Texture jump2 = SBDL::loadTexture("assets/run/8.png");
    Texture jump3 = SBDL::loadTexture("assets/run/9.png");
    Texture jump4 = SBDL::loadTexture("assets/run/10.png");
    Texture squirrel1 = SBDL::loadTexture("assets/obstacles/squirrels/SQ1.png");
    Texture squirrel2 = SBDL::loadTexture("assets/obstacles/squirrels/SQ2.png");
    Texture squirrel3 = SBDL::loadTexture("assets/obstacles/squirrels/SQ3.png");
    Texture squirrel4 = SBDL::loadTexture("assets/obstacles/squirrels/SQ4.png");
    Texture house1 = SBDL::loadTexture("assets/obstacles/houses/balcony.png");
    Texture house2 = SBDL::loadTexture("assets/obstacles/houses/balcony2.png");
    Texture thrower = SBDL::loadTexture("assets/obstacles/thrower/thrower.png");
    Texture blade1 = SBDL::loadTexture("assets/obstacles/blade/1.png");
    Texture bird1 = SBDL::loadTexture("assets/obstacles/bird/bird1.png");
    Texture bird2 = SBDL::loadTexture("assets/obstacles/bird/bird2.png");
    Texture bird3= SBDL::loadTexture("assets/obstacles/bird/bird3.png");
    Texture spike = SBDL::loadTexture("assets/obstacles/spike/spikes.png");
    Texture falling1 = SBDL::loadTexture("assets/falling(emtiyazi)/falling1.png");
    Texture falling2 = SBDL::loadTexture("assets/falling(emtiyazi)/falling2.png");
    Texture falling3 = SBDL::loadTexture("assets/falling(emtiyazi)/falling3.png");
    Texture shield =SBDL::loadTexture("assets/Shield/shield.png");
    Texture shieldrunleft1 =SBDL::loadTexture("assets/ShieldRunning/b1.png");
    Texture shieldrunleft2 =SBDL::loadTexture("assets/ShieldRunning/b2.png");
    Texture shieldrunleft3 =SBDL::loadTexture("assets/ShieldRunning/b3.png");
    Texture shieldrunright1 =SBDL::loadTexture("assets/ShieldRunning/b4.png");
    Texture shieldrunright2 =SBDL::loadTexture("assets/ShieldRunning/b5.png");
    Texture shieldruntight3 =SBDL::loadTexture("assets/ShieldRunning/b6.png");
    Texture shieldjump1=SBDL::loadTexture("assets/ShieldRunning/b7.png");
    Texture shieldjump2=SBDL::loadTexture("assets/ShieldRunning/b8.png");
    Texture shieldjump3=SBDL::loadTexture("assets/ShieldRunning/b9.png");
    Texture boostblade1=SBDL::loadTexture("assets/Boosts(emtiyazi)/blade_boost1.png");
    Texture boostblade2=SBDL::loadTexture("assets/Boosts(emtiyazi)/blade_boost2.png");
    Texture boostbird1=SBDL::loadTexture("assets/Boosts(emtiyazi)/bird_boost1.png");
    Texture boostbird2=SBDL::loadTexture("assets/Boosts(emtiyazi)/bird_boost2.png");
    Texture boostsquirrel=SBDL::loadTexture("assets/Boosts(emtiyazi)/squirrel_boost1.png");
    Texture menubackground = SBDL::loadTexture("assets/menu/back2.png");
    Texture play =SBDL::loadTexture("assets/menu/play.png");
    Texture sound =SBDL::loadTexture("assets/menu/sound_btn.png");
    Texture exit =SBDL::loadTexture("assets/menu/exit.png");
    Texture pausemenu = SBDL::loadTexture("assets/menu/PAUSEMENU.png");
    Texture resume = SBDL::loadTexture("assets/menu/resume.png");
    Texture home = SBDL::loadTexture("assets/menu/home.png");
    Texture playagain=SBDL::loadTexture("assets/menu/playagain.png");
    Texture gameovermenu=SBDL::loadTexture("assets/menu/gameover_panel.png");
    Texture offslash = SBDL::loadTexture("assets/menu/off_slash.png");
    Texture extrashield =SBDL::loadTexture("assets/menu/EXTRALIFE.png");
    Font *font = SBDL::loadFont("assets/font/Azuki Regular.ttf", 20);
    Font *highscorefont = SBDL::loadFont("assets/font/Azuki Regular.ttf", 50);
    Font *scorefont = SBDL::loadFont("assets/font/digitalnumberbttf.otf", 50);
    Music *music = SBDL::loadMusic("assets/sound/music.mp3");
    Sound *click = SBDL::loadSound("assets/sound/click.mp3");
    Sound *falling =SBDL::loadSound("assets/sound/fall_1.wav");
    ///////////////////////////////////firstinitializerope&&squirrels\\\\\\\\\\\\\\\\\\?
    for (int i = 0; i <3 ; ++i) {
       roper[i] ={48,-200,400,50};
        squirrelr[i] ={48,-2000000,30,30};
       roper[i].y=-200+((rand()%10)*-100);
       if((rand()%10)<4)
       squirrelr[i].y=roper[i].y-20;
    }
        boost[0]={200,30,30,30};
    boost[1]={230,30,30,30};
    boost[2]={260,30,30,30};
    SBDL::playMusic(music,-1);
    while (SBDL::isRunning()) {
        int startTime = SBDL::getTime();

        SBDL::updateEvents();
        SBDL::clearRenderScreen();

            if(game==false){
                if(firstmenu) {
                    SBDL::showTexture(menubackground, menuback);
                    SBDL::showTexture(play, menuplay);
                    SBDL::showTexture(sound, menusound);
                    SBDL::showTexture(exit, menuexit);
                    if(musicon==false){
                        SBDL::showTexture(offslash,offslashr);
                    }
                    if(SBDL::mouseInRect(menuplay)){
                        if(SBDL::Mouse.clicked(1)) {
                            SBDL::playSound(click,1);
                            game = true;
                            firstmenu = false;
                            restartgame(foreground);
                        }
                    }
                    if(SBDL::mouseInRect(menusound)){
                        if(SBDL::Mouse.clicked(1)){
                            SBDL::playSound(click,1);
                            if(musicon==true){
                                SBDL::stopMusic();
                                musicon=false;
                            } else {
                                SBDL::playMusic(music, -1);
                                musicon=true;
                            }


                        }

                    }
                    if(SBDL::mouseInRect(menuexit)){
                        if(SBDL::Mouse.clicked(1)){
                            SBDL::playSound(click,1);
                            return(0);

                        }


                    }

                }
                else if(pausemenub){

                SBDL::showTexture(pausemenu,pausemenur);
                SBDL::showTexture(resume,continuepause);
                SBDL::showTexture(playagain,playagainpause);
                SBDL::showTexture(home,firstmenupause);
                if(SBDL::mouseInRect(continuepause)){
                    if(SBDL::Mouse.clicked(1)){
                        SBDL::playSound(click,1);
                        game=true;
                        pausemenub=false;
                    }

                }
                if(SBDL::mouseInRect(playagainpause)){
                    if(SBDL::Mouse.clicked(1)){
                        SBDL::playSound(click,1);
                        game=true;
                        pausemenub=false;
                       restartgame(foreground);
                    }

                }
                if(SBDL::mouseInRect(firstmenupause)){
                    if(SBDL::Mouse.clicked(1)){
                        SBDL::playSound(click,1);
                        game=false;
                        pausemenub=false;
                        firstmenu=true;
                    }


                }
                }
                else if(gameover){
                    SBDL::showTexture(gameovermenu,gameoverback);
                    Texture scoretexture = SBDL::createFontTexture(scorefont,to_string(score/10), 0, 0, 0);
                    Texture highscoretexture = SBDL::createFontTexture(scorefont,to_string(highscore), 0, 0, 0);
                    SBDL::showTexture(playagain,playagaingo);
                    SBDL::showTexture(home,firstmenugo);
                    SBDL::showTexture(scoretexture, 200, 40);
                    SBDL::showTexture(highscoretexture, 200,120);
                    if(SBDL::mouseInRect(playagaingo)){
                        if(SBDL::Mouse.clicked(1)){
                            SBDL::playSound(click,1);
                            game=true;
                            gameover=false;
                            restartgame(foreground);

                        }
                    }
                    if(SBDL::mouseInRect(firstmenugo)){
                        if(SBDL::Mouse.clicked(1)){
                            SBDL::playSound(click,1);
                            game=false;
                            gameover=false;
                            firstmenu=true;
                        }


                    }

                }

            }
            else {

                if((score/10)>highscore){
                    highscore = score/10;
                    fstream file("highscore.txt", ios::out);
                    file << highscore << endl;
                    file.close();
                }
                if(SBDL::keyPressed(SDL_SCANCODE_P)){
                    game=false;
                    pausemenub=true;
                }
                initializegamebackground(background);

                squirrelfunc(squirrel1, squirrel2, squirrel3, squirrel4);
                ropefunc(rope);
                houseinitialize(house1, house2);
                throwerfunc(thrower);
                throwblade(blade1);
                birdright(bird1, bird2, bird3);
                birdleft(bird1, bird2, bird3);
                spikefunc(spike);
                shieldfunc(shield);
                if (shieldb) {
                    runright.w = 50;
                    runright.h = 50;
                    runright.x = 410;
                    runleft.w = 50;
                    runleft.h = 50;
                    runleft.x = 40;
                    jump.w = 110;
                    jump.h = 110;
                    jump.y = 240;

                } else {
                    runright.w = 20;
                    runright.h = 40;
                    runright.x = 430;
                    runleft.x = 50;
                    runleft.w = 20;
                    runleft.h = 40;
                    jump.w = 50;
                    jump.h = 40;
                    jump.y = 270;
                }
                if (birdcounter >= 3) {

                    isbirdboost = true;
                    birdcounter = 0;
                } else if (bladecounter >= 3) {

                    isbladeboost = true;
                    bladecounter = 0;
                } else if (squirrelcounter >= 3) {
                    issquirrelboost = true;
                    squirrelcounter = 0;
                }
                if (issquirrelboost || isbladeboost || isbirdboost) {
                    FPS = 500;
                    delay = 1000 / FPS;
                    boostanimationfunc(boostblade1, boostblade2, boostbird1, boostbird2, boostsquirrel);

                } else {
                    FPS = 60;
                    delay = 1000 / FPS;
                    if (rightp == true) {

                        if (isfallingr) {
                            fallinganimation(falling1, falling2, falling3);
                            SBDL::playSound(falling,1);
                        } else {
                            if (SBDL::keyPressed(SDL_SCANCODE_SPACE)) {
                                jumpaction = true;
                            }
                            if (jumpaction) {
                                fire();
                                jumpfunc(jump1, jump2, jump3, jump4, rightp, shieldjump1, shieldjump2, shieldjump3);
                            } else {
                                checkfunc();
                                fallright();
                                runanimationright(runright1, runright2, runright3, shieldrunright1, shieldrunright2,
                                                  shieldruntight3);
                            }
                        }

                    } else {

                        if (isfallingl) {
                            fallinganimation(falling1, falling2, falling3);
                            SBDL::playSound(falling,1);
                        } else {
                            if (SBDL::keyPressed(SDL_SCANCODE_SPACE)) {
                                jumpaction = true;
                            }
                            if (jumpaction) {
                                fire();
                                jumpfunc(jump1, jump2, jump3, jump4, rightp, shieldjump1, shieldjump2, shieldjump3);
                            } else {
                                checkfunc();
                                fallleft();
                                runanimationleft(runleft1, runleft2, runleft3, shieldrunleft1, shieldrunleft2,
                                                 shieldrunleft3);
                            }
                        }
                    }
                }
                if (shieldcount > 0)
                    SBDL::showTexture(extrashield, shieldalarm);
                if (SBDL::mouseInRect(shieldalarm)) {
                    if (SBDL::Mouse.clicked(1)) {
                        shieldcount = 0;
                        shieldb = true;
                    }

                }
                for (int i = 0; i < birdcounter; ++i) {
                    SBDL::showTexture(bird1, boost[i]);
                }
                for (int j = 0; j < bladecounter; ++j) {
                    SBDL::showTexture(blade1, boost[j]);
                }
                for (int k = 0; k < squirrelcounter; ++k) {
                    SBDL::showTexture(squirrel1, boost[k]);
                }
                score++;
                Texture scoretexture = SBDL::createFontTexture(font, "Score: " + to_string(score/10), 0, 0, 0);
                SBDL::showTexture(scoretexture, 220, 0);
                if((score/10)>highscore) {
                    if(counter8==0) {
                        newrecord = true;
                        highscore = score / 10;
                        counter8++;
                    }
                }
                if(newrecord){
                    Texture scoretexture = SBDL::createFontTexture(highscorefont, "NEW RECORD!!!!", 0, 0, 0);
                        counter8++;
                        if(counter8<180) {
                            SBDL::showTexture(scoretexture,100, 400);
                            if (counter8 >= 179) {
                                newrecord = false;
                                counter8=1;
                            }
                        }
                    }

                initializeforeground(foreground);

            }
                SBDL::updateRenderScreen();

        int elapsedTime = SBDL::getTime() - startTime;
        if (elapsedTime < delay)
            SBDL::delay(delay - elapsedTime);

    }
}