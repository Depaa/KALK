#ifndef CONTROL_H
#define CONTROL_H
#include"model.h"
#include"view.h"
#include<QString>
#include<QTime>
#include<QDate>
#include <QDateTime>
#include <QChar>
/*
The Controller can ask the Model to update its data.
The Controller can ask the View to change its presentation,
e.g. Showing a Dialog instead of Outputing to Console.
Basically it is a component that takes input from the user and
sends commands to the View or Model.

Controller:
Intermediary between Model & View
Updates the view when the model changes
Updates the model when the user manipulates the view
Typically where the app logic lives

conversioni dai tipi QT ai tipi nostri

*/

class control
{
    private:
        model* mod;
    public:
        control(model*);

        virtual ~control();

        bool onClickCreaOrario(QString) const;
        bool onClickCreaData(QString) const;
        bool onClickCreaFuso(string) const;
        bool onClickCreaSole(QString) const;

        //METODI VIRTUALI
        bool onClickSomma(QString) const;
        bool onClickSottrazione(QString) const;
        void onClickClear() const;

        //metodi solo di orario
        double onClickVelocita(double) const;
        void onClickOrarioForm() const;
        void onClickDividi() const;

        //metodi solo di data
        int onClickSettimana() const; //numero settimana
        int onClickGiornoAnno() const; //numero
        string onClickGiornoSett() const; //nome giorno
        string onClickStagione() const;
        void onClickDataForm() const;
        int onClickDurata(QString) const;

        //metodi solo di fuso
        int onClickFuso() const;
        double onClickLat() const;
        double onClickLon() const;
        int onClickEmis() const;
        int onClickDifferenza(string) const;
        //getDateTime per non ripetere 4 volte solite operazioni
        QDateTime getDateTime() const;

        QDateTime onClickOrarioAltraCitta(string) const;

        //metodi solo di sole
        QDateTime onClickSunrise() const;
        QDateTime onClickSunset() const;
        QDateTime onClickNoon() const;

};

#endif // CONTROL_H
