# CIR2Project Burger Quiz

## Installation

Ajouter un compte utilisateur en base de données et cocher la case :
> Créer une base portant son nom et donner à cet utilisateur tous les privilèges sur cette base.

Se rendre dans la base créée puis cliquer sur **Importer**

Choisir le fichier *database.sql* (dans le dossier sql) puis cliquer sur **Executer**


## Compilation

En console dans le dossier contenant *adminburgerquiz.pro* :
```
~$ qmake
~$ make
~$ make clean
```

## Connexion

Lancer *AdministrationBDD.exe* (double clique ou en console ./AdministrationBDD.exe)

Remplir les champs correctement : 
1. Ip de la base de données
2. Nom de la base de données (même nom que le compte utilisateur créé)
3. Mot de passe de la base de données (mot de passe du compte utilisateur)

**_Si le mot de passe de la base de données est incorrect, le programme se ferma_**

4. Nom d'utilisateur/Mot de Passe (premiere connexion : admin/admin)

# OU


Remplir le fichier de configuration : *Ressources/conf.txt*
**_Format :_**
- ip:votre_ip
- dbname:nom_de_la_bdd

Lancer *AdministrationBDD.exe* (double clique ou en console ./AdministrationBDD.exe)

Puis remplir les champs restants :
1. Mot de passe de la base de données (mot de passe du compte utilisateur)
2. Nom d'utilisateur/Mot de Passe (premiere connexion : admin/admin)


Cliquer sur **Se connecter**

## Documentation

Se rendre dans le dossier **html**
Ouvrir le fichier *index.html* dans votre navigateur
