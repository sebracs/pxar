#include "PHCalibration.hh"

#include <TMath.h>

using namespace std;

// ----------------------------------------------------------------------
PHCalibration::PHCalibration() {

}


// ----------------------------------------------------------------------
PHCalibration::~PHCalibration() {

}

// ----------------------------------------------------------------------
double PHCalibration::vcal(int iroc, int icol, int irow, double ph) {
  int idx = icol*80+irow; 
  double x = (TMath::ATanH((ph - fParameters[iroc][idx].p3)/fParameters[iroc][idx].p2) + fParameters[iroc][idx].p1)
    / fParameters[iroc][idx].p0;
  return x;
}

// ----------------------------------------------------------------------
double PHCalibration::ph(int iroc, int icol, int irow, double vcal) {
  int idx = icol*80+irow; 
  double x = fParameters[iroc][idx].p3 + fParameters[iroc][idx].p2 
    * TMath::TanH(fParameters[iroc][idx].p0 * vcal - fParameters[iroc][idx].p1);
  return x;
}

// ----------------------------------------------------------------------
void PHCalibration::setPHParameters(std::vector<std::vector<gainPedestalParameters> >v) {
  fParameters = v; 
} 
