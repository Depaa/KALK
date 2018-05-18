#include "view.h"
#include "control.h"
#include <QApplication>
#include <QFont>
#include <QLabel>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QDialog>
#include <QString>
#include <QDialogButtonBox>
#include <QTime>
#include <QMessageBox>
#include <QComboBox>

view::view(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Kalk");
    contGrid = new QGridLayout();
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowCloseButtonHint);
    //setFixedSize(800,500);

    Orario = new QPushButton("Inserisci\nOrario", this); //QPushButton(const QString & text, QWidget * parent = 0)
    Orario -> setFont(QFont("Arial", 10));
    Orario->setFixedSize(170,170);
    contGrid->addWidget(Orario, 0, 0); //riga, colonna

    Data = new QPushButton("Inserisci\nData", this);
    Data -> setFont(QFont("Arial", 10));
    Data->setFixedSize(170,170);
    contGrid->addWidget(Data, 1, 0);

    Fuso = new QPushButton("Inserisci\nFuso", this);
    Fuso -> setFont(QFont("Arial", 10));
    Fuso->setFixedSize(170,170);
    contGrid->addWidget(Fuso, 2, 0);

    Sole = new QPushButton("Inserisci\nSole", this);
    Sole -> setFont(QFont("Arial", 10));
    Sole->setFixedSize(170,170);
    contGrid->addWidget(Sole, 3, 0);

    clearButton=new QPushButton("RESET", this);
    clearButton -> setFont(QFont("Arial", 10));
    clearButton->setDisabled(true);
    contGrid->addWidget(clearButton, 4, 0);

    time = new QLabel(this);
    time->setFixedSize(200,50);
    //time->setStyleSheet(QString("border: 2px solid black"));
    time->setAlignment(Qt::AlignCenter);
    time->setFont(QFont( "Arial", 10, QFont::Bold));
    time->hide();
    contGrid->addWidget(time, 0, 2);

    date = new QLabel(this);
    date->setFixedSize(200,50);
    //date->setStyleSheet(QString("border: 2px solid black"));
    date->setAlignment(Qt::AlignCenter);
    date->setFont(QFont( "Arial", 10, QFont::Bold));
    date->hide();
    contGrid->addWidget(date, 1, 2);

    fuso = new QLabel(this);
    fuso->setFixedSize(200,50);
    //fuso->setStyleSheet(QString("border: 2px solid black"));
    fuso->setAlignment(Qt::AlignCenter);
    fuso->setFont(QFont( "Arial", 10, QFont::Bold));
    fuso->hide();
    contGrid->addWidget(fuso, 2, 2);

    sole = new QLabel(this);
    sole->setFixedSize(200,50);
    //sole->setStyleSheet(QString("border: 2px solid black"));
    sole->setAlignment(Qt::AlignCenter);
    sole->setFont(QFont( "Arial", 10, QFont::Bold));
    sole->hide();
    contGrid->addWidget(sole, 3, 2);

    QGridLayout* gOrario=new QGridLayout();
    sommaButton= new QPushButton("+", this);
    sommaButton->setFont(QFont("Arial", 10));
    sommaButton->setFixedSize(60,60);
    sommaButton->setDisabled(true);
    gOrario->addWidget(sommaButton, 0, 0);

    sottrazioneButton= new QPushButton("-", this);
    sottrazioneButton->setFont(QFont("Arial", 10));
    sottrazioneButton->setFixedSize(60,60);
    sottrazioneButton->setDisabled(true);
    gOrario->addWidget(sottrazioneButton, 1, 0);

    //metodi solo di orario
    velocitaButton = new QPushButton("Velocita", this) ;
    velocitaButton->setFont(QFont("Arial", 10));
    velocitaButton->setFixedSize(60,60);
    velocitaButton->setDisabled(true);
    gOrario->addWidget(velocitaButton, 0, 1);

    orarioFormButton = new QPushButton("Form", this) ;
    orarioFormButton->setFont(QFont("Arial", 10));
    orarioFormButton->setFixedSize(60,60);
    orarioFormButton->setDisabled(true);
    gOrario->addWidget(orarioFormButton, 1, 1);

    dividiButton = new QPushButton("/", this) ;
    dividiButton->setFont(QFont("Arial", 10));
    dividiButton->setFixedSize(60,60);
    dividiButton->setDisabled(true);
    //gOrario->setRowMinimumHeight(2, 140);
    gOrario->addWidget(dividiButton, 0, 2, Qt::AlignCenter);

    //metodi solo di data
    QGridLayout* gData=new QGridLayout();
    settimanaButton = new QPushButton("N.\nSett", this) ; //numero settimana
    settimanaButton->setFont(QFont("Arial", 10));
    settimanaButton->setFixedSize(60,60);
    settimanaButton->setDisabled(true);
    gData->addWidget(settimanaButton, 0, 0);

    giornoAnnoButton = new QPushButton("N.\nGiorno", this) ; //numero
    giornoAnnoButton->setFont(QFont("Arial", 10));
    giornoAnnoButton->setFixedSize(60,60);
    giornoAnnoButton->setDisabled(true);
    gData->addWidget(giornoAnnoButton, 1, 0);

    giornoSettButton = new QPushButton("Giorno", this) ; //nome giorno.
    giornoSettButton->setFont(QFont("Arial", 10));
    giornoSettButton->setFixedSize(60,60);
    giornoSettButton->setDisabled(true);
    gData->addWidget(giornoSettButton, 0, 1);

    stagioneButton = new QPushButton("Stag.", this) ;
    stagioneButton->setFont(QFont("Arial", 10));
    stagioneButton->setFixedSize(60,60);
    stagioneButton->setDisabled(true);
    gData->addWidget(stagioneButton, 1, 1);

    dataFormButton = new QPushButton("Form", this) ;
    dataFormButton->setFont(QFont("Arial", 10));
    dataFormButton->setFixedSize(60,60);
    dataFormButton->setDisabled(true);
    gData->addWidget(dataFormButton, 0, 2);

    durataButton = new QPushButton("Durata", this) ;
    durataButton->setFont(QFont("Arial", 10));
    durataButton->setFixedSize(60,60);
    durataButton->setDisabled(true);
    gData->addWidget(durataButton, 1, 2);

    aggGiorniButton=new QPushButton("Aggiungi\nGiorni", this) ;
    aggGiorniButton->setFont(QFont("Arial", 10));
    aggGiorniButton->setFixedSize(60,60);
    aggGiorniButton->setDisabled(true);
    gData->addWidget(aggGiorniButton, 0, 3);

    //metodi solo di fuso
    QGridLayout* gFuso=new QGridLayout();
    fusoButton = new QPushButton("Fuso", this) ;
    fusoButton->setFont(QFont("Arial", 10));
    fusoButton->setFixedSize(60,60);
    fusoButton->setDisabled(true);
    gFuso->addWidget(fusoButton, 0, 0);

    latButton = new QPushButton("Lat", this) ;
    latButton->setFont(QFont("Arial", 10));
    latButton->setFixedSize(60,60);
    latButton->setDisabled(true);
    gFuso->addWidget(latButton, 1, 0);

    lonButton = new QPushButton("Lon", this) ;
    lonButton->setFont(QFont("Arial", 10));
    lonButton->setFixedSize(60,60);
    lonButton->setDisabled(true);
    gFuso->addWidget(lonButton, 0, 1);

    emisButton = new QPushButton("Emis", this) ;
    emisButton->setFont(QFont("Arial", 10));
    emisButton->setFixedSize(60,60);
    emisButton->setDisabled(true);
    gFuso->addWidget(emisButton, 1, 1);

    differenzaButton = new QPushButton("-", this) ;
    differenzaButton->setFont(QFont("Arial",10));
    differenzaButton->setFixedSize(60,60);
    differenzaButton->setDisabled(true);
    gFuso->addWidget(differenzaButton, 0, 2);


    orarioAltraCittaButton = new QPushButton("Citta", this) ;
    orarioAltraCittaButton->setFont(QFont("Arial", 10));
    orarioAltraCittaButton->setFixedSize(60,60);
    orarioAltraCittaButton->setDisabled(true);
    gFuso->addWidget(orarioAltraCittaButton, 1, 2);

    //metodi solo di sole
    QGridLayout* gSole=new QGridLayout();
    sunriseButton = new QPushButton("Rise", this) ;
    sunriseButton->setFont(QFont("Arial", 10));
    sunriseButton->setFixedSize(60,60);
    sunriseButton->setDisabled(true);
    gSole->addWidget(sunriseButton, 0, 0);

    sunsetButton = new QPushButton("Set", this) ;
    sunsetButton->setFont(QFont("Arial", 10));
    sunsetButton->setFixedSize(60,60);
    sunsetButton->setDisabled(true);
    gSole->addWidget(sunsetButton, 0, 1);

    noonButton = new QPushButton("Noon", this) ;
    noonButton->setFont(QFont("Arial", 10));
    noonButton->setFixedSize(60,60);
    noonButton->setDisabled(true);
    gSole->addWidget(noonButton, 0, 2);

    //connessioni

    connect(Orario, SIGNAL(clicked(bool)), this, SLOT(clickCreaOrario()));
    connect(Data, SIGNAL(clicked(bool)), this, SLOT(clickCreaData()));
    connect(Fuso, SIGNAL(clicked(bool)), this, SLOT(clickCreaFuso()));
    connect(Sole, SIGNAL(clicked(bool)), this, SLOT(clickCreaSole()));

    connect(sommaButton, SIGNAL(clicked(bool)), this, SLOT(clickSomma()));
    connect(sottrazioneButton, SIGNAL(clicked(bool)), this, SLOT(clickSottrazione()));
    connect(clearButton, SIGNAL(clicked(bool)), this, SLOT(clickClear()));

    connect(velocitaButton, SIGNAL(clicked(bool)), this, SLOT(clickVelocita()));
    connect(orarioFormButton, SIGNAL(clicked(bool)), this, SLOT(clickOrarioForm()));
    connect(dividiButton, SIGNAL(clicked(bool)), this, SLOT(clickDividi()));

    connect(settimanaButton, SIGNAL(clicked(bool)), this, SLOT(clickSettimana()));
    connect(giornoAnnoButton, SIGNAL(clicked(bool)), this, SLOT(clickGiornoAnno()));
    connect(giornoSettButton, SIGNAL(clicked(bool)), this, SLOT(clickGiornoSett()));
    connect(stagioneButton, SIGNAL(clicked(bool)), this, SLOT(clickStagione()));
    connect(dataFormButton, SIGNAL(clicked(bool)), this, SLOT(clickDataForm()));
    connect(durataButton, SIGNAL(clicked(bool)), this, SLOT(clickDurata()));
    connect(aggGiorniButton, SIGNAL(clicked(bool)), this, SLOT(clickAggGiorni()));

    connect(fusoButton, SIGNAL(clicked(bool)), this, SLOT(clickFuso()));
    connect(latButton, SIGNAL(clicked(bool)), this, SLOT(clickLat()));
    connect(lonButton, SIGNAL(clicked(bool)), this, SLOT(clickLon()));
    connect(emisButton, SIGNAL(clicked(bool)), this, SLOT(clickEmis()));
    connect(differenzaButton, SIGNAL(clicked(bool)), this, SLOT(clickDifferenza()));
    connect(orarioAltraCittaButton, SIGNAL(clicked(bool)), this, SLOT(clickOrarioAltraCitta()));

    connect(sunriseButton, SIGNAL(clicked(bool)), this, SLOT(clickSunrise()));
    connect(sunsetButton, SIGNAL(clicked(bool)), this, SLOT(clickSunset()));
    connect(noonButton, SIGNAL(clicked(bool)), this, SLOT(clickNoon()));

    contGrid->setRowMinimumHeight(0, 200);
    contGrid->setRowMinimumHeight(1, 230);
    contGrid->setRowMinimumHeight(2, 230);

    contGrid->setColumnMinimumWidth(0,200);
    contGrid->setColumnMinimumWidth(1,200);
    contGrid->setColumnMinimumWidth(2,200);

    contGrid->addLayout(gOrario, 0,1,Qt::AlignCenter);
    contGrid->addLayout(gData, 1,1,Qt::AlignCenter);
    contGrid->addLayout(gFuso, 2,1,Qt::AlignCenter);
    contGrid->addLayout(gSole, 3,1,Qt::AlignCenter);
    setLayout(contGrid);
}

view::~view() {}

void view::setControl(control* c) {
    controller=c;
}

void view::clickCreaOrario() {
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Inserisci Orario"));
    QLineEdit* line1= new QLineEdit(dialog);
    QString textline1=QString("Ore: ");
    QLineEdit* line2= new QLineEdit(dialog);
    QString textline2=QString("Minuti: ");
    QLineEdit* line3= new QLineEdit(dialog);
    QString textline3=QString("Secondi: ");
    form.addRow(textline1, line1);
    form.addRow(textline2, line2);
    form.addRow(textline3, line3);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        bool sent=true;
        QString s;
        s= line1->text() + ":" + line2->text() + ":" + line3->text();
        sent= controller->onClickCreaOrario(s);
        if (sent)
        {
            mostraOra=s;
            time->setText(mostraOra);
            time->show();

            Orario->setDisabled(true);
            Data->setEnabled(true);
            Sole->setEnabled(true);
            Fuso->setEnabled(true);

            sommaButton->setEnabled(true);
            sottrazioneButton->setEnabled(true);
            velocitaButton->setEnabled(true);
            orarioFormButton->setEnabled(true);
            dividiButton->setEnabled(true);
            clearButton->setEnabled(true);

            settimanaButton->setDisabled(true);
            giornoAnnoButton->setDisabled(true);
            giornoSettButton->setDisabled(true);
            stagioneButton->setDisabled(true);
            dataFormButton->setDisabled(true);
            durataButton->setDisabled(true);
            fusoButton->setDisabled(true);
            latButton->setDisabled(true);
            lonButton->setDisabled(true);
            emisButton->setDisabled(true);
            differenzaButton->setDisabled(true);
            orarioAltraCittaButton->setDisabled(true);
            sunriseButton->setDisabled(true);
            sunsetButton->setDisabled(true);
            noonButton->setDisabled(true);
            aggGiorniButton->setDisabled(true);
        }

        else
        {
            QMessageBox m;
            m.setText("Hai sbagliato coglione");
            m.exec();
        }
    }
}

void view::clickCreaData() {
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Inserisci Data"));
    QLineEdit* line1= new QLineEdit(dialog);
    QString textline1=QString("Giorno*: ");
    QLineEdit* line2= new QLineEdit(dialog);
    QString textline2=QString("Mese*: ");
    QLineEdit* line3= new QLineEdit(dialog);
    QString textline3=QString("Anno*: ");
    QLineEdit* line4= new QLineEdit(dialog);
    QString textline4=QString("Ore: ");
    QLineEdit* line5= new QLineEdit(dialog);
    QString textline5=QString("Minuti: ");
    QLineEdit* line6= new QLineEdit(dialog);
    QString textline6=QString("Secondi: ");
    form.addRow(textline1, line1);
    form.addRow(textline2, line2);
    form.addRow(textline3, line3);
    form.addRow(textline4, line4);
    form.addRow(textline5, line5);
    form.addRow(textline6, line6);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        bool sent=true;
        QString s;
        s= line1->text() + "/" + line2->text() + "/" + line3->text() + "," + line4->text() + ":" + line5->text() + ":" + line6->text();
        sent= controller->onClickCreaData(s);
        if (sent)
        {
            QDate d=controller->getDate();
            QTime t=controller->getTime();
            mostraData=d.toString("dd/MM/yyyy");
            mostraOra=t.toString("hh:mm:ss");

            time->setText(mostraOra);
            time->show();
            date->setText(mostraData);
            date->show();

            Orario->setDisabled(true);
            Data->setDisabled(true);
            Sole->setEnabled(true);
            Fuso->setEnabled(true);

            sommaButton->setEnabled(true);
            sottrazioneButton->setEnabled(true);
            settimanaButton->setEnabled(true);
            giornoAnnoButton->setEnabled(true);
            giornoSettButton->setEnabled(true);
            stagioneButton->setEnabled(true);
            dataFormButton->setEnabled(true);
            durataButton->setEnabled(true);
            velocitaButton->setEnabled(true);
            orarioFormButton->setEnabled(true);
            dividiButton->setEnabled(true);
            aggGiorniButton->setEnabled(true);
            clearButton->setEnabled(true);

            fusoButton->setDisabled(true);
            latButton->setDisabled(true);
            lonButton->setDisabled(true);
            emisButton->setDisabled(true);
            differenzaButton->setDisabled(true);
            orarioAltraCittaButton->setDisabled(true);
            sunriseButton->setDisabled(true);
            sunsetButton->setDisabled(true);
            noonButton->setDisabled(true);
        }
        else
        {
            QMessageBox m;
            m.setText("Hai sbagliato coglione");
            m.exec();
        }
    }
}


void view::clickCreaFuso(){
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Scegli Citta"));
    QComboBox* CB=new QComboBox;
    CB->addItem("Londra");
    CB->addItem("Casablanca");
    CB->addItem("Roma");
    CB->addItem("Parigi");
    CB->addItem("Madrid");
    CB->addItem("Helsinki");
    CB->addItem("Citta del Capo");
    CB->addItem("Mosca");
    CB->addItem("Abu Dhabi");
    CB->addItem("Bangkok");
    CB->addItem("Pechino");
    CB->addItem("Tokyp");
    CB->addItem("Seul");
    CB->addItem("Sydney");
    CB->addItem("Wellington");
    CB->addItem("Rio de Janeiro");
    CB->addItem("Buenos Aires");
    CB->addItem("Santiago");
    CB->addItem("New York");
    CB->addItem("Chicago");
    CB->addItem("Citta del Messico");
    CB->addItem("Denver");
    CB->addItem("Los Angeles");
    QLineEdit* line1= new QLineEdit(dialog);
    QString textline1=QString("Giorno*: ");
    QLineEdit* line2= new QLineEdit(dialog);
    QString textline2=QString("Mese*: ");
    QLineEdit* line3= new QLineEdit(dialog);
    QString textline3=QString("Anno*: ");
    QLineEdit* line4= new QLineEdit(dialog);
    QString textline4=QString("Ore*: ");
    QLineEdit* line5= new QLineEdit(dialog);
    QString textline5=QString("Minuti*: ");
    QLineEdit* line6= new QLineEdit(dialog);
    QString textline6=QString("Secondi*: ");
    form.addRow(CB);
    form.addRow(textline1, line1);
    form.addRow(textline2, line2);
    form.addRow(textline3, line3);
    form.addRow(textline4, line4);
    form.addRow(textline5, line5);
    form.addRow(textline6, line6);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        bool sent=true;
        QString s;
        s= CB->currentText() + "," + line1->text() + "/" + line2->text() + "/" + line3->text() + "," + line4->text() + ":" + line5->text() + ":" + line6->text();
        sent= controller->onClickCreaFuso(s);
        if (sent)
        {
            QString f=controller->getFuso();
            QDate d=controller->getDate();
            QTime t=controller->getTime();
            mostraData=d.toString("dd/MM/yyyy");
            mostraOra=t.toString("hh:mm:ss");
            mostraFuso=f;
            fuso->setText(mostraFuso);
            time->setText(mostraOra);
            date->setText(mostraData);
            fuso->show();
            time->show();
            date->show();

            Orario->setDisabled(true);
            Data->setDisabled(true);
            Fuso->setDisabled(true);
            Sole->setDisabled(true);

            fusoButton->setEnabled(true);
            latButton->setEnabled(true);
            lonButton->setEnabled(true);
            emisButton->setEnabled(true);
            differenzaButton->setEnabled(true);
            orarioAltraCittaButton->setEnabled(true);
            sommaButton->setEnabled(true);
            sottrazioneButton->setEnabled(true);
            settimanaButton->setEnabled(true);
            giornoAnnoButton->setEnabled(true);
            giornoSettButton->setEnabled(true);
            stagioneButton->setEnabled(true);
            dataFormButton->setEnabled(true);
            durataButton->setEnabled(true);
            velocitaButton->setEnabled(true);
            orarioFormButton->setEnabled(true);
            dividiButton->setEnabled(true);
            aggGiorniButton->setEnabled(true);
            clearButton->setEnabled(true);

            sunriseButton->setDisabled(true);
            sunsetButton->setDisabled(true);
            noonButton->setDisabled(true);
        }
        else
        {
            QMessageBox m;
            m.setText("Hai sbagliato coglione");
            m.exec();
        }
    }
}

void view::clickCreaSole(){
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Inserisci Sole"));
    QLineEdit* line1= new QLineEdit(dialog);
    QString textline1=QString("Latitudine: ");
    QLineEdit* line2= new QLineEdit(dialog);
    QString textline2=QString("Longitudine: ");
    QLineEdit* line3= new QLineEdit(dialog);
    QString textline3=QString("Fuso Orario: ");
    QLineEdit* line4= new QLineEdit(dialog);
    QString textline4=QString("Giorno : ");
    QLineEdit* line5= new QLineEdit(dialog);
    QString textline5=QString("Mese: ");
    QLineEdit* line6= new QLineEdit(dialog);
    QString textline6=QString("Anno: ");
    QLineEdit* line7= new QLineEdit(dialog);
    QString textline7=QString("Ora(attuali): ");
    QLineEdit* line8= new QLineEdit(dialog);
    QString textline8=QString("Minuti(attuali): ");
    QLineEdit* line9= new QLineEdit(dialog);
    QString textline9=QString("Secondi(attuali): ");
    QLineEdit* line10= new QLineEdit(dialog);
    QString textline10=QString("Ora Legale(1 o 0): ");
    QLineEdit* line11= new QLineEdit(dialog);
    QString textline11=QString("Equazione del Tempo: ");
    QLineEdit* line12= new QLineEdit(dialog);
    QString textline12=QString("Declinazione Solare: ");
    form.addRow(textline1, line1);
    form.addRow(textline2, line2);
    form.addRow(textline3, line3);
    form.addRow(textline4, line4);
    form.addRow(textline5, line5);
    form.addRow(textline6, line6);
    form.addRow(textline7, line7);
    form.addRow(textline8, line8);
    form.addRow(textline9, line9);
    form.addRow(textline10, line10);
    form.addRow(textline11, line11);
    form.addRow(textline12, line12);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        bool sent=true;
        QString s;
        s= line1->text() + "," + line2->text() + "," + line3->text() + "," + line4->text() + "/" + line5->text() + "/" + line6->text() + "," + line7->text() + ":" + line8->text() + ":" + line9->text()+ "," + line10->text() + "," + line11->text() + "," + line12->text();
        sent= controller->onClickCreaSole(s);
        if (sent)
        {
            QDate d=controller->getDate();
            QTime t=controller->getTime();
            mostraData=d.toString("dd/MM/yyyy");
            mostraOra=t.toString("hh:mm:ss");

            time->setText(mostraOra);
            date->setText(mostraData);
            time->show();
            date->show();

            Orario->setDisabled(true);
            Data->setDisabled(true);
            Fuso->setDisabled(true);
            Sole->setDisabled(true);

            sommaButton->setEnabled(true);
            sottrazioneButton->setEnabled(true);
            settimanaButton->setEnabled(true);
            giornoAnnoButton->setEnabled(true);
            giornoSettButton->setEnabled(true);
            stagioneButton->setEnabled(true);
            dataFormButton->setEnabled(true);
            durataButton->setEnabled(true);
            velocitaButton->setEnabled(true);
            orarioFormButton->setEnabled(true);
            dividiButton->setEnabled(true);
            sunriseButton->setEnabled(true);
            sunsetButton->setEnabled(true);
            noonButton->setEnabled(true);
            aggGiorniButton->setEnabled(true);
            clearButton->setEnabled(true);

            fusoButton->setDisabled(true);
            latButton->setDisabled(true);
            lonButton->setDisabled(true);
            emisButton->setDisabled(true);
            differenzaButton->setDisabled(true);
            orarioAltraCittaButton->setDisabled(true);
        }
        else
        {
            QMessageBox m;
            m.setText("Hai sbagliato coglione");
            m.exec();
        }
    }
}

//METODI VIRTUALI
void view::clickSomma(){
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Somma Orario"));
    QLineEdit* line1= new QLineEdit(dialog);
    QString textline1=QString("Ore: ");
    QLineEdit* line2= new QLineEdit(dialog);
    QString textline2=QString("Minuti: ");
    QLineEdit* line3= new QLineEdit(dialog);
    QString textline3=QString("Secondi: ");

    form.addRow(textline1, line1);
    form.addRow(textline2, line2);
    form.addRow(textline3, line3);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        bool sent=true;
        QString s;
        if(!(Orario->isEnabled()) && Data->isEnabled()) { //sono su orario
            s= s+line1->text() + ":" + line2->text() + ":" + line3->text();
            sent= controller->onClickSomma(s);
            if (sent)
            {
                //time->hide();
                QTime t=controller->getTime();
                mostraOra=t.toString("hh:mm:ss");
                time->setText(mostraOra);
                time->show();
            }
            else
            {
                QMessageBox m;
                m.setText("Hai sbagliato coglione");
                m.exec();
            }
        }
        else { //sono su data
            s= s+line1->text() + ":" + line2->text() + ":" + line3->text();
            sent= controller->onClickSomma(s);
            if(sent) {
                   QDateTime d=controller->getDateTime();
                   //QTime t=controller->getTime();
                   mostraData=d.date().toString("dd/MM/yyyy");
                   mostraOra=d.time().toString("hh:mm:ss");
                   time->setText(mostraOra);
                   date->setText(mostraData);
                   time->show();
                   date->show();
            }

            else {
                QMessageBox m;
                m.setText("Hai sbagliato coglione");
                m.exec();
            }
        }
    }
}


void view::clickSottrazione(){
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Sottrai Orario"));
    QLineEdit* line1= new QLineEdit(dialog);
    QString textline1=QString("Ore: ");
    QLineEdit* line2= new QLineEdit(dialog);
    QString textline2=QString("Minuti: ");
    QLineEdit* line3= new QLineEdit(dialog);
    QString textline3=QString("Secondi: ");

    form.addRow(textline1, line1);
    form.addRow(textline2, line2);
    form.addRow(textline3, line3);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        bool sent=true;
        QString s;
        if(!(Orario->isEnabled()) && Data->isEnabled()) { //sono su orario
            s= s+line1->text() + ":" + line2->text() + ":" + line3->text();
            sent= controller->onClickSottrazione(s);
            if (sent)
            {
                //time->hide();
                QTime t=controller->getTime();
                mostraOra=t.toString("hh:mm:ss");
                time->setText(mostraOra);
                time->show();
            }
            else
            {
                QMessageBox m;
                m.setText("Hai sbagliato coglione");
                m.exec();
            }
        }
        else { //sono su data
            s= s+line1->text() + ":" + line2->text() + ":" + line3->text();
            sent= controller->onClickSottrazione(s);
            if(sent) {
                   QDateTime d=controller->getDateTime();
                   //QTime t=controller->getTime();
                   mostraData=d.date().toString("dd/MM/yyyy");
                   mostraOra=d.time().toString("hh:mm:ss");
                   time->setText(mostraOra);
                   date->setText(mostraData);
                   time->show();
                   date->show();
            }

            else {
                QMessageBox m;
                m.setText("Hai sbagliato coglione");
                m.exec();
            }
        }
    }
}


void view::clickClear(){
    controller->onClickClear();
    Orario->setEnabled(true);
    Data->setEnabled(true);
    Sole->setEnabled(true);
    Fuso->setEnabled(true);

    //time->hide();
    //date->hide();
    //fuso->hide();
    //sole->hide();
    QDateTime d=controller->getDateTime();
    mostraOra= d.time().toString("hh:mm:ss");
    mostraData=d.date().toString("dd/MM/yyyy");
    time->setText(mostraOra);
    date->setText(mostraData);
    time->show();
    date->show();
    fusoButton->setDisabled(true);
    latButton->setDisabled(true);
    lonButton->setDisabled(true);
    emisButton->setDisabled(true);
    differenzaButton->setDisabled(true);
    orarioAltraCittaButton->setDisabled(true);
    clearButton->setDisabled(true);

    sommaButton->setDisabled(true);
    sottrazioneButton->setDisabled(true);
    settimanaButton->setDisabled(true);
    giornoAnnoButton->setDisabled(true);
    giornoSettButton->setDisabled(true);
    stagioneButton->setDisabled(true);
    dataFormButton->setDisabled(true);
    durataButton->setDisabled(true);
    velocitaButton->setDisabled(true);
    orarioFormButton->setDisabled(true);
    dividiButton->setDisabled(true);
    sunriseButton->setDisabled(true);
    sunsetButton->setDisabled(true);
    noonButton->setDisabled(true);
}


//metodi solo di orario
void view::clickVelocita(){
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Inserisci Chilometri"));
    QLineEdit* line1= new QLineEdit(dialog);
    form.addRow(line1);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        QString s;
        s=s+line1->text();
        double km=s.toDouble();
        double aux=controller->onClickVelocita(km);
        QMessageBox MB;
        MB.setWindowTitle("Velocita");
        MB.setText("Hai guidato con una media di " + QString::number(aux) +" km/h");
        MB.setFont(QFont( "Arial", 10, QFont::Bold));
        MB.exec();
    }
}

void view::clickOrarioForm() {
    QTime t=controller->onClickOrarioForm();
    QMessageBox MB;
    MB.setWindowTitle("Formato 12h");
    MB.setText("Il formato 12h e': " + t.toString("hh:mm:ss"));
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}

void view::clickDividi(){
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Inserisci in quante parti\nVuoi dividere l'orario"));
    QLineEdit* line1= new QLineEdit(dialog);
    form.addRow(line1);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        QTime timediv=controller->onClickDividi(line1->text().toInt());
        QMessageBox MB;
        MB.setWindowTitle("Dividi Tempo");
        MB.setText(timediv.toString("hh:mm:ss"));
        MB.setFont(QFont( "Arial", 10, QFont::Bold));
        MB.exec();
    }
}
//metodi solo di data
void view::clickSettimana() {
    int sett=controller->onClickSettimana();
    QMessageBox MB;
    MB.setWindowTitle("Numero Settimana");
    MB.setText(QString::number(sett));
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}


void view::clickAggGiorni(){
    //int aux=controller->onClickAggGiorni();
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Inserisci Giorni"));
    QLineEdit* line1= new QLineEdit(dialog);
    form.addRow(line1);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        QString s;
        s=s+line1->text();
        int agg=s.toInt();
        controller->onClickAggGiorni(agg);
        QDateTime d=controller->getDateTime();
        //QTime t=controller->getTime();
        mostraData=d.date().toString("dd/MM/yyyy");
        mostraOra=d.time().toString("hh:mm:ss");
        time->setText(mostraOra);
        date->setText(mostraData);
        time->show();
        date->show();
    }
}

void view::clickGiornoAnno(){
    int day=controller->onClickGiornoAnno();
    QMessageBox MB;
    MB.setWindowTitle("Numero Giorno");
    MB.setText(QString::number(day));
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}

void view::clickGiornoSett() {
    string Nday=controller->onClickGiornoSett();
    QMessageBox MB;
    MB.setWindowTitle("Giorno della settimana");
    MB.setText(QString::fromStdString(Nday));
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}

void view::clickStagione(){
    string stag=controller->onClickStagione();
    QMessageBox MB;
    MB.setWindowTitle("Stagione");
    MB.setText(QString::fromStdString(stag));
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}

void view::clickDataForm(){
    QString s=controller->onClickDataForm();
    QMessageBox MB;
    MB.setWindowTitle("Formato Data");
    MB.setText(s);
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}

void view::clickDurata() {
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Durata Date"));
    QLineEdit* line1= new QLineEdit(dialog);
    QString textline1=QString("Giorno: ");
    QLineEdit* line2= new QLineEdit(dialog);
    QString textline2=QString("Mese: ");
    QLineEdit* line3= new QLineEdit(dialog);
    QString textline3=QString("Anno: ");

    form.addRow(textline1, line1);
    form.addRow(textline2, line2);
    form.addRow(textline3, line3);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        QString s= line1->text() + "/" + line2->text() + "/" + line3->text();
        int durata=controller->onClickDurata(s);
        QMessageBox MB;
        MB.setWindowTitle("Durata Date");
        MB.setText(QString::number(durata));
        MB.setFont(QFont( "Arial", 10, QFont::Bold));
        MB.exec();
    }
}


//metodi solo di fuso
void view::clickFuso(){
    int s=controller->onClickFuso();
    QMessageBox MB;
    MB.setWindowTitle("Fuso Orario");
    MB.setText(QString::number(s));
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}

void view::clickLat(){
    double s=controller->onClickLat();
    QMessageBox MB;
    MB.setWindowTitle("Latitudine");
    MB.setText(QString::number(s));
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}

void view::clickLon(){
    double s=controller->onClickLon();
    QMessageBox MB;
    MB.setWindowTitle("Longitudine");
    MB.setText(QString::number(s));
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}

void view::clickEmis(){
    QString s=controller->onClickEmis();
    QMessageBox MB;
    MB.setWindowTitle("Emisfero");
    MB.setText(s);
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}

void view::clickDifferenza(){
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Scegli Citta"));
    QComboBox* CB=new QComboBox;
    CB->addItem("Londra");
    CB->addItem("Casablanca");
    CB->addItem("Roma");
    CB->addItem("Parigi");
    CB->addItem("Madrid");
    CB->addItem("Helsinki");
    CB->addItem("Citta del Capo");
    CB->addItem("Mosca");
    CB->addItem("Abu Dhabi");
    CB->addItem("Bangkok");
    CB->addItem("Pechino");
    CB->addItem("Tokyp");
    CB->addItem("Seul");
    CB->addItem("Sydney");
    CB->addItem("Wellington");
    CB->addItem("Rio de Janeiro");
    CB->addItem("Buenos Aires");
    CB->addItem("Santiago");
    CB->addItem("New York");
    CB->addItem("Chicago");
    CB->addItem("Citta del Messico");
    CB->addItem("Denver");
    CB->addItem("Los Angeles");
    form.addRow(CB);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        QString s=CB->currentText();
        int diff=controller->onClickDifferenza(s.toStdString());
        QMessageBox MB;
        MB.setWindowTitle("Differenza");
        MB.setText("La di fusoorari tra le due citta' e': " + QString::number(diff));
        MB.setFont(QFont( "Arial", 10, QFont::Bold));
        MB.exec();
    }
}

void view::clickOrarioAltraCitta(){
    QDialog* dialog=new QDialog(this);
    QFormLayout form(dialog);

    form.addRow(new QLabel("Scegli Citta"));
    QComboBox* CB=new QComboBox;
    CB->addItem("Londra");
    CB->addItem("Casablanca");
    CB->addItem("Roma");
    CB->addItem("Parigi");
    CB->addItem("Madrid");
    CB->addItem("Helsinki");
    CB->addItem("Citta del Capo");
    CB->addItem("Mosca");
    CB->addItem("Abu Dhabi");
    CB->addItem("Bangkok");
    CB->addItem("Pechino");
    CB->addItem("Tokyp");
    CB->addItem("Seul");
    CB->addItem("Sydney");
    CB->addItem("Wellington");
    CB->addItem("Rio de Janeiro");
    CB->addItem("Buenos Aires");
    CB->addItem("Santiago");
    CB->addItem("New York");
    CB->addItem("Chicago");
    CB->addItem("Citta del Messico");
    CB->addItem("Denver");
    CB->addItem("Los Angeles");
    form.addRow(CB);

    QDialogButtonBox* B=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, dialog);
    form.addRow(B);
    QObject::connect(B, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(B, SIGNAL(rejected()), dialog, SLOT(reject()));

    if(dialog->exec()==QDialog::Accepted) {
        QString s=CB->currentText();
        QDateTime oracit=controller->onClickOrarioAltraCitta(s.toStdString());
        QMessageBox MB;
        MB.setWindowTitle("Orario Altra Citta'");
        MB.setText("A " + CB->currentText() + " sono le " + oracit.time().toString("hh:mm:ss") + " del " + oracit.date().toString("dd/MM/yyyy"));
        MB.setFont(QFont( "Arial", 10, QFont::Bold));
        MB.exec();
    }
}


//metodi solo di sole
void view::clickSunrise(){
    QDateTime s=controller->onClickSunrise();
    QMessageBox MB;
    MB.setWindowTitle("Sorgere");
    MB.setText(s.toString("dd:MM:yyyy") + " alle " + s.toString("hh:mm:ss"));
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}

void view::clickSunset(){
    QDateTime s=controller->onClickSunset();
    QMessageBox MB;
    MB.setWindowTitle("Tramonto");
    MB.setText(s.toString("dd:MM:yyyy") + " alle " + s.toString("hh:mm:ss"));
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}

void view::clickNoon(){
    QDateTime s=controller->onClickNoon();
    QMessageBox MB;
    MB.setWindowTitle("Mezzogiorno Solare");
    MB.setText(s.toString("dd:MM:yyyy") + " alle " + s.toString("hh:mm:ss"));
    MB.setFont(QFont( "Arial", 10, QFont::Bold));
    MB.exec();
}
