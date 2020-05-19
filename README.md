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
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
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
	* Rien ne doit être sélectionné dans le dossier puis aller dans ```Fichier``` puis ```Windows PowerShell```
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
## Utilisation des scenes
* Respecter le format de chaque bloc du fichier

```
[type de bloc]{
'tabulation'[variable]= [données]
}

type de block = [scene - camera - light - object]
```

### Scene

```
'	ambient-light= {r, g, b}'

r.g.b = [0-1]
```
```
'	width= largeur'

largeur = [100-960]
```
```
'	height= hauteur'

hauteur = [100-720]
```
```
'	filter= nom_du_filtre'

nom_du_filtre = [greyscale - sepia - negative - cel-shading]
```

### Camera

```
'	pos= {x, y, z}'

x.y.z = [float]
```
```
'	dir= {x, y, z}'

x.y.z = [float]
```
```
'	fov= fov_cam'

fov_cam = [int]
```

### Lumière

```
'	type= type_de_lumière'

type_de_lumière = [POINT - DIRECTIONAL - SPOT]
```
```
'	pos= {x, y, z}'

x.y.z = [float]
```
```
'	dir= {x, y, z}'

x.y.z = [float]
```
```
'	color= {r, g, b}'

{r, g, b} = [float]
---
'	color= hexa'

hexa = [#......] ou [0x......]
```

### Objet

```
'	type= type_objet'

type_objet = [SPHERE - PLANE - CONE - CYLINDER]
```
```
'	radius= rayon'

rayon = [float]
```
```
'	pos= {x, y, z}'

x.y.z = [float]
```
```
'	dir= {x, y, z}'

x.y.z = [float]
```
```
'	point_a= {x, y, z}'

x.y.z = [float]
```
```
'	point_b= {x, y, z}'

x.y.z = [float]
```
```
'	point_c= {x, y, z}'

x.y.z = [float]
```
```
'	color= {r, g, b}'

{r, g, b} = [float]
---
'	color= hexa'

hexa = [#......] ou [0x......]
```
```
'	reflect= reflection'

reflection = [0-1]
```
```
'	refract= refraction'

refraction = [0-1]
```
```
'	shininess= brillance'

brillance = [0-1]
```

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
