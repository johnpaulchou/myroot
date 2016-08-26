#include "histarray.hh"

histarray::histarray(void) : TNamed() {
  fXaxis.SetName("xaxis");
  fXaxis.SetParent(this);
  fNbinsY=0;
  fNcells=0;
}

histarray::histarray(const char* name, const char* title, Int_t nbinsx, const Float_t* xbins, Int_t nbinsy) :
  TNamed(name, title)
{
  fXaxis.SetName("xaxis");
  fXaxis.SetParent(this);

  if(nbinsx <= 0) nbinsx = 1;
  fXaxis.Set(nbinsx,xbins);

  fNbinsY=nbinsy;
  fNcells=(nbinsx+2)*fNbinsY;
  TArrayD::Set(fNcells);
}

histarray::histarray(const char* name, const char* title, Int_t nbinsx, const Double_t* xbins, Int_t nbinsy) :
  TNamed(name, title)
{
  fXaxis.SetName("xaxis");
  fXaxis.SetParent(this);

  if(nbinsx <= 0) nbinsx = 1;
  fXaxis.Set(nbinsx,xbins);

  fNbinsY=nbinsy;
  fNcells=(nbinsx+2)*fNbinsY;
  TArrayD::Set(fNcells);
}

histarray::histarray(const char* name, const char* title, Int_t nbinsx, Double_t xlow, Double_t xup, Int_t nbinsy) :
  TNamed(name, title)
{
  fXaxis.SetName("xaxis");
  fXaxis.SetParent(this);

  if(nbinsx <= 0) nbinsx = 1;
  fXaxis.Set(nbinsx,xlow,xup);

  fNbinsY=nbinsy;
  fNcells=(nbinsx+2)*fNbinsY;
  TArrayD::Set(fNcells);
}

Int_t histarray::GetBin(Double_t x, Int_t biny)
{
  Int_t binx = fXaxis.FindBin(x);
  return GetBin_(binx, biny);
}

Int_t histarray::GetNbinsX(void) const
{
  return fXaxis.GetNbins();
}

Int_t histarray::GetNbinsY(void) const
{
  return fNbinsY;
}


Int_t histarray::Fill(Double_t x, Int_t biny, Double_t weight)
{
  Int_t bin = GetBin(x, biny);
  if(bin<0) return -1;

  AddBinContent(bin, weight);
  return bin;
}

void histarray::AddBinContent(Int_t bin, Double_t content)
{
  Double_t old=GetBinContent(bin);
  SetBinContent(bin, old+content);
  return;
}

void histarray::SetBinContent(Int_t bin, Double_t content)
{
  if(bin<0 || bin>fNcells) return;
  fArray[bin] = content;
  return;
}

Double_t histarray::GetBinContent(Int_t bin) const
{
  if(bin<0 || bin>fNcells) return 0.0;
  return fArray[bin];
}

TH1D* histarray::GetHist(const char* name, Int_t biny)
{
  TH1D* h;
  // creating the new histogram depends on how the axis was defined
  if(fXaxis.GetXbins()->GetSize()>0)
    h=new TH1D(name, name, fXaxis.GetNbins(), fXaxis.GetXbins()->fArray);
  else
    h=new TH1D(name, name, fXaxis.GetNbins(), fXaxis.GetXmin(), fXaxis.GetXmax());

  for(Int_t binx=0; binx<=fXaxis.GetNbins()+1; binx++) {
    Int_t bin = GetBin_(binx, biny);
    h->SetBinContent(binx, GetBinContent(bin));
  }
  return h;
}

Int_t histarray::GetBin_(Int_t binx, Int_t biny) const
{
  if(binx<0 || binx>=(GetNbinsX()+2) || biny<0 || biny>=GetNbinsY()) return -1;

  return (binx + (GetNbinsX()+2)*biny);
}

ClassImp(histarray);
