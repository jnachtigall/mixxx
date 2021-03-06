// Tue Haste Andersen <haste@diku.dk>, (C) 2003

#ifndef WNUMBERPOS_H
#define WNUMBERPOS_H

#include "wnumber.h"

class ControlObjectThreadWidget;
class ControlObjectThread;

class WNumberPos : public WNumber {
    Q_OBJECT
  public:
    WNumberPos(const char *group, QWidget *parent=0);
    virtual ~WNumberPos();

    void setValue(double dValue);
    // Set if the display shows remaining time (true) or position (false)
    void setRemain(bool bRemain);

  protected:
    void mousePressEvent(QMouseEvent* pEvent);

  private slots:
    void slotSetValue(double);
    void slotSetRemain(double dRemain);
    void slotSetTrackSampleRate(double dSampleRate);
    void slotSetTrackSamples(double dSamples);

  private:
    // Old value set
    double m_dOldValue;
    double m_dTrackSamples;
    double m_dTrackSampleRate;
    // True if remaining content is being shown
    bool m_bRemain;
    ControlObjectThread* m_pShowTrackTimeRemaining;
    // Pointer to control object for position, rate, and track info
    ControlObjectThread* m_pVisualPlaypos;
    ControlObjectThreadWidget* m_pTrackSamples;
    ControlObjectThreadWidget* m_pTrackSampleRate;
};

#endif