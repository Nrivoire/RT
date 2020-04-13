# Projet RT
Sujets :<br><br>
[RTv1](https://cdn.intra.42.fr/pdf/pdf/6260/rtv1.fr.pdf)<br>
[RT](https://cdn.intra.42.fr/pdf/pdf/6266/rt.fr.pdf)<br>
## Installation
* Git clone : ```git clone https://github.com/Nrivoire/RT.git```<br>
ou
* [Telecharger le ZIP](https://github.com/Nrivoire/RT/archive/master.zip)


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
