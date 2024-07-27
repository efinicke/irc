

########################
# BONUS FILE TRANSFERT #
########################

    ENVOI:
    - se connecter a irssi
    - /dcc chat <destinataireNickname>
    - /dcc send <nomDeFichier>
    RECEPTION
    - se connecter a irssi
    - /dcc listen
    - /dcc get <expediteur>

    DCC est un protocole utilisé pour établir des connexions directes entre deux clients IRC afin de transférer des fichiers. Dans Irssi, vous pouvez utiliser la commande
        "/dcc send" pour envoyer un fichier et
        "/dcc get" pour recevoir un fichier.
    Voici comment utiliser la commande "/dcc send" pour envoyer un  fichier:

        /dcc send <nom_utilisateur> <chemin_du_fichier> <port>

    <nom_utilisateur> est le nom d'utilisateur de la personne à qui     vous souhaitez envoyer le fichier.
    <chemin_du_fichier> est le chemin d'accès absolu ou relatif du  fichier que vous souhaitez envoyer.
    <port> est le numéro de port que vous souhaitez utiliser pour la    connexion DCC.
    Exemple:

        /dcc send Bob ~/Documents/mon_fichier.txt 5000

    Dans cet exemple, nous envoyons le fichier "mon_fichier.txt" à  l'utilisateur "Bob" en utilisant le port 5000.

    Voici comment utiliser la commande "/dcc get" pour recevoir un  fichier:

        /dcc get <nom_utilisateur> <chemin_du_fichier>  <taille_du_fichier>

    <nom_utilisateur> est le nom d'utilisateur de la personne qui   envoie le fichier.
    <chemin_du_fichier> est le chemin d'accès absolu ou relatif où  vous souhaitez enregistrer le fichier.
    <taille_du_fichier> est la taille du fichier que vous souhaitez     recevoir.
    Exemple:

        /dcc get Bob ~/Downloads/mon_fichier.txt 1024

    Dans cet exemple, nous demandons à recevoir le fichier  "mon_fichier.txt" de l'utilisateur "Bob" et à l'enregistrer dans     le dossier "Downloads" avec une taille de 1024 octets.
    Il est important de noter que vous devez vous assurer que votre     pare-feu autorise les connexions DCC entrantes et sortantes sur     le port que vous avez spécifié. Si vous ne pouvez pas vous  connecter ou envoyer des fichiers, cela peut être dû à des   restrictions de pare-feu.

    DCC (Direct Client-to-Client) est un protocole qui permet à     deux clients IRC de communiquer directement entre eux, sans     passer par le serveur. Irssi est un client IRC populaire qui    prend en charge le protocole DCC pour envoyer et recevoir  des fichiers.

    Pour envoyer un fichier avec DCC et Irssi, vous pouvez  suivre ces étapes:

    Ouvrez une session Irssi et connectez-vous à un serveur IRC.

    Entrez la commande "/dcc send nom_utilisateur nom_fichier"  pour envoyer un fichier à un autre utilisateur IRC.  Remplacez "nom_utilisateur" par le nom d'utilisateur de la   personne à qui vous souhaitez envoyer le fichier, et  "nom_fichier" par le nom du fichier que vous souhaitez   envoyer.

    Si l'utilisateur accepte la demande de transfert de fichier,    Irssi ouvrira une connexion DCC pour transférer le fichier.    Si l'utilisateur refuse la demande, le transfert sera annulé.

    Attendez que le transfert de fichier soit terminé. Le temps     nécessaire dépend de la taille du fichier et de la vitesse  de connexion entre les deux clients.

    Pour recevoir un fichier avec DCC et Irssi, vous pouvez     suivre ces étapes:

    Attendez que l'utilisateur qui souhaite vous envoyer un     fichier initie la demande de transfert.

    Lorsque la demande de transfert de fichier apparaît dans la     fenêtre de discussion Irssi, acceptez-la en tapant "/dcc    accept" ou en cliquant sur le bouton "Accept" dans la  fenêtre de dialogue DCC.

    Attendez que le transfert de fichier soit terminé. Le   fichier sera enregistré dans le dossier spécifié dans les     paramètres de votre client Irssi.

    Il est important de noter que les transferts de fichiers DCC    sont souvent sujets à des problèmes de sécurité, car les   connexions sont directes entre les clients et peuvent être    interceptées ou manipulées par des tiers malveillants. Par     conséquent, il est recommandé de ne transférer des fichiers     que vers des utilisateurs de confiance et de s'assurer que  les fichiers sont vérifiés pour les virus ou autres menaces  avant d'être ouverts ou exécutés.

    Pour utiliser la commande /dcc send dans Irssi, suivez les  étapes suivantes:

    Connectez-vous à un serveur IRC en utilisant Irssi.

    Trouvez le nom d'utilisateur de la personne à qui vous  souhaitez envoyer un fichier. Vous pouvez utiliser la    commande "/whois nom_utilisateur" pour obtenir des     informations sur cet utilisateur.

    Une fois que vous avez le nom d'utilisateur de la personne,     tapez la commande "/dcc send nom_utilisateur chemin_fichier"    dans la fenêtre de discussion Irssi. Remplacez     "nom_utilisateur" par le nom d'utilisateur de la personne à     qui vous souhaitez envoyer le fichier, et "chemin_fichier"  par le chemin complet du fichier que vous souhaitez envoyer.

    Appuyez sur "Entrée" pour envoyer la commande. Irssi enverra    une demande de transfert de fichier à la personne spécifiée.

    Si l'utilisateur accepte la demande, Irssi commencera à     envoyer le fichier. Vous pouvez suivre la progression du    transfert en utilisant la commande "/dcc" pour voir une    liste de toutes les connexions DCC en cours.

    Une fois que le transfert est terminé, le fichier sera  enregistré dans le répertoire de téléchargement spécifié     dans les paramètres de votre client Irssi.

    @SYNTAX:dcc@

    /DCC LIST
        - Shows all the open DCC connections.
    /DCC RESUME [<nick> [<file>]]
        - Resumes a DCC SEND/GET connection.
    /DCC CHAT [-passive] [<nick>]
        - Sends a chat connection request to remote client or   accepts 
          a chat connection if the remote end has already sent a    request.
          If -passive is used then the passive DCC protocol is  used (as mIRC
          can do). This is useful to bypass a NAT/firewall which    limit your
          possibility in listening for remote connections.
    /DCC GET [<nick> [<file>]]
        - Gets the file offered by remote client. The file is   downloaded and
          saved into the directory specified by the     `dcc_download_path' setting.
    /DCC SEND [-passive] [-append | -prepend | -flush |     -rmtail | -rmhead]
              <nick> <file> [<file> ...]
        - Sends a DCC SEND request to remote client. Remote end     has to accept
          the request before the transmission can be started.   Giving multiple
          files queues them. File names may contain shell   expansion
          characters: * ? [] ~ (~ expansion may not be supported    on all
          platforms). Files with spaces in their names need to  be quoted (eg.
          "file name"). If -passive is used then the passive DCC    protocol is
          used (as mIRC and xchat > 2.0.7 can do). This is  useful to bypass a
          NAT/firewall which limit your possibility in      listening for remote
          connections.
    /DCC SERVER [<+|-scf> <port>]
        - Starts a DCC SERVER on the specified port. The remote     can connect
          to this server and initiate chat, send and fserve     requests. You can
          specify + or - using any combination of the flags 's'     (Send),
          'c' (Chat), or 'f' (Fserver).
    /DCC CLOSE <type> <nick> [<file>]
        - Closes a DCC-connection. Type can be either SEND, GET     or CHAT.

    Pour résoudre l'erreur "Irssi: warning dcc_listen() failed: Address     already in use", vous pouvez essayer de modifier le port utilisé pour   la connexion DCC dans les paramètres d'irssi. Pour cela, vous pouvez  utiliser la commande "/set dcc_port <port>" dans la fenêtre de   discussion, en remplaçant "<port>" par un numéro de port disponible   sur votre ordinateur ou sur le réseau.
    
    Pour résoudre l'erreur "DCC lost chat to toto", vous pouvez essayer de  rétablir la connexion DCC en utilisant la commande "/dcc chat <toto>"    dans la fenêtre de discussion. Si la connexion ne peut pas être    rétablie, il est possible que l'utilisateur "toto" ait également   rencontré des problèmes de connexion ou ait quitté le réseau IRC. Dans    ce cas, vous devrez peut-être attendre ou essayer de contacter     l'utilisateur par d'autres moyens.

