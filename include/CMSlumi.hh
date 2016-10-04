#ifndef __CMSLUMI_HH__
#define __CMSLUMI_HH__

#include <TString.h>

class TPad;

class CMSlumi
{
public:
  CMSlumi();
  CMSlumi(TString lumiText_) : CMSlumi() { lumiText=lumiText_; }
  ~CMSlumi() {}

  void Draw(TPad* pad, int iPosX=10, bool writeExtra=false);

  inline void SetExtraText(TString s) { extraText=s; }
  
private:
  TString cmsText;
  float cmsTextFont;
  
  TString extraText;
  float extraTextFont;
  
  // text sizes and text offsets with respect to the top frame
  // in unit of the top margin size
  float lumiTextSize;
  float lumiTextOffset;
  float cmsTextSize;
  float cmsTextOffset;
  
  float relPosX;
  float relPosY;
  float relExtraDY;
  
  // ratio of "CMS" and extra text size
  float extraOverCmsTextSize;
  
  TString lumiText;
  bool drawLogo;

};

#endif
