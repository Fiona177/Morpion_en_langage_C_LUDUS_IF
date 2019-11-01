#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define TAILLE 3

//Prototypes
void initTableau(char cTabCar[TAILLE][TAILLE]);
void placerTableau(char cTabCar[TAILLE][TAILLE],int nx,int ny,int nJoueur);
void afficheTableau (char cTabCar[TAILLE][TAILLE]);
void verifCase (char cTabCar[TAILLE][TAILLE], int nJoueur);
int victoire (char cTabCar[TAILLE][TAILLE]);

char cTabCar[TAILLE][TAILLE];



//----Programme Principal----
int main()
{
    int nTour=1;
    int nJeu=0;
    int nJoueur;

    //On appelle la procédure pour initialiser tous les cases du tableau
    initTableau(cTabCar);

    while (nJeu!=1) //Tant que nJeu est différent de 1 alors le jeu continue
    {
           switch (nTour) //Cas parmi pour les tours
           {
               case 1 : //Lorsque nTour vaut 1 alors c'est le joueur 1 qui joue
                   nJoueur = 1;
                   verifCase (cTabCar,nJoueur); //On appelle la procédure qui vérifie si la case du joueur est libre
                   nTour+=1;
               break;
               case 2 : //Lorsque nTour vaut 2 alors c'est le joueur 2 qui joue
                   nJoueur = 2;
                   verifCase (cTabCar,nJoueur); //On appelle la procédure qui vérifie si la case du joueur est libre
                   nTour=1;
               break;
           }
            afficheTableau(cTabCar); //On affiche le tableau
            nJeu=victoire(cTabCar); //On affecte à nJeu le résultat de la fonction victoire qui permettra de dire si l'une des conditions de victoire a été remplies
    }

    printf("\n\n\n");
    printf("Le joueur %d est le vaiqueur de la partie\n\n",nJoueur); //On indique le gagnant de la partie
    afficheTableau(cTabCar); //On affiche le tableau

    return 0;
}







//----Initialisation du tableau----
void initTableau(char cTabCar[TAILLE][TAILLE])
{
    int ni,nj;
    for (ni=0; ni<=TAILLE;ni++)
    {
        for (nj=0; nj<=TAILLE;nj++)
        {
            cTabCar[ni][nj]='~';
        }
    }
}

//----Verfication si la case est prise + appel de la procédure pour placer les CO----
void verifCase (char cTabCar[TAILLE][TAILLE],int nJoueur)
{
    int ni,nj;
    int nJoueurTemp=nJoueur;
    do
    {
       printf("Joueur %d veuillez indiquer le x et y\n",nJoueurTemp);
        scanf("%d%d",&ni ,&nj);
        ni-=1;
        nj-=1;
    }while (cTabCar[ni][nj]!='~');
    placerTableau(cTabCar,ni,nj,nJoueur); //On appelle la procédure qui pert de placer le caractère du joueur en fonction des coordonnées qu'il a donné

}



//----Placer le caractère du joueur en fonction des Coordonnées dans le tableau----
void placerTableau(char cTabCar[TAILLE][TAILLE],int nx,int ny,int nJoueur)
{
    int ni=nx;
    int nj=ny;
    int nJoueurTemp=nJoueur;
    if (nJoueurTemp==1) cTabCar[ni][nj]='X';
    else cTabCar[ni][nj]='O';
}




//----Condition de victoire----
int victoire (char cTabCar[TAILLE][TAILLE])
{
    int ni,nj;
    int nVictoire;
    for (ni=0;ni<=TAILLE-1;ni++)
    {
        for (nj=0;nj<=TAILLE-1;nj++)
        {
            if (cTabCar[ni][nj]!='~')
            {
                //Il faut que 3 même caractères se suivent
                //Vérification horizontale
                if ((cTabCar[ni][nj-1]==cTabCar[ni][nj])&&(cTabCar[ni][nj+1]==cTabCar[ni][nj])) nVictoire=1;
                //Vérification verticale
                if ((cTabCar[ni-1][nj]==cTabCar[ni][nj])&&(cTabCar[ni+1][nj]==cTabCar[ni][nj])) nVictoire=1;
                //Vérification diagonale haut gauche à bas droite
                if ((cTabCar[ni-1][nj-1]==cTabCar[ni][nj])&&(cTabCar[ni+1][nj+1]==cTabCar[ni][nj])) nVictoire=1;
                //Vérification diagonale bas gauche à haut droite
                if ((cTabCar[ni+1][nj+1]==cTabCar[ni][nj])&&(cTabCar[ni-1][nj-1]==cTabCar[ni][nj])) nVictoire=1;
            }
        }
    }
    return nVictoire;
}




//----AFFICHAGE----
void afficheTableau (char cTabCar[TAILLE][TAILLE])
{
    int ni,nj;
    for (ni=0; ni<=TAILLE-1;ni++)
    {
        for (nj=0; nj<=TAILLE-1;nj++)
        {
            printf("%c",cTabCar[ni][nj]);
        }
        printf("\n");
    }
}





