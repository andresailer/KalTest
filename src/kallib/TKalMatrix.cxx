//*************************************************************************
//* ====================
//*  TKalMatrix Class
//* ====================
//*
//* (Description)
//*   This is the base class for matrix used by Kalman filter.
//* (Requires)
//* 	TMatrixD
//* (Provides)
//* 	class TKalMatrix
//* (Update Recored)
//*   2003/09/30  K.Fujii	Original version.
//*
//*************************************************************************
//
#include <iostream>
#include <iomanip>
#include "TString.h"
#include "TKalMatrix.h"

//_____________________________________________________________________
//  ------------------------------
//  A Wrapper for TMatrixD
//  ------------------------------
//
ClassImp(TKalMatrix)

//-------------------------------------------------------
// Ctors and Dtor
//-------------------------------------------------------

TKalMatrix::TKalMatrix(Int_t rowdim, Int_t coldim)
              :TMatrixD(rowdim, coldim)
{
}
                                                                                
TKalMatrix::TKalMatrix(const TKalMatrix &orig)
              :TMatrixD(orig)
{
}
                                                                                
TKalMatrix::TKalMatrix(const TMatrixD &orig)
              :TMatrixD(orig)
{
}

TKalMatrix::TKalMatrix(TMatrixD::EMatrixCreatorsOp1 op,
                             const TKalMatrix &prototype)
              :TMatrixD(op, prototype)
{
}
                                                                                
TKalMatrix::TKalMatrix(TMatrixD::EMatrixCreatorsOp1 op,
                             const TMatrixD &prototype)
              :TMatrixD(op, prototype)
{
}
                                                                                
TKalMatrix::TKalMatrix(const TKalMatrix &a,
                             TMatrixD::EMatrixCreatorsOp2 op,
                             const TKalMatrix &b)
              :TMatrixD(a, op, b)
{
}

TKalMatrix::TKalMatrix(const TMatrixD &a,
                             TMatrixD::EMatrixCreatorsOp2 op,
                             const TMatrixD &b)
              :TMatrixD(a, op, b)
{
}

TKalMatrix::TKalMatrix(const TVector3 &v)
              :TMatrixD(TKalMatrix::ToKalMat(v))
{
}

TKalMatrix::TKalMatrix(const TRotation &r)
	       :TMatrixD(3,3)
{
	(*this)(0,0) = r.XX();
	(*this)(0,1) = r.XY();
	(*this)(0,2) = r.XZ();

	(*this)(1,0) = r.YX();
	(*this)(1,1) = r.YY();
	(*this)(1,2) = r.YZ();

	(*this)(2,0) = r.ZX();
	(*this)(2,1) = r.ZY();
	(*this)(2,2) = r.ZZ();
}

//-------------------------------------------------------
// Print
//-------------------------------------------------------

void TKalMatrix::DebugPrint(std::ostream& os, Option_t *opt, Int_t ncolsps ) const
{
  using namespace std ;

   Int_t ncols   = GetNcols();
   Int_t nrows   = GetNrows();
   Int_t nsheets = (ncols-1)/ncolsps + 1;
   Int_t lastcw  = ncols - ncolsps*(nsheets-1);
   Int_t ns      = 0;

   TString title(opt);
   TString off(title.Length());
   for (Int_t c=0; c<title.Length(); c++) off += " ";

   for (Int_t sc = 1; sc <= ncols; sc += ncolsps) {
      ns++;
      if (ns == 1) os << title << "+-";
      if (ns == nsheets) {
         for (Int_t ib = 1; ib <= 11*lastcw; ib++) os << " ";
         os << "-+" << endl;
      } else {
         os << endl;
      }
      for (Int_t i = 1; i <= nrows; i++) {
         if (ns == 1) os << off << "| ";
         for (Int_t j = sc; j < sc+ncolsps && j <= ncols; j++) {
            os // << setiosflags(ios::scientific) 
                 << setw(11) << setprecision(4)
                 << (*this)(i-1,j-1);
            if (j == ncols) os << " |";
         }
         os << endl;
      }
      if (ns == 1) os << off << "+-";
      if (ns == nsheets) {
         for (Int_t ib = 1; ib <= 11*lastcw; ib++) os << " ";
         os << "-+" << endl;
      } else {
         os << endl;
      }
   }
}

//-------------------------------------------------------
// VectorToMatrix
//-------------------------------------------------------

TKalMatrix TKalMatrix::ToKalMat(const TVector3 &a)
{
   TKalMatrix md(3,1);
   md(0,0) = a.x();
   md(1,0) = a.y();
   md(2,0) = a.z();
   return md;
}

//-------------------------------------------------------
// MatrixToVector
//-------------------------------------------------------

TVector3 TKalMatrix::ToThreeVec(const TMatrixD &a)
{
   TVector3 v;
   v.SetXYZ(a(0,0), a(1,0),a(2,0));
   return v;
}
