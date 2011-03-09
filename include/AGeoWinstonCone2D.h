// $Id: AGeoWinstonCone2D.h 10 2010-11-28 06:35:46Z oxon $
// Author: Akira Okumura 2011/03/05

/******************************************************************************
 * Copyright (C) 2006-, Akira Okumura                                         *
 * All rights reserved.                                                       *
 *****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
//
// AGeoWinstonCone2D
//
// Geometry class for 2 dimensional (+ 1D length) Winston cone
// The 3rd dimention is along with Y axis
// Roland Winston (1970) J. Opt. Soc.Amer. 60, 245-247
//
///////////////////////////////////////////////////////////////////////////////

#ifndef A_GEO_WINSTON_CONE_2D_H
#define A_GEO_WINSTON_CONE_2D_H

#ifndef ROOT_TGeoBBox
#include "TGeoBBox.h"
#endif

class AGeoWinstonCone2D : public TGeoBBox {
protected:
   Double_t fR1; // Half of the larger aperture
   Double_t fR2; // Half of the smaller aperture
   Double_t fTheta; // Cutoff angle
   Double_t fF; // Focal length

public:
   AGeoWinstonCone2D();
   AGeoWinstonCone2D(Double_t r1, Double_t r2, Double_t y);
   AGeoWinstonCone2D(const char *name, Double_t r1, Double_t r2, Double_t y);
   virtual ~AGeoWinstonCone2D();

   virtual Double_t    CalcR(Double_t z) const throw(std::exception);
   virtual Double_t    CalcdRdZ(Double_t z) const throw(std::exception);
   virtual Double_t    Capacity() const;
   virtual void        ComputeBBox();
   virtual void        ComputeNormal(Double_t* point, Double_t* dir, Double_t* norm);
   virtual Bool_t      Contains(Double_t* point) const;
   virtual Int_t       DistancetoPrimitive(Int_t px, Int_t py);
   virtual Double_t    DistFromInside(Double_t* point, Double_t* dir,
                                      Int_t iact = 1,
                                      Double_t step = TGeoShape::Big(),
                                      Double_t *safe = 0) const;
   virtual Double_t    DistFromOutside(Double_t* point, Double_t* dir,
                                       Int_t iact = 1,
                                       Double_t step = TGeoShape::Big(),
                                       Double_t* safe = 0) const;
   virtual Double_t    DistToParabola(Double_t* point, Double_t* dir) const;
   virtual Double_t    DistToXY(Double_t* point, Double_t* dir) const;
   virtual Double_t    DistToXZ(Double_t* point, Double_t* dir) const;
   virtual TGeoVolume* Divide(TGeoVolume* voldiv, const char* divname,
                              Int_t iaxis, Int_t ndiv, Double_t start,
                              Double_t step);
   virtual void        GetBoundingCylinder(Double_t* param) const;
   virtual const TBuffer3D& GetBuffer3D(Int_t reqSections, Bool_t localFrame) const;
   //virtual Int_t       GetByteCount() const {return 68 + 4*(fNPol1 + fNPol2);} // to be checked
   virtual TGeoShape*  GetMakeRuntimeShape(TGeoShape*, TGeoMatrix*) const {return 0;}
   virtual void        GetMeshNumbers(Int_t& nvert, Int_t& nsegs, Int_t& npols) const;
   virtual Int_t       GetNmeshVertices() const;
   virtual void        InspectShape() const;
   virtual Bool_t      IsCylType() const {return kFALSE;}
   virtual TBuffer3D*  MakeBuffer3D() const;
   virtual Double_t    Safety(Double_t* point, Bool_t in = kTRUE) const;
   virtual void        SavePrimitive(ostream& out, Option_t* option = "");
   virtual void        SetWinstonDimensions(Double_t r1, Double_t r2, Double_t y);
   virtual void        SetDimensions(Double_t* param);
   virtual void        SetPoints(Double_t* points) const;
   virtual void        SetPoints(Float_t* points) const;
   virtual void        SetSegsAndPols(TBuffer3D& buff) const;
   virtual void        Sizeof3D() const;

   ClassDef(AGeoWinstonCone2D, 1)
};

#endif // A_GEO_WINSTON_CONE_2D_H
