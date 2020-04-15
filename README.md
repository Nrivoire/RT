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
* [Telecharger le ZIP](https://github.com/Nrivoire/RT/archive/master.zip)
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
* Installer [MinGW](http://www.mingw.org) pour integrer le compilateur gcc et la librairie de threading POSIX : Lancer l'executable [```mingw.exe```](Windows/mingw.exe) present dans le dossier [Windows](Windows)
	* Faire suivant tant que possible
	* Une fois arriver sur la page d'installation des packages, cocher toutes les cases dans la liste presentee en seleccionnant ```Mark for installation```
	* Puis dans le panneau lateral gauche, aller dans ```All packages``` puis ```MinGW``` et enfin ```MinGW Base System```
		* Aller dans ```MinGW Compiler Suite``` puis dans la liste des packages, cocher toutes les lignes dont la description contient ```C Compiler```
		* Aller dans ```MinGW Standard Librairies``` puis cocher toutes les lignes dont la description contient ```POSIX```
	* Cliquer sur ```Installation``` en haut a gauche de la fenetre puis sur ```Update Catalogue```
	* Cliquer ensuite sur ```Review changes``` puis ```Apply```
* Installer [Cygwin](http://www.cygwin.com) pour integrer la gestion de Makefiles : Lancer l'executable [```cygwin-x86_64.exe```](Windows/cygwin-x86_64.exe) pour un processeur 64 bits et [```cygwin-x86.exe```](Windows/cygwin-x86.exe) le cas echeant, tous deux presents dans le dossier [Windows](Windows)
	* Au moment de choisir le chemin d'installation, copier le chemin par defaut de cote
	* Faire suivant jusqu'a arriver sur la page ```Select packages``` (si une liste de sites bloque l'avancee avant, choisir le premier puis cliquer sur suivant)
		* Dans la case ```View```, choisir ```Full```
		* Rechercher ```make```
		* Installer la ligne qui contient le package ```make``` et la Categorie ```Devel```
			* Choisir la version la plus recente
	* Continuer a faire suivant jusqu'a la fin de l'installation
* Ajouter les variables d'environnement
	* Rechercher les variables d'environnement du systeme
	* Cliquer sur ```Variables d'environnement```
	* Dans ```Variables systeme```, seleccionner la ligne ```PATH```, puis cliquer sur ```Modifier```
		* Cliquer sur ```Nouveau``` puis coller la ligne suivante pour integrer les variables d'environnement de MinGW : ```C:\MinGW\bin```
		* Faire la meme chose pour Cygwin en indiquant le chemin d'installation par defaut que vous avez precedemment mis de cote, suivi de ```\bin```
	* Fermer toutes les fenetres en cliquant sur ```Ok```
* Lancer le terminal ```cmd``` ou ```Windows PowerShell``` dans le dossier RT-master
	* Rien ne doit etre seleccionne dans le dossier puis aller dans ```Fichier``` puis ```Windows PowerShell```
* Copier les fichiers ```DLL``` indispensables au lancement de la SDL et du projet
	* 32 bits : ```cp -r SDL\SDL2*\i686-w64-mingw32\bin\*.dll C:\MingW\bin```
	* 64 bits : ```cp -r SDL\SDL2*\x86_64-w64-mingw32\bin\*.dll C:\MingW\bin```
* Compiler
```bash
make
```
* puis lancer le projet
```bash
.\rt.exe
```
<br><br><br><br><br><br><br>
# TO-DO
tuto raytracing: https://www.gabrielgambetta.com/computer-graphics-from-scratch/basic-ray-tracing.html <br>

plan: ax + by + cz + d = 0 <br>
quadratique: ax2 + by2 + cz2 + dxy + exz + fyz + gx + hy + iz + j = 0 <br>
sphere: (x-a)2 + (y-b)2 + (z-c)2 = r2 <br>


## To-do

- [X] Préliminaire

Partie Obligatoire

- [X] Expose sans recalcule

- [X] Les Objets
	- [X] 4 Objets simple
	- [X] Translation des Objets
	- [X] Rotation des Objets

- [X] REM : Rapide Eye Movement

- [ ] Lumiere
	- [/] L'ombre des Objets
	- [/] L'ombre multi-spot
	- [ ] La Brillance
	- [/] Le Multi-spot

Partie Optionnelle

- [X] Fichier de scene
- [X] Fichier de scene ++

- [X] Lumiere ambiante
- [X] Ambiante ++

- [ ] Objets limites
	- [ ] Decoupe basique d'un Objet en XYZ
	- [ ] Choix de l'axe de decoupe
	- [ ] Rotation et Translation de l'Objet decouper
	- [ ] Decoupe unique a chaque Objet
	- [ ] Decoupe du Plan

- [ ] Perturbations
	- [ ] Normal	--->	"impression d'avoir des vaguelettes"
	- [ ] Couleur	--->	"Le Damier"
	- [X] Couleur	--->	"Texture Procedurale"
	- [X] Couleur	--->	"Bruit de Perlin"

- [ ] Lumiere Directe
- [ ] Lumiere Paralelle --->	"Lumiere Directionnel"

- [ ] Reflexion & Transparence
	- [ ] Reflexion	--->	"Effet Miroir"
	- [ ] Change % de reflexion
	- [ ] La Transparence
	- [ ] Indice de refraction
	- [ ] Change le % de transparence

- [ ] Ombres de l'Objet Transparent

- [ ] Textures I
	- [X] Applique une texture au moins sur 1 Objet
	- [/] Applique une texture sur les 4 Objets de base
	- [ ] Etire ou Contracte une Texture
	- [ ] Faire bouge la texture sur l'Objet
	- [X] Texture au format jpeg, png, ...

- [ ] Texture II
	- [ ] La Texture sert a modifier la normal
	- [ ] La Texture sert a la transparence de l'objet
	- [ ] La Texture sert a la limite de decoupe de l'Objet
	- [ ] La Texture sert de diapositive

- [ ] Objets Compose
	- [ ] Un Cube
	- [ ] Un Verre
	- [ ] Bouge les Objets compose

- [ ] Objets simple suplementaire
	- [ ] Une autre primitive => A FAIRE

- [ ] Effet visuel classique
	- [X] Anti-aliasing "Super-sampling"
	- [X] Effet Cartoon
	- [X] Motion Blur ou Blur
	- [X] Filtre sepia ou autre filtre de couleur
	- [ ] Stereoscopie Simple

- [ ] Effets Technique
	- [ ] Calculs en Cluster
	- [ ] Calculs multi-tread
	- [ ] GPU
	- [X] Sauvegarde d'une Image dans RT

- [ ] Environnement
	- [X] Interface Sommaire "Bare de Progression"
	- [ ] Interface Chiade en GTK, QT ...
	- [X] Modifie les variables de la scene
	- [X] Paramettre plusieurs rendus
	- [/] Ajoute des Objets dans la scene

- [X] Travaille en Groupe

- [ ] Les Objets Exotique
	- [ ] Cube Troue
	- [ ] Une Nappe
	- [ ] Le Tore
	- [ ] Resolution d'equation
	- [ ] Fractal

- [ ] En vrac
	- [ ] Sequence video du RT => !!!!!!!
	- [ ] Gestion du Fichier .pov, .3ds, .obj => !!!
	- [ ] Enrelief sur TV 3D ou Oculuse Rift
	- [ ] Spot non Ponctuel => !!
	- [ ] Autre "Au choix" => !!!!!

- [ ] Ruban de Moebius => !!

- [ ] Caustics et/ou Global illumination

- [?] Rendu Magnifique
