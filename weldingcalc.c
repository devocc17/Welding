//welding calc
#include <stdio.h>

char casts(char size);
char msteel(char elc, char size);
char ssteel(char elc);
char amig(char tk);
char ssmig(char tk);
char smig(char tk);
char atig(char tt, char joint);
char dctig();
char mgtig();
char ss_stig();
char flux(char size, char gas);

int main(){
    // smt = stick material type, tmt = tig material type, mmt = MIG material type
    char wt;
    // Stick
    char mt, elct, elcs, stick;
    // MIG
    char mmt, mtk;
    // TIG
    char tmt, ttk, tmth;
    // Flux-Cored MIG
      // tk = thickness
    char tk, gs, flx;

  printf("What Welding process are you working with?: 1.(Stick) 2.(MIG) 3.(tIG) 4.(Flux-Cored MIG): ");
    scanf(" %c", &wt);

    switch(wt){
      case '1':
        printf("Stick\n");
      break;
      case '2':
        printf("MIG\n");
      break;
      case '3':
        printf("TIG\n");
      break;
      case '4':
        printf("Flux-Core MIG");
      break;
    }
    // 1=stick, 2=MIG, 3=TIG, 4=Flux MIG
    if(wt == '1'){
      printf("What material are being worked with?: 1.(Cast Iron) 2.(Mild Steel) 3.(Stainless Steel): ");
         scanf(" %c", &mt);

         if(mt == '1'){
             printf("Your Electordes for Cast Iorn are: Ni-CL: 1.(1/8) 2.(3/16) 3.(3/32) 4.(5/32): ");
                 scanf(" %c", &elct);
                 stick = casts(elct);
          }else if(mt == '2'){
             printf("Your Electrodes for Mild Steel are : 1.(E6010/E6011) 2.(E6013) 3.(E7014) 4.(E7018) 5.(E7024): ");
                 scanf(" %c", &elct);
              if(elct == '1'){
                printf("What is the Diamiter of rod are you using: E6010/E6011: 1.(1/4) 2.(1/8) 3.(3/16) 4.(3/32) 5.(5/32) 6.(7/32): ");
                  scanf(" %c", &elcs);
              }else if(elct == '2'){
                printf("What is the Diamiter of rod are you using: E6013: 1.(1/16) 2.(1/4) 3.(1/8) 4.(3/16) 5.(3/32) 6.(5/32) 7.(5/64) 8.(7/32): ");
                  scanf(" %c", &elcs);
              }else if(elct == '3' || elct == '4' || elct == '5'){
                printf("What is the Diamiter of rod are you using: E7014, E7018, E7024: 1.(1/4) 2.(1/8) 3.(3/16) 4.(3/32) 5.(5/32) 6.(7/32): ");
                  scanf(" %c", &elcs);
              }
             stick = msteel(elct, elcs);
          }else if(mt == '3'){
             printf("Your Electordes for Stainless Steel are: 1.(E308L 1/8) 2.(E308L 3/32) 3.(E308L 5/32): \n");
                scanf(" %c", &elct);
                ssteel(elct);
         }
    }else if(wt == '2'){
         printf("What material are being worked with?: 1.(Aluminum) 2.(Stainless Steel) 3.(Steel): \n");
          scanf(" %c", &mmt);
        if(mmt == '1'){
          printf("What thickness of Material is being used: 1.(1/8) 2.(3/16) 3.(1/4) 4.(5/16) 5.(3/8) 6.(7/16) 7.(1/2 +): ");
            scanf(" %c", &mtk);
            amig(mtk);
        }else if(mmt == '2'){
         printf("What thickness of Material is being used: 1.(18ga.) 2.(16ga.) 3.(14ga.) 4.(12ga.) 5.(3/16) 6.(1/4) 7.(5/16) 8.(3/8) 9.(7/16) 10.(1/2 +): ");
          scanf(" %c", &mtk);
            ssmig(mtk);
        }else if(mmt == '3'){
         printf("What thickness of Material is being used: 1.(22ga.) 2.(20ga.) 3.(18ga.) 4.(16ga.) 5.(14ga.) 6.(1/8) 7.(3/16) 8.(1/4) 9.(5/16) 10.(3/8) 11.(1/2 +): ");
          scanf(" %c", &mtk);
            smig(mtk);
        }
    }else if(wt == '3'){
        printf("What material ate being worked with?: 1.(Aluminum) 2.(Deoxidised Copper) 3.(Magnesium) 4.(Stainless Steel/Steel): ");
         scanf(" %c", &tmt);
        //printf("What type of weld are you doing: 1.(Butt) 2.(Lap) 3.(Corner) 4.(Fillet) 5.(Corner, V-Grove) 6.(Butt, Open Root) 7.(Butt, V-Grove) 8.(Butt, Dbl V-Grove): ");
          if(tmt == '1'){
          printf("What size is being used: 1.(1/16) 2.(1/8) 3.(3/16) 4.(1/4) 5.(3/8) 6.(1/2): ");
            scanf(" %c", &ttk);
        }
    }else if(wt == '4'){

       printf("What thickness is being used?: 1.(3/32) 2.(1/8) 3.(3/16) 4.(1/4) 5.(3/8): only gas shielded: 6.(1/2) 7.(5/8): ");
        scanf(" %c", &tk);

       printf("Are you using a sheilding gass or Self-shielded: g or s: ");
         scanf(" %c", &gs);
        flx = flux(tk, gs);
     }

  return 0;
}
char casts(char size){
  if(size == '1'){
          printf("You have chosen Ni-CL 1/8 inch \n");
          printf("The Amperage range for this setting is: 65 - 85\n");
          printf("The Polarity is: AC or DCEP\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Cast Iron\n");
  }else if(size == '2'){
          printf("You have chosen Ni-CL 3/16 \n");
          printf("The Amperage range of this Electrode is: 130 - 175\n");
          printf("Polatiry is: AC or DCEP\n");
          printf("Penetration: Low\n");
          printf("Weld Postion: All Postions (Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Cast Iron\n");
  }else if(size == '3'){
          printf("You have chosen Ni-CL 3/32 \n");
          printf("The Amperage range of this setting is: 50 - 70 \n");
          printf("The Polatity is: AC or DCEP \n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Positions (Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Cast Iron\n");
  }else if(size == '4'){
          printf("You have chosen Ni-CL 5/32\n");
          printf("The Amperage range of this setting is: 100 - 140\n");
          printf("The Polatiry is: AC or DCEP\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Positions (Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Cast Iron\n");
  }
}
char ssteel(char elc){
  if(elc == '1'){
      printf("You have selected: E308L: 1/8\n");
        printf("The Amperage range of this Electrode is: 75 - 115\n");
        printf("The Polarity is: AC or DCEP\n");
        printf("Penetration: Low\n");
        printf("Weld Postion: All Postions (Flat, Horizontal, Vertical, Overhead)\n");
        printf("Usage: Stainless Steel\n");
  }else if(elc == '2'){
    printf("You have selected: E308L: 3/32\n");
      printf("The Amperage range of this Electrode is: 40 - 80\n");
      printf("The Polarity is: AC or DCEP\n");
      printf("Penetration: Low\n");
      printf("Weld Postion: All Postions (Flat, Horizontal, Vertical, Overhead)\n");
      printf("Usage: Stainless Steel\n");
  }else if(elc == '3'){
    printf("You have selected: E308L: 5/32\n");
      printf("The Amperage range of this Electrode is: 105 - 160\n");
      printf("The Polarity is: AC or DCEP\n");
      printf("Penetration: Low\n");
      printf("Weld Postion: All Postions (Flat, Horizontal, Vertical, Overhead)\n");
      printf("Usage: Stainless Steel\n");
  }
}
char msteel(char elc, char size){
  // E6010/E6011
    if(elc == '1' && size == '1'){
      printf("You have chosen: E6010/E6011: 1/4  \n");
          printf("The Amperage range for this setting is: 210 - 315\n");
          printf("The Polarity is: E6010:(DCEP) E6011:(AC or DCEP)\n");
          printf("Penetration: Deep\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Minimun Prep, Rough Bead, High Splater\n");
    }else if(elc == '1' && size == '2'){
      printf("You have chosen: E6010/E6011: 1/8 \n");
          printf("The Amperage range for this setting is: 75 - 125\n");
          printf("The Polarity is: E6010:(DCEP) E6011:(AC or DCEP)\n");
          printf("Penetration: Deep\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Minimup prep, Rough Bead, High Splater\n");
    }else if(elc == '1' && size == '3'){
      printf("You have chosen: E6010/E6011: 3/16 \n");
          printf("The Amperage range for this setting is: 140 - 210\n");
          printf("The Polarity is: E6010:(DCEP) E6011:(AC or DCEP)\n");
          printf("Penetration: Deep\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage:Minimup prep, Rough Bead, High Splater\n ");
    }else if(elc == '1' && size == '4'){
      printf("You have chosen: E6010/E6011: 3/32 \n");
          printf("The Amperage range for this setting is: 40 - 85\n");
          printf("The Polarity is: E6010:(DCEP) E6011:(AC or DCEP)\n");
          printf("Penetration: Deep\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Minimup prep, Rough Bead, High Splater\n");
    }else if(elc == '1' && size == '5'){
      printf("You have chosen: E6010/E6011: 5/32 \n");
          printf("The Amperage range for this setting is: 110 - 165\n");
          printf("The Polarity is: E6010:(DCEP) E6011:(AC or DCEP)\n");
          printf("Penetration: Deep\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Minimup prep, Rough Bead, High Splater\n");
    }else if(elc == '1' && size == '6'){
      printf("You have chosen: E6010/E6011: 7/32 \n");
          printf("The Amperage range for this setting is: 160 - 250\n");
          printf("The Polarity is: E6010:(DCEP) E6011:(AC or DCEP)\n");
          printf("Penetration: Deep\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage:Minimup prep, Rough Bead, High Splater\n ");
    }
  // E6013
    else if(elc == '2' && size == '1'){
      printf("You have chosen: E6013: 1/16  \n");
          printf("The Amperage range for this setting is: 20 - 45\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: General Purpose\n");
    }else if(elc == '2' && size == '2'){
      printf("You have chosen: E6013: 1/4\n");
          printf("The Amperage range for this setting is: 250 - 350\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: General Purpose\n");
    }else if(elc == '2' && size == '3'){
      printf("You have chosen: E6013: 1/8\n");
          printf("The Amperage range for this setting is: 80 - 130\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: General Purpose\n");
    }else if(elc == '2' && size == '4'){
      printf("You have chosen: E6013: 3/16 \n");
          printf("The Amperage range for this setting is: 150 - 230\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: General Purpose\n");
    }else if(elc == '2' && size == '5'){
      printf("You have chosen: E6013: 3/32\n");
          printf("The Amperage range for this setting is: 40 - 90\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: General Purpose");
    }else if(elc == '2' && size == '6'){
      printf("You have chosen: E6013:  5/32\n");
          printf("The Amperage range for this setting is: 105 - 180\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: General Purpose\n");
    }else if(elc == '2' && size == '7'){
      printf("You have chosen: E6013: 5/64\n");
          printf("The Amperage range for this setting is: 35 - 60\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: General Purpose\n");
    }else if(elc == '2' && size == '8'){
      printf("You have chosen: E6013: 7/32\n");
          printf("The Amperage range for this setting is: 210 - 300\n");
          printf("The Polarity is: AC DCEP DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: General Purpose\n");
    }
  // E7014
   else if(elc == '3' && size == '1'){
      printf("You have chosen: E7014: 1/4  \n");
          printf("The Amperage range for this setting is: 330 - 415 \n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Medium\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Smooth Bead, Easy, Fast\n");
    }else if(elc == '3' && size == '2'){
      printf("You have chosen: E7014: 1/8 \n");
          printf("The Amperage range for this setting is: 110 - 165\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Medium\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Smooth Bead, Easy, Fast\n");
    }else if(elc == '3' && size == '3'){
      printf("You have chosen: E7014:  3/16 \n");
          printf("The Amperage range for this setting is: 200 - 275\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Medium\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Smooth Bead, Easy, Fast\n");
    }else if(elc == '3' && size == '4'){
      printf("You have chosen: E7014: 3/32 \n");
          printf("The Amperage range for this setting is: 80 - 125\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Medium\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Smooth Bead, Easy, Fast\n");
    }else if(elc == '3' && size == '5'){
      printf("You have chosen: E7014: 5/32 \n");
          printf("The Amperage range for this setting is: 150 - 210\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Medium\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Smooth Bead, Easy, Fast\n");
    }else if(elc == '3' && size == '6'){
      printf("You have chosen: E7014: 7/32\n");
          printf("The Amperage range for this setting is: 255 - 340\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Medium\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Smooth Bead, Easy, Fast\n");
    }
  // E7018
    else if(elc == '4' && size == '1'){
      printf("You have chosen: E7018: 1/4 \n");
          printf("The Amperage range for this setting is: 320 - 400\n");
          printf("The Polarity is: AC or DCEP\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Low Hydrogen, Strong Weld\n");
    }else if(elc == '4' && size == '2'){
      printf("You have chosen: E7018: 1/8 \n");
          printf("The Amperage range for this setting is: 110 - 165\n");
          printf("The Polarity is: AC or DCEP\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Low Hydrogen, Strong Weld\n");
    }else if(elc == '4' && size == '3'){
      printf("You have chosen: E7018: 3/16 \n");
          printf("The Amperage range for this setting is: 200 - 275\n");
          printf("The Polarity is: AC or DCEP\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Low Hydrogen, Strong Weld\n");
    }else if(elc == '4' && size == '4'){
      printf("You have chosen: E7018: 3/32 \n");
          printf("The Amperage range for this setting is: 65 - 100 \n");
          printf("The Polarity is: AC or DCEP\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Low Hydrogen, Strong Weld\n");
    }else if(elc == '4' && size == '5'){
      printf("You have chosen: E7018: 5/32 \n");
          printf("The Amperage range for this setting is: 150 - 220\n");
          printf("The Polarity is: AC or DCEP\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Low Hydrogen, Strong Weld\n");
    }else if(elc == '4' && size == '6'){
      printf("You have chosen: E7018: 7/32 \n");
          printf("The Amperage range for this setting is: 260 - 340\n");
          printf("The Polarity is: AC or DCEP\n");
          printf("Penetration: Low\n");
          printf("Weld Position: All Postions(Flat, Horizontal, Vertical, Overhead)\n");
          printf("Usage: Low Hydrogen, Strong Weld\n");
    }
  // E7024
    else if(elc == '5' && size == '1'){
      printf("You have chosen: E7024: 1/4 \n");
          printf("The Amperage range for this setting is: 335 - 430\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: Flat, Horizontal, Fillet\n");
          printf("Usage: Smooth Bead, Easy, Faster\n");
    }else if(elc == '5' && size == '2'){
      printf("You have chosen: E7024: 1/8 \n");
          printf("The Amperage range for this setting is: 140 - 190\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: Flat, Horizontal, Fillet\n");
          printf("Usage: Smooth Bead, Easy, Faster\n");
    }else if(elc == '5' && size == '3'){
      printf("You have chosen: E7024: 3/16 \n");
          printf("The Amperage range for this setting is: 230 - 305\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: Flat, Horizontal, Fillet\n");
          printf("Usage: Smooth Bead, Easy, Faster\n");
    }else if(elc == '5' && size == '4'){
      printf("You have chosen: E7024: 3/32\n");
          printf("The Amperage range for this setting is: 100 - 145\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: Flat, Horizontal, Fillet\n");
          printf("Usage: Smooth Bead, Easy, Faster\n");
    }else if(elc == '5' && size == '5'){
      printf("You have chosen: E7024: 5/32 \n");
          printf("The Amperage range for this setting is: 180 - 250\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: Flat, Horizontal, Fillet\n");
          printf("Usage: Smooth Bead, Easy, Faster\n");
    }else if(elc == '5' && size == '6'){
      printf("You have chosen: E7024: 7/32 \n");
          printf("The Amperage range for this setting is: 275 - 365\n");
          printf("The Polarity is: AC, DCEP, DCEN\n");
          printf("Penetration: Low\n");
          printf("Weld Position: Flat, Horizontal, Fillet\n");
          printf("Usage: Smooth Bead, Easy, Faster\n");
    }
}
char amig(char tk){
    if(tk == '1'){
      printf("Spray Arc Transfer:\n");
        printf("Material Thickness: 1/8\n");
        printf("Wire size: .035\n");
        printf("Wire Feed Speed: 350 - 400 imp\n");
        prinf("Wire size: 3/64\n");
        printf("wire Feed Speed: 240 - 270\n");
        prinf("Shielding gas & Voltage: Argon (AL): 21 - 22 Volts\n");
        printf("Amperage Range: 110 - 130\n");
    }else if(tk == '2'){
      printf("Spray Arc Transfer:\n");
        printf("Material Thickness: 3/16\n");      
        printf("Wire size: .035\n");
        printf("Wire Feed Speed: 425 - 450 ipm\n");
        prinf("Wire size: 3/64\n");
        printf("wire Feed Speed: 300 - 325 ipm\n");
        prinf("Shielding gas & Voltage: Argon (AL): 23 - 24 Volts\n");
        printf("Amperage Range: 140 - 150\n");
    }else if(tk == '3'){
      printf("Spray Arc Transfer:\n");
        printf("Material Thickness: 1/4\n");      
        printf("Wire size: 3/64\n");
        printf("Wire Feed Speed: 350 - 375 ipm\n");
        prinf("Wire size: 1/16\n");
        printf("wire Feed Speed: 170 - 185 ipm\n");
        prinf("Shielding gas & Voltage: Argon (AL): 24 - 25 Volts\n");
        printf("Amperage Range: 180 - 210\n");
    }else if(tk == '4'){
      printf("Spray Arc Transfer:\n");
        printf("Material Thickness: 5/16\n");
        printf("Wire size: 3/64\n");
        printf("Wire Feed Speed: 400 - 425 ipm\n");
        prinf("Wire size: 1/16\n");
        printf("wire Feed Speed: 200 - 210 ipm\n");
        prinf("Shielding gas & Voltage: Argon (AL): 26 - 27 Volts\n");
        printf("Amperage Range: 200 - 230\n");
    }else if(tk == '5'){
      printf("Spray Arc Transfer:\n");
        printf("Material Thickness: 3/8\n");  
        printf("Wire size: 3/64\n");
        printf("Wire Feed Speed: 450 - 480 ipm\n");
        prinf("Wire size: 1/16\n");
        printf("wire Feed Speed: 220 - 230 ipm\n");
        prinf("Shielding gas & Voltage: Argon (AL): 26 - 28 Volts\n");
        printf("Amperage Range: 220 - 250\n");
    }else if(tk == '6'){
      printf("Spray Arc Transfer:\n");
        printf("Material Thickness: 7/16\n");
        printf("Wire size: 1/16\n");
        printf("Wire Feed Speed: 240 - 270 ipm\n");
        prinf("Shielding gas & Voltage: Argon (AL): 28 - 29 Volts\n");
        printf("Amperage Range: 280\n");
    }else if(tk == '7'){
      printf("Spray Arc Transfer:\n");
        printf("Material Thickness: 1/2 and up\n");
        printf("Wire size: 1/16\n");
        printf("Wire Feed Speed: 290 - 300 ipm\n");
        prinf("Shielding gas & Voltage: Argon (AL): 29 - 30 Volts\n");
        printf("Amperage Range: 300\n");
    }
}
char ssmig(char tk){
  if(tk == '1'){
    printf("Short Circuit Transfer: \n");
      printf("Material Thickness: 18ga.\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 120 - 150 ipm\n");
      printf("Shielding Gas & Voltage range: He + Ar + CO2: 19 - 20 Volts \n");
      printf("Amperage range: 50 - 60\n");
  }else if(tk == '2'){
    printf("Short Circuit Transfer: \n");
      printf("Material Thickness: 16ga.\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 180 - 205 ipm\n");
      printf("Shielding Gas & Voltage range: He + Ar + CO2: 19 - 20 Volts\n");
      printf("Amperage range: 70 - 80\n");
  }else if(tk == '3'){
    printf("Short Circuit Transfer: \n");
      printf("Material Thickness: 14ga.\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 230 - 275 ipm\n");
      printf("Shielding Gas & Voltage range: He + Ar + CO2: 20 - 21 Volts\n");
      printf("Amperage range: 90 - 110\n");
  }else if(tk == '4'){
    printf("Short Circuit Transfer: \n");
      printf("Material Thickness: 12ga.\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 300 - 325 ipm\n");
      printf("Shielding Gas & Voltage range: He + Ar + CO2: 20 - 21 Volts\n");
      printf("Amperage range: 120 - 130\n");
  }else if(tk == '5'){
    printf("Short Circuit Transfer: \n");
      printf("Material Thickness: 3/16\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 350 - 375 ipm\n");
      printf("Shielding Gas & Voltage range: He + Ar + CO2: 20 - 21 Volts\n");
      printf("Amperage range: 140 - 150\n");
    printf("Spray Arc Transfer: \n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 400 - 425\n");
      printf("Shielding Gas & Voltage range: 98Ar/2O2\n");
      printf("Amperage range: 160 - 170\n");
  }else if(tk == '6'){
    printf("Short Circuit Transfer: \n");
      printf("Material Thickness: 1/4\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 400 - 425 ipm\n");
      printf("Shielding Gas & Voltage range: He + Ar + CO2: 20 - 21 Volts\n");
      printf("Amperage range: 160 - 170\n");
    printf("Spray Arc Transfer: \n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 450 - 475 ipm\n");
      printf("Shielding Gas & Voltage range: 98Ar/2O2\n");
      printf("Amperage range: 180 - 190\n");
  }else if(tk == '7'){
    printf("Short Ciruit Transfer: \n");
      printf("Material Thickness: 5/16\n");
      printf("Wire size: .035\n");
      printf("Wire Feed speed: 450 - 475 ipm\n");
      printf("Shielding Gas& Voltage range: He + Ar + CO2: 21 - 22 Volts\n");
      printf("Amperage Range: 180 - 190\n");
    printf("Spray Arc Transfer: \n");
      printf("Wire size: .045\n");
      printf("Wire Feed Speed: 250 - 300 ipm\n");
      printf("Shielding Gas & Voltage range: 98Ar/2O2: 24 - 25 Volts\n");
      printf("Amperage range: 200 - 210\n");
  }else if(tk == '8'){
    printf("Spray Arc Transfer: \n");
      printf("Material Thickness: 3/8\n");
      printf("Wire size: 1/16\n");
      printf("Wire Feed Speed: 140 - 170 ipm\n");
      printf("Shielding Gas & Voltage range: 98Ar/2O2: 25 - 26 Volts\n");
      printf("Amperage range: 250 - 275\n");
  }else if(tk == '9'){
    printf("Spray Arc Transfer: \n");
      prinf("Material Thickness: 7/16\n");
      printf("Wire size: 1/16\n");
      printf("Wire Feed Speed: 170 - 200 ipm\n");
      printf("Shielding Gas & Voltage range: 98Ar/2O2: 26 - 27 Volts\n");
      printf("Amperage range: 275 - 300\n");
  }else if(tk == '10'){
    printf("Spray Arc Transfer: \n");
      printf("Material Thickness: 1/2 and up\n");
      printf("Wire size: 1/16\n");
      printf("Wire Feed Speed: 200 - 230 ipm\n");
      printf("Shielding Gas & Voltage range: 98Ar/2O2: 27 - 32 Volts\n");
      printf("Amperage range: 300 - 325\n");
  }
}
char smig(char tk){
  if(tk == '1'){
    printf("Short Circuit Transfer: \n");
      printf("Material Size: 22ga.\n");
      printf("Wire size: .030\n");
      printf("Wire Feed Speed: 90 - 100 ipm\n");
      printf("Shielding Gas & Voltage Range: CO2: 16 - 17 Volts\n");
      printf("Shielding Gas & Voltage Range: 75Ar/25CO2: 15 - 16 Volts\n");
      printf("Amperage Range: 40 - 55\n");
  }else if(tk == '2'){
      printf("Short Circuit Transfer: \n");
      printf("Material Size: 20ga.\n");
      printf("Wire size: .030\n");
      printf("Wire Feed Speed: 120 - 135 ipm\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 105 - 115\n");
      printf("Shielding Gas & Voltage Range: CO2: 17 - 18 Volts\n");
      printf("Shielding Gas & Voltage Range: 75Ar/25CO2: 15 - 16 Volts\n");
      printf("Amperage Range: 50 - 60\n");
  }else if(tk == '3'){
    printf("Short Circuit Transfer: \n");
      printf("Material Size: 18ga.\n");
      printf("Wire size: .030\n");
      printf("Wire Feed Speed: 150 - 175 ipm\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 140 - 160 ipm\n");
      printf("Wire size: .045\n");
      printf("Wire Feed Speed: 70 ipm\n");
      printf("Shielding Gas & Voltage Range: CO2: 18 - 19 Volts\n");
      printf("Shielding Gas & Voltage Range: 75Ar/25CO2: 16 - 17 Volts\n");
      printf("Amperage Range: 70- 80\n");
  }else if(tk == '4'){
    printf("Short Circuit Transfer: \n");
      printf("Material Size: 16ga.\n");
      printf("Wire size: .030\n");
      printf("Wire Feed Speed: 220 - 250 ipm\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 180 - 220 ipm\n");
      printf("Wire size: .045\n");
      printf("Wire Feed Speed: 90 - 110 ipm\n");
      printf("Shielding Gas & Voltage Range: CO2: 19 - 20 Volts\n");
      printf("Shielding Gas & Voltage Range: 75Ar/25CO2: 17 - 18 Volts\n");
      printf("Amperage Range: 90 - 110\n");
  }else if(tk == '5'){
    printf("Short Circuit Transfer: \n");
      printf("Material Size: 14ga. \n");
      printf("Wire size: .030\n");
      printf("Wire Feed Speed: 250 - 340 ipm\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 240 - 260 ipm\n");
      printf("Wire size: .045\n");
      printf("Wire Feed Speed: 120 - 130 ipm\n");
      printf("Shielding Gas & Voltage Range: CO2: 20 - 21 Volts\n");
      printf("Shielding Gas & Voltage Range: 75Ar/25CO2: 17 - 18 Volts\n");
      printf("Amperage Range: 120 - 130\n");
  }else if(tk == '6'){
    printf("Short Circuit Transfer: \n");
      printf("Material Size: 1/8\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 280 - 300 ipm\n");
      printf("Wire size: .045\n");
      printf("Wire Feed Speed: 140 - 150 ipm\n");
      printf("Shielding Gas & Voltage Range: CO2: 21 - 22 Volts\n");
      printf("Shielding Gas & Voltage Range: 75Ar/25CO2: 18 - 19 Volts\n");
      printf("Amperage Ranger: 140 - 150\n");
    printf("Spray Arc Transfer: \n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 320 - 340 ipm\n");
      printf("Wire size: .045\n");
      prinf("Wire Feed Speed: 160 - 175 ipm\n");
      prinf("Shielding Gas & Voltage Range: 98Ar/2O2: 23 - 24 Volts\n");
      prinf("Amperage Range: 160 - 170\n");
  }else if(tk == '7'){
    printf("Short Circuit Transfer: \n");
      printf("Material Size: 3/16\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 320 - 340 ipm\n");
      printf("Wire size: .045\n");
      printf("Wire Feed Speed: 160 - 175 ipm\n");
      printf("Shielding Gas & Voltage Range: CO2: 21 - 22 Volts\n");
      printf("Shielding Gas & Voltage Range: 75Ar/25CO2: 18 - 19 Volts\n");
      printf("Amperage Ranger: 160 - 170\n");
    printf("Spray Arc Transfer: \n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 360 - 380 ipm\n");
      printf("Wire size: .045\n");
      prinf("Wire Feed Speed: 185 - 195 ipm\n");
      prinf("Shielding Gas & Voltage Range: 98Ar/2O2: 24 - 25 Volts\n");
      prinf("Amperage Range: 180 - 190\n");
  }else if(tk == '8'){
    printf("Short Circuit Transfer: \n");
      printf("Material Size: 1/4\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 360 - 380 ipm\n");
      printf("Wire size: .045\n");
      printf("Wire Feed Speed: 185 - 195 ipm\n");
      printf("Shielding Gas & Voltage Range: CO2: 23 - 24 Volts\n");
      printf("Shielding Gas & Voltage Range: 75Ar/25CO2: 21 - 22 Volts")
      printf("Amperage Ranger: 180 - 190\n");
    printf("Spray Arc Transfer: \n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 400 - 420 ipm\n");
      printf("Wire size: .045\n");
      prinf("Wire Feed Speed: 210 - 220 ipm\n");
      prinf("Shielding Gas & Voltage Range: 98Ar/2P2: 24 - 25 Volts\n");
      prinf("Amperage Range: 200 - 210\n");
  }else if(tk == '9'){
    printf("Short Circuit Transfer: \n");
      printf("Material Size: 5/16\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 400 - 420 ipm\n");
      printf("Wire size: .045\n");
      printf("Wire Feed Speed: 210 - 220 ipm\n");
      printf("Shielding Gas & Voltage Range: CO2: 23 - 24 Volts\n");
      printf("Shielding Gas & Voltage Range: 75Ar/25CO2: 21 - 22 Volts\n");
      printf("Amperage Ranger: 200 - 210\n");
    printf("Spray Arc Transfer: \n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 420 - 520 ipm\n");
      printf("Wire size: .045\n");
      prinf("Wire Feed Speed: 220 - 270 ipm\n");
      prinf("Shielding Gas & Voltage Range: 98Ar/2O2: 25 - 26 Volts\n");
      prinf("Amperage Range: 220 - 250\n");
  }else if(tk == '10'){
    printf("Short Circuit Transfer: \n");
      printf("Material Size: 3/8\n");
      printf("Wire size: .035\n");
      printf("Wire Feed Speed: 420 - 520\n");
      printf("Wire size: .045\n");
      printf("Wire Feed Speed: 220 - 270 ipm\n");
      printf("Shielding Gas & Voltage Range: CO2: 24 - 25 Volts\n");
      prinf("Shielding Gas & Voltage Range: 75Ar/25CO2: 23 - 24 Volts\n"):
      printf("Amperage Ranger: 220 - 250\n");
    printf("Spray Arc Transfer: \n");
      printf("Wire size: .045\n");
      printf("Wire Feed Speed: 375 ipm\n");
      prinf("Shielding Gas & Voltage Range: 98Ar/2O2: 26 - 27 Volts\n");
      prinf("Amperage Range: 300\n");
  }else if(tk == '11'){
    printf("Spray Arc: \n");
      printf("Material Thickness: 1/2 & up\n");
      printf("Wire size: .045\n");
      printf("Wire Feed Speed: 390 ipm\n");
      printf("Shielding Gas & Voltage Range: 98Ar/@O2: 29 - 30 Volts\n");
      printf("Amperage Range: 315\n");
  }
}
char atig(char tt, char size){

}
char dctig(char tt, char size){

}
char mgtig(char tt, char size){

}
char ss_stig(char tt, char size){

}
char flux(char size, char gas){
    if(gas == 'g'){
      if(size == '1'){
          printf("Size: 3/32\n");
            printf("Wire size: .045\n");
              printf("Wire Feed speed: 175 - 185 ipm\n");
              printf("Amperage range: 110 - 125\n");
              printf("Shielding gas: CO2: 19 - 21 Volts\n");
              printf("Shielding gas: 75Ar-25CO2: 18 - 20 Volts\n");
      }else if(size == '2'){
          printf("Size: 1/8\n");
            printf("Wire size: .045\n");
              printf("Wire Feed speed: 210 - 230 ipm\n");
              printf("Amperage range: 140 - 150\n");
              printf("Shielding gas: CO2: 20 - 22 Volts\n");
              printf("Shielding gas: 75Ar-25CO2: 20 - 21 Volts\n");
      }else if(size == '3'){
          printf("Size: 3/16 \n");
            printf("Wire size: .045\n");
              printf("Wire Feed speed: 235 - 255 ipm\n");
              printf("Amperage range: 155 - 190\n");
              printf("Shielding gas: CO2: 21 - 23 Volts\n");
              printf("Shielding gas: 75Ar-25CO2: 21.5 - 22.5 Volts\n");
            printf("Wire size: 1/16\n");
              printf("Wire Feed speed: 180 - 200 ipm\n");
              printf("Shielding gas: CO2: 25 - 26 Volts\n");
              printf("Shielding gas: 75Ar-25CO2: 24 - 25 Volts\n");
        }else if(size == '4'){
           printf("Size: 1/4 \n");
             printf("Wire size: .045\n");
               printf("Wire Feed speed: 255 - 280 ipm\n");
               printf("Amperage range:  170 - 190\n");
               printf("Shelding gas: CO2: 24 - 25 Volts\n");
               printf("Shelding gas: 75Ar-25CO2: 23 - 24 Volts\n");
             printf("Wire size: 1/16\n");
               printf("Wire Feed speed: 300 - 325 ipm\n");
               printf("Shielding gas: CO2: 28 - 29 Volts\n");
               printf("Shielding gas: 75Ar-25CO2: 26 - 28 Volts\n");
        }else if(size == '5'){
           printf("Size: 3/8 \n");
             printf("Wire size: 1/16\n");
               printf("Wire Feed speed: 350 - 400 ipm\n");
               printf("Amperage range: 330 - 375\n");
               printf("Shielding gas: CO2: 29 - 30 Volts\n");
               printf("Shielding gas: 75Ar-25CO2: 27 - 28 Volts\n");
             printf("Wire size: 3/32\n");
               printf("Wire Feed speed: 120 - 130 ipm\n");
               printf("Amperage range: 340 - 360\n");
               printf("Shielding gas: CO2: 29 - 30 Volts\n");
               printf("Shielding gas: 75Ar-25CO2: 28 - 29 Volts\n");
        }else if(size == '6'){
            printf("Size: 1/2 \n");
              printf("Wire size: 3/32\n");
                printf("Wire Feed speed: 180 - 210 ipm\n");
                printf("Amperage range: 430 - 470\n");
                printf("Shielding gas: CO2: 30 - 31 Volts\n");
                printf("Shielding gas: 75Ar-25CO2: 29 - 30 Volts\n");
              printf("Wire size: 1/8\n");
                printf("Wire Feed speed: 100 - 110 ipm\n");
                printf("Amperage range: 450 - 500\n");
                printf("Shielding gas: CO2: 29 - 30 Volts\n");
                printf("Shielding gas: 75Ar-25CO2: 29 - 30 Volts\n");
          }else if(size == '7'){
             printf("Size: 5/8 \n");
             printf("Wire size: 3/32\n");
               printf("Wire Feed speed: 230 - 250 ipm\n");
               printf("Amperage range: 490 - 525\n");
               printf("Shielding gas: CO2: 31 - 32 Volts\n");
               printf("Shielding gas: 75Ar-25CO2: 30 - 31 Volts\n");
             printf("Wire size: 1/8\n");
               printf("Wire Feed speed: 140 - 160 ipm\n");
               printf("Amperage range: 550 - 600\n");
               printf("Shielding gas: CO2: 29 - 30 Volts\n");
               printf("Shielding gas: 75Ar-25CO2:  29 - 30 Volts\n");
        }

        }else if(gas == 's'){

        if(size == '1'){
           printf("Size: 3/32\n");
           printf("Wire size: .035\n");
               printf("Wire Feed speed: 145 - 155 ipm\n");
               printf("Amperage Range: 110 - 125\n");
               printf("Voltage range: 14 - 15 Volts\n");
           printf("Wire Size: .045\n");
               printf("Wire Feed speed: 75 - 85 ipm\n");
               printf("Amperage Range: 110 - 125\n");
               printf("Voltage Range: 14 - 15 Volts\n");
        }else if(size == '2'){
         printf("Size: 1/8\n");
            printf("Wire size: .035\n");
                printf("Wire Feed speed: 175 - 185 ipm\n");
                printf("Amperage Range: 140 - 155\n");
                printf("Voltage range: 14 - 15 Volts\n");
            printf("Wire Size: .045\n");
                printf("Wire Feed speed: 85 - 95 ipm\n");
                printf("Amperage Range: 140 - 155\n");
                printf("Voltage Range: 14 - 15 Volts\n");
          }else if(size == '3'){
                  printf("Size: 3/16 \n");
                     printf("Wire size: .035\n");
                         printf("Wire Feed speed:  205 - 215 ipm\n");
                         printf("Amperage Range: 190 - 220\n");
                         printf("Voltage range: 15 - 16 Volts\n");
                     printf("Wire Size: .045\n");
                         printf("Wire Feed speed: 105 - 115 ipm\n");
                         printf("Amperage Range: 190 - 220\n");
                         printf("Voltage Range: 15 - 16 Volts\n");
        }else if(size == '4'){
                  printf("Size: 1/4\n");
                     printf("Wire size: .035\n");
                         printf("Wire Feed speed: 220 - 230 ipm\n");
                         printf("Amperage Range: 170 - 190\n");
                         printf("Voltage range: 15 - 16 Volts\n");
                     printf("Wire Size: .045\n");
                         printf("Wire Feed speed: 125 - 135 ipm\n");
                         printf("Amperage Range: 170 - 190\n");
                         printf("Voltage Range: 16 - 17 Volts\n");
                }else if(size == '5'){
                  printf("Size: 3/8\n");
                    printf("Wire size: .035\n");
                        printf("Wire Feed speed: 245 - 255 ipm\n");
                        printf("Amperage range: 330 - 375\n");
                        printf("Voltage range: 16 - 17 Volts\n");
                    printf("Wire size: .045\n");
                        printf("Wire Feed speed: 165 - 175 ipm\n");
                        printf("Amperage range: 330 - 375\n");
                        printf("Voltage range: 17 - 18 Volts\n");
                }else if(size == '6' && '7'){
                    printf("Not Recommened\n");
                }
            }
}
