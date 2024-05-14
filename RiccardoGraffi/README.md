LINUX

   COSA FAREMO:

      ARGOMENTO 1: LA COMUNITÀ LINUX E UNA CARRIERA NELL’OPEN SOURCE                                            kernel(quello che divide il disco dal SO)
	 1.1 Evoluzione di Linux e Sistemi Operativi più Diffusi
	      • Distribuzioni
	      • Sistemi Integrati
	      • Linux nel Cloud
 	 1.2 Principali Applicazioni Open Source
	      • Applicazioni desktop
	      • Applicazioni server
	      • Linguaggi di sviluppo
	      • Strumenti di gestione dei pacchetti e repository     
	 1.4 Competenze ICT - Lavorare con Linux

      



LA COMUNITÀ LINUX E UNA CARRIERA NELL’OPEN SOURCE:

 1.1 Evoluzione di Linux e Sistemi Operativi più Diffusi 

   STORIA DI LINUX:

  Il suo sviluppo è stato avviato nel 1991 da Linus. Tale sistema operativo è stato ispirato da Unix.
  A quel tempo, un sistema Unix economico non era ancora disponibile per computer come quelli da ufficio,
  che tendevano ad essere basati sulla piattaforma x86. Pertanto Linus, che a quel tempo era studente, 
  iniziò a implementare un sistema operativo di tipo Unix in grado di funzionare su quell’architettura.
	  |
	  |
	  V
  quindi l'obbiettivo di linus era quindi l'utilizzo di Unix in una architettura semplice lavorando direttamente 
  da dal kernel il quale modifica direttamente l'hardware
	   |
	   |
	   V	
  L’obiettivo di una distribuzione è quello di ottimizzare il kernel e le applicazioni in esecuzione 
  sul sistema operativo per un particolare caso d’uso o gruppo di utenti. Questo è il motivo
  per cui alcune distribuzioni vengono utilizzate principalmente per ambienti desktop dove
  devono essere facili da usare, mentre altre vengono utilizzate principalmente sui server per
  utilizzare le risorse disponibili nel modo più efficiente possibile.
	    |
	    |
	    V 
  Un altro modo per classificare le distribuzioni è quello di fare riferimento alla famiglia di
  distribuzione di appartenenza.
		
	CARATTERISTICHE:

	 - colori ed estetica/ l'interfaccia grafica
	 - package menager: il package manager aggiorna e gestisce i pacchetti che utilizzi.
		
		LE PRINCIPALI:
		 
		   - Debian GNU/Linux: Debian GNU/Linux mira a fornire un sistema operativo molto affidabile.
		     Inoltre promuove la visione di Richard Stallman di un sistema operativo che rispetti le libertà
		     dell’utente di eseguire, studiare, distribuire e migliorare il software. Per questo motivo non
		     fornisce di default alcun software proprietario.
		   
		   - Ubuntu: Lo scopo di Ubuntu è quello di fornire un software libero per tutti in tutto il mondo e di
		     ridurre il costo dei servizi professionali. La distribuzione prevede una nuova versione
                     programmata ogni sei mesi con una versione di supporto a lungo termine ogni 2 anni, 
	             la carateristiche principale di ubuntu e che ubuntu deriva da Debian GNU/Linux e utiliza i
		     pacchetti .dev.

		   - Red Hat: Viene fornita alle aziende come soluzione di livello enterprise affidabile,
	             supportata da Red Hat e dotata di un software che mira a facilitare l’utilizzo 
		     di Linux in ambienti server professionali. Alcuni dei suoi componenti richiedono
		     abbonamenti o licenze a pagamento.

		   - SUSE: Questo strumento di configurazione permette agli amministratori di 
		     installare e configurare software e hardware, nonchè server e reti. Analogamente a RHEL,
		     SUSE rilascia SUSE Linux Enterprise Server, che ne rappresenta la versione commerciale.
		     È caratterizzata da rilasci poco frequenti ed è adatta per l’implementazione aziendale e 
		     di produzione


     SISTEMI INTEGRATI

  I sistemi integrati sono una combinazione di hardware e software progettati per avere una
  funzione specifica all’interno di un sistema più grande. Solitamente fanno parte di altri dispositivi
  e aiutano a controllare i dispositivi stessi di cui fanno parte.Grazie alla loro vasta gamma di applicazioni,
  sono stati sviluppati vari sistemi operativi basati sul kernel Linux per
  essere utilizzati nei sistemi integrati.
  Due dei più popolari progetti di software integrato sono Android e Raspian(utilizzato principalemente su
  dispositivi Raspberry pi).
      		 
    - ANDROID

    	Android è principalmente un sistema operativo mobile sviluppato da Google. La base di Android è una versione 
    	modificata del kernel Linux con software open source aggiuntivo. Android è liberamente disponibile
    	in ambiente open source come Android Open Source Project
		
    - RASPBIAN E IL RASPBERRY PI

	Raspberry Pi è un computer a basso costo, dalle dimensioni di una carta di credito, che può
	funzionare come un computer desktop con funzionalità complete, ma che può essere anche
	utilizzato in un sistema Linux integrato.

	Il suo scopo principale è quello di insegnare ai giovani a imparare a programmare e comprendere
	il funzionamento dei computer. Raspberry Pi può essere progettato e programmato per eseguire 
	le attività o le operazioni desiderate che fannoparte di un sistema molto più complesso.
     	Le particolarità di Raspberry Pi includono una serie di pin General Purpose Input-Output (GPIO)
	che possono essere utilizzati per collegare dispositivi elettronici e schede di estensione. Ciò
	consente di utilizzare Raspberry Pi come piattaforma per lo sviluppo hardware
	
	Raspberry Pi utilizza processori ARM. Vari sistemi operativi, tra cui Linux, funzionano su
	Raspberry Pi. Poiché Raspberry Pi non contiene un disco rigido, il sistema operativo viene avviato
	da una scheda di memoria SD.

  Ecco alcuni sistemi integrati.

	

	LINUX e CLOUD
  
   Il termine cloud computing si riferisce a un modo standardizzato di gestire risorse informatiche,
   acquistandole presso un fornitore di cloud pubblico o eseguendo una cloud privata. a. Ogni fornitore di
   servizi cloud, da Amazon Web Services (AWS) a Google Cloud Platform (GCP), offre diversi sistemi
   di tipo Linux.

   Le istanze IaaS sono macchine virtuali che vengono fornite in pochi minuti in cloud. Quando si avvia una istanza IaaS,
   viene scelta una immagine contenente i dati che verranno caricati sulla nuova istanza.
   I fornitori di servizi cloud offrono varie immagini contenenti installazioni pronte all’uso sia delle distribuzioni 
   Linux più diffuse sia delle proprie versioni di Linux.


 1.2 Principali Applicazioni Open Source


   INTRODUZIONE
 Una applicazione è un programma per computer il cui scopo non è direttamente legato al
 funzionamento interno del computer, ma ai compiti eseguiti dall’utente.

   PACCHETTI SOFTWARE
 Ogni distribuzione Linux offre un insieme preinstallato di applicazioni predefinite. Oltre
 alle applicazioni preinstallate, una distribuzione ha un repository di pacchetti con un’ampia
 raccolta di applicazioni disponibili per l’installazione tramite il package manager.
 
      STRUMENTI ESSENZIALI PER L'UTILIZZO DI ALCUNI PACCHETTI SOFTWARE(Debian, Ubuntu e Linux Mint):
        - Dpkg(serve per dire cosa installare, ma non ti risolve le dipendenze dice solo quali sono)
        - apt-get e apt(serve per dire cosa installare e anche le dipendenze)

      STRUMENTI ESSENZIALI PER L'UTILIZZO DI ALCUNI PACCHETTI SOFTWARE(Red Hat, Fedora e CentOS):

	- rpm(serve per dire cosa installare, ma non ti risolve le dipendenze dice solo quali sono) 
	- yum e dnf(serve per dire cosa installare e anche le dipendenze)
   
    INSTALLAZIONE DI UN PACCHETTO
  Se la tua distribuzione funziona con i pacchetti DEB, puoi cercare nei suoi repository usando apt-cache
  search nome_pacchetto o apt search nome_pacchetto. Il comando apt-cache è usato per cercare i pacchetti
  e per mostrare informazioni  
  
	$ apt-cache search figlet
	figlet - Make large character ASCII banners out of ordinary text
   	
  La ricerca individua un pacchetto chiamato figlet che corrisponde al comando mancante. Le
  operazioni di installazione e rimozione di un pacchetto richiedono autorizzazioni speciali
  concesse solo all’amministratore di sistema: l’utente chiamato root. Sui sistemi desktop, gli utenti
  ordinari possono installare o rimuovere i pacchetti anteponendo il comando sudo ai comandi di installazione/rimozione
  Ciò richiederà di digitare la password per procedere. Per i pacchetti DEB, l’installazione viene eseguita
  con il comando apt-get install nome_pacchetto o aptinstall nome_pacchetto:

    1. digitazioni comando e richista password

	$ sudo apt-get install figlet
	Reading package lists... Done
	Building dependency tree
	Reading state information... Done
	The following NEW packages will be installed:
	  figlet
	0 upgraded, 1 newly installed, 0 to remove and 0 not upgraded

    2. installazione pacchetto

	Need to get 184 kB of archives.
	After this operation, 741 kB of additional disk space will be used.
	Get:1 http://archive.raspbian.org/raspbian stretch/main armhf figlet armhf 2.2.5-2 [184 kB]
	Fetched 184 kB in 0s (213 kB/s)
	Selecting previously unselected package figlet.
	(Reading database ... 115701 files and directories currently installed.)
	Preparing to unpack .../figlet_2.2.5-2_armhf.deb ...
	Unpacking figlet (2.2.5-2) ...
	Setting up figlet (2.2.5-2) ...
	update-alternatives: using /usr/bin/figlet-figlet to provide /usr/bin/figlet (figlet) in
	auto mode
	Processing triggers for man-db (2.7.6.1-2) ...

   3. termine installazione

	$ figlet Awesome!


 
  	
   	 _                               
	/ \__      _____ ___  ___  _ __ ___   ___       
       / _ \ \ /\ / /_ \/ __|/ _ \| '_ ` _ \ / _ \ 
      / ___ \ V  V / __/\__ \ (_) | | | | | |  __/
     /_/   \_\_/\_/\___||___/\___/|_| |_| |_|\___






































