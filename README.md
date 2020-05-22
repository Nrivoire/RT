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
./rt --help -> pour voir son utilisation
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
./rt --help -> pour voir son utilisation
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
* Format d'utilisation et de création d'un fichier de configuation/scene.

```
[BLOCK]{
'tabulation'[variable]= [données]
}

BLOCK = [scene / camera / light / object]
```

### Scene

```
'	ambient-light= {red [0-1 float], green [0-1 float], blue [0-1 float]}'
'	width= [100-1280 int]'
'	height= [100-720 int]'
'	filter= [greyscale / sepia / negative / cel-shading]'
```

### Camera

```
'	pos= {x [float], y [float], z [float]}'
'	dir= {angle_x [degrees float], angle_y [degrees float], angle_z [degrees float]}'
'	fov= [30-170 int]
```

### Lumière

```
'	type= [POINT / DIRECTIONAL / SPOT]'
'	pos= {x [float], y [float], z [float]}'
'	dir= {x [float], y [float], z [float]}'
'	color= {red [0-1 float], green [0-1 float], blue [0-1 float]} ou {#......} ou {0x......}'
```

### Objet

```
'	type= [SPHERE / PLANE / CONE / CYLINDER]
'	radius= [float]'
'	pos= {x [float], y [float], z [float]}'
'	dir= pos= {x [-1-1 float], y [-1-1 float], z [-1-1 float]}'
'	point_a= {x [float], y [float], z [float]}'
'	point_b= {x [float], y [float], z [float]}'
'	point_c= {x [float], y [float], z [float]}'
'	color= {red [0-255 float], green [0-255 float], blue [0-255 float]} ou {#......} ou {0x......}'
'	reflect= [0-1 float]'
'	refract= [0-1 float]'
'	density= [1-3 float]'
'	shininess= [0-1 float]'
'	texture= "./textures/nom_de_la_texture.png"'
'	fix= {x [float], y [float], z [float]}'
'	texture-procedural= [PERLIN / WOOD / MARBLE / WAVES / GRADIENT]
```

## Commandes

<table style="background-color:grey;" width="100%">
<thead>
<tr>
<td width="60%" height="60px" style="background-color:#606060;" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="40%" align="center" style="background-color:#606060;" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program (quit/exit)</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" style="background-color:#707070;">Move the camera</td>
<td valign="top" style="background-color:#707070;" align="center"></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the axe z (-z)</td>
<td valign="top" align="center"><kbd>&nbsp;W&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the axe x (-x)</td>
<td valign="top" align="center"><kbd>&nbsp;A&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the axe z (+z)</td>
<td valign="top" align="center"><kbd>&nbsp;S&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the axe x (+x)</td>
<td valign="top" align="center"><kbd>&nbsp;D&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the axe y (+y)</td>
<td valign="top" align="center"><kbd>&nbsp;Q&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the axe y (-y)</td>
<td valign="top" align="center"><kbd>&nbsp;E&nbsp;</kbd></td>
</tr>
<td valign="top" style="background-color:#707070;">Rotate the camera</td>
<td valign="top" style="background-color:#707070;" align="center"></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the angle_x (+angle_x)</td>
<td valign="top" align="center"><kbd>&nbsp;I&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the angle_y (+angle_y)</td>
<td valign="top" align="center"><kbd>&nbsp;J&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the angle_x (-angle_x)</td>
<td valign="top" align="center"><kbd>&nbsp;K&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the angle_y (-angle_y)</td>
<td valign="top" align="center"><kbd>&nbsp;L&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the angle_z (+angle_z)</td>
<td valign="top" align="center"><kbd>&nbsp;U&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the angle_z (-angle_z)</td>
<td valign="top" align="center"><kbd>&nbsp;O&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> on the angle_z (-angle_z)</td>
<td valign="top" align="center"><kbd>&nbsp;O&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top"></td>
<td valign="top" align="center"></td>
</tr>
<tr>
<td valign="top" style="background-color:#707070;">Move the selected object<br></td>
<td valign="top" style="background-color:#707070;" align="center"></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> position on y (+y)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;W&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> position on x (-x)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;A&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> position on y (-y)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;S&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> position on x (+x)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;D&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> position on z (-z)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;Q&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> position on z (+z)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;E&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" style="background-color:#707070;">Rotate the selected object</td>
<td valign="top" style="background-color:#707070;" align="center"></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> direction on x (+x)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;I&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> direction on y (+)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;J&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> direction on x (-x)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;K&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> direction on y (-angle_y)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;L&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> direction on z (+angle_z)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;U&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-> direction on z (-angle_z)</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;O&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">To accelerate the object event</td>
<td valign="top" align="center"><kbd>&nbsp;LSHIFT&nbsp;</kbd> or <kbd>&nbsp;RSHIFT&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change the radius of the selected object</td>
<td valign="top" align="center"><kbd>&nbsp;WHEEL&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Delete the selected object</td>
<td valign="top" align="center"><kbd>&nbsp;SPACE&nbsp;</kbd> + <kbd>&nbsp;G&nbsp;</kbd> + <kbd>&nbsp;N&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top"></td>
<td valign="top" align="center"></td>
</tr>
<tr>
<td valign="top" style="background-color:#707070;">+Plus</td>
<td valign="top" style="background-color:#707070;" align="center"></td>
</tr>
<tr>
<td valign="top" height="30px">Change the filter</td>
<td valign="top" align="center"><kbd>&nbsp;F&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Activate the supersampling</td>
<td valign="top" align="center"><kbd>&nbsp;V&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Activate the blur</td>
<td valign="top" align="center"><kbd>&nbsp;B&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Desactivate supersampling & blur</td>
<td valign="top" align="center"><kbd>&nbsp;C&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Desactivate the BigPixel rendering</td>
<td valign="top" align="center"><kbd>&nbsp;T&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Reactivate the BigPixel rendering</td>
<td valign="top" align="center"><kbd>&nbsp;R&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Take a screenshot (or the right click)</td>
<td valign="top" align="center"><kbd>&nbsp;P&nbsp;</kbd></td>
</tr>
</tbody>
</table>
