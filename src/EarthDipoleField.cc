

#include "EarthDipoleField.hh"



EarthDipoleField::EarthDipoleField()
: G4MagneticField(),
  fDipoleMoment(8.e6),    // Tesla-km^3
  fGeomagLatitude(70.),   // deg
  fEarthRadius(6371.)     // km
{}


EarthDipoleField::~EarthDipoleField()
{}


void EarthDipoleField::GetFieldValue(const G4double Point[4],
		                             G4double *Bfield) const
{
  G4double geomagLat_radians = fGeomagLatitude * 3.1415926 / 180.;

  // Radial distance from Earth center input in kilometers
  G4double z = fEarthRadius + (Point[2]/km + 1020./2.);

  Bfield[0] = 0; // Bx
  Bfield[1] = 0; // By
  Bfield[2] = -fDipoleMoment / std::pow(z, 3) 
	  * std::sqrt(1 + 3 * std::pow(std::sin(geomagLat_radians), 2)) 
	  * tesla; // Bz
  Bfield[3] = 0; // Ex
  Bfield[4] = 0; // Ey
  Bfield[5] = 0; // Ez

}

