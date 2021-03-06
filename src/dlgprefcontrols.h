/***************************************************************************
                          dlgprefcontrols.h  -  description
                             -------------------
    begin                : Sat Jul 5 2003
    copyright            : (C) 2003 by Tue & Ken Haste Andersen
    email                : haste@diku.dk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef DLGPREFCONTROLS_H
#define DLGPREFCONTROLS_H

#include <QWidget>

#include "ui_dlgprefcontrolsdlg.h"
#include "configobject.h"
#include "preferences/dlgpreferencepage.h"

class ControlObjectThread;
class ControlPotmeter;
class SkinLoader;
class PlayerManager;
class MixxxApp;
class ControlObject;

/**
  *@author Tue & Ken Haste Andersen
  */

class DlgPrefControls : public DlgPreferencePage, public Ui::DlgPrefControlsDlg  {
    Q_OBJECT
  public:
    DlgPrefControls(QWidget *parent, MixxxApp *mixxx,
                    SkinLoader* pSkinLoader, PlayerManager* pPlayerManager,
                    ConfigObject<ConfigValue> *pConfig);
    virtual ~DlgPrefControls();

  public slots:
    void slotUpdate();
    void slotApply();
    void slotShow();
    void slotHide();

    void slotSetRateRange(int pos);
    void slotSetRateDir(int pos);
    void slotSetRateTempLeft(double);
    void slotSetRateTempRight(double);
    void slotSetRatePermLeft(double);
    void slotSetRatePermRight(double);
    void slotSetTooltips(int pos);
    void slotSetSkin(int);
    void slotSetScheme(int);
    void slotUpdateSchemes();
    void slotSetPositionDisplay(int);
    void slotSetPositionDisplay(double);
    void slotSetAllowTrackLoadToPlayingDeck(int);
    void slotSetCueDefault(int);
    void slotSetCueRecall(int);
    void slotSetAutoDjRequeue(int);
    void slotSetAutoDjMinimumAvailable(int);
    void slotSetAutoDjUseIgnoreTime(int);
    void slotSetAutoDjIgnoreTime(const QTime &a_rTime);
    void slotSetRateRamp(bool);
    void slotSetRateRampSensitivity(int);
    void slotSetLocale(int);


    void slotSetFrameRate(int frameRate);
    void slotSetWaveformType(int index);
    void slotSetWaveformOverviewType(int index);
    void slotSetDefaultZoom(int index);
    void slotSetZoomSynchronization(bool checked);
    void slotSetVisualGainAll(double gain);
    void slotSetVisualGainLow(double gain);
    void slotSetVisualGainMid(double gain);
    void slotSetVisualGainHigh(double gain);
    void slotSetNormalizeOverview( bool normalize);

  protected:
    void timerEvent(QTimerEvent *);

  private:
    void initWaveformControl();
    void notifyRebootNecessary();
    bool checkSkinResolution(QString skin);

    ConfigObject<ConfigValue>* m_pConfig;
    int m_timer;
    ControlObject* m_pControlPositionDisplay;
    QList<ControlObjectThread*> m_cueControls;
    QList<ControlObjectThread*> m_rateControls;
    QList<ControlObjectThread*> m_rateDirControls;
    QList<ControlObjectThread*> m_rateRangeControls;
    MixxxApp *m_mixxx;
    SkinLoader* m_pSkinLoader;
    PlayerManager* m_pPlayerManager;
};

#endif
