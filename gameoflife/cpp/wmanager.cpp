#include "wmanager.h"
#include "gamelife.h"
#include <QApplication>

#include <QDir>
#include <QFileDialog>
#include <iostream>



WManager::WManager(QObject *parent) : QObject(parent)
{
    qDebug() << "WManager::instance construite ";
}

void WManager::load()
{
    QList<QString> fichiersQML;
    fichiersQML << QString("qml");

    for( int t=0 ; t<1 ; t++)
    {
        makeQMLtab(fichiersQML.at(t));
        std::cout << "tab " << t << " ready." << std::endl;
    }
}

void WManager::makeQMLtab(QString nomFichierQMLsansExtension)
{
    QQuickView* view = new QQuickView();
    quickViews.push_back(view);

    view->setResizeMode( QQuickView::SizeRootObjectToView);
    view->setGeometry(QRect(120, 120, 700, 500));

    // Mise en mémoire des objets pour communiquer avec le QML (avant le chargement de la page)
    m_QMLcontexts << view->engine()->rootContext();

    m_qmlContext = m_QMLcontexts.at(0);
    m_qmlContext->setContextProperty("Context", this->getInstance());
    //

    // Initialisation plateau
    initPlateau();
    QStringList sl_plateau = createStringFromPlateau(m_plateau);
    updateQML_ListView("modelPlateau", sl_plateau);

    //
    QString repertoireProjet = getRepertoireProjet();

    QString fichierQML = repertoireProjet + QString("/qml/") + nomFichierQMLsansExtension + QString(".qml");
    std::cout  << "charge le fichier QML : " << fichierQML.toLatin1().constData() << std::endl;

    // Chargement du fichier QML
    view->setSource( QUrl::fromLocalFile(fichierQML) ) ;
    view->show();
}

QString WManager::getRepertoireProjet(bool trace)//false
{
    QString repertoireduFichierApplication( qApp->applicationFilePath() );
    if( trace)
        std::cout << "qApp->applicationFilePath() = "<< repertoireduFichierApplication.toLatin1().constData() << std::endl;

    QDir fichier(repertoireduFichierApplication);
    fichier.cdUp() ;
    fichier.cdUp() ;
    if( trace)
        std::cout << "qApp->applicationName() = "<< qApp->applicationName().toLatin1().constData() << std::endl;

    fichier.cd(qApp->applicationName());
    QString repertoireProjet  = fichier.absolutePath() ;
    if( trace)
        std::cout  << "repertoireProjet : " << repertoireProjet.toLatin1().constData() << std::endl;

    return repertoireProjet;
}

void WManager::displayInitialInformations()
{
    getRepertoireProjet(true);
}

//.............................................................

void WManager::updateQML_ListView(QString nomModele, QStringList sl)
{
    m_qmlContext = m_QMLcontexts.at(0);
    m_qmlContext->setContextProperty(nomModele, QVariant::fromValue( sl ) );
}

void WManager::sendActionToCpp(QString nom, QString param)
{
    qDebug() << "WManager::sendActionfromQML : " << nom;
    qDebug() << "WManager::sendActionfromQML : " << param;

    if ( nom == "updateCombo" )
    {
        QStringList nouvelleListe;
        nouvelleListe << "chaine 5";
        nouvelleListe << "chaine 6";

        updateQML_ListView( "SousTypes", nouvelleListe );
    }
    else if ( nom == "Reinitialiser" )
    {

        qDebug() << "paramètres=>" << param;
    }
    else if ( nom == "changeCaseValue" )
    {
        qDebug() << "paramètres=>" << param;
    }
}

void WManager::sendCaseToCpp(QPoint pt)
{
    m_plateau[pt.y()][pt.x()] = 1 - m_plateau[pt.y()][pt.x()];
    updateQML_ListView("modelPlateau", createStringFromPlateau(m_plateau) );
}

void WManager::initPlateau(int i, int j)
{
    m_plateau = vector<vector<int>> { (size_t)i, vector<int>(j) };

    // écrire la fonction équivalente à l'initialisation avec 2 boucles for, qqchose comme

//    for (int p = 0; p < i; ++p) {
//        for (int q = 0; var < j; ++var) {
//            m_plateau.push_back(0);
//        }
//    }
}

QStringList WManager::createStringFromPlateau(vector<vector<int>> plateau)
{
    QStringList rslt;
    for( vector<int> ligneP : plateau )
    {
        QString ligne("");
        for( int v : ligneP)
        {
            ligne += (v==0) ? "0" : "1";
        }
        rslt << ligne;
    }
    return rslt;
}
