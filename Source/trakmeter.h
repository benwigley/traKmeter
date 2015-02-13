/* ----------------------------------------------------------------------------

   traKmeter
   =========
   Loudness meter for correctly setting up tracking and mixing levels

   Copyright (c) 2012-2015 Martin Zuther (http://www.mzuther.de/)

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   Thank you for using free software!

---------------------------------------------------------------------------- */

#ifndef __TRAKMETER_H__
#define __TRAKMETER_H__

#include "JuceHeader.h"
#include "meter_ballistics.h"
#include "meter_bar_average.h"
#include "meter_bar_peak.h"
#include "meter_segment_overload.h"
#include "meter_signal_led.h"
#include "skin.h"


//==============================================================================
/**
*/
class TraKmeter : public Component
{
public:
    static const int TRAKMETER_LABEL_WIDTH = 38;
    static const int TRAKMETER_SEGMENT_WIDTH = 22;

    TraKmeter(const String &componentName, int PosX, int PosY, int nCrestFactor, int nNumChannels, int nSegmentHeight, int meter_type);
    ~TraKmeter();

    void setLevels(MeterBallistics *pMeterBallistics);
    void applySkin(Skin *pSkin);
    void resized();

private:
    JUCE_LEAK_DETECTOR(TraKmeter);

    int nInputChannels;
    int nMeterType;

    MeterBarAverage **AverageMeters;
    MeterBarPeak **PeakMeters;
    MeterSegmentOverload **MeterSegmentOverloads;

    MeterSignalLed **PeakMeterSignals;
};


#endif  // __TRAKMETER_H__


// Local Variables:
// ispell-local-dictionary: "british"
// End:
