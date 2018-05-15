#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QString>

#include <QPushButton> //pulsante
#include <QToolButton> //pulsante con immagine
#include <QGridLayout>
//#include 'Controller.h'
#include <QTimer>
#include <QLabel>  //mostra testo o immagine


class view : public QWidget
{
    Q_OBJECT

    public:
        explicit view(QWidget* parent = 0);

        virtual ~view();

        //void setController(controller*);

    public slots:
        void clickCreaOrario();
        void clickCreaData();
        void clickCreaFuso();
        void clickCreaSole();

        void clickMostraOrario();
        void clickMostraData();
        void clickMostraFuso();
        void clickMostraSole();

        //METODI VIRTUALI
        void clickSomma();
        void clickSottrazione();
        void clickClear();

        //metodi solo di orario
        void clickVelocita();
        void clickOrarioForm();
        void clickDividi();

        //metodi solo di data
        void clickSettimana(); //numero settimana
        void clickGiornoAnno(); //numero
        void clickGiornoSett(); //nome giorno
        void clickStagione();
        void clickDataForm();
        void clickDurata();

        //metodi solo di fuso
        void clickFuso();
        void clickLat();
        void clickLon();
        void clickEmis();
        void clickDifferenza();
        void clickOrarioAltraCitta();

        //metodi solo di sole
        void clickSunrise();
        void clickSunset();
        void clickNoon();

    private:
        //controller* contr;
        QGridLayout* contGrid;

        QLabel* time;
        QLabel* date;
        QLabel* fuso;
        QLabel* sole;

        /*
        QTimer* timerOra;
        QTimer* timerData;
        QTimer* timerFuso;
        QTimer* timerSole;
        */

        QPushButton* Orario;
        QPushButton* Data;
        QPushButton* Fuso;
        QPushButton* Sole;

        //METODI VIRTUALI
        QPushButton* sommaButton;
        QPushButton* sottrazioneButton;
        QPushButton* clearButton;

        //metodi solo di orario
        QPushButton* velocitaButton;
        QPushButton* orarioFormButton;
        QPushButton* dividiButton;

        //metodi solo di data
        QPushButton* settimanaButton; //numero settimana
        QPushButton* giornoAnnoButton; //numero
        QPushButton* giornoSettButton; //nome giorno
        QPushButton* stagioneButton;
        QPushButton* dataFormButton;
        QPushButton* durataButton;

        //metodi solo di fuso
        QPushButton* fusoButton;
        QPushButton* latButton;
        QPushButton* lonButton;
        QPushButton* emisButton;
        QPushButton* differenzaButton;
        QPushButton* orarioAltraCittaButton;

        //metodi solo di sole
        QPushButton* sunriseButton;
        QPushButton* sunsetButton;
        QPushButton* noonButton;
};

#endif // VIEW_H
