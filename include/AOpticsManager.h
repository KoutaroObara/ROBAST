// $Id: AOpticsManager.h 3 2010-11-26 17:17:31Z oxon $
// Author: Akira Okumura 2007/09/24

/******************************************************************************
 * Copyright (C) 2006-, Akira Okumura                                         *
 * All rights reserved.                                                       *
 *****************************************************************************/

#ifndef A_OPTICS_MANAGER_H
#define A_OPTICS_MANAGER_H

///////////////////////////////////////////////////////////////////////////////
//
// AOpticsManager
//
// Manager of optics
//
///////////////////////////////////////////////////////////////////////////////

#ifndef ROOT_TGeoManager
#include "TGeoManager.h"
#endif
#ifndef ROOT_TMath
#include "TMath.h"
#endif

#ifndef A_RAY_ARRAY_H
#include "ARayArray.h"
#endif
#ifndef A_FOCAL_SURFACE_H
#include "AFocalSurface.h"
#endif
#ifndef A_LENS_H
#include "ALens.h"
#endif
#ifndef A_MIRROR_H
#include "AMirror.h"
#endif
#ifndef A_OPTICAL_COMPONENT_H
#include "AOpticalComponent.h"
#endif
#ifndef A_OBSCURATION_H
#include "AObscuration.h"
#endif

class AOpticsManager : public TGeoManager {
 private:
  Int_t fLimit; // Maximum number of crossing calculations
  UInt_t fNThreads;
  Bool_t fDisableFresnelReflection; // disable Fresnel reflection

  Double_t  fStep; //!
  Double_t  fD1[3]; //! start direction to be shared among methods
  Double_t  fD2[3]; //! end direction to be shared among methods
  Double_t  fX1[4]; //! start point to be shared among methods
  Double_t  fX2[4]; //! end point to be shared among methods
  TGeoNode* fEndNode; //! end node
  TGeoNode* fStartNode; //! start node
  Int_t     fTypeEnd; //! type of end node
  Int_t     fTypeStart; //! type of start node

 public:
  enum {kLens, kObs, kMirror, kFocus, kOpt, kOther, kNull};

  AOpticsManager();
  AOpticsManager(const char* name, const char* title);
  virtual ~AOpticsManager();

  static Double_t km() { return 1e3*m();};
  static Double_t  m() { return 1e2*cm();};
  static Double_t cm() { return 1;};
  static Double_t mm() { return 1e-3*m();};
  static Double_t um() { return 1e-6*m();};
  static Double_t nm() { return 1e-9*m();};

  void   DisableFresnelReflection(Bool_t disable) {fDisableFresnelReflection = disable;}
  void   DoFresnel(Double_t n1, Double_t n2, ARay& ray);
  void   DoReflection(Double_t n1, ARay& ray);
  Bool_t IsFocalSurface(TGeoNode* node) const { return node->GetVolume()->IsA() == AFocalSurface::Class();};
  Bool_t IsLens(TGeoNode* node) const { return node->GetVolume()->IsA() == ALens::Class();};
  Bool_t IsMirror(TGeoNode* node) const { return node->GetVolume()->IsA() == AMirror::Class();};
  Bool_t IsObscuration(TGeoNode* node) const { return node->GetVolume()->IsA() == AObscuration::Class();};
  Bool_t IsOpticalComponent(TGeoNode* node) const { return node->GetVolume()->IsA() == AOpticalComponent::Class();};
  TVector3 GetFacetNormal();
  void SetLimit(Int_t n);
  void TraceNonSequential(ARay& ray);
  void TraceNonSequential(ARayArray& array);

  ClassDef(AOpticsManager, 1)
};

#endif // A_OPTICS_MANAGER_H
