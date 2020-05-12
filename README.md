# Projet RT
Sujets :<br><br>
[RTv1](https://cdn.intra.42.fr/pdf/pdf/6260/rtv1.fr.pdf)<br>
[RT](https://cdn.intra.42.fr/pdf/pdf/6266/rt.fr.pdf)<br>
## Installation
* Git clone
```bash
git clone https://github.com/Nrivoire/RT.git
```
ou
* [Télécharger le ZIP](https://github.com/Nrivoire/RT/archive/master.zip)
### Sur MacOS
* Compiler
```bash
make
```
* puis lancer le projet
```bash
./rt
```
### Sur Linux
* Installer la librairie SDL
```bash
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
```
* Compiler
```bash
make
```
* puis lancer le projet
```bash
./rt
```
### Sur Windows
* Installer [MinGW](http://www.mingw.org) pour intégrer le compilateur gcc et la librairie de threading POSIX : Lancer l'executable [```mingw.exe```](Windows/mingw.exe) présent dans le dossier [Windows](Windows)
	* Faire suivant tant que possible (ne pas changer le chemin d'installation)
	* Une fois arrivé sur la page d'installation des packages, cocher toutes les cases dans la liste presentée en séleccionnant ```Mark for installation```
	* Puis dans le panneau latéral gauche, aller dans ```All packages``` puis ```MinGW``` et enfin ```MinGW Base System```
		* Aller dans ```MinGW Compiler Suite``` puis dans la liste des packages, cocher toutes les lignes dont la description contient ```C Compiler```
		* Aller dans ```MinGW Standard Librairies``` puis cocher toutes les lignes dont la description contient ```POSIX```
	* Cliquer sur ```Installation``` en haut à gauche de la fenetre puis sur ```Update Catalogue```
	* Cliquer ensuite sur ```Review changes``` puis ```Apply```
* Installer [Cygwin](http://www.cygwin.com) pour intégrer la gestion des Makefiles : Lancer l'exécutable [```cygwin-x86_64.exe```](Windows/cygwin-x86_64.exe) pour un processeur 64 bits et [```cygwin-x86.exe```](Windows/cygwin-x86.exe) le cas échéant, tous deux présents dans le dossier [Windows](Windows) (Dans le doute, prendre le premier)
	* Choisir ```C:\cygwin``` comme chemin d'installation
	* Faire suivant jusqu'à arriver sur la page ```Select packages``` (si une liste de sites bloque l'avancée avant, choisir le premier puis cliquer sur suivant)
		* Dans la case ```View```, choisir ```Full```
		* Rechercher ```make```
		* Installer la ligne qui contient le package ```make``` et la Categorie ```Devel``` (en double-cliquant)
			* Choisir la version la plus recente
	* Continuer à faire suivant jusqu'à la fin de l'installation
* Ajouter les variables d'environnement
	* Rechercher les variables d'environnement du PC (Taper ```variables``` dans la barre de recherche de la barre des tâches)
	* Cliquer sur ```Variables d'environnement```
	* Dans ```Variables système```, séleccionner la ligne ```PATH```, puis cliquer sur ```Modifier```
		* Cliquer sur ```Nouveau``` puis coller la ligne suivante pour intégrer les variables d'environnement de MinGW : ```C:\MinGW\bin```
		* Faire la même chose pour Cygwin en rajoutant ```C:\cygwin\bin```
	* Fermer toutes les fenêtres en cliquant sur ```Ok```
* Lancer le terminal ```cmd``` ou ```Windows PowerShell``` dans le dossier RT-master (suivant comment vous avez nommé le dossier du projet)
	* Rien ne doit être séleccionné dans le dossier puis aller dans ```Fichier``` puis ```Windows PowerShell```
* Copier les fichiers ```DLL``` indispensables au lancement de la SDL et du projet
```bash
cp -r SDL\SDL2*\i686-w64-mingw32\bin\*.dll C:\MinGW\bin
```
* Pour prendre en compte les derniers changements, taper ```exit``` puis rouvrir l'invite de commandes de la même manière que précédemment
* Compiler
```bash
make
```
* puis lancer le projet
```bash
.\rt.exe
```
