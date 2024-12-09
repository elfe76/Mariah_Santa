Boule à Neige Magique 🎵✨

Ce projet transforme une boule à neige traditionnelle en une expérience magique avec son et lumière, contrôlée via un ESP32. L'intégration de composants comme un lecteur SD, un ampli, et un MOSFET permet de synchroniser musique et lumière pour un effet unique.
🎁 Composants Utilisés
Boule à Neige

    Boule à neige Magic Village
    Utilisée comme base pour le projet.

Électronique

    MOSFET Switch Drive Module DC 5V-36V 15A
    https://fr.aliexpress.com/item/1005005954937751.html?spm=a2g0o.order_list.order_list_main.17.90c35e5bzEMOHc&gatewayAdapt=glo2fra
    Pour contrôler le moteur ou d'autres charges en synchronisation avec la musique.

    ESP32 Microcontroller
    https://fr.aliexpress.com/item/1005007514633433.html?spm=a2g0o.order_list.order_list_main.29.90c35e5bzEMOHc&gatewayAdapt=glo2fra
    Le cœur du système pour contrôler l'ensemble des fonctionnalités.

    Batterie 18650
    https://fr.aliexpress.com/item/1005006224109912.html?spm=a2g0o.order_list.order_list_main.41.90c35e5bzEMOHc&gatewayAdapt=glo2fra
    Alimentation portable pour le projet.

    Lecteur de carte SD
    https://fr.aliexpress.com/item/1005005094642611.html?spm=a2g0o.order_list.order_list_main.75.90c35e5bzEMOHc&gatewayAdapt=glo2fra
    Pour stocker et lire les fichiers MP3.

    Mini Amplificateur Audio
    https://fr.aliexpress.com/item/1005006044079239.html?spm=a2g0o.order_list.order_list_main.86.90c35e5bzEMOHc&gatewayAdapt=glo2fra
    Amplifie le son avant qu'il ne soit joué par l'enceinte.

    Enceinte compacte
    https://fr.aliexpress.com/item/1005006044079239.html?spm=a2g0o.order_list.order_list_main.86.90c35e5bzEMOHc&gatewayAdapt=glo2fra
    Pour diffuser le son.

📜 Fonctionnalités

    Lecture de musique :
        Chargement et lecture d'un fichier MP3 depuis une carte SD.
        Synchronisation du son avec l'éclairage et le moteur.

    Contrôle via bouton poussoir :
        Un appui pour démarrer la musique et activer la lumière/moteur.
        Un appui pour arrêter la musique et désactiver la lumière/moteur.

    MOSFET pour contrôle haute puissance :
        Utilisé pour contrôler des charges comme un moteur ou des LED puissantes.

⚙️ Schéma de Connexion
Principaux GPIO utilisés :

    GPIO2 : Contrôle de la LED.
    GPIO15 : Contrôle du MOSFET (lumière/moteur).
    GPIO4 : Entrée pour le bouton poussoir.
    SD_CS_PIN (GPIO5) : Sélection de la carte SD.

🚀 Instructions

    Assemblez le matériel :
        Suivez les connexions indiquées dans le tableau ci-dessus.
        Insérez la carte SD avec votre fichier MP3 (/alliwant.mp3).

    Chargez le code sur l'ESP32 :
        Utilisez l'environnement Arduino IDE.
        Assurez-vous que les bibliothèques nécessaires sont installées :
            AudioGeneratorMP3
            AudioFileSourceSD
            AudioOutputI2S

    Testez le système :
        Appuyez sur le bouton poussoir pour démarrer ou arrêter la lecture.

🔧 Développement Futur

    Ajout d'un mode aléatoire pour lire plusieurs fichiers MP3.
    Contrôle via une application mobile (Bluetooth).

📷 Galerie

EN ATTENTE

📄 Licence

Ce projet est open-source et sous licence MIT. Vous êtes libre de l'utiliser et de le modifier.

Si vous avez des questions ou des suggestions, n'hésitez pas à créer une issue ou à soumettre une pull request sur ce dépôt ! 😊
