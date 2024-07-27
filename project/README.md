IRC tutorial

NOTE: test en make run puis dans un autre terminal nc -C localhost 6667 (-C permet de mettre automatiquement \r\n)
    OU make run et dans un autre terminal irssi puis /connect localhost 6667
    pour le parsing look at strok() ou strtok()
    look les fonctions de string

Test avc proxy.sh pour comprendre syntaxe IRC:
lancer ./proxy.sh 4243 irc.ircube.org 6667
lancer dans une autre fenetre irssi (/c!onnect localhost 4243)
voir ce que recoit le serveur et ce qu'il doit afficher
Le proxy fait office de bureau de poste et il lit le courrier

Pour fermer le serveur:
    catcher le signal ctrl + c puis fermer proprement le programme (leaks et cie)
    le code de ctrl + c c'est SIGINT

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



    ##################
    PARTIE 1 - Serveur
    ##################

        Creer un serveur qui compile
            creer la socket, la bind, listen et accept
        Le close avec un signal (cf Minitalk signal/sigaction structure)
        Tester la connexion avec Netcat (deja installe sur la session) puis irssi
        *Pleurer*
        Attention: poll() ne fonctionne pas sur mac
        Checkpoint: qd j;envoie un message via irssi, le serveur repond bien recu et/ou le message recu
        Pour se remettre dans le bain de C++, faire le sujet de exam05 avec une map
        L'exam06 est coder un serveur qui recoit des requetes
        Creer une classe Client
        Coder les fonction primaires pour le client (commandes client):
            pass()
            user()
            nick()
            quit() (le client s'en va)
        Gerer les deux sens nick-user et user-nick
        *Pleurer*
        Gerer les reply de base et commnandes de base
        Tout ERR et RPL finit par \r\n
        *Le vrai taf commence*
        *Pleurer*
        Implementer poll(), la gestion de plusieurs clients
        Ranger les clients dans une map (aller voir Lara)
        Check les erreurs (pas de doublons user/nickname, password)
        Optionnel:
            coder ping() et pong() eet gettime()
            si irssi envoit a serveur ping(argv1) alors serveur doit repondre pong(argv1 de ping)
            Prevoir un delai d'attente de pong assez long (env 3 minutes)
            Ca sert a verifier si un user est encore actif (ex: riri, fifi et loulou sont actifs sur le serveur, riri ping loulou, l'ordi de loulou a   plante, loulou est considere inactif apres le delai sil ne pong pas, il est delete) 

    ##############################################################
    PARTIE 2 - Toutes les commandes ne concernant pas les channels
    ##############################################################

        Pour se remettre au C++, s'entrainer sur l'exam05 avec une map
        Creer une classe Client
        oper() cree un serveur operateur (admin, mode -o)
        nick() et user() si pas fait en partie 1
        privmsg() et notice() qui ont la meme fonction
            le 2eme argument de privmsg precise si la destination est une conversation privee ou un channel (partie 3)
        *Pleurer*
        Tester avec Netcat puis irssi, verifier que le serveur se segfault pas et pas de leaks
        *Pleurer*
        irssi recup automatiquement les infos 
            ex: username = grannou
            hostname = e1r1p1, obtenu avec gethostname()
            fullname = grannou@e1r1p1

    #######################################################
    PARTIE 3 - Toutes les commandes concernant les channels
    #######################################################

        Creer une class Channel
        Ne pas oublier de free tous les channels soit quand:
            - il n'y a plus de users dans le channel
            - le serveur est close
        join()      creer/rejoindre un channel
        part()      quitter un channel
        gettime()   afficher l'heure de creation du channel/topic
        topic()     ajouter une description du channel
        names()     liste tous les users du channel
        list()      liste tous les channels
        kick()      supprime un user d'un channel
        privmsg() et notice() pour les channels
        *Pleurer*
        quit()      le user doit sortir de tous les channels ou il est et afficher un message dans chacun genre "Goodbye" 
        Tester le fonctionnement des channels avec Netcat puis irssi
        *Pleurer*
        gerer les modes operateur

    ################
    PARTIE 4 - Bonus
    ################

        irssi gere de base l'envoi de fichier, aller regarder le fornmat de la commande
        a voir pour le bot qui est un client qui est une machine et qui repond un message automatique quand on lui ecrit
        Interessant pour avoir plus d'XP et de jours de BH pour Transcendence


#####################
grannou documentation
#####################



##########################################
Launch server: ./ircserv <port> <password>
##########################################

################################################
Launch client in another terminal: irssi + emter
################################################

COMMANDES IRC
    run irssi dans le terminal
        irssi

    afficher la liste des servers
        /server list

    se connecter a un server
        /connect <nom server>

    configurer un pseudo
        /nick <pseudo>

    rejoindre/creer un salon de chat (existant/non existant)
        /join <nom salon>

    Ajouter un autre utilisateur
        ouvrir un autre terminal
        irssi
        /server list
        /connect <nom server>
        /nick <pseudo>
        /join <nom room>
        /subscribe <nom utilisateur dans salon different de pseudo> channel

    sortir d'un salon
        /exit

    Tuto youtube (C++ sockets - Create simple server and client chat Linux)
        https://www.youtube.com/watch?v=IydkqseK6oQ
        tester le dossier TutoC++ClientServer

    
DEFINITIONS:

    Socket: basic component of a server. allows your operating system to connect to a network in a particular way

    En C++ on cree une classe qui represente une socket et qui sera portable pour d'autres fonctions (un serveur, un client ou un reseau peer to peer)
    
    On doit creer une socket avec la fonction socket(AF_INET, SOCK_STREAM, 0)
        AF_INET = domain or address family
            AF_INET  -> IP
            AF_INET6 -> IPv6
            AF_UNIX  -> local channel, similar to pipes
            AF_ISO   -> ISO protocols
            AF_NS    -> Xerox Network Systems protocols
        SOCK_STREAM = type
            SOCK_STREAM -> virtual circuit service
            SOCK_DGRAM  -> datagram service
            SOCK_RAW    -> direct IP service
        0 = protocol to use un supporting the sockets operation
            For TCP/IP sockets, we want to specify the IP address family (AF_INET) and virtual service circuit (SOCK_STREAM). 
            Since there's only one form of virtual circuit servicem there are no variations of the protocol, so the last argument protocol is 0
    puis la bind a un reseau avec la fonction bind(server_fd, (...))
    puis listen avec la fonction listen(server_fd, ...)
    Pour chaque etape, check si error (== 0 ou < 0)
    The analogy of creating a socker is that of requesting a telehone line from the phone compagny
    
      
    
Notions pour coder un serveur http:
    - OSI (Open Systems Interconnection model) = modele theorique en 7 couches pour assurer la communication standardisee par des protocoles pour une interoperabilite

    - 4ene couche du modele OSI: Transport layer
    s'assure que les infos sont transmises d'un point A a un poitn B sans erreurs
    ex: TCP (Transmission Control Protocol), UDP (User Datagram Protocol), SPX (Sequenced Packet Exchange)
    
    - En general la communication http se fait avec les protocoles TCP/IP et le port 80 par defaut, meme si d'autre ports peuvent etre utilises (et UDP est plus rapide mais moins fiable)

    - RFC (Request For Comments) = official documents of Internet specifications, communications protocols, procedures and events

    - To implement HTTP server, read RFC 7230, 7231, 7232, 7233, 7234, 7235

IRC COMMANDS

    INVITE
    JOIN -
    KICK -
    LIST -
    NAMES -
    PART -
    TOPIC -
    MODE
    NICK -
    OPER -
    QUIT -
    USER -
    KILL -
    PING -
    PONG -
    PASS -
    PRIVMSG -
    NOTICE -
    MOTD -

    Optional:
    AWAY
    ISON
    USERHOST
    USERS
    WALLOPS
    ADMIN
    INFO
    LUSERS
    TIME
    VERSION
    WHO
    WHOIS
    WHOWAS

IRC MODES

    USER MODES:
        a : away
        i : invisible
        w : wallops
        r : restricted
        o : operator
    
    CHANNEL MODES:
        for users
            O : channel creator
            o : channel operator
            v : voice
        for channels
            i : invite only
            m : moderated
            n : outside privmsg disabled
            p : private
            t : topic locked
            k : key locked
            l : user limit

#############
IRC Wikipedia
#############
    IRC = "Discussion relayee par internet"
    C'est un protocole de communication textuel sur internet
    Pour la communication instantanee sous forme de discussions en groupes via des canaux de discussion et pour les communications privees entre deux personnes et aussi pour faire du transfert du fichier

########
RFC 2812 -> defines the Client Protocol
########

    Internet Relay Chat Protocol is for use with text based conferencing;
    the simpliest client being any socket program capable of connecting to the server

#################################################################################################
#                                        RAPPPEL C++                                            #
#################################################################################################

Declaration of a class in a canonical form

MyClass.hpp file:

    #ifndef MYCLASS_HPP

        # define MYCLASS_HPP

        # include <string>

        class MyClass
        {
        
            public:

                // Default Constructor
                MyClass(void);

                // Constructor with parameter 
                MyClass(int val, std::string str);

                // Copy Constructor
                MyClass(const MyClass &other);

                // Overload operator
                MyCLass operator=(const MyClass &other);
        
                // Accessor/getter functions
                int         getVal() const;
                std::string getStr() const;

            private:

                int             _val;
                std::string     _str;
        }

    #endif

MyClass.cpp file:

    #include "MyClass.hpp"

    // Constructor implementation
    MyClass::MyClass(int val, std::string str) : _val(val), _str(str)
    {
        std::cout << "Constructor called" << std::endl;
    }

    // Copy Constructor implementation
    MyClass::MyClass(const MyClass &other): _val(other._val), _str(other._str)
    {
        std::cout << "Copy Constructor called" << std::endl;
    }

    // Destructor implementation
    ~MyClass
    {
        std::cout << "Destructor called" << std::endl;
    }

    // Accessor/getter function implementation
    int             MyClass::getVal() const {return _val;}
    std::string     MyClass::getStr() const {return _str;}

    // Overload operator implementation
    MyClass MyClass::operator=(const MyClass &other)
    {
        
    }