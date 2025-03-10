#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nom[50];
    char email[50];
    char mdp[50];
    int role;
}Utilisateurs;


//-------------------------------------------------Menu Principal


void MenuPrincipal()
{
   Principal:
    int choix;
    puts("\n==================== Menu Principal ==================== \n");
    puts("1. Inscription\n");
    puts("2. Connexion\n");
    puts("3 Quitter\n");
    puts("Faites votre choix : \n");
    scanf("%d", &choix);
    switch(choix)
    {
        case 1:
        char rep;
        do{
           inscription();
           puts("========================================");
           puts("Voulez-vous continuer la saisie ! Tapez Y ou y pour continuer ou tous autres caractére pour quitter .");
           scanf(" %c", &rep);
        }while(rep == 'Y' || rep == 'y');
           break;
           
        case 2 :
            connexion();
            break;
        case 3 :
            printf("Au revoir");
            break;
        default:
            printf("Veuillez faire un choix valide !!");
    }
    goto Principal;

}

//-----------------------------------------------1fonction inscription

void inscription()
{
    

        FILE *fich = fopen("UTILISATEUR", "ab");
        if(fich == NULL)
        {
            printf("Fichier vide");
        }

        Utilisateurs users;
        fflush(stdin);
        printf("\n==================== Inscription ==================== \n");
        printf("Entrez votre nom :");
        scanf("%s",users.nom);
        printf("Entrez votre email :");
        scanf("%s",users.email);
        printf("Entrez votre mot de passe :");
        scanf("%s",users.mdp);
        printf("choississez votre role :");
        scanf("%d", &users.role);

        fwrite(&users, sizeof(Utilisateurs), 1, fich);
        fclose(fich);

        printf("Inscription réussie.Vous pouvez maintenant vous connecter.\n\n");

}


//-------------------------------------------------fonction connexion

void connexion()
{

    FILE *fich = fopen("UTILISATEUR", "rb");
    if(fich == NULL)
    {
        printf("fichier vide");
    }
 
    Utilisateurs users, tmp;
    int trouve = 0;
    printf("\n==================== Connexion ==================== \n");
    printf("Entrez votre email :");
    scanf("%s", users.email);
    printf("Entrez votre mot de passe :");
    scanf("%s", users.mdp);

    while (fread(&tmp, sizeof(Utilisateurs), 1, fich))
    {
        if(strcmp(users.email, tmp.email) == 0 && strcmp(users.mdp, tmp.mdp == 0))
        {
             printf("Connexion réussie");
             trouve = 1;
             if(tmp.role == 1)
             {
                 /// MenuEtudiant();
             }
             else if(tmp.role == 2)
            {
                 // MenuEnseignant();
            }
            else
            {
                printf("Votre choix est indisponible !!");
            }
        }
    }
    if(!trouve)
    {
        printf("Erreur : Mot de passe ou email incorrect !!");
    }
    fclose(fich);

}

int main()
{
    MenuPrincipal();
}