#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QSpinBox>
#include <QMdiArea>
#include <QMenu>
#include <QMenuBar>
#include <QTextEdit>
#include <QFileDialog>
#include <QFontDialog>
#include <QFont>
#include <QToolBar>
#include <QStatusBar>

class Principale: public QMainWindow{
    Q_OBJECT
public:
    Principale();
    ~Principale();
public slots:
    void ouvrir();
    void enregistreSous();
    void police();
    void statut();
private:
    QWidget *m_central;
    QLineEdit *m_mnom;
    QLabel *m_nom;
    QLineEdit *m_mprenom;
    QLabel *m_prenom;
    QSpinBox *m_mage;
    QLabel *m_age;
    QFormLayout *m_formc1;
    QPushButton *m_valider;
    QPushButton *m_annuler;
    QHBoxLayout *m_hlayc1;
    QVBoxLayout *m_vlayc1;
    QTextEdit *m_text;
    QVBoxLayout *m_vlayc2;

    QAction *m_AnouveauF;
    QAction *m_AouvrirF;
    QAction *m_AenregistreF;
    QAction *m_AenregistreSF;
    QAction *m_AquiterF;

    QAction *m_AannulerE;
    QAction *m_AcopierE;
    QAction *m_AcouperE;
    QAction *m_AcolerE;
    QAction *m_AselectionToutE;

    QAction *m_ApoliceF;
    QAction *m_AaligneF;

    QAction *m_AzoomNA;
    QAction *m_AzoomPA;
    QAction *m_AzoomEA;
    QAction *m_AetatA;

    QAction *m_AsexS;
    QAction *m_AaproS;

    /*QMenu *m_fichier;
    QMenu *m_edition;
    QMenu *m_format;
    QMenu *m_affichage;
    QMenu *m_aide;*/
};

#endif // FENPRINCIPALE_H
