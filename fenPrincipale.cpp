#include "qfiledialog.h"
#include <fenPrincipale.h>

Principale::Principale(): QMainWindow(){

    setGeometry(400,120,900,700);

    //titre de la fenetre
    setWindowTitle("Sex code");

    //Allocation dynamique de widgets et layouts
    m_central= new QWidget();
    m_nom= new QLabel("nom ");
    m_mnom= new QLineEdit();
    m_prenom= new QLabel("prenom ");
    m_mprenom= new QLineEdit();
    m_age= new QLabel("age ");
    m_mage= new QSpinBox();
    m_valider= new QPushButton("Valider");
    m_annuler= new QPushButton("Annuler");
    m_text= new QTextEdit();
    m_formc1= new QFormLayout();
    m_hlayc1= new QHBoxLayout();
    m_vlayc1= new QVBoxLayout();
    m_vlayc2= new QVBoxLayout();

    //creation des menus
    QMenu *fichier= menuBar()->addMenu("Fichier");
    QMenu *edition= menuBar()->addMenu("Edition");
    QMenu *affichage= menuBar()->addMenu("Affichage");
    QMenu *format= menuBar()->addMenu("Format");
    QMenu *sex= menuBar()->addMenu("Sex");

    //Allocation des actions dans le menu fichier
    m_AnouveauF= new QAction("Nouveau",this);
    m_AouvrirF= new QAction("Ouvrir....",this);
    m_AenregistreF= new QAction("Enregistrer",this);
    m_AenregistreSF= new QAction("Enregistrer sous....",this);
    m_AquiterF= new QAction("Quitter",this);
    fichier->addAction(m_AnouveauF);
    m_AnouveauF->setShortcut(QKeySequence("Ctrl+N"));
    fichier->addAction(m_AouvrirF);
    m_AouvrirF->setShortcut(QKeySequence("Ctrl+O"));
    fichier->addAction(m_AenregistreF);
    m_AenregistreF->setShortcut(QKeySequence("Ctrl+S"));
    fichier->addAction(m_AenregistreSF);
    fichier->addSeparator();
    m_AenregistreSF->setShortcut(QKeySequence("Ctrl+Alt+S"));
    fichier->addAction(m_AquiterF);
    m_AquiterF->setShortcut(QKeySequence("Alt+F4"));

    //signaux d'actions dans le menu fichier
    connect(m_AenregistreSF,SIGNAL(triggered(bool)),this,SLOT(enregistreSous()));
    connect(m_AquiterF,SIGNAL(triggered(bool)),qApp,SLOT(quit()));
    connect(m_AouvrirF,SIGNAL(triggered(bool)),this,SLOT(ouvrir()));


    //Allocation des actions dans le menu Edition
    m_AannulerE= new QAction("Annuler",this);
    m_AcouperE= new QAction("Couper",this);
    m_AcopierE= new QAction("Copier",this);
    m_AcolerE= new QAction("Coler",this);
    m_AselectionToutE= new QAction("Selectionner Tout",this);
    edition->addAction(m_AannulerE);
    edition->addSeparator();
    m_AannulerE->setShortcut(QKeySequence("Ctrl+Z"));
    edition->addAction(m_AcouperE);
    m_AcouperE->setShortcut(QKeySequence("Ctrl+X"));
    edition->addAction(m_AcopierE);
    m_AcopierE->setShortcut(QKeySequence("Ctrl+C"));
    edition->addAction(m_AcolerE);
    m_AcolerE->setShortcut(QKeySequence("Ctrl+V"));
    edition->addSeparator();
    edition->addAction(m_AselectionToutE);
    m_AselectionToutE->setShortcut(QKeySequence("Ctrl+A"));

    //signaux d'actions dans le menu Edition

    //Allocation des actions dans le menu Format
    m_ApoliceF=new QAction("Police",this);
    m_AaligneF= new QAction("Retour automatique à la ligne",this);
    format->addAction(m_AaligneF);
    format->addSeparator();
    format->addAction(m_ApoliceF);
    //connection de police d'écriture
    connect(m_ApoliceF,SIGNAL(triggered(bool)),this,SLOT(police()));

    //Allocation des actions dans le menu Affichage
    m_AzoomNA= new QAction("Zoom avant",this);
    m_AzoomPA= new QAction("Zoom arriere",this);
    m_AzoomEA= new QAction("Restaurer le zoom par défaut");
    QMenu *zoom= affichage->addMenu("Zoom");
    affichage->addSeparator();
    m_AetatA= new QAction("Barre d'etat",this);
    //................ rendre la barre d'etat cochable
    m_AetatA->setCheckable(true);
            //................
    zoom->addAction(m_AzoomNA);
    m_AzoomNA->setShortcut(QKeySequence("Ctrl++"));
    zoom->addAction(m_AzoomPA);
    m_AzoomPA->setShortcut(QKeySequence("Ctrl+-"));
    affichage->addAction(m_AetatA);
    m_AzoomEA->setShortcut(QKeySequence("Ctrl+O"));
    zoom->addAction(m_AzoomEA);
    //connection de l'action m_AetatA à la barre d'etat
    connect(m_AetatA,SIGNAL(triggered(bool)),this,SLOT(statut()));

    //Disposition des icone dans les sous menus
    m_AquiterF->setIcon(QIcon("quit.png"));
    m_AnouveauF->setIcon(QIcon("folderO.png"));
    m_AouvrirF->setIcon(QIcon("folderL.png"));
    m_AenregistreF->setIcon(QIcon("save.png"));
    m_AenregistreSF->setIcon(QIcon("saveAs.png"));
    m_AzoomEA->setIcon(QIcon("zoom.png"));
    m_AzoomNA->setIcon(QIcon("zoom+.png"));
    m_AzoomPA->setIcon(QIcon("zoom-.png"));
    m_ApoliceF->setIcon(QIcon("police.png"));
    zoom->setIcon(QIcon("zoom.png"));

    //Allocation des actions dans le menu Sex
    m_AsexS= new QAction("Tu cherche ?",this);
    m_AaproS=new QAction("A propos de Sex-code");
    sex->addAction(m_AsexS);
    sex->addSeparator();
    sex->addAction(m_AaproS);

    //insertion d'objet dans le widget
    m_formc1->addRow(m_nom,m_mnom);
    m_formc1->addRow(m_prenom,m_mprenom);
    m_formc1->addRow(m_age,m_mage);
    m_hlayc1->addWidget(m_valider);
    m_hlayc1->addWidget(m_annuler);
    m_vlayc1->addLayout(m_formc1);
    m_vlayc1->addLayout(m_hlayc1);

    m_vlayc2->addWidget(m_text);

    connect(m_annuler,SIGNAL(clicked(bool)),qApp,SLOT(quit()));
    //m_central->addSubWindow(m_text);
    m_central->setLayout(m_vlayc2);
    //m_central->addSubWindow(m_text);

    //creation de la barre d'outils
    QToolBar *toolBarFichier = addToolBar("File");
    //Definition d'actions pour la barre d'outils
    toolBarFichier->addAction(m_AouvrirF);
    toolBarFichier->addSeparator();
    toolBarFichier->addAction(m_AenregistreF);
    toolBarFichier->addSeparator();
    toolBarFichier->addAction(m_AquiterF);

    //central widget
    setCentralWidget(m_central);


}
void Principale::statut(){
    if(m_AetatA->isChecked()){
        //definition de la barre d'etat
        QStatusBar *statut=new QStatusBar(this);
        //statut->currentMessage();
        statut->showMessage("Le programme en cours d'utilisation....");
        this->setStatusBar(statut);
    }
}
void Principale::police(){
    bool ok = false;
    QFont police = QFontDialog::getFont(&ok, m_text->font(), this, "Choisissez une police");
    if(ok){
        m_text->setFont(police);
    }
}

void Principale::ouvrir(){
    QFileDialog::getExistingDirectory(this,"Ouvrir un fichier",QString());
}

void Principale:: enregistreSous(){
    QFileDialog::getSaveFileName(this,"Enregistrer sous",QString(),"text(*.txt)");
}

Principale::~Principale(){


}
